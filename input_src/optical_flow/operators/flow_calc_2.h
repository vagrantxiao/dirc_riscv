void flow_calc_2(
		hls::stream<stdio_t> &Input_1,
		hls::stream<stdio_t> &Input_2,
		hls::stream<stdio_t> &Output_1);
#pragma map_target=riscv page_num=6 inst_mem_size = 65536

#pragma debug_port = 3
