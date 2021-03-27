void data_mover(
		hls::stream<ap_uint<32> > & Input_1,
		hls::stream<ap_uint<32> > & Output_1
		);
#pragma map_target = HW page_num = 30 inst_mem_size = 32768
