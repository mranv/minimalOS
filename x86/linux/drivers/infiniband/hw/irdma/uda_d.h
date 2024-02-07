/* SPDX-License-Identifier: GPL-2.0 OR Linux-OpenIB */
/* Copyright (c) 2016 - 2021 Intel Corporation */
#ifndef IRDMA_UDA_D_H
#define IRDMA_UDA_D_H

/* L4 packet type */
#define IRDMA_E_UDA_SQ_L4T_UNKNOWN	0
#define IRDMA_E_UDA_SQ_L4T_TCP		1
#define IRDMA_E_UDA_SQ_L4T_SCTP		2
#define IRDMA_E_UDA_SQ_L4T_UDP		3

/* Inner IP header type */
#define IRDMA_E_UDA_SQ_IIPT_UNKNOWN		0
#define IRDMA_E_UDA_SQ_IIPT_IPV6		1
#define IRDMA_E_UDA_SQ_IIPT_IPV4_NO_CSUM	2
#define IRDMA_E_UDA_SQ_IIPT_IPV4_CSUM		3
#define IRDMA_UDA_QPSQ_PUSHWQE BIT_ULL(56)
#define IRDMA_UDA_QPSQ_INLINEDATAFLAG BIT_ULL(57)
#define IRDMA_UDA_QPSQ_INLINEDATALEN GENMASK_ULL(55, 48)
#define IRDMA_UDA_QPSQ_ADDFRAGCNT GENMASK_ULL(41, 38)
#define IRDMA_UDA_QPSQ_IPFRAGFLAGS GENMASK_ULL(43, 42)
#define IRDMA_UDA_QPSQ_NOCHECKSUM BIT_ULL(45)
#define IRDMA_UDA_QPSQ_AHIDXVALID BIT_ULL(46)
#define IRDMA_UDA_QPSQ_LOCAL_FENCE BIT_ULL(61)
#define IRDMA_UDA_QPSQ_AHIDX GENMASK_ULL(16, 0)
#define IRDMA_UDA_QPSQ_PROTOCOL GENMASK_ULL(23, 16)
#define IRDMA_UDA_QPSQ_EXTHDRLEN GENMASK_ULL(40, 32)
#define IRDMA_UDA_QPSQ_MULTICAST BIT_ULL(63)
#define IRDMA_UDA_QPSQ_MACLEN GENMASK_ULL(62, 56)
#define IRDMA_UDA_QPSQ_MACLEN_LINE 2
#define IRDMA_UDA_QPSQ_IPLEN GENMASK_ULL(54, 48)
#define IRDMA_UDA_QPSQ_IPLEN_LINE 2
#define IRDMA_UDA_QPSQ_L4T GENMASK_ULL(31, 30)
#define IRDMA_UDA_QPSQ_L4T_LINE 2
#define IRDMA_UDA_QPSQ_IIPT GENMASK_ULL(29, 28)
#define IRDMA_UDA_QPSQ_IIPT_LINE 2

#define IRDMA_UDA_QPSQ_DO_LPB_LINE 3
#define IRDMA_UDA_QPSQ_FWD_PROG_CONFIRM BIT_ULL(45)
#define IRDMA_UDA_QPSQ_FWD_PROG_CONFIRM_LINE 3
#define IRDMA_UDA_QPSQ_IMMDATA GENMASK_ULL(63, 0)

/* Byte Offset 0 */
#define IRDMA_UDAQPC_IPV4_M BIT_ULL(3)
#define IRDMA_UDAQPC_INSERTVLANTAG BIT_ULL(5)
#define IRDMA_UDAQPC_ISQP1 BIT_ULL(6)

#define IRDMA_UDAQPC_ECNENABLE BIT_ULL(14)
#define IRDMA_UDAQPC_PDINDEXHI GENMASK_ULL(21, 20)
#define IRDMA_UDAQPC_DCTCPENABLE BIT_ULL(25)

#define IRDMA_UDAQPC_RCVTPHEN IRDMAQPC_RCVTPHEN
#define IRDMA_UDAQPC_XMITTPHEN IRDMAQPC_XMITTPHEN
#define IRDMA_UDAQPC_RQTPHEN IRDMAQPC_RQTPHEN
#define IRDMA_UDAQPC_SQTPHEN IRDMAQPC_SQTPHEN
#define IRDMA_UDAQPC_PPIDX IRDMAQPC_PPIDX
#define IRDMA_UDAQPC_PMENA IRDMAQPC_PMENA
#define IRDMA_UDAQPC_INSERTTAG2 BIT_ULL(11)
#define IRDMA_UDAQPC_INSERTTAG3 BIT_ULL(14)

#define IRDMA_UDAQPC_RQSIZE IRDMAQPC_RQSIZE
#define IRDMA_UDAQPC_SQSIZE IRDMAQPC_SQSIZE
#define IRDMA_UDAQPC_TXCQNUM IRDMAQPC_TXCQNUM
#define IRDMA_UDAQPC_RXCQNUM IRDMAQPC_RXCQNUM
#define IRDMA_UDAQPC_QPCOMPCTX IRDMAQPC_QPCOMPCTX
#define IRDMA_UDAQPC_SQTPHVAL IRDMAQPC_SQTPHVAL
#define IRDMA_UDAQPC_RQTPHVAL IRDMAQPC_RQTPHVAL
#define IRDMA_UDAQPC_QSHANDLE IRDMAQPC_QSHANDLE
#define IRDMA_UDAQPC_RQHDRRINGBUFSIZE GENMASK_ULL(49, 48)
#define IRDMA_UDAQPC_SQHDRRINGBUFSIZE GENMASK_ULL(33, 32)
#define IRDMA_UDAQPC_PRIVILEGEENABLE BIT_ULL(25)
#define IRDMA_UDAQPC_USE_STATISTICS_INSTANCE BIT_ULL(26)
#define IRDMA_UDAQPC_STATISTICS_INSTANCE_INDEX GENMASK_ULL(6, 0)
#define IRDMA_UDAQPC_PRIVHDRGENENABLE BIT_ULL(0)
#define IRDMA_UDAQPC_RQHDRSPLITENABLE BIT_ULL(3)
#define IRDMA_UDAQPC_RQHDRRINGBUFENABLE BIT_ULL(2)
#define IRDMA_UDAQPC_SQHDRRINGBUFENABLE BIT_ULL(1)
#define IRDMA_UDAQPC_IPID GENMASK_ULL(47, 32)
#define IRDMA_UDAQPC_SNDMSS GENMASK_ULL(29, 16)
#define IRDMA_UDAQPC_VLANTAG GENMASK_ULL(15, 0)

#define IRDMA_UDA_CQPSQ_MAV_PDINDEXHI GENMASK_ULL(21, 20)
#define IRDMA_UDA_CQPSQ_MAV_PDINDEXLO GENMASK_ULL(63, 48)
#define IRDMA_UDA_CQPSQ_MAV_SRCMACADDRINDEX GENMASK_ULL(29, 24)
#define IRDMA_UDA_CQPSQ_MAV_ARPINDEX GENMASK_ULL(63, 48)
#define IRDMA_UDA_CQPSQ_MAV_TC GENMASK_ULL(39, 32)
#define IRDMA_UDA_CQPSQ_MAV_HOPLIMIT GENMASK_ULL(39, 32)
#define IRDMA_UDA_CQPSQ_MAV_FLOWLABEL GENMASK_ULL(19, 0)
#define IRDMA_UDA_CQPSQ_MAV_ADDR0 GENMASK_ULL(63, 32)
#define IRDMA_UDA_CQPSQ_MAV_ADDR1 GENMASK_ULL(31, 0)
#define IRDMA_UDA_CQPSQ_MAV_ADDR2 GENMASK_ULL(63, 32)
#define IRDMA_UDA_CQPSQ_MAV_ADDR3 GENMASK_ULL(31, 0)
#define IRDMA_UDA_CQPSQ_MAV_WQEVALID BIT_ULL(63)
#define IRDMA_UDA_CQPSQ_MAV_OPCODE GENMASK_ULL(37, 32)
#define IRDMA_UDA_CQPSQ_MAV_DOLOOPBACKK BIT_ULL(62)
#define IRDMA_UDA_CQPSQ_MAV_IPV4VALID BIT_ULL(59)
#define IRDMA_UDA_CQPSQ_MAV_AVIDX GENMASK_ULL(16, 0)
#define IRDMA_UDA_CQPSQ_MAV_INSERTVLANTAG BIT_ULL(60)
#define IRDMA_UDA_MGCTX_VFFLAG BIT_ULL(29)
#define IRDMA_UDA_MGCTX_DESTPORT GENMASK_ULL(47, 32)
#define IRDMA_UDA_MGCTX_VFID GENMASK_ULL(28, 22)
#define IRDMA_UDA_MGCTX_VALIDENT BIT_ULL(31)
#define IRDMA_UDA_MGCTX_PFID GENMASK_ULL(21, 18)
#define IRDMA_UDA_MGCTX_FLAGIGNOREDPORT BIT_ULL(30)
#define IRDMA_UDA_MGCTX_QPID GENMASK_ULL(17, 0)
#define IRDMA_UDA_CQPSQ_MG_WQEVALID BIT_ULL(63)
#define IRDMA_UDA_CQPSQ_MG_OPCODE GENMASK_ULL(37, 32)
#define IRDMA_UDA_CQPSQ_MG_MGIDX GENMASK_ULL(12, 0)
#define IRDMA_UDA_CQPSQ_MG_IPV4VALID BIT_ULL(60)
#define IRDMA_UDA_CQPSQ_MG_VLANVALID BIT_ULL(59)
#define IRDMA_UDA_CQPSQ_MG_HMC_FCN_ID GENMASK_ULL(5, 0)
#define IRDMA_UDA_CQPSQ_MG_VLANID GENMASK_ULL(43, 32)
#define IRDMA_UDA_CQPSQ_QS_HANDLE GENMASK_ULL(9, 0)
#define IRDMA_UDA_CQPSQ_QHASH_QPN GENMASK_ULL(49, 32)
#define IRDMA_UDA_CQPSQ_QHASH_ BIT_ULL(0)
#define IRDMA_UDA_CQPSQ_QHASH_SRC_PORT GENMASK_ULL(31, 16)
#define IRDMA_UDA_CQPSQ_QHASH_DEST_PORT GENMASK_ULL(15, 0)
#define IRDMA_UDA_CQPSQ_QHASH_ADDR0 GENMASK_ULL(63, 32)
#define IRDMA_UDA_CQPSQ_QHASH_ADDR1 GENMASK_ULL(31, 0)
#define IRDMA_UDA_CQPSQ_QHASH_ADDR2 GENMASK_ULL(63, 32)
#define IRDMA_UDA_CQPSQ_QHASH_ADDR3 GENMASK_ULL(31, 0)
#define IRDMA_UDA_CQPSQ_QHASH_WQEVALID BIT_ULL(63)
#define IRDMA_UDA_CQPSQ_QHASH_OPCODE GENMASK_ULL(37, 32)
#define IRDMA_UDA_CQPSQ_QHASH_MANAGE GENMASK_ULL(62, 61)
#define IRDMA_UDA_CQPSQ_QHASH_IPV4VALID GENMASK_ULL(60, 60)
#define IRDMA_UDA_CQPSQ_QHASH_LANFWD GENMASK_ULL(59, 59)
#define IRDMA_UDA_CQPSQ_QHASH_ENTRYTYPE GENMASK_ULL(44, 42)
#endif /* IRDMA_UDA_D_H */
