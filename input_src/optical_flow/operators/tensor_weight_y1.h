// tensor weight
void tensor_weight_y1(
		hls::stream<databus_t> &Input_1,
		hls::stream<databus_t> &Output_1);
#pragma map_target=riscv page_num=19 inst_mem_size = 131072
#pragma debug_port = 3
