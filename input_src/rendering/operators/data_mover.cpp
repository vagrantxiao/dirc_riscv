#include "../host/typedefs.h"



void data_mover(
		hls::stream<ap_uint<32> > & Input_1,
		hls::stream<ap_uint<32> > & Output_1
		)

//( bit32 input[3*NUM_3D_TRI], bit32 output[NUM_FB])
{
#pragma HLS INTERFACE ap_hs port=Input_1
#pragma HLS INTERFACE ap_hs port=Output_1
    // create space for input and output
    bit32 input_tmp;
    static int cnt = 0;
    // pack input data for better performance
    	input_tmp = Input_1.read();
#ifdef RISCV
    	if((cnt&0x1ff) == 0){
    		print_dec(cnt);
    		print_str("\n");
    	}
    	cnt++;

#endif
    	Output_1.write(input_tmp);
}



