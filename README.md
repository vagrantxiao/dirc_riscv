# DIRC based on PicoRV32 (for FPL2021 Blind Review)
## 1 Introduction
DIRC (**D**ataflow **I**ncremental **R**efinement of **C** code) is a top-level 
tool, that allows the developers migrate applications from pure software to hydrid-
or pure-hardware running on the FPGAs. 
This is a temporary anonymous repo for DIRC with [picorv32](https://github.com/cliffordwolf/picorv32) support.
We will release it as an open-source repo if the paper could be accepted.
DIRC is based on Vivado and RISC-V 
tool chains. When C++ application are developed in the form of dataflow computational 
graph, DIRC can map streaming operators within the application too a pre-defined 
overlays and performs fast compilation. As an initial functional implementation, 
DIRC can map the C/C++ applications to RISC-V cores clusters within seconds for 
quick functionality verfication and debugging. After that, the users can change 
the operators mapping targets by only changing some pragmas, the DIRC can compile 
only the changed operators in parallel. DIRC can run both on local machine and 
google cloud platform (GCP). When run DIRC on the local machine, the Makefile 
can explore the maximum parallelism  by the maximum local threads. When running 
the DIRC on the google cloud platform, we use SLURM as the scheculer to parallel 
independent compilation jobs. In the following section, we will show you how to 
use DIRC for incremental development by mapping **Optical Flow** from [Rosetta Benchmark](https://github.com/cornell-zhang/rosetta), 
both with local macine and GCP.

### 1.1 How DIRC works?
To use DIRC to develop the benchmarks, the application code should be written in the form 
of dataflow graph. We take the optical flow example as below.

![](images/opticalflow_origin.jpg)

It has 9 operators. Each operator has an individual .cpp and .h file. The Makefile
will detect wether these .cpp or .h files have been ever changed, and only lauch 
corresponding compilation jobs either locally or on the goole cloud. As the figure
below, all the 9 operators compilations jobs are idependent and can be performed 
in parallel. Accroding to the opertor's header file, the operators can be mapped
to FPGA Fabric or pre-compiled RISC-V cores. As shown in the flow_calc.h Line 3,
flow_calc operator's target is hardware (HW), the flow_calc.cpp will be compiled
by the Vivado_HLS to generate the verilog files. Out-of_context synthesis can compile
the Verilog files into DCP files. The overlay is pre-compiled DCP, which are
equipped with RISC-V cores on all the Partical Reconfigurable pages. It obay the 
normal partial reconfigration flow from Xilinx. After the overlay is implemented
(Placed and routed), we empty the paritial reconfigurable pages out, and store the 
corresponding bitstreams as a RISC-V library. 

If the operator target HW, the pragam direvative p_num can specify which leaf to 
map (flow_cal.h L3). The overlay will first be loaded, and fill in the target 
leaf with the flow_calc.dcp and do the placement and routing under the context of
the overlay. After that, the partial bitstream will be generated.

If the operator taget is riscv, the tersor_x.cpp will be passed through RISC-V
tool chain and generate the ELF (Executable and Linkage File) without any hardware
compilation. It usually takes around seconds.    



![](images/DIRC_system.jpg)




## 2 Tool Setup

### 2.1 SDSoC Preparation
Due to Rosetta Benchmark is based on some libraries (hls_video.h, ect.), which are stripped off by the latest
Vitis_HLS, we still develop the demo with [SDSoC 2018.2](https://www.xilinx.com/support/download/index.html/content/xilinx/en/downloadNav/vitis/archive-sdsoc.html) 
and target the [ZCU102 board](https://www.xilinx.com/support/documentation/boards_and_kits/zcu102/ug1182-zcu102-eval-bd.pdf).
As the partial reconfiguration shell is released recently , we will move on to Vitls_HLS
soon.

### 2.2 RISC-V Tool Praparation

The RISC-V toolchain is based on picorv32 repo. You can install the RISC-V toolchain with 
this commit tag (411d134).
We copy the installation guide from [picorv32](https://github.com/cliffordwolf/picorv32) 
as below.

    # Ubuntu packages needed:
    sudo apt-get install autoconf automake autotools-dev curl libmpc-dev \
            libmpfr-dev libgmp-dev gawk build-essential bison flex texinfo \
	    gperf libtool patchutils bc zlib1g-dev git libexpat1-dev

    sudo mkdir /opt/RISC-V32i
    sudo chown $USER /opt/RISC-V32i

    git clone https://github.com/RISC-V/RISC-V-gnu-toolchain RISC-V-gnu-toolchain-rv32i
    cd RISC-V-gnu-toolchain-rv32i
    git checkout 411d134
    git submodule update --init --recursive

    mkdir build; cd build
    ../configure --with-arch=rv32i --prefix=/opt/RISC-V32i
    make -j$(nproc)


## 3 Benchmark Preparation
1. To get our [Makefile](./Makefile) to work, you need to copy your application cpp
code to certain directory. We take 
**Optial Flow** as an example.
2. You can create the directory [optical_flow](./input_src) with the same 
name as the benchmark under '**./input_src**'.
3. We create one cpp file and one header file for each operator. In 
[./input_src/optical_flow/operators](./input_src/optical_flow/operators), we
can see 9 operators to be mapped to partial reconfigurable pages.
4. We can set the page number and target (HW or RISC-V) in the header file
for each [operator](input_src/rendering/operators/data_redir_m.h).

```c
    #pragma map_target = HW page_num = 3 inst_mem_size = 65536
```

5. Currently, we use a **top** function in [./input_src/optical_flow/host/top.cpp](./input_src/optical_flow/host/top.cpp)
to show how to connect different operators together. Our python script 
([config.py](./pr_flow/config.py)) will
parse the top.cpp and operator header files to extract the interconnection,
and generate the configuration packets.
 

## 4 Tutorial 2: Map one operator to RISC-V
1. The partial reconfigurable page 3 is pre-loaded with one picorc32 cores.
To make sure the RISC-V core can run 'ap_int.h' and 'ap_fixed.h', the 
smallest bram size it 65536 Bytes. We could only pre-load one page (page 3) with
RISC-V for ultra96, but for ZCU102, we can pre-load 16 RISC-V cores.

![](images/Overlay_ultra96.png)

2. We are going to switch '**data_redir**' page to RISC-V. To achieve
this goal, we only need to avoid downloading any partial bitstreams to
page 3 and use ARM to send instruction data through BFT to the pre-loaded
RISC-V core. 

3. As the user, we only need to change the pragma in [data_redir.h](./input_src/rendering/operators/data_redir_m.h).
```c
    #pragma map_target = riscv page_num = 3 inst_mem_size = 65536
```
4. Type '**Make**', the RISC-V elf file will be compiled automatically.

5. Type '**Make config**", the instr_data will make copied to Vitis project,
and the cpp source will also be updated.

6. Type '**Make download**' to download the bitstreams into the board,
and launch the Vitis project to run the project. You can see the results
with one page running on the RISC-V core.



## 3 Tutorial 1: Map all Operators to Hardware
1. After you set up all the necessary tools, you need set the directory 
for Vitis and RISC-V toolchain in [configure.xml](./common/configure/configure.xml).
```c
    <spec name = "Xilinx_dir" value = "/scratch/unsafe/SDSoC/Vivado/2020.1/settings64.sh" />
    <spec name = "RISC-V_dir"  value = "/scratch/unsafe/RISCV/RISC-V32" />
```

2. In the [Makefile](./Makefile), change the **prj_name** to **rendering**.
```c
    prj_name=rendering
```

3. Type '**Make -j$(nproc)**'. It will generate all the necessary DCP and 
bitstream files automatically. Different operators can be compiled in 
parallel according to the thread number of your local machine. Be carefull
with the memory requirements, when you use multi-threads to compile the 
project. When I use 8 threads to compile, I at least need 32 GB DDR 
memory.
```c
Make -j$(nproc)
```

4. Type **Make mono_prj -j$(nproc)**. It will generate floorplan_staitc_wrapper.xsa
file for Vitis project under ./workspace/F007_mono_bft_rendering/prj/.
This is a one-time compilation to get the xsa file for Vitis. You don't 
need to compile the xsa when you make changes to the operators later.
To save time, you can also copy the floorplan_staitc_wrapper.xsa [here](./BSP).
```c
Make mono_prj -j$(nproc)
```

5. I recomend you set your Vitis directory to ./workspace/vitis, and create
an empty cpp application with the same name as the benchmark, so that our Makefile
can directly copy the application cpp files to the correct directory later.
Change the stack and heap size to 0x20000 in lscript.ld file.

![](images/empty_cpp.png)

6. Type '**Make config**'. It will generate all the necessary cpp files
for the Vitis project under './workspace/F008_sdk_rendering/cpp_src'.
If you create your Vitis project under the right place, the Makefile
has already copied the cpp source to your Vitis project/src/.
Otherwise, you need to copy the source files to your Vitis project by yourself.

![](images/vitis_src.png)

7. As our floorplan_staitc_wrapper.xsa includes the correct bitstreams, you can
run the vitis project and get the correct results. At least run it once 
to get a '**run configuration file**', which we can modify later.

8. However, our target is to replace the bitstreams with our partially-generated ones. Therefore, 
we need to modify the '**run configurations file**' to avoid downloading bitstream
when launch the ARM. You can right click the project->Run As->Run Configurations.
Uncheck **Program FPGA** and **Reset entire system**, check **Reset APU**, 
and fianlly click **Apply** and **Close**. 

![](images/configuration.png)

9. Type '**Make download**', the terminal will download the static and 
partial bitstreams into the board automatically. This time, run the 
Vitis application, you should get the correct results.


## 5 Tutorial 3: Enable Print Function for Risc-V.

1. The RISC-V core can also print out some debugging information and send
it back to ARM. The ARM can parse the printed-out information and show 
it through UART.

2. We have 7 debug ports to receive debugging information from up to 7
RISC-V cores. The ARM will detect whether there are valid data in the receiving
stream fifo according to a timer interrupt, and read out the debugging data. 

3. You can modify the file [data_redir.h](./input_src/rendering/operators/data_redir_m.h) 
This means that the debugging information from page 3 will send to 
debug port 2.
```c
    #pragma map_target = riscv page_num = 3 inst_mem_size = 65536
    #pragma debug_port = 2
```

4. In the [data_redir.cpp](./input_src/rendering/operators/data_redir_m.cpp),
you can use the **print_dec** and **print_str** functions for RISC-V.
Change **RISCV1** to **RISCV**. The print code will be enabled.

```c
#ifdef RISCV
      print_dec(cnt);
      print_str("\n");
      cnt++;
    #else
      //printf("in: %08x\n", (unsigned int)input_lo);
      //printf("in: %08x\n", (unsigned int)input_mi);
      unsigned int data;
      data = input_lo;
      //printf("cnt = %08x\n", input_lo.to_int());
      cnt++;
#endif
```
`
5. Type '**Make**', the RISC-V elf file will be compiled automatically.

6. Type '**Make config**", the instr_data will make copied to Vitis project,
and the cpp source will also be updated.

7. Type '**Make download**' to download the bitstreams into the board,
and launch the Vitis project to run the project. You can see the results
with one page running on the RISC-V core. The debugging information from 
RISC-V core will show up.


## 6 Mapping Report
Type '**Make report**', you can find the compile and resource report under 
'workspace/report'.








