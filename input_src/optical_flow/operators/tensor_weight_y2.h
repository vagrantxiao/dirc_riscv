
void tensor_weight_y2(
		hls::stream<databus_t> &Input_1,
		hls::stream<databus_t> &Output_1);
#pragma map_target=riscv page_num=20 inst_mem_size = 131072
#pragma debug_port = 3
