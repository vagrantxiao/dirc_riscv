
void bin_dense_wrapper(
	hls::stream< bit32 > & Input_1,
	hls::stream< bit32 > & Input_2,
	hls::stream< bit32 > & Output_1
);
#pragma map_target = riscv page_num = 8  inst_mem_size = 131072
#pragma debug_port = 3
