void wfilter3

(
  hls::stream<ap_uint<32> > & Input_1,
  hls::stream<ap_uint<32> > & Input_2,
  hls::stream<ap_uint<32> > & Input_3,
  hls::stream<ap_uint<32> > & Output_1,
  hls::stream<ap_uint<32> > & Output_2,
  hls::stream<ap_uint<32> > & Output_3
);
#pragma map_target = riscv page_num = 17 inst_mem_size = 65536
#pragma debug_port = 3
