void wfilter3_process(
	hls::stream<ap_uint<32> > & Input_1,
	hls::stream<ap_uint<32> > & Output_1
);
#pragma map_target = riscv page_num = 24 inst_mem_size = 65536
#pragma debug_port = 3
