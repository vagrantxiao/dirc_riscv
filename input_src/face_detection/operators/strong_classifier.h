void strong_classifier

(
  hls::stream<ap_uint<32> > & Input_1,
  hls::stream<ap_uint<32> > & Input_2,
  hls::stream<ap_uint<32> > & Input_3,
  hls::stream<ap_uint<32> > & Input_4,
  hls::stream<ap_uint<32> > & Input_5,
  hls::stream<ap_uint<32> > & Output_1
);
#pragma map_target = riscv page_num = 9 inst_mem_size = 32768
#pragma debug_port = 3
