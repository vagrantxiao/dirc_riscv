#include "hls_design_meta.h"
const Port_Property HLS_Design_Meta::port_props[]={
	Port_Property("ap_clk", 1, hls_in, -1, "", "", 1),
	Port_Property("ap_rst_n", 1, hls_in, -1, "", "", 1),
	Port_Property("m_axi_gmem_read_AWVALID", 1, hls_out, 0, "m_axi", "VALID", 1),
	Port_Property("m_axi_gmem_read_AWREADY", 1, hls_in, 0, "m_axi", "READY", 1),
	Port_Property("m_axi_gmem_read_AWADDR", 32, hls_out, 0, "m_axi", "ADDR", 1),
	Port_Property("m_axi_gmem_read_AWID", 1, hls_out, 0, "m_axi", "ID", 1),
	Port_Property("m_axi_gmem_read_AWLEN", 8, hls_out, 0, "m_axi", "LEN", 1),
	Port_Property("m_axi_gmem_read_AWSIZE", 3, hls_out, 0, "m_axi", "SIZE", 1),
	Port_Property("m_axi_gmem_read_AWBURST", 2, hls_out, 0, "m_axi", "BURST", 1),
	Port_Property("m_axi_gmem_read_AWLOCK", 2, hls_out, 0, "m_axi", "LOCK", 1),
	Port_Property("m_axi_gmem_read_AWCACHE", 4, hls_out, 0, "m_axi", "CACHE", 1),
	Port_Property("m_axi_gmem_read_AWPROT", 3, hls_out, 0, "m_axi", "PROT", 1),
	Port_Property("m_axi_gmem_read_AWQOS", 4, hls_out, 0, "m_axi", "QOS", 1),
	Port_Property("m_axi_gmem_read_AWREGION", 4, hls_out, 0, "m_axi", "REGION", 1),
	Port_Property("m_axi_gmem_read_AWUSER", 1, hls_out, 0, "m_axi", "USER", 1),
	Port_Property("m_axi_gmem_read_WVALID", 1, hls_out, 0, "m_axi", "VALID", 1),
	Port_Property("m_axi_gmem_read_WREADY", 1, hls_in, 0, "m_axi", "READY", 1),
	Port_Property("m_axi_gmem_read_WDATA", 128, hls_out, 0, "m_axi", "DATA", 1),
	Port_Property("m_axi_gmem_read_WSTRB", 16, hls_out, 0, "m_axi", "STRB", 1),
	Port_Property("m_axi_gmem_read_WLAST", 1, hls_out, 0, "m_axi", "LAST", 1),
	Port_Property("m_axi_gmem_read_WID", 1, hls_out, 0, "m_axi", "ID", 1),
	Port_Property("m_axi_gmem_read_WUSER", 1, hls_out, 0, "m_axi", "USER", 1),
	Port_Property("m_axi_gmem_read_ARVALID", 1, hls_out, 0, "m_axi", "VALID", 1),
	Port_Property("m_axi_gmem_read_ARREADY", 1, hls_in, 0, "m_axi", "READY", 1),
	Port_Property("m_axi_gmem_read_ARADDR", 32, hls_out, 0, "m_axi", "ADDR", 1),
	Port_Property("m_axi_gmem_read_ARID", 1, hls_out, 0, "m_axi", "ID", 1),
	Port_Property("m_axi_gmem_read_ARLEN", 8, hls_out, 0, "m_axi", "LEN", 1),
	Port_Property("m_axi_gmem_read_ARSIZE", 3, hls_out, 0, "m_axi", "SIZE", 1),
	Port_Property("m_axi_gmem_read_ARBURST", 2, hls_out, 0, "m_axi", "BURST", 1),
	Port_Property("m_axi_gmem_read_ARLOCK", 2, hls_out, 0, "m_axi", "LOCK", 1),
	Port_Property("m_axi_gmem_read_ARCACHE", 4, hls_out, 0, "m_axi", "CACHE", 1),
	Port_Property("m_axi_gmem_read_ARPROT", 3, hls_out, 0, "m_axi", "PROT", 1),
	Port_Property("m_axi_gmem_read_ARQOS", 4, hls_out, 0, "m_axi", "QOS", 1),
	Port_Property("m_axi_gmem_read_ARREGION", 4, hls_out, 0, "m_axi", "REGION", 1),
	Port_Property("m_axi_gmem_read_ARUSER", 1, hls_out, 0, "m_axi", "USER", 1),
	Port_Property("m_axi_gmem_read_RVALID", 1, hls_in, 0, "m_axi", "VALID", 1),
	Port_Property("m_axi_gmem_read_RREADY", 1, hls_out, 0, "m_axi", "READY", 1),
	Port_Property("m_axi_gmem_read_RDATA", 128, hls_in, 0, "m_axi", "DATA", 1),
	Port_Property("m_axi_gmem_read_RLAST", 1, hls_in, 0, "m_axi", "LAST", 1),
	Port_Property("m_axi_gmem_read_RID", 1, hls_in, 0, "m_axi", "ID", 1),
	Port_Property("m_axi_gmem_read_RUSER", 1, hls_in, 0, "m_axi", "USER", 1),
	Port_Property("m_axi_gmem_read_RRESP", 2, hls_in, 0, "m_axi", "RESP", 1),
	Port_Property("m_axi_gmem_read_BVALID", 1, hls_in, 0, "m_axi", "VALID", 1),
	Port_Property("m_axi_gmem_read_BREADY", 1, hls_out, 0, "m_axi", "READY", 1),
	Port_Property("m_axi_gmem_read_BRESP", 2, hls_in, 0, "m_axi", "RESP", 1),
	Port_Property("m_axi_gmem_read_BID", 1, hls_in, 0, "m_axi", "ID", 1),
	Port_Property("m_axi_gmem_read_BUSER", 1, hls_in, 0, "m_axi", "USER", 1),
	Port_Property("fifo_out_0_V_TDATA", 32, hls_out, 5, "axis", "out_data", 1),
	Port_Property("fifo_out_0_V_TVALID", 1, hls_out, 5, "axis", "out_vld", 1),
	Port_Property("fifo_out_0_V_TREADY", 1, hls_in, 5, "axis", "out_acc", 1),
	Port_Property("fifo_out_1_V_TDATA", 32, hls_out, 6, "axis", "out_data", 1),
	Port_Property("fifo_out_1_V_TVALID", 1, hls_out, 6, "axis", "out_vld", 1),
	Port_Property("fifo_out_1_V_TREADY", 1, hls_in, 6, "axis", "out_acc", 1),
	Port_Property("fifo_out_2_V_TDATA", 32, hls_out, 7, "axis", "out_data", 1),
	Port_Property("fifo_out_2_V_TVALID", 1, hls_out, 7, "axis", "out_vld", 1),
	Port_Property("fifo_out_2_V_TREADY", 1, hls_in, 7, "axis", "out_acc", 1),
	Port_Property("fifo_out_3_V_TDATA", 32, hls_out, 8, "axis", "out_data", 1),
	Port_Property("fifo_out_3_V_TVALID", 1, hls_out, 8, "axis", "out_vld", 1),
	Port_Property("fifo_out_3_V_TREADY", 1, hls_in, 8, "axis", "out_acc", 1),
	Port_Property("fifo_out_4_V_TDATA", 32, hls_out, 9, "axis", "out_data", 1),
	Port_Property("fifo_out_4_V_TVALID", 1, hls_out, 9, "axis", "out_vld", 1),
	Port_Property("fifo_out_4_V_TREADY", 1, hls_in, 9, "axis", "out_acc", 1),
	Port_Property("fifo_out_5_V_TDATA", 32, hls_out, 10, "axis", "out_data", 1),
	Port_Property("fifo_out_5_V_TVALID", 1, hls_out, 10, "axis", "out_vld", 1),
	Port_Property("fifo_out_5_V_TREADY", 1, hls_in, 10, "axis", "out_acc", 1),
	Port_Property("s_axi_control_AWVALID", 1, hls_in, -1, "", "", 1),
	Port_Property("s_axi_control_AWREADY", 1, hls_out, -1, "", "", 1),
	Port_Property("s_axi_control_AWADDR", 6, hls_in, -1, "", "", 1),
	Port_Property("s_axi_control_WVALID", 1, hls_in, -1, "", "", 1),
	Port_Property("s_axi_control_WREADY", 1, hls_out, -1, "", "", 1),
	Port_Property("s_axi_control_WDATA", 32, hls_in, -1, "", "", 1),
	Port_Property("s_axi_control_WSTRB", 4, hls_in, -1, "", "", 1),
	Port_Property("s_axi_control_ARVALID", 1, hls_in, -1, "", "", 1),
	Port_Property("s_axi_control_ARREADY", 1, hls_out, -1, "", "", 1),
	Port_Property("s_axi_control_ARADDR", 6, hls_in, -1, "", "", 1),
	Port_Property("s_axi_control_RVALID", 1, hls_out, -1, "", "", 1),
	Port_Property("s_axi_control_RREADY", 1, hls_in, -1, "", "", 1),
	Port_Property("s_axi_control_RDATA", 32, hls_out, -1, "", "", 1),
	Port_Property("s_axi_control_RRESP", 2, hls_out, -1, "", "", 1),
	Port_Property("s_axi_control_BVALID", 1, hls_out, -1, "", "", 1),
	Port_Property("s_axi_control_BREADY", 1, hls_in, -1, "", "", 1),
	Port_Property("s_axi_control_BRESP", 2, hls_out, -1, "", "", 1),
	Port_Property("interrupt", 1, hls_out, -1, "", "", 1),
};
const char* HLS_Design_Meta::dut_name = "circ_buff_read_many128";
