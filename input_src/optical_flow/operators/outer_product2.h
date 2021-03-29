void outer_product2(
    		       hls::stream<databus_t> &Input_1,
		       hls::stream<databus_t> &Input_2,
		       hls::stream<databus_t> &Input_3,
		   hls::stream<databus_t> &Output_1
			);
#pragma map_target=riscv page_num =18 inst_mem_size = 32768
#pragma debug_port = 3
