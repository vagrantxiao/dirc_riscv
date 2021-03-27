// ==============================================================
// RTL generated by Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC
// Version: 2018.3
// Copyright (C) 1986-2018 Xilinx, Inc. All Rights Reserved.
// 
// ===========================================================

#ifndef _circ_buff_read_many128_HH_
#define _circ_buff_read_many128_HH_

#include "systemc.h"
#include "AESL_pkg.h"

#include "circ_buff_read_many128_mux_42_8_1_1.h"
#include "circ_buff_read_many128_mul_mul_8ns_16ns_24_1_1.h"
#include "circ_buff_read_many128_local_words.h"
#include "circ_buff_read_many128_tail.h"
#include "circ_buff_read_many128_data_V.h"
#include "circ_buff_read_many128_control_s_axi.h"
#include "circ_buff_read_many128_gmem_read_m_axi.h"

namespace ap_rtl {

template<unsigned int C_M_AXI_GMEM_READ_ADDR_WIDTH = 32,
         unsigned int C_M_AXI_GMEM_READ_ID_WIDTH = 1,
         unsigned int C_M_AXI_GMEM_READ_AWUSER_WIDTH = 1,
         unsigned int C_M_AXI_GMEM_READ_DATA_WIDTH = 128,
         unsigned int C_M_AXI_GMEM_READ_WUSER_WIDTH = 1,
         unsigned int C_M_AXI_GMEM_READ_ARUSER_WIDTH = 1,
         unsigned int C_M_AXI_GMEM_READ_RUSER_WIDTH = 1,
         unsigned int C_M_AXI_GMEM_READ_BUSER_WIDTH = 1,
         unsigned int C_S_AXI_CONTROL_ADDR_WIDTH = 6,
         unsigned int C_S_AXI_CONTROL_DATA_WIDTH = 32>
struct circ_buff_read_many128 : public sc_module {
    // Port declarations 83
    sc_in_clk ap_clk;
    sc_in< sc_logic > ap_rst_n;
    sc_out< sc_logic > m_axi_gmem_read_AWVALID;
    sc_in< sc_logic > m_axi_gmem_read_AWREADY;
    sc_out< sc_uint<C_M_AXI_GMEM_READ_ADDR_WIDTH> > m_axi_gmem_read_AWADDR;
    sc_out< sc_uint<C_M_AXI_GMEM_READ_ID_WIDTH> > m_axi_gmem_read_AWID;
    sc_out< sc_lv<8> > m_axi_gmem_read_AWLEN;
    sc_out< sc_lv<3> > m_axi_gmem_read_AWSIZE;
    sc_out< sc_lv<2> > m_axi_gmem_read_AWBURST;
    sc_out< sc_lv<2> > m_axi_gmem_read_AWLOCK;
    sc_out< sc_lv<4> > m_axi_gmem_read_AWCACHE;
    sc_out< sc_lv<3> > m_axi_gmem_read_AWPROT;
    sc_out< sc_lv<4> > m_axi_gmem_read_AWQOS;
    sc_out< sc_lv<4> > m_axi_gmem_read_AWREGION;
    sc_out< sc_uint<C_M_AXI_GMEM_READ_AWUSER_WIDTH> > m_axi_gmem_read_AWUSER;
    sc_out< sc_logic > m_axi_gmem_read_WVALID;
    sc_in< sc_logic > m_axi_gmem_read_WREADY;
    sc_out< sc_uint<C_M_AXI_GMEM_READ_DATA_WIDTH> > m_axi_gmem_read_WDATA;
    sc_out< sc_uint<C_M_AXI_GMEM_READ_DATA_WIDTH/8> > m_axi_gmem_read_WSTRB;
    sc_out< sc_logic > m_axi_gmem_read_WLAST;
    sc_out< sc_uint<C_M_AXI_GMEM_READ_ID_WIDTH> > m_axi_gmem_read_WID;
    sc_out< sc_uint<C_M_AXI_GMEM_READ_WUSER_WIDTH> > m_axi_gmem_read_WUSER;
    sc_out< sc_logic > m_axi_gmem_read_ARVALID;
    sc_in< sc_logic > m_axi_gmem_read_ARREADY;
    sc_out< sc_uint<C_M_AXI_GMEM_READ_ADDR_WIDTH> > m_axi_gmem_read_ARADDR;
    sc_out< sc_uint<C_M_AXI_GMEM_READ_ID_WIDTH> > m_axi_gmem_read_ARID;
    sc_out< sc_lv<8> > m_axi_gmem_read_ARLEN;
    sc_out< sc_lv<3> > m_axi_gmem_read_ARSIZE;
    sc_out< sc_lv<2> > m_axi_gmem_read_ARBURST;
    sc_out< sc_lv<2> > m_axi_gmem_read_ARLOCK;
    sc_out< sc_lv<4> > m_axi_gmem_read_ARCACHE;
    sc_out< sc_lv<3> > m_axi_gmem_read_ARPROT;
    sc_out< sc_lv<4> > m_axi_gmem_read_ARQOS;
    sc_out< sc_lv<4> > m_axi_gmem_read_ARREGION;
    sc_out< sc_uint<C_M_AXI_GMEM_READ_ARUSER_WIDTH> > m_axi_gmem_read_ARUSER;
    sc_in< sc_logic > m_axi_gmem_read_RVALID;
    sc_out< sc_logic > m_axi_gmem_read_RREADY;
    sc_in< sc_uint<C_M_AXI_GMEM_READ_DATA_WIDTH> > m_axi_gmem_read_RDATA;
    sc_in< sc_logic > m_axi_gmem_read_RLAST;
    sc_in< sc_uint<C_M_AXI_GMEM_READ_ID_WIDTH> > m_axi_gmem_read_RID;
    sc_in< sc_uint<C_M_AXI_GMEM_READ_RUSER_WIDTH> > m_axi_gmem_read_RUSER;
    sc_in< sc_lv<2> > m_axi_gmem_read_RRESP;
    sc_in< sc_logic > m_axi_gmem_read_BVALID;
    sc_out< sc_logic > m_axi_gmem_read_BREADY;
    sc_in< sc_lv<2> > m_axi_gmem_read_BRESP;
    sc_in< sc_uint<C_M_AXI_GMEM_READ_ID_WIDTH> > m_axi_gmem_read_BID;
    sc_in< sc_uint<C_M_AXI_GMEM_READ_BUSER_WIDTH> > m_axi_gmem_read_BUSER;
    sc_out< sc_lv<32> > fifo_out_0_V_TDATA;
    sc_out< sc_logic > fifo_out_0_V_TVALID;
    sc_in< sc_logic > fifo_out_0_V_TREADY;
    sc_out< sc_lv<32> > fifo_out_1_V_TDATA;
    sc_out< sc_logic > fifo_out_1_V_TVALID;
    sc_in< sc_logic > fifo_out_1_V_TREADY;
    sc_out< sc_lv<32> > fifo_out_2_V_TDATA;
    sc_out< sc_logic > fifo_out_2_V_TVALID;
    sc_in< sc_logic > fifo_out_2_V_TREADY;
    sc_out< sc_lv<32> > fifo_out_3_V_TDATA;
    sc_out< sc_logic > fifo_out_3_V_TVALID;
    sc_in< sc_logic > fifo_out_3_V_TREADY;
    sc_out< sc_lv<32> > fifo_out_4_V_TDATA;
    sc_out< sc_logic > fifo_out_4_V_TVALID;
    sc_in< sc_logic > fifo_out_4_V_TREADY;
    sc_out< sc_lv<32> > fifo_out_5_V_TDATA;
    sc_out< sc_logic > fifo_out_5_V_TVALID;
    sc_in< sc_logic > fifo_out_5_V_TREADY;
    sc_in< sc_logic > s_axi_control_AWVALID;
    sc_out< sc_logic > s_axi_control_AWREADY;
    sc_in< sc_uint<C_S_AXI_CONTROL_ADDR_WIDTH> > s_axi_control_AWADDR;
    sc_in< sc_logic > s_axi_control_WVALID;
    sc_out< sc_logic > s_axi_control_WREADY;
    sc_in< sc_uint<C_S_AXI_CONTROL_DATA_WIDTH> > s_axi_control_WDATA;
    sc_in< sc_uint<C_S_AXI_CONTROL_DATA_WIDTH/8> > s_axi_control_WSTRB;
    sc_in< sc_logic > s_axi_control_ARVALID;
    sc_out< sc_logic > s_axi_control_ARREADY;
    sc_in< sc_uint<C_S_AXI_CONTROL_ADDR_WIDTH> > s_axi_control_ARADDR;
    sc_out< sc_logic > s_axi_control_RVALID;
    sc_in< sc_logic > s_axi_control_RREADY;
    sc_out< sc_uint<C_S_AXI_CONTROL_DATA_WIDTH> > s_axi_control_RDATA;
    sc_out< sc_lv<2> > s_axi_control_RRESP;
    sc_out< sc_logic > s_axi_control_BVALID;
    sc_in< sc_logic > s_axi_control_BREADY;
    sc_out< sc_lv<2> > s_axi_control_BRESP;
    sc_out< sc_logic > interrupt;
    sc_signal< sc_logic > ap_var_for_const0;
    sc_signal< sc_logic > ap_var_for_const6;
    sc_signal< sc_lv<1> > ap_var_for_const1;
    sc_signal< sc_lv<2> > ap_var_for_const4;
    sc_signal< sc_lv<3> > ap_var_for_const3;
    sc_signal< sc_lv<32> > ap_var_for_const2;
    sc_signal< sc_lv<4> > ap_var_for_const5;
    sc_signal< sc_lv<16> > ap_var_for_const7;
    sc_signal< sc_lv<8> > ap_var_for_const8;
    sc_signal< sc_lv<8> > ap_var_for_const9;
    sc_signal< sc_lv<8> > ap_var_for_const10;
    sc_signal< sc_lv<8> > ap_var_for_const11;


    // Module declarations
    circ_buff_read_many128(sc_module_name name);
    SC_HAS_PROCESS(circ_buff_read_many128);

    ~circ_buff_read_many128();

    sc_trace_file* mVcdFile;

    ofstream mHdltvinHandle;
    ofstream mHdltvoutHandle;
    circ_buff_read_many128_local_words* local_words_U;
    circ_buff_read_many128_tail* tail_U;
    circ_buff_read_many128_control_s_axi<C_S_AXI_CONTROL_ADDR_WIDTH,C_S_AXI_CONTROL_DATA_WIDTH>* circ_buff_read_many128_control_s_axi_U;
    circ_buff_read_many128_gmem_read_m_axi<0,128,32,5,16,16,16,16,C_M_AXI_GMEM_READ_ID_WIDTH,C_M_AXI_GMEM_READ_ADDR_WIDTH,C_M_AXI_GMEM_READ_DATA_WIDTH,C_M_AXI_GMEM_READ_AWUSER_WIDTH,C_M_AXI_GMEM_READ_ARUSER_WIDTH,C_M_AXI_GMEM_READ_WUSER_WIDTH,C_M_AXI_GMEM_READ_RUSER_WIDTH,C_M_AXI_GMEM_READ_BUSER_WIDTH,C_M_AXI_GMEM_READ_USER_VALUE,C_M_AXI_GMEM_READ_PROT_VALUE,C_M_AXI_GMEM_READ_CACHE_VALUE>* circ_buff_read_many128_gmem_read_m_axi_U;
    circ_buff_read_many128_data_V* data_V_U;
    circ_buff_read_many128_mux_42_8_1_1<1,1,8,8,8,8,2,8>* circ_buff_read_many128_mux_42_8_1_1_U1;
    circ_buff_read_many128_mul_mul_8ns_16ns_24_1_1<1,1,8,16,24>* circ_buff_read_many128_mul_mul_8ns_16ns_24_1_1_U2;
    sc_signal< sc_logic > ap_rst_n_inv;
    sc_signal< sc_logic > ap_start;
    sc_signal< sc_logic > ap_done;
    sc_signal< sc_logic > ap_idle;
    sc_signal< sc_lv<26> > ap_CS_fsm;
    sc_signal< sc_logic > ap_CS_fsm_state1;
    sc_signal< sc_logic > ap_ready;
    sc_signal< sc_lv<32> > input_V;
    sc_signal< sc_lv<8> > reset;
    sc_signal< sc_lv<64> > debug_register;
    sc_signal< sc_lv<3> > useable_words_address0;
    sc_signal< sc_logic > useable_words_ce0;
    sc_signal< sc_lv<8> > useable_words_q0;
    sc_signal< sc_lv<32> > fifo_out_0_V_1_data_out;
    sc_signal< sc_logic > fifo_out_0_V_1_vld_in;
    sc_signal< sc_logic > fifo_out_0_V_1_vld_out;
    sc_signal< sc_logic > fifo_out_0_V_1_ack_in;
    sc_signal< sc_logic > fifo_out_0_V_1_ack_out;
    sc_signal< sc_lv<32> > fifo_out_0_V_1_payload_A;
    sc_signal< sc_lv<32> > fifo_out_0_V_1_payload_B;
    sc_signal< sc_logic > fifo_out_0_V_1_sel_rd;
    sc_signal< sc_logic > fifo_out_0_V_1_sel_wr;
    sc_signal< sc_logic > fifo_out_0_V_1_sel;
    sc_signal< sc_logic > fifo_out_0_V_1_load_A;
    sc_signal< sc_logic > fifo_out_0_V_1_load_B;
    sc_signal< sc_lv<2> > fifo_out_0_V_1_state;
    sc_signal< sc_logic > fifo_out_0_V_1_state_cmp_full;
    sc_signal< sc_lv<32> > fifo_out_1_V_1_data_out;
    sc_signal< sc_logic > fifo_out_1_V_1_vld_in;
    sc_signal< sc_logic > fifo_out_1_V_1_vld_out;
    sc_signal< sc_logic > fifo_out_1_V_1_ack_in;
    sc_signal< sc_logic > fifo_out_1_V_1_ack_out;
    sc_signal< sc_lv<32> > fifo_out_1_V_1_payload_A;
    sc_signal< sc_lv<32> > fifo_out_1_V_1_payload_B;
    sc_signal< sc_logic > fifo_out_1_V_1_sel_rd;
    sc_signal< sc_logic > fifo_out_1_V_1_sel_wr;
    sc_signal< sc_logic > fifo_out_1_V_1_sel;
    sc_signal< sc_logic > fifo_out_1_V_1_load_A;
    sc_signal< sc_logic > fifo_out_1_V_1_load_B;
    sc_signal< sc_lv<2> > fifo_out_1_V_1_state;
    sc_signal< sc_logic > fifo_out_1_V_1_state_cmp_full;
    sc_signal< sc_lv<32> > fifo_out_2_V_1_data_out;
    sc_signal< sc_logic > fifo_out_2_V_1_vld_in;
    sc_signal< sc_logic > fifo_out_2_V_1_vld_out;
    sc_signal< sc_logic > fifo_out_2_V_1_ack_in;
    sc_signal< sc_logic > fifo_out_2_V_1_ack_out;
    sc_signal< sc_lv<32> > fifo_out_2_V_1_payload_A;
    sc_signal< sc_lv<32> > fifo_out_2_V_1_payload_B;
    sc_signal< sc_logic > fifo_out_2_V_1_sel_rd;
    sc_signal< sc_logic > fifo_out_2_V_1_sel_wr;
    sc_signal< sc_logic > fifo_out_2_V_1_sel;
    sc_signal< sc_logic > fifo_out_2_V_1_load_A;
    sc_signal< sc_logic > fifo_out_2_V_1_load_B;
    sc_signal< sc_lv<2> > fifo_out_2_V_1_state;
    sc_signal< sc_logic > fifo_out_2_V_1_state_cmp_full;
    sc_signal< sc_lv<32> > fifo_out_3_V_1_data_out;
    sc_signal< sc_logic > fifo_out_3_V_1_vld_in;
    sc_signal< sc_logic > fifo_out_3_V_1_vld_out;
    sc_signal< sc_logic > fifo_out_3_V_1_ack_in;
    sc_signal< sc_logic > fifo_out_3_V_1_ack_out;
    sc_signal< sc_lv<32> > fifo_out_3_V_1_payload_A;
    sc_signal< sc_lv<32> > fifo_out_3_V_1_payload_B;
    sc_signal< sc_logic > fifo_out_3_V_1_sel_rd;
    sc_signal< sc_logic > fifo_out_3_V_1_sel_wr;
    sc_signal< sc_logic > fifo_out_3_V_1_sel;
    sc_signal< sc_logic > fifo_out_3_V_1_load_A;
    sc_signal< sc_logic > fifo_out_3_V_1_load_B;
    sc_signal< sc_lv<2> > fifo_out_3_V_1_state;
    sc_signal< sc_logic > fifo_out_3_V_1_state_cmp_full;
    sc_signal< sc_lv<32> > fifo_out_4_V_1_data_out;
    sc_signal< sc_logic > fifo_out_4_V_1_vld_in;
    sc_signal< sc_logic > fifo_out_4_V_1_vld_out;
    sc_signal< sc_logic > fifo_out_4_V_1_ack_in;
    sc_signal< sc_logic > fifo_out_4_V_1_ack_out;
    sc_signal< sc_lv<32> > fifo_out_4_V_1_payload_A;
    sc_signal< sc_lv<32> > fifo_out_4_V_1_payload_B;
    sc_signal< sc_logic > fifo_out_4_V_1_sel_rd;
    sc_signal< sc_logic > fifo_out_4_V_1_sel_wr;
    sc_signal< sc_logic > fifo_out_4_V_1_sel;
    sc_signal< sc_logic > fifo_out_4_V_1_load_A;
    sc_signal< sc_logic > fifo_out_4_V_1_load_B;
    sc_signal< sc_lv<2> > fifo_out_4_V_1_state;
    sc_signal< sc_logic > fifo_out_4_V_1_state_cmp_full;
    sc_signal< sc_lv<32> > fifo_out_5_V_1_data_out;
    sc_signal< sc_logic > fifo_out_5_V_1_vld_in;
    sc_signal< sc_logic > fifo_out_5_V_1_vld_out;
    sc_signal< sc_logic > fifo_out_5_V_1_ack_in;
    sc_signal< sc_logic > fifo_out_5_V_1_ack_out;
    sc_signal< sc_lv<32> > fifo_out_5_V_1_payload_A;
    sc_signal< sc_lv<32> > fifo_out_5_V_1_payload_B;
    sc_signal< sc_logic > fifo_out_5_V_1_sel_rd;
    sc_signal< sc_logic > fifo_out_5_V_1_sel_wr;
    sc_signal< sc_logic > fifo_out_5_V_1_sel;
    sc_signal< sc_logic > fifo_out_5_V_1_load_A;
    sc_signal< sc_logic > fifo_out_5_V_1_load_B;
    sc_signal< sc_lv<2> > fifo_out_5_V_1_state;
    sc_signal< sc_logic > fifo_out_5_V_1_state_cmp_full;
    sc_signal< sc_lv<1> > first;
    sc_signal< sc_lv<3> > local_words_address0;
    sc_signal< sc_logic > local_words_ce0;
    sc_signal< sc_logic > local_words_we0;
    sc_signal< sc_lv<8> > local_words_q0;
    sc_signal< sc_lv<3> > tail_address0;
    sc_signal< sc_logic > tail_ce0;
    sc_signal< sc_logic > tail_we0;
    sc_signal< sc_lv<16> > tail_d0;
    sc_signal< sc_lv<16> > tail_q0;
    sc_signal< sc_logic > gmem_read_blk_n_AR;
    sc_signal< sc_logic > ap_CS_fsm_state5;
    sc_signal< sc_logic > gmem_read_blk_n_R;
    sc_signal< sc_logic > ap_CS_fsm_state12;
    sc_signal< sc_logic > ap_CS_fsm_pp0_stage0;
    sc_signal< sc_logic > ap_enable_reg_pp0_iter1;
    sc_signal< bool > ap_block_pp0_stage0;
    sc_signal< sc_lv<1> > tmp_s_reg_930;
    sc_signal< sc_logic > ap_enable_reg_pp0_iter8;
    sc_signal< sc_lv<1> > tmp_s_reg_930_pp0_iter7_reg;
    sc_signal< sc_logic > gmem_read_blk_n_AW;
    sc_signal< sc_logic > ap_CS_fsm_state29;
    sc_signal< sc_logic > gmem_read_blk_n_W;
    sc_signal< sc_logic > ap_CS_fsm_state30;
    sc_signal< sc_logic > gmem_read_blk_n_B;
    sc_signal< sc_logic > ap_CS_fsm_state35;
    sc_signal< sc_lv<1> > tmp_8_reg_920;
    sc_signal< sc_logic > fifo_out_0_V_TDATA_blk_n;
    sc_signal< sc_logic > ap_CS_fsm_pp1_stage0;
    sc_signal< sc_logic > ap_enable_reg_pp1_iter1;
    sc_signal< bool > ap_block_pp1_stage0;
    sc_signal< sc_lv<3> > stride_reg_366;
    sc_signal< sc_logic > ap_enable_reg_pp1_iter2;
    sc_signal< sc_logic > fifo_out_1_V_TDATA_blk_n;
    sc_signal< sc_logic > fifo_out_2_V_TDATA_blk_n;
    sc_signal< sc_logic > fifo_out_3_V_TDATA_blk_n;
    sc_signal< sc_logic > fifo_out_4_V_TDATA_blk_n;
    sc_signal< sc_logic > fifo_out_5_V_TDATA_blk_n;
    sc_signal< sc_logic > gmem_read_AWVALID;
    sc_signal< sc_logic > gmem_read_AWREADY;
    sc_signal< sc_lv<32> > gmem_read_AWADDR;
    sc_signal< sc_logic > gmem_read_WVALID;
    sc_signal< sc_logic > gmem_read_WREADY;
    sc_signal< sc_lv<128> > gmem_read_WDATA;
    sc_signal< sc_logic > gmem_read_ARVALID;
    sc_signal< sc_logic > gmem_read_ARREADY;
    sc_signal< sc_lv<32> > gmem_read_ARADDR;
    sc_signal< sc_logic > gmem_read_RVALID;
    sc_signal< sc_logic > gmem_read_RREADY;
    sc_signal< sc_lv<128> > gmem_read_RDATA;
    sc_signal< sc_logic > gmem_read_RLAST;
    sc_signal< sc_lv<1> > gmem_read_RID;
    sc_signal< sc_lv<1> > gmem_read_RUSER;
    sc_signal< sc_lv<2> > gmem_read_RRESP;
    sc_signal< sc_logic > gmem_read_BVALID;
    sc_signal< sc_logic > gmem_read_BREADY;
    sc_signal< sc_lv<2> > gmem_read_BRESP;
    sc_signal< sc_lv<1> > gmem_read_BID;
    sc_signal< sc_lv<1> > gmem_read_BUSER;
    sc_signal< sc_lv<16> > val_assign_reg_378;
    sc_signal< sc_lv<15> > h_reg_389;
    sc_signal< sc_lv<15> > h_reg_389_pp0_iter1_reg;
    sc_signal< bool > ap_block_state14_pp0_stage0_iter0;
    sc_signal< bool > ap_block_state15_pp0_stage0_iter1;
    sc_signal< sc_logic > ap_sig_ioackin_gmem_read_ARREADY;
    sc_signal< bool > ap_block_state15_io;
    sc_signal< bool > ap_block_state16_pp0_stage0_iter2;
    sc_signal< bool > ap_block_state17_pp0_stage0_iter3;
    sc_signal< bool > ap_block_state18_pp0_stage0_iter4;
    sc_signal< bool > ap_block_state19_pp0_stage0_iter5;
    sc_signal< bool > ap_block_state20_pp0_stage0_iter6;
    sc_signal< bool > ap_block_state21_pp0_stage0_iter7;
    sc_signal< bool > ap_block_state22_pp0_stage0_iter8;
    sc_signal< bool > ap_block_state23_pp0_stage0_iter9;
    sc_signal< bool > ap_block_pp0_stage0_11001;
    sc_signal< sc_lv<15> > h_reg_389_pp0_iter2_reg;
    sc_signal< sc_lv<15> > h_reg_389_pp0_iter3_reg;
    sc_signal< sc_lv<15> > h_reg_389_pp0_iter4_reg;
    sc_signal< sc_lv<15> > h_reg_389_pp0_iter5_reg;
    sc_signal< sc_lv<15> > h_reg_389_pp0_iter6_reg;
    sc_signal< sc_lv<15> > h_reg_389_pp0_iter7_reg;
    sc_signal< sc_lv<15> > h_reg_389_pp0_iter8_reg;
    sc_signal< sc_lv<24> > indvar_flatten_reg_401;
    sc_signal< sc_lv<15> > h2_reg_412;
    sc_signal< sc_lv<4> > t_V_reg_423;
    sc_signal< sc_lv<29> > tmp_16_cast8_fu_480_p1;
    sc_signal< sc_lv<29> > tmp_16_cast8_reg_826;
    sc_signal< sc_lv<1> > first_load_load_fu_484_p1;
    sc_signal< sc_lv<1> > first_load_reg_833;
    sc_signal< sc_lv<3> > i_1_fu_494_p2;
    sc_signal< sc_lv<3> > i_1_reg_840;
    sc_signal< sc_logic > ap_CS_fsm_state2;
    sc_signal< sc_lv<64> > tmp_2_fu_500_p1;
    sc_signal< sc_lv<64> > tmp_2_reg_845;
    sc_signal< sc_lv<1> > tmp_1_fu_488_p2;
    sc_signal< sc_lv<3> > stride_1_fu_517_p2;
    sc_signal< sc_lv<3> > stride_1_reg_861;
    sc_signal< sc_logic > ap_CS_fsm_state4;
    sc_signal< sc_lv<12> > idx_fu_523_p5;
    sc_signal< sc_lv<12> > idx_reg_866;
    sc_signal< sc_lv<1> > exitcond1_fu_511_p2;
    sc_signal< sc_lv<13> > idx_cast_fu_535_p1;
    sc_signal< sc_lv<13> > idx_cast_reg_871;
    sc_signal< sc_lv<29> > input_V2_sum_fu_549_p2;
    sc_signal< sc_lv<29> > input_V2_sum_reg_876;
    sc_signal< sc_lv<128> > stream_head_V_reg_887;
    sc_signal< sc_lv<3> > tail_addr_1_reg_894;
    sc_signal< sc_lv<17> > idx_cast3_fu_570_p1;
    sc_signal< sc_lv<17> > idx_cast3_reg_904;
    sc_signal< sc_logic > ap_CS_fsm_state13;
    sc_signal< sc_lv<8> > words_reg_914;
    sc_signal< sc_lv<1> > tmp_8_fu_577_p2;
    sc_signal< sc_lv<16> > bytes_read_fu_604_p2;
    sc_signal< sc_lv<16> > bytes_read_reg_924;
    sc_signal< sc_lv<1> > tmp_s_fu_614_p2;
    sc_signal< sc_lv<1> > tmp_s_reg_930_pp0_iter1_reg;
    sc_signal< sc_lv<1> > tmp_s_reg_930_pp0_iter2_reg;
    sc_signal< sc_lv<1> > tmp_s_reg_930_pp0_iter3_reg;
    sc_signal< sc_lv<1> > tmp_s_reg_930_pp0_iter4_reg;
    sc_signal< sc_lv<1> > tmp_s_reg_930_pp0_iter5_reg;
    sc_signal< sc_lv<1> > tmp_s_reg_930_pp0_iter6_reg;
    sc_signal< sc_lv<1> > tmp_s_reg_930_pp0_iter8_reg;
    sc_signal< sc_lv<15> > h_1_fu_619_p2;
    sc_signal< sc_lv<15> > h_1_reg_934;
    sc_signal< sc_logic > ap_enable_reg_pp0_iter0;
    sc_signal< sc_lv<29> > input_V2_sum4_fu_638_p2;
    sc_signal< sc_lv<29> > input_V2_sum4_reg_939;
    sc_signal< sc_lv<16> > stream_tail_1_cast_fu_653_p1;
    sc_signal< sc_lv<16> > stream_tail_1_cast_reg_944;
    sc_signal< sc_lv<128> > gmem_read_addr_1_rea_reg_955;
    sc_signal< sc_lv<24> > bound_fu_820_p2;
    sc_signal< sc_lv<24> > bound_reg_960;
    sc_signal< sc_logic > ap_CS_fsm_state24;
    sc_signal< sc_lv<1> > exitcond_flatten_fu_687_p2;
    sc_signal< sc_lv<1> > exitcond_flatten_reg_965;
    sc_signal< bool > ap_block_state25_pp1_stage0_iter0;
    sc_signal< bool > ap_block_state26_pp1_stage0_iter1;
    sc_signal< bool > ap_predicate_op195_write_state26;
    sc_signal< bool > ap_block_state26_io;
    sc_signal< bool > ap_block_state27_pp1_stage0_iter2;
    sc_signal< bool > ap_predicate_op206_write_state27;
    sc_signal< bool > ap_block_state27_io;
    sc_signal< bool > ap_block_pp1_stage0_11001;
    sc_signal< sc_lv<24> > indvar_flatten_next_fu_692_p2;
    sc_signal< sc_logic > ap_enable_reg_pp1_iter0;
    sc_signal< sc_lv<4> > t_V_mid2_fu_698_p3;
    sc_signal< sc_lv<4> > t_V_mid2_reg_974;
    sc_signal< sc_lv<15> > temp_V_mid2_v_fu_712_p3;
    sc_signal< sc_lv<15> > temp_V_mid2_v_reg_979;
    sc_signal< sc_lv<4> > word_V_fu_725_p2;
    sc_signal< sc_lv<32> > tmp_20_fu_758_p1;
    sc_signal< sc_lv<29> > input_V2_sum3_fu_777_p2;
    sc_signal< sc_lv<29> > input_V2_sum3_reg_1004;
    sc_signal< sc_logic > ap_CS_fsm_state28;
    sc_signal< sc_logic > ap_sig_ioackin_gmem_read_AWREADY;
    sc_signal< sc_lv<3> > i_2_fu_803_p2;
    sc_signal< sc_logic > ap_CS_fsm_state36;
    sc_signal< bool > ap_block_pp0_stage0_subdone;
    sc_signal< sc_logic > ap_condition_pp0_exit_iter0_state14;
    sc_signal< sc_logic > ap_enable_reg_pp0_iter2;
    sc_signal< sc_logic > ap_enable_reg_pp0_iter3;
    sc_signal< sc_logic > ap_enable_reg_pp0_iter4;
    sc_signal< sc_logic > ap_enable_reg_pp0_iter5;
    sc_signal< sc_logic > ap_enable_reg_pp0_iter6;
    sc_signal< sc_logic > ap_enable_reg_pp0_iter7;
    sc_signal< sc_logic > ap_enable_reg_pp0_iter9;
    sc_signal< bool > ap_block_pp1_stage0_subdone;
    sc_signal< sc_logic > ap_condition_pp1_exit_iter0_state25;
    sc_signal< sc_lv<9> > data_V_address0;
    sc_signal< sc_logic > data_V_ce0;
    sc_signal< sc_logic > data_V_we0;
    sc_signal< sc_lv<128> > data_V_q0;
    sc_signal< sc_lv<3> > i_reg_342;
    sc_signal< sc_logic > ap_CS_fsm_state3;
    sc_signal< sc_lv<1> > first_flag_reg_353;
    sc_signal< bool > ap_block_state35;
    sc_signal< sc_lv<1> > tmp_4_fu_505_p2;
    sc_signal< sc_lv<16> > ap_phi_mux_val_assign_phi_fu_382_p4;
    sc_signal< sc_lv<15> > ap_phi_mux_h_phi_fu_393_p4;
    sc_signal< sc_lv<15> > ap_phi_mux_h2_phi_fu_416_p4;
    sc_signal< sc_lv<3> > i1_reg_434;
    sc_signal< sc_lv<1> > exitcond_fu_797_p2;
    sc_signal< sc_lv<1> > ap_phi_mux_first_flag_1_phi_fu_449_p4;
    sc_signal< sc_lv<1> > first_flag_1_reg_445;
    sc_signal< sc_lv<1> > first_new_1_reg_457;
    sc_signal< sc_lv<64> > tmp_3_fu_564_p1;
    sc_signal< sc_lv<64> > tmp_12_fu_667_p1;
    sc_signal< sc_lv<64> > temp_V_mid2_fu_720_p1;
    sc_signal< sc_lv<64> > tmp_5_fu_809_p1;
    sc_signal< sc_lv<64> > input_V2_sum_cast_fu_554_p1;
    sc_signal< sc_lv<64> > input_V2_sum4_cast_fu_657_p1;
    sc_signal< sc_lv<64> > input_V2_sum3_cast_fu_782_p1;
    sc_signal< sc_logic > ap_reg_ioackin_gmem_read_ARREADY;
    sc_signal< bool > ap_block_pp0_stage0_01001;
    sc_signal< sc_logic > ap_reg_ioackin_gmem_read_AWREADY;
    sc_signal< sc_logic > ap_reg_ioackin_gmem_read_WREADY;
    sc_signal< sc_logic > ap_sig_ioackin_gmem_read_WREADY;
    sc_signal< sc_logic > ap_CS_fsm_state37;
    sc_signal< bool > ap_block_state37;
    sc_signal< bool > ap_block_pp1_stage0_01001;
    sc_signal< sc_lv<28> > tmp_fu_470_p4;
    sc_signal< sc_lv<13> > tmp_9_fu_539_p2;
    sc_signal< sc_lv<29> > tmp_cast_fu_545_p1;
    sc_signal< sc_lv<128> > tmp_6_fu_573_p1;
    sc_signal< sc_lv<16> > tmp_10_fu_587_p1;
    sc_signal< sc_lv<1> > tmp_7_fu_582_p2;
    sc_signal< sc_lv<16> > p_s_fu_590_p2;
    sc_signal< sc_lv<16> > p_pn_fu_596_p3;
    sc_signal< sc_lv<16> > h_cast_fu_610_p1;
    sc_signal< sc_lv<17> > tmp_16_cast_fu_625_p1;
    sc_signal< sc_lv<17> > tmp_13_fu_629_p2;
    sc_signal< sc_lv<29> > tmp_15_cast_fu_634_p1;
    sc_signal< sc_lv<9> > tmp_14_fu_643_p1;
    sc_signal< sc_lv<9> > stream_tail_fu_647_p2;
    sc_signal< sc_lv<8> > tmp_24_cast_fu_678_p1;
    sc_signal< sc_lv<1> > tmp_15_fu_682_p2;
    sc_signal< sc_lv<15> > h_s_fu_706_p2;
    sc_signal< sc_lv<2> > op2_assign_fu_734_p5;
    sc_signal< sc_lv<8> > op2_assign_fu_734_p6;
    sc_signal< sc_lv<128> > tmp_19_fu_748_p1;
    sc_signal< sc_lv<128> > r_V_fu_752_p2;
    sc_signal< sc_lv<13> > tmp_16_fu_768_p2;
    sc_signal< sc_lv<29> > tmp_19_cast_fu_773_p1;
    sc_signal< sc_lv<8> > bound_fu_820_p0;
    sc_signal< sc_lv<16> > bound_fu_820_p1;
    sc_signal< sc_lv<26> > ap_NS_fsm;
    sc_signal< sc_logic > ap_idle_pp0;
    sc_signal< sc_logic > ap_enable_pp0;
    sc_signal< sc_logic > ap_idle_pp1;
    sc_signal< sc_logic > ap_enable_pp1;
    sc_signal< sc_lv<24> > bound_fu_820_p00;
    sc_signal< sc_lv<24> > bound_fu_820_p10;
    sc_signal< bool > ap_condition_1071;
    static const sc_logic ap_const_logic_1;
    static const sc_logic ap_const_logic_0;
    static const sc_lv<26> ap_ST_fsm_state1;
    static const sc_lv<26> ap_ST_fsm_state2;
    static const sc_lv<26> ap_ST_fsm_state3;
    static const sc_lv<26> ap_ST_fsm_state4;
    static const sc_lv<26> ap_ST_fsm_state5;
    static const sc_lv<26> ap_ST_fsm_state6;
    static const sc_lv<26> ap_ST_fsm_state7;
    static const sc_lv<26> ap_ST_fsm_state8;
    static const sc_lv<26> ap_ST_fsm_state9;
    static const sc_lv<26> ap_ST_fsm_state10;
    static const sc_lv<26> ap_ST_fsm_state11;
    static const sc_lv<26> ap_ST_fsm_state12;
    static const sc_lv<26> ap_ST_fsm_state13;
    static const sc_lv<26> ap_ST_fsm_pp0_stage0;
    static const sc_lv<26> ap_ST_fsm_state24;
    static const sc_lv<26> ap_ST_fsm_pp1_stage0;
    static const sc_lv<26> ap_ST_fsm_state28;
    static const sc_lv<26> ap_ST_fsm_state29;
    static const sc_lv<26> ap_ST_fsm_state30;
    static const sc_lv<26> ap_ST_fsm_state31;
    static const sc_lv<26> ap_ST_fsm_state32;
    static const sc_lv<26> ap_ST_fsm_state33;
    static const sc_lv<26> ap_ST_fsm_state34;
    static const sc_lv<26> ap_ST_fsm_state35;
    static const sc_lv<26> ap_ST_fsm_state36;
    static const sc_lv<26> ap_ST_fsm_state37;
    static const sc_lv<32> ap_const_lv32_0;
    static const bool ap_const_boolean_1;
    static const sc_lv<1> ap_const_lv1_0;
    static const sc_lv<1> ap_const_lv1_1;
    static const sc_lv<2> ap_const_lv2_0;
    static const sc_lv<2> ap_const_lv2_2;
    static const sc_lv<2> ap_const_lv2_3;
    static const sc_lv<2> ap_const_lv2_1;
    static const sc_lv<32> ap_const_lv32_4;
    static const sc_lv<32> ap_const_lv32_B;
    static const sc_lv<32> ap_const_lv32_D;
    static const bool ap_const_boolean_0;
    static const sc_lv<32> ap_const_lv32_11;
    static const sc_lv<32> ap_const_lv32_12;
    static const sc_lv<32> ap_const_lv32_17;
    static const sc_lv<32> ap_const_lv32_F;
    static const sc_lv<3> ap_const_lv3_0;
    static const sc_lv<3> ap_const_lv3_1;
    static const sc_lv<3> ap_const_lv3_2;
    static const sc_lv<3> ap_const_lv3_3;
    static const sc_lv<3> ap_const_lv3_4;
    static const sc_lv<3> ap_const_lv3_7;
    static const sc_lv<3> ap_const_lv3_6;
    static const sc_lv<3> ap_const_lv3_5;
    static const int C_S_AXI_DATA_WIDTH;
    static const int C_M_AXI_GMEM_READ_USER_VALUE;
    static const int C_M_AXI_GMEM_READ_PROT_VALUE;
    static const int C_M_AXI_GMEM_READ_CACHE_VALUE;
    static const int C_M_AXI_DATA_WIDTH;
    static const sc_lv<32> ap_const_lv32_1;
    static const sc_lv<32> ap_const_lv32_3;
    static const sc_lv<32> ap_const_lv32_C;
    static const sc_lv<32> ap_const_lv32_E;
    static const sc_lv<32> ap_const_lv32_10;
    static const sc_lv<32> ap_const_lv32_18;
    static const sc_lv<32> ap_const_lv32_2;
    static const sc_lv<15> ap_const_lv15_0;
    static const sc_lv<24> ap_const_lv24_0;
    static const sc_lv<4> ap_const_lv4_0;
    static const sc_lv<16> ap_const_lv16_FFFF;
    static const sc_lv<32> ap_const_lv32_19;
    static const sc_lv<16> ap_const_lv16_0;
    static const sc_lv<32> ap_const_lv32_1F;
    static const sc_lv<8> ap_const_lv8_1;
    static const sc_lv<5> ap_const_lv5_0;
    static const sc_lv<13> ap_const_lv13_201;
    static const sc_lv<16> ap_const_lv16_200;
    static const sc_lv<15> ap_const_lv15_1;
    static const sc_lv<9> ap_const_lv9_1;
    static const sc_lv<24> ap_const_lv24_1;
    static const sc_lv<4> ap_const_lv4_1;
    static const sc_lv<8> ap_const_lv8_0;
    static const sc_lv<8> ap_const_lv8_20;
    static const sc_lv<8> ap_const_lv8_40;
    static const sc_lv<8> ap_const_lv8_60;
    static const sc_lv<13> ap_const_lv13_200;
    // Thread declarations
    void thread_ap_var_for_const0();
    void thread_ap_var_for_const6();
    void thread_ap_var_for_const1();
    void thread_ap_var_for_const4();
    void thread_ap_var_for_const3();
    void thread_ap_var_for_const2();
    void thread_ap_var_for_const5();
    void thread_ap_var_for_const7();
    void thread_ap_var_for_const8();
    void thread_ap_var_for_const9();
    void thread_ap_var_for_const10();
    void thread_ap_var_for_const11();
    void thread_ap_clk_no_reset_();
    void thread_ap_CS_fsm_pp0_stage0();
    void thread_ap_CS_fsm_pp1_stage0();
    void thread_ap_CS_fsm_state1();
    void thread_ap_CS_fsm_state12();
    void thread_ap_CS_fsm_state13();
    void thread_ap_CS_fsm_state2();
    void thread_ap_CS_fsm_state24();
    void thread_ap_CS_fsm_state28();
    void thread_ap_CS_fsm_state29();
    void thread_ap_CS_fsm_state3();
    void thread_ap_CS_fsm_state30();
    void thread_ap_CS_fsm_state35();
    void thread_ap_CS_fsm_state36();
    void thread_ap_CS_fsm_state37();
    void thread_ap_CS_fsm_state4();
    void thread_ap_CS_fsm_state5();
    void thread_ap_block_pp0_stage0();
    void thread_ap_block_pp0_stage0_01001();
    void thread_ap_block_pp0_stage0_11001();
    void thread_ap_block_pp0_stage0_subdone();
    void thread_ap_block_pp1_stage0();
    void thread_ap_block_pp1_stage0_01001();
    void thread_ap_block_pp1_stage0_11001();
    void thread_ap_block_pp1_stage0_subdone();
    void thread_ap_block_state14_pp0_stage0_iter0();
    void thread_ap_block_state15_io();
    void thread_ap_block_state15_pp0_stage0_iter1();
    void thread_ap_block_state16_pp0_stage0_iter2();
    void thread_ap_block_state17_pp0_stage0_iter3();
    void thread_ap_block_state18_pp0_stage0_iter4();
    void thread_ap_block_state19_pp0_stage0_iter5();
    void thread_ap_block_state20_pp0_stage0_iter6();
    void thread_ap_block_state21_pp0_stage0_iter7();
    void thread_ap_block_state22_pp0_stage0_iter8();
    void thread_ap_block_state23_pp0_stage0_iter9();
    void thread_ap_block_state25_pp1_stage0_iter0();
    void thread_ap_block_state26_io();
    void thread_ap_block_state26_pp1_stage0_iter1();
    void thread_ap_block_state27_io();
    void thread_ap_block_state27_pp1_stage0_iter2();
    void thread_ap_block_state35();
    void thread_ap_block_state37();
    void thread_ap_condition_1071();
    void thread_ap_condition_pp0_exit_iter0_state14();
    void thread_ap_condition_pp1_exit_iter0_state25();
    void thread_ap_done();
    void thread_ap_enable_pp0();
    void thread_ap_enable_pp1();
    void thread_ap_idle();
    void thread_ap_idle_pp0();
    void thread_ap_idle_pp1();
    void thread_ap_phi_mux_first_flag_1_phi_fu_449_p4();
    void thread_ap_phi_mux_h2_phi_fu_416_p4();
    void thread_ap_phi_mux_h_phi_fu_393_p4();
    void thread_ap_phi_mux_val_assign_phi_fu_382_p4();
    void thread_ap_predicate_op195_write_state26();
    void thread_ap_predicate_op206_write_state27();
    void thread_ap_ready();
    void thread_ap_rst_n_inv();
    void thread_ap_sig_ioackin_gmem_read_ARREADY();
    void thread_ap_sig_ioackin_gmem_read_AWREADY();
    void thread_ap_sig_ioackin_gmem_read_WREADY();
    void thread_bound_fu_820_p0();
    void thread_bound_fu_820_p00();
    void thread_bound_fu_820_p1();
    void thread_bound_fu_820_p10();
    void thread_bytes_read_fu_604_p2();
    void thread_data_V_address0();
    void thread_data_V_ce0();
    void thread_data_V_we0();
    void thread_exitcond1_fu_511_p2();
    void thread_exitcond_flatten_fu_687_p2();
    void thread_exitcond_fu_797_p2();
    void thread_fifo_out_0_V_1_ack_in();
    void thread_fifo_out_0_V_1_ack_out();
    void thread_fifo_out_0_V_1_data_out();
    void thread_fifo_out_0_V_1_load_A();
    void thread_fifo_out_0_V_1_load_B();
    void thread_fifo_out_0_V_1_sel();
    void thread_fifo_out_0_V_1_state_cmp_full();
    void thread_fifo_out_0_V_1_vld_in();
    void thread_fifo_out_0_V_1_vld_out();
    void thread_fifo_out_0_V_TDATA();
    void thread_fifo_out_0_V_TDATA_blk_n();
    void thread_fifo_out_0_V_TVALID();
    void thread_fifo_out_1_V_1_ack_in();
    void thread_fifo_out_1_V_1_ack_out();
    void thread_fifo_out_1_V_1_data_out();
    void thread_fifo_out_1_V_1_load_A();
    void thread_fifo_out_1_V_1_load_B();
    void thread_fifo_out_1_V_1_sel();
    void thread_fifo_out_1_V_1_state_cmp_full();
    void thread_fifo_out_1_V_1_vld_in();
    void thread_fifo_out_1_V_1_vld_out();
    void thread_fifo_out_1_V_TDATA();
    void thread_fifo_out_1_V_TDATA_blk_n();
    void thread_fifo_out_1_V_TVALID();
    void thread_fifo_out_2_V_1_ack_in();
    void thread_fifo_out_2_V_1_ack_out();
    void thread_fifo_out_2_V_1_data_out();
    void thread_fifo_out_2_V_1_load_A();
    void thread_fifo_out_2_V_1_load_B();
    void thread_fifo_out_2_V_1_sel();
    void thread_fifo_out_2_V_1_state_cmp_full();
    void thread_fifo_out_2_V_1_vld_in();
    void thread_fifo_out_2_V_1_vld_out();
    void thread_fifo_out_2_V_TDATA();
    void thread_fifo_out_2_V_TDATA_blk_n();
    void thread_fifo_out_2_V_TVALID();
    void thread_fifo_out_3_V_1_ack_in();
    void thread_fifo_out_3_V_1_ack_out();
    void thread_fifo_out_3_V_1_data_out();
    void thread_fifo_out_3_V_1_load_A();
    void thread_fifo_out_3_V_1_load_B();
    void thread_fifo_out_3_V_1_sel();
    void thread_fifo_out_3_V_1_state_cmp_full();
    void thread_fifo_out_3_V_1_vld_in();
    void thread_fifo_out_3_V_1_vld_out();
    void thread_fifo_out_3_V_TDATA();
    void thread_fifo_out_3_V_TDATA_blk_n();
    void thread_fifo_out_3_V_TVALID();
    void thread_fifo_out_4_V_1_ack_in();
    void thread_fifo_out_4_V_1_ack_out();
    void thread_fifo_out_4_V_1_data_out();
    void thread_fifo_out_4_V_1_load_A();
    void thread_fifo_out_4_V_1_load_B();
    void thread_fifo_out_4_V_1_sel();
    void thread_fifo_out_4_V_1_state_cmp_full();
    void thread_fifo_out_4_V_1_vld_in();
    void thread_fifo_out_4_V_1_vld_out();
    void thread_fifo_out_4_V_TDATA();
    void thread_fifo_out_4_V_TDATA_blk_n();
    void thread_fifo_out_4_V_TVALID();
    void thread_fifo_out_5_V_1_ack_in();
    void thread_fifo_out_5_V_1_ack_out();
    void thread_fifo_out_5_V_1_data_out();
    void thread_fifo_out_5_V_1_load_A();
    void thread_fifo_out_5_V_1_load_B();
    void thread_fifo_out_5_V_1_sel();
    void thread_fifo_out_5_V_1_state_cmp_full();
    void thread_fifo_out_5_V_1_vld_in();
    void thread_fifo_out_5_V_1_vld_out();
    void thread_fifo_out_5_V_TDATA();
    void thread_fifo_out_5_V_TDATA_blk_n();
    void thread_fifo_out_5_V_TVALID();
    void thread_first_load_load_fu_484_p1();
    void thread_gmem_read_ARADDR();
    void thread_gmem_read_ARVALID();
    void thread_gmem_read_AWADDR();
    void thread_gmem_read_AWVALID();
    void thread_gmem_read_BREADY();
    void thread_gmem_read_RREADY();
    void thread_gmem_read_WDATA();
    void thread_gmem_read_WVALID();
    void thread_gmem_read_blk_n_AR();
    void thread_gmem_read_blk_n_AW();
    void thread_gmem_read_blk_n_B();
    void thread_gmem_read_blk_n_R();
    void thread_gmem_read_blk_n_W();
    void thread_h_1_fu_619_p2();
    void thread_h_cast_fu_610_p1();
    void thread_h_s_fu_706_p2();
    void thread_i_1_fu_494_p2();
    void thread_i_2_fu_803_p2();
    void thread_idx_cast3_fu_570_p1();
    void thread_idx_cast_fu_535_p1();
    void thread_idx_fu_523_p5();
    void thread_indvar_flatten_next_fu_692_p2();
    void thread_input_V2_sum3_cast_fu_782_p1();
    void thread_input_V2_sum3_fu_777_p2();
    void thread_input_V2_sum4_cast_fu_657_p1();
    void thread_input_V2_sum4_fu_638_p2();
    void thread_input_V2_sum_cast_fu_554_p1();
    void thread_input_V2_sum_fu_549_p2();
    void thread_local_words_address0();
    void thread_local_words_ce0();
    void thread_local_words_we0();
    void thread_op2_assign_fu_734_p5();
    void thread_p_pn_fu_596_p3();
    void thread_p_s_fu_590_p2();
    void thread_r_V_fu_752_p2();
    void thread_stream_tail_1_cast_fu_653_p1();
    void thread_stream_tail_fu_647_p2();
    void thread_stride_1_fu_517_p2();
    void thread_t_V_mid2_fu_698_p3();
    void thread_tail_address0();
    void thread_tail_ce0();
    void thread_tail_d0();
    void thread_tail_we0();
    void thread_temp_V_mid2_fu_720_p1();
    void thread_temp_V_mid2_v_fu_712_p3();
    void thread_tmp_10_fu_587_p1();
    void thread_tmp_12_fu_667_p1();
    void thread_tmp_13_fu_629_p2();
    void thread_tmp_14_fu_643_p1();
    void thread_tmp_15_cast_fu_634_p1();
    void thread_tmp_15_fu_682_p2();
    void thread_tmp_16_cast8_fu_480_p1();
    void thread_tmp_16_cast_fu_625_p1();
    void thread_tmp_16_fu_768_p2();
    void thread_tmp_19_cast_fu_773_p1();
    void thread_tmp_19_fu_748_p1();
    void thread_tmp_1_fu_488_p2();
    void thread_tmp_20_fu_758_p1();
    void thread_tmp_24_cast_fu_678_p1();
    void thread_tmp_2_fu_500_p1();
    void thread_tmp_3_fu_564_p1();
    void thread_tmp_4_fu_505_p2();
    void thread_tmp_5_fu_809_p1();
    void thread_tmp_6_fu_573_p1();
    void thread_tmp_7_fu_582_p2();
    void thread_tmp_8_fu_577_p2();
    void thread_tmp_9_fu_539_p2();
    void thread_tmp_cast_fu_545_p1();
    void thread_tmp_fu_470_p4();
    void thread_tmp_s_fu_614_p2();
    void thread_useable_words_address0();
    void thread_useable_words_ce0();
    void thread_word_V_fu_725_p2();
    void thread_ap_NS_fsm();
    void thread_hdltv_gen();
};

}

using namespace ap_rtl;

#endif