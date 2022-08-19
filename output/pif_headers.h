/* Copyright (C) 2015-2016,  Netronome Systems, Inc.  All rights reserved. */

#ifndef __PIF_HEADERS_H__
#define __PIF_HEADERS_H__

/* Generated C source defining PIF headers, metadata and registers */
/* Warning: your edits to this file may be lost */

/*
 * Packet headers
 */

/* arp (8B) */
struct pif_header_arp {
    unsigned int hw_type:16;
    unsigned int proto_type:16;
    unsigned int hw_addr_len:8;
    unsigned int proto_addr_len:8;
    unsigned int opcode:16;
};

/* arp field accessor macros */
#define PIF_HEADER_GET_arp___hw_type(_hdr_p) (((_hdr_p)->hw_type)) /* arp.hw_type [16;0] */

#define PIF_HEADER_SET_arp___hw_type(_hdr_p, _val) \
    do { \
        (_hdr_p)->hw_type = (unsigned)(((_val))); \
    } while (0) /* arp.hw_type[16;0] */

#define PIF_HEADER_GET_arp___proto_type(_hdr_p) (((_hdr_p)->proto_type)) /* arp.proto_type [16;0] */

#define PIF_HEADER_SET_arp___proto_type(_hdr_p, _val) \
    do { \
        (_hdr_p)->proto_type = (unsigned)(((_val))); \
    } while (0) /* arp.proto_type[16;0] */

#define PIF_HEADER_GET_arp___hw_addr_len(_hdr_p) (((_hdr_p)->hw_addr_len)) /* arp.hw_addr_len [8;0] */

#define PIF_HEADER_SET_arp___hw_addr_len(_hdr_p, _val) \
    do { \
        (_hdr_p)->hw_addr_len = (unsigned)(((_val))); \
    } while (0) /* arp.hw_addr_len[8;0] */

#define PIF_HEADER_GET_arp___proto_addr_len(_hdr_p) (((_hdr_p)->proto_addr_len)) /* arp.proto_addr_len [8;0] */

#define PIF_HEADER_SET_arp___proto_addr_len(_hdr_p, _val) \
    do { \
        (_hdr_p)->proto_addr_len = (unsigned)(((_val))); \
    } while (0) /* arp.proto_addr_len[8;0] */

#define PIF_HEADER_GET_arp___opcode(_hdr_p) (((_hdr_p)->opcode)) /* arp.opcode [16;0] */

#define PIF_HEADER_SET_arp___opcode(_hdr_p, _val) \
    do { \
        (_hdr_p)->opcode = (unsigned)(((_val))); \
    } while (0) /* arp.opcode[16;0] */


/* inner_tcp (20B) */
struct pif_header_inner_tcp {
    unsigned int src_port:16;
    unsigned int dst_port:16;
    unsigned int seqNo:32;
    unsigned int ackNo:32;
    unsigned int dataOffset:4;
    unsigned int res:3;
    unsigned int ecn:3;
    unsigned int ctrl:6;
    unsigned int window:16;
    unsigned int checksum:16;
    unsigned int urgentPtr:16;
};

/* inner_tcp field accessor macros */
#define PIF_HEADER_GET_inner_tcp___src_port(_hdr_p) (((_hdr_p)->src_port)) /* inner_tcp.src_port [16;0] */

#define PIF_HEADER_SET_inner_tcp___src_port(_hdr_p, _val) \
    do { \
        (_hdr_p)->src_port = (unsigned)(((_val))); \
    } while (0) /* inner_tcp.src_port[16;0] */

#define PIF_HEADER_GET_inner_tcp___dst_port(_hdr_p) (((_hdr_p)->dst_port)) /* inner_tcp.dst_port [16;0] */

#define PIF_HEADER_SET_inner_tcp___dst_port(_hdr_p, _val) \
    do { \
        (_hdr_p)->dst_port = (unsigned)(((_val))); \
    } while (0) /* inner_tcp.dst_port[16;0] */

#define PIF_HEADER_GET_inner_tcp___seqNo(_hdr_p) (((_hdr_p)->seqNo)) /* inner_tcp.seqNo [32;0] */

#define PIF_HEADER_SET_inner_tcp___seqNo(_hdr_p, _val) \
    do { \
        (_hdr_p)->seqNo = (unsigned)(((_val))); \
    } while (0) /* inner_tcp.seqNo[32;0] */

#define PIF_HEADER_GET_inner_tcp___ackNo(_hdr_p) (((_hdr_p)->ackNo)) /* inner_tcp.ackNo [32;0] */

#define PIF_HEADER_SET_inner_tcp___ackNo(_hdr_p, _val) \
    do { \
        (_hdr_p)->ackNo = (unsigned)(((_val))); \
    } while (0) /* inner_tcp.ackNo[32;0] */

#define PIF_HEADER_GET_inner_tcp___dataOffset(_hdr_p) (((_hdr_p)->dataOffset)) /* inner_tcp.dataOffset [4;0] */

#define PIF_HEADER_SET_inner_tcp___dataOffset(_hdr_p, _val) \
    do { \
        (_hdr_p)->dataOffset = (unsigned)(((_val))); \
    } while (0) /* inner_tcp.dataOffset[4;0] */

#define PIF_HEADER_GET_inner_tcp___res(_hdr_p) (((_hdr_p)->res)) /* inner_tcp.res [3;0] */

#define PIF_HEADER_SET_inner_tcp___res(_hdr_p, _val) \
    do { \
        (_hdr_p)->res = (unsigned)(((_val))); \
    } while (0) /* inner_tcp.res[3;0] */

#define PIF_HEADER_GET_inner_tcp___ecn(_hdr_p) (((_hdr_p)->ecn)) /* inner_tcp.ecn [3;0] */

#define PIF_HEADER_SET_inner_tcp___ecn(_hdr_p, _val) \
    do { \
        (_hdr_p)->ecn = (unsigned)(((_val))); \
    } while (0) /* inner_tcp.ecn[3;0] */

#define PIF_HEADER_GET_inner_tcp___ctrl(_hdr_p) (((_hdr_p)->ctrl)) /* inner_tcp.ctrl [6;0] */

#define PIF_HEADER_SET_inner_tcp___ctrl(_hdr_p, _val) \
    do { \
        (_hdr_p)->ctrl = (unsigned)(((_val))); \
    } while (0) /* inner_tcp.ctrl[6;0] */

#define PIF_HEADER_GET_inner_tcp___window(_hdr_p) (((_hdr_p)->window)) /* inner_tcp.window [16;0] */

#define PIF_HEADER_SET_inner_tcp___window(_hdr_p, _val) \
    do { \
        (_hdr_p)->window = (unsigned)(((_val))); \
    } while (0) /* inner_tcp.window[16;0] */

#define PIF_HEADER_GET_inner_tcp___checksum(_hdr_p) (((_hdr_p)->checksum)) /* inner_tcp.checksum [16;0] */

#define PIF_HEADER_SET_inner_tcp___checksum(_hdr_p, _val) \
    do { \
        (_hdr_p)->checksum = (unsigned)(((_val))); \
    } while (0) /* inner_tcp.checksum[16;0] */

#define PIF_HEADER_GET_inner_tcp___urgentPtr(_hdr_p) (((_hdr_p)->urgentPtr)) /* inner_tcp.urgentPtr [16;0] */

#define PIF_HEADER_SET_inner_tcp___urgentPtr(_hdr_p, _val) \
    do { \
        (_hdr_p)->urgentPtr = (unsigned)(((_val))); \
    } while (0) /* inner_tcp.urgentPtr[16;0] */


/* udp (8B) */
struct pif_header_udp {
    unsigned int src_port:16;
    unsigned int dst_port:16;
    unsigned int len:16;
    unsigned int checksum:16;
};

/* udp field accessor macros */
#define PIF_HEADER_GET_udp___src_port(_hdr_p) (((_hdr_p)->src_port)) /* udp.src_port [16;0] */

#define PIF_HEADER_SET_udp___src_port(_hdr_p, _val) \
    do { \
        (_hdr_p)->src_port = (unsigned)(((_val))); \
    } while (0) /* udp.src_port[16;0] */

#define PIF_HEADER_GET_udp___dst_port(_hdr_p) (((_hdr_p)->dst_port)) /* udp.dst_port [16;0] */

#define PIF_HEADER_SET_udp___dst_port(_hdr_p, _val) \
    do { \
        (_hdr_p)->dst_port = (unsigned)(((_val))); \
    } while (0) /* udp.dst_port[16;0] */

#define PIF_HEADER_GET_udp___len(_hdr_p) (((_hdr_p)->len)) /* udp.len [16;0] */

#define PIF_HEADER_SET_udp___len(_hdr_p, _val) \
    do { \
        (_hdr_p)->len = (unsigned)(((_val))); \
    } while (0) /* udp.len[16;0] */

#define PIF_HEADER_GET_udp___checksum(_hdr_p) (((_hdr_p)->checksum)) /* udp.checksum [16;0] */

#define PIF_HEADER_SET_udp___checksum(_hdr_p, _val) \
    do { \
        (_hdr_p)->checksum = (unsigned)(((_val))); \
    } while (0) /* udp.checksum[16;0] */


/* gtpu_ex (4B) */
struct pif_header_gtpu_ex {
    unsigned int len:8;
    unsigned int pdu_type:4;
    unsigned int spare:6;
    unsigned int qfi:6;
    unsigned int next_type:8;
};

/* gtpu_ex field accessor macros */
#define PIF_HEADER_GET_gtpu_ex___len(_hdr_p) (((_hdr_p)->len)) /* gtpu_ex.len [8;0] */

#define PIF_HEADER_SET_gtpu_ex___len(_hdr_p, _val) \
    do { \
        (_hdr_p)->len = (unsigned)(((_val))); \
    } while (0) /* gtpu_ex.len[8;0] */

#define PIF_HEADER_GET_gtpu_ex___pdu_type(_hdr_p) (((_hdr_p)->pdu_type)) /* gtpu_ex.pdu_type [4;0] */

#define PIF_HEADER_SET_gtpu_ex___pdu_type(_hdr_p, _val) \
    do { \
        (_hdr_p)->pdu_type = (unsigned)(((_val))); \
    } while (0) /* gtpu_ex.pdu_type[4;0] */

#define PIF_HEADER_GET_gtpu_ex___spare(_hdr_p) (((_hdr_p)->spare)) /* gtpu_ex.spare [6;0] */

#define PIF_HEADER_SET_gtpu_ex___spare(_hdr_p, _val) \
    do { \
        (_hdr_p)->spare = (unsigned)(((_val))); \
    } while (0) /* gtpu_ex.spare[6;0] */

#define PIF_HEADER_GET_gtpu_ex___qfi(_hdr_p) (((_hdr_p)->qfi)) /* gtpu_ex.qfi [6;0] */

#define PIF_HEADER_SET_gtpu_ex___qfi(_hdr_p, _val) \
    do { \
        (_hdr_p)->qfi = (unsigned)(((_val))); \
    } while (0) /* gtpu_ex.qfi[6;0] */

#define PIF_HEADER_GET_gtpu_ex___next_type(_hdr_p) (((_hdr_p)->next_type)) /* gtpu_ex.next_type [8;0] */

#define PIF_HEADER_SET_gtpu_ex___next_type(_hdr_p, _val) \
    do { \
        (_hdr_p)->next_type = (unsigned)(((_val))); \
    } while (0) /* gtpu_ex.next_type[8;0] */


/* gtpu (8B) */
struct pif_header_gtpu {
    unsigned int version:3;
    unsigned int pt:1;
    unsigned int spare:1;
    unsigned int ex_flag:1;
    unsigned int seq_flag:1;
    unsigned int npdu_flag:1;
    unsigned int msgtype:8;
    unsigned int msglen:16;
    unsigned int teid:32;
};

/* gtpu field accessor macros */
#define PIF_HEADER_GET_gtpu___version(_hdr_p) (((_hdr_p)->version)) /* gtpu.version [3;0] */

#define PIF_HEADER_SET_gtpu___version(_hdr_p, _val) \
    do { \
        (_hdr_p)->version = (unsigned)(((_val))); \
    } while (0) /* gtpu.version[3;0] */

#define PIF_HEADER_GET_gtpu___pt(_hdr_p) (((_hdr_p)->pt)) /* gtpu.pt [1;0] */

#define PIF_HEADER_SET_gtpu___pt(_hdr_p, _val) \
    do { \
        (_hdr_p)->pt = (unsigned)(((_val))); \
    } while (0) /* gtpu.pt[1;0] */

#define PIF_HEADER_GET_gtpu___spare(_hdr_p) (((_hdr_p)->spare)) /* gtpu.spare [1;0] */

#define PIF_HEADER_SET_gtpu___spare(_hdr_p, _val) \
    do { \
        (_hdr_p)->spare = (unsigned)(((_val))); \
    } while (0) /* gtpu.spare[1;0] */

#define PIF_HEADER_GET_gtpu___ex_flag(_hdr_p) (((_hdr_p)->ex_flag)) /* gtpu.ex_flag [1;0] */

#define PIF_HEADER_SET_gtpu___ex_flag(_hdr_p, _val) \
    do { \
        (_hdr_p)->ex_flag = (unsigned)(((_val))); \
    } while (0) /* gtpu.ex_flag[1;0] */

#define PIF_HEADER_GET_gtpu___seq_flag(_hdr_p) (((_hdr_p)->seq_flag)) /* gtpu.seq_flag [1;0] */

#define PIF_HEADER_SET_gtpu___seq_flag(_hdr_p, _val) \
    do { \
        (_hdr_p)->seq_flag = (unsigned)(((_val))); \
    } while (0) /* gtpu.seq_flag[1;0] */

#define PIF_HEADER_GET_gtpu___npdu_flag(_hdr_p) (((_hdr_p)->npdu_flag)) /* gtpu.npdu_flag [1;0] */

#define PIF_HEADER_SET_gtpu___npdu_flag(_hdr_p, _val) \
    do { \
        (_hdr_p)->npdu_flag = (unsigned)(((_val))); \
    } while (0) /* gtpu.npdu_flag[1;0] */

#define PIF_HEADER_GET_gtpu___msgtype(_hdr_p) (((_hdr_p)->msgtype)) /* gtpu.msgtype [8;0] */

#define PIF_HEADER_SET_gtpu___msgtype(_hdr_p, _val) \
    do { \
        (_hdr_p)->msgtype = (unsigned)(((_val))); \
    } while (0) /* gtpu.msgtype[8;0] */

#define PIF_HEADER_GET_gtpu___msglen(_hdr_p) (((_hdr_p)->msglen)) /* gtpu.msglen [16;0] */

#define PIF_HEADER_SET_gtpu___msglen(_hdr_p, _val) \
    do { \
        (_hdr_p)->msglen = (unsigned)(((_val))); \
    } while (0) /* gtpu.msglen[16;0] */

#define PIF_HEADER_GET_gtpu___teid(_hdr_p) (((_hdr_p)->teid)) /* gtpu.teid [32;0] */

#define PIF_HEADER_SET_gtpu___teid(_hdr_p, _val) \
    do { \
        (_hdr_p)->teid = (unsigned)(((_val))); \
    } while (0) /* gtpu.teid[32;0] */


/* tcp (20B) */
struct pif_header_tcp {
    unsigned int src_port:16;
    unsigned int dst_port:16;
    unsigned int seqNo:32;
    unsigned int ackNo:32;
    unsigned int dataOffset:4;
    unsigned int res:3;
    unsigned int ecn:3;
    unsigned int ctrl:6;
    unsigned int window:16;
    unsigned int checksum:16;
    unsigned int urgentPtr:16;
};

/* tcp field accessor macros */
#define PIF_HEADER_GET_tcp___src_port(_hdr_p) (((_hdr_p)->src_port)) /* tcp.src_port [16;0] */

#define PIF_HEADER_SET_tcp___src_port(_hdr_p, _val) \
    do { \
        (_hdr_p)->src_port = (unsigned)(((_val))); \
    } while (0) /* tcp.src_port[16;0] */

#define PIF_HEADER_GET_tcp___dst_port(_hdr_p) (((_hdr_p)->dst_port)) /* tcp.dst_port [16;0] */

#define PIF_HEADER_SET_tcp___dst_port(_hdr_p, _val) \
    do { \
        (_hdr_p)->dst_port = (unsigned)(((_val))); \
    } while (0) /* tcp.dst_port[16;0] */

#define PIF_HEADER_GET_tcp___seqNo(_hdr_p) (((_hdr_p)->seqNo)) /* tcp.seqNo [32;0] */

#define PIF_HEADER_SET_tcp___seqNo(_hdr_p, _val) \
    do { \
        (_hdr_p)->seqNo = (unsigned)(((_val))); \
    } while (0) /* tcp.seqNo[32;0] */

#define PIF_HEADER_GET_tcp___ackNo(_hdr_p) (((_hdr_p)->ackNo)) /* tcp.ackNo [32;0] */

#define PIF_HEADER_SET_tcp___ackNo(_hdr_p, _val) \
    do { \
        (_hdr_p)->ackNo = (unsigned)(((_val))); \
    } while (0) /* tcp.ackNo[32;0] */

#define PIF_HEADER_GET_tcp___dataOffset(_hdr_p) (((_hdr_p)->dataOffset)) /* tcp.dataOffset [4;0] */

#define PIF_HEADER_SET_tcp___dataOffset(_hdr_p, _val) \
    do { \
        (_hdr_p)->dataOffset = (unsigned)(((_val))); \
    } while (0) /* tcp.dataOffset[4;0] */

#define PIF_HEADER_GET_tcp___res(_hdr_p) (((_hdr_p)->res)) /* tcp.res [3;0] */

#define PIF_HEADER_SET_tcp___res(_hdr_p, _val) \
    do { \
        (_hdr_p)->res = (unsigned)(((_val))); \
    } while (0) /* tcp.res[3;0] */

#define PIF_HEADER_GET_tcp___ecn(_hdr_p) (((_hdr_p)->ecn)) /* tcp.ecn [3;0] */

#define PIF_HEADER_SET_tcp___ecn(_hdr_p, _val) \
    do { \
        (_hdr_p)->ecn = (unsigned)(((_val))); \
    } while (0) /* tcp.ecn[3;0] */

#define PIF_HEADER_GET_tcp___ctrl(_hdr_p) (((_hdr_p)->ctrl)) /* tcp.ctrl [6;0] */

#define PIF_HEADER_SET_tcp___ctrl(_hdr_p, _val) \
    do { \
        (_hdr_p)->ctrl = (unsigned)(((_val))); \
    } while (0) /* tcp.ctrl[6;0] */

#define PIF_HEADER_GET_tcp___window(_hdr_p) (((_hdr_p)->window)) /* tcp.window [16;0] */

#define PIF_HEADER_SET_tcp___window(_hdr_p, _val) \
    do { \
        (_hdr_p)->window = (unsigned)(((_val))); \
    } while (0) /* tcp.window[16;0] */

#define PIF_HEADER_GET_tcp___checksum(_hdr_p) (((_hdr_p)->checksum)) /* tcp.checksum [16;0] */

#define PIF_HEADER_SET_tcp___checksum(_hdr_p, _val) \
    do { \
        (_hdr_p)->checksum = (unsigned)(((_val))); \
    } while (0) /* tcp.checksum[16;0] */

#define PIF_HEADER_GET_tcp___urgentPtr(_hdr_p) (((_hdr_p)->urgentPtr)) /* tcp.urgentPtr [16;0] */

#define PIF_HEADER_SET_tcp___urgentPtr(_hdr_p, _val) \
    do { \
        (_hdr_p)->urgentPtr = (unsigned)(((_val))); \
    } while (0) /* tcp.urgentPtr[16;0] */


/* ipv4 (20B) */
struct pif_header_ipv4 {
    unsigned int version:4;
    unsigned int ihl:4;
    unsigned int dscp:6;
    unsigned int ecn:2;
    unsigned int len:16;
    unsigned int identification:16;
    unsigned int flags:3;
    unsigned int frag_offset:13;
    unsigned int ttl:8;
    unsigned int protocol:8;
    unsigned int hdr_checksum:16;
    unsigned int src_addr:32;
    unsigned int dst_addr:32;
};

/* ipv4 field accessor macros */
#define PIF_HEADER_GET_ipv4___version(_hdr_p) (((_hdr_p)->version)) /* ipv4.version [4;0] */

#define PIF_HEADER_SET_ipv4___version(_hdr_p, _val) \
    do { \
        (_hdr_p)->version = (unsigned)(((_val))); \
    } while (0) /* ipv4.version[4;0] */

#define PIF_HEADER_GET_ipv4___ihl(_hdr_p) (((_hdr_p)->ihl)) /* ipv4.ihl [4;0] */

#define PIF_HEADER_SET_ipv4___ihl(_hdr_p, _val) \
    do { \
        (_hdr_p)->ihl = (unsigned)(((_val))); \
    } while (0) /* ipv4.ihl[4;0] */

#define PIF_HEADER_GET_ipv4___dscp(_hdr_p) (((_hdr_p)->dscp)) /* ipv4.dscp [6;0] */

#define PIF_HEADER_SET_ipv4___dscp(_hdr_p, _val) \
    do { \
        (_hdr_p)->dscp = (unsigned)(((_val))); \
    } while (0) /* ipv4.dscp[6;0] */

#define PIF_HEADER_GET_ipv4___ecn(_hdr_p) (((_hdr_p)->ecn)) /* ipv4.ecn [2;0] */

#define PIF_HEADER_SET_ipv4___ecn(_hdr_p, _val) \
    do { \
        (_hdr_p)->ecn = (unsigned)(((_val))); \
    } while (0) /* ipv4.ecn[2;0] */

#define PIF_HEADER_GET_ipv4___len(_hdr_p) (((_hdr_p)->len)) /* ipv4.len [16;0] */

#define PIF_HEADER_SET_ipv4___len(_hdr_p, _val) \
    do { \
        (_hdr_p)->len = (unsigned)(((_val))); \
    } while (0) /* ipv4.len[16;0] */

#define PIF_HEADER_GET_ipv4___identification(_hdr_p) (((_hdr_p)->identification)) /* ipv4.identification [16;0] */

#define PIF_HEADER_SET_ipv4___identification(_hdr_p, _val) \
    do { \
        (_hdr_p)->identification = (unsigned)(((_val))); \
    } while (0) /* ipv4.identification[16;0] */

#define PIF_HEADER_GET_ipv4___flags(_hdr_p) (((_hdr_p)->flags)) /* ipv4.flags [3;0] */

#define PIF_HEADER_SET_ipv4___flags(_hdr_p, _val) \
    do { \
        (_hdr_p)->flags = (unsigned)(((_val))); \
    } while (0) /* ipv4.flags[3;0] */

#define PIF_HEADER_GET_ipv4___frag_offset(_hdr_p) (((_hdr_p)->frag_offset)) /* ipv4.frag_offset [13;0] */

#define PIF_HEADER_SET_ipv4___frag_offset(_hdr_p, _val) \
    do { \
        (_hdr_p)->frag_offset = (unsigned)(((_val))); \
    } while (0) /* ipv4.frag_offset[13;0] */

#define PIF_HEADER_GET_ipv4___ttl(_hdr_p) (((_hdr_p)->ttl)) /* ipv4.ttl [8;0] */

#define PIF_HEADER_SET_ipv4___ttl(_hdr_p, _val) \
    do { \
        (_hdr_p)->ttl = (unsigned)(((_val))); \
    } while (0) /* ipv4.ttl[8;0] */

#define PIF_HEADER_GET_ipv4___protocol(_hdr_p) (((_hdr_p)->protocol)) /* ipv4.protocol [8;0] */

#define PIF_HEADER_SET_ipv4___protocol(_hdr_p, _val) \
    do { \
        (_hdr_p)->protocol = (unsigned)(((_val))); \
    } while (0) /* ipv4.protocol[8;0] */

#define PIF_HEADER_GET_ipv4___hdr_checksum(_hdr_p) (((_hdr_p)->hdr_checksum)) /* ipv4.hdr_checksum [16;0] */

#define PIF_HEADER_SET_ipv4___hdr_checksum(_hdr_p, _val) \
    do { \
        (_hdr_p)->hdr_checksum = (unsigned)(((_val))); \
    } while (0) /* ipv4.hdr_checksum[16;0] */

#define PIF_HEADER_GET_ipv4___src_addr(_hdr_p) (((_hdr_p)->src_addr)) /* ipv4.src_addr [32;0] */

#define PIF_HEADER_SET_ipv4___src_addr(_hdr_p, _val) \
    do { \
        (_hdr_p)->src_addr = (unsigned)(((_val))); \
    } while (0) /* ipv4.src_addr[32;0] */

#define PIF_HEADER_GET_ipv4___dst_addr(_hdr_p) (((_hdr_p)->dst_addr)) /* ipv4.dst_addr [32;0] */

#define PIF_HEADER_SET_ipv4___dst_addr(_hdr_p, _val) \
    do { \
        (_hdr_p)->dst_addr = (unsigned)(((_val))); \
    } while (0) /* ipv4.dst_addr[32;0] */


/* inner_ipv4 (20B) */
struct pif_header_inner_ipv4 {
    unsigned int version:4;
    unsigned int ihl:4;
    unsigned int dscp:6;
    unsigned int ecn:2;
    unsigned int len:16;
    unsigned int identification:16;
    unsigned int flags:3;
    unsigned int frag_offset:13;
    unsigned int ttl:8;
    unsigned int protocol:8;
    unsigned int hdr_checksum:16;
    unsigned int src_addr:32;
    unsigned int dst_addr:32;
};

/* inner_ipv4 field accessor macros */
#define PIF_HEADER_GET_inner_ipv4___version(_hdr_p) (((_hdr_p)->version)) /* inner_ipv4.version [4;0] */

#define PIF_HEADER_SET_inner_ipv4___version(_hdr_p, _val) \
    do { \
        (_hdr_p)->version = (unsigned)(((_val))); \
    } while (0) /* inner_ipv4.version[4;0] */

#define PIF_HEADER_GET_inner_ipv4___ihl(_hdr_p) (((_hdr_p)->ihl)) /* inner_ipv4.ihl [4;0] */

#define PIF_HEADER_SET_inner_ipv4___ihl(_hdr_p, _val) \
    do { \
        (_hdr_p)->ihl = (unsigned)(((_val))); \
    } while (0) /* inner_ipv4.ihl[4;0] */

#define PIF_HEADER_GET_inner_ipv4___dscp(_hdr_p) (((_hdr_p)->dscp)) /* inner_ipv4.dscp [6;0] */

#define PIF_HEADER_SET_inner_ipv4___dscp(_hdr_p, _val) \
    do { \
        (_hdr_p)->dscp = (unsigned)(((_val))); \
    } while (0) /* inner_ipv4.dscp[6;0] */

#define PIF_HEADER_GET_inner_ipv4___ecn(_hdr_p) (((_hdr_p)->ecn)) /* inner_ipv4.ecn [2;0] */

#define PIF_HEADER_SET_inner_ipv4___ecn(_hdr_p, _val) \
    do { \
        (_hdr_p)->ecn = (unsigned)(((_val))); \
    } while (0) /* inner_ipv4.ecn[2;0] */

#define PIF_HEADER_GET_inner_ipv4___len(_hdr_p) (((_hdr_p)->len)) /* inner_ipv4.len [16;0] */

#define PIF_HEADER_SET_inner_ipv4___len(_hdr_p, _val) \
    do { \
        (_hdr_p)->len = (unsigned)(((_val))); \
    } while (0) /* inner_ipv4.len[16;0] */

#define PIF_HEADER_GET_inner_ipv4___identification(_hdr_p) (((_hdr_p)->identification)) /* inner_ipv4.identification [16;0] */

#define PIF_HEADER_SET_inner_ipv4___identification(_hdr_p, _val) \
    do { \
        (_hdr_p)->identification = (unsigned)(((_val))); \
    } while (0) /* inner_ipv4.identification[16;0] */

#define PIF_HEADER_GET_inner_ipv4___flags(_hdr_p) (((_hdr_p)->flags)) /* inner_ipv4.flags [3;0] */

#define PIF_HEADER_SET_inner_ipv4___flags(_hdr_p, _val) \
    do { \
        (_hdr_p)->flags = (unsigned)(((_val))); \
    } while (0) /* inner_ipv4.flags[3;0] */

#define PIF_HEADER_GET_inner_ipv4___frag_offset(_hdr_p) (((_hdr_p)->frag_offset)) /* inner_ipv4.frag_offset [13;0] */

#define PIF_HEADER_SET_inner_ipv4___frag_offset(_hdr_p, _val) \
    do { \
        (_hdr_p)->frag_offset = (unsigned)(((_val))); \
    } while (0) /* inner_ipv4.frag_offset[13;0] */

#define PIF_HEADER_GET_inner_ipv4___ttl(_hdr_p) (((_hdr_p)->ttl)) /* inner_ipv4.ttl [8;0] */

#define PIF_HEADER_SET_inner_ipv4___ttl(_hdr_p, _val) \
    do { \
        (_hdr_p)->ttl = (unsigned)(((_val))); \
    } while (0) /* inner_ipv4.ttl[8;0] */

#define PIF_HEADER_GET_inner_ipv4___protocol(_hdr_p) (((_hdr_p)->protocol)) /* inner_ipv4.protocol [8;0] */

#define PIF_HEADER_SET_inner_ipv4___protocol(_hdr_p, _val) \
    do { \
        (_hdr_p)->protocol = (unsigned)(((_val))); \
    } while (0) /* inner_ipv4.protocol[8;0] */

#define PIF_HEADER_GET_inner_ipv4___hdr_checksum(_hdr_p) (((_hdr_p)->hdr_checksum)) /* inner_ipv4.hdr_checksum [16;0] */

#define PIF_HEADER_SET_inner_ipv4___hdr_checksum(_hdr_p, _val) \
    do { \
        (_hdr_p)->hdr_checksum = (unsigned)(((_val))); \
    } while (0) /* inner_ipv4.hdr_checksum[16;0] */

#define PIF_HEADER_GET_inner_ipv4___src_addr(_hdr_p) (((_hdr_p)->src_addr)) /* inner_ipv4.src_addr [32;0] */

#define PIF_HEADER_SET_inner_ipv4___src_addr(_hdr_p, _val) \
    do { \
        (_hdr_p)->src_addr = (unsigned)(((_val))); \
    } while (0) /* inner_ipv4.src_addr[32;0] */

#define PIF_HEADER_GET_inner_ipv4___dst_addr(_hdr_p) (((_hdr_p)->dst_addr)) /* inner_ipv4.dst_addr [32;0] */

#define PIF_HEADER_SET_inner_ipv4___dst_addr(_hdr_p, _val) \
    do { \
        (_hdr_p)->dst_addr = (unsigned)(((_val))); \
    } while (0) /* inner_ipv4.dst_addr[32;0] */


/* ethernet (14B) */
struct pif_header_ethernet {
    /* dst_addr [32;16] */
    unsigned int dst_addr:32;
    /* dst_addr [16;0] */
    unsigned int __dst_addr_1:16;
    /* src_addr [16;32] */
    unsigned int src_addr:16;
    /* src_addr [32;0] */
    unsigned int __src_addr_1:32;
    unsigned int ether_type:16;
};

/* ethernet field accessor macros */
#define PIF_HEADER_GET_ethernet___dst_addr___0(_hdr_p) ((((_hdr_p)->dst_addr & 0xffff) << 16) | ((_hdr_p)->__dst_addr_1)) /* ethernet.dst_addr [32;0] */

#define PIF_HEADER_SET_ethernet___dst_addr___0(_hdr_p, _val) \
    do { \
        (_hdr_p)->dst_addr &= (unsigned)(0xffff0000); \
        (_hdr_p)->dst_addr |= (unsigned)((((_val) >> 16) & 0xffff)); \
        (_hdr_p)->__dst_addr_1 = (unsigned)(((_val))); \
    } while (0) /* ethernet.dst_addr[32;0] */

#define PIF_HEADER_GET_ethernet___dst_addr___1(_hdr_p) ((((_hdr_p)->dst_addr >> 16) & 0xffff)) /* ethernet.dst_addr [16;32] */

#define PIF_HEADER_SET_ethernet___dst_addr___1(_hdr_p, _val) \
    do { \
        (_hdr_p)->dst_addr &= (unsigned)(0xffff); \
        (_hdr_p)->dst_addr |= (unsigned)((((_val) & 0xffff) << 16)); \
    } while (0) /* ethernet.dst_addr[16;32] */

#define PIF_HEADER_GET_ethernet___src_addr___0(_hdr_p) (((_hdr_p)->__src_addr_1)) /* ethernet.src_addr [32;0] */

#define PIF_HEADER_SET_ethernet___src_addr___0(_hdr_p, _val) \
    do { \
        (_hdr_p)->__src_addr_1 = (unsigned)(((_val))); \
    } while (0) /* ethernet.src_addr[32;0] */

#define PIF_HEADER_GET_ethernet___src_addr___1(_hdr_p) (((_hdr_p)->src_addr)) /* ethernet.src_addr [16;32] */

#define PIF_HEADER_SET_ethernet___src_addr___1(_hdr_p, _val) \
    do { \
        (_hdr_p)->src_addr = (unsigned)(((_val))); \
    } while (0) /* ethernet.src_addr[16;32] */

#define PIF_HEADER_GET_ethernet___ether_type(_hdr_p) (((_hdr_p)->ether_type)) /* ethernet.ether_type [16;0] */

#define PIF_HEADER_SET_ethernet___ether_type(_hdr_p, _val) \
    do { \
        (_hdr_p)->ether_type = (unsigned)(((_val))); \
    } while (0) /* ethernet.ether_type[16;0] */


/* gtpu_option (4B) */
struct pif_header_gtpu_option {
    unsigned int seq_num:16;
    unsigned int n_pdu_num:8;
    unsigned int type:8;
};

/* gtpu_option field accessor macros */
#define PIF_HEADER_GET_gtpu_option___seq_num(_hdr_p) (((_hdr_p)->seq_num)) /* gtpu_option.seq_num [16;0] */

#define PIF_HEADER_SET_gtpu_option___seq_num(_hdr_p, _val) \
    do { \
        (_hdr_p)->seq_num = (unsigned)(((_val))); \
    } while (0) /* gtpu_option.seq_num[16;0] */

#define PIF_HEADER_GET_gtpu_option___n_pdu_num(_hdr_p) (((_hdr_p)->n_pdu_num)) /* gtpu_option.n_pdu_num [8;0] */

#define PIF_HEADER_SET_gtpu_option___n_pdu_num(_hdr_p, _val) \
    do { \
        (_hdr_p)->n_pdu_num = (unsigned)(((_val))); \
    } while (0) /* gtpu_option.n_pdu_num[8;0] */

#define PIF_HEADER_GET_gtpu_option___type(_hdr_p) (((_hdr_p)->type)) /* gtpu_option.type [8;0] */

#define PIF_HEADER_SET_gtpu_option___type(_hdr_p, _val) \
    do { \
        (_hdr_p)->type = (unsigned)(((_val))); \
    } while (0) /* gtpu_option.type[8;0] */


/* inner_udp (8B) */
struct pif_header_inner_udp {
    unsigned int src_port:16;
    unsigned int dst_port:16;
    unsigned int len:16;
    unsigned int checksum:16;
};

/* inner_udp field accessor macros */
#define PIF_HEADER_GET_inner_udp___src_port(_hdr_p) (((_hdr_p)->src_port)) /* inner_udp.src_port [16;0] */

#define PIF_HEADER_SET_inner_udp___src_port(_hdr_p, _val) \
    do { \
        (_hdr_p)->src_port = (unsigned)(((_val))); \
    } while (0) /* inner_udp.src_port[16;0] */

#define PIF_HEADER_GET_inner_udp___dst_port(_hdr_p) (((_hdr_p)->dst_port)) /* inner_udp.dst_port [16;0] */

#define PIF_HEADER_SET_inner_udp___dst_port(_hdr_p, _val) \
    do { \
        (_hdr_p)->dst_port = (unsigned)(((_val))); \
    } while (0) /* inner_udp.dst_port[16;0] */

#define PIF_HEADER_GET_inner_udp___len(_hdr_p) (((_hdr_p)->len)) /* inner_udp.len [16;0] */

#define PIF_HEADER_SET_inner_udp___len(_hdr_p, _val) \
    do { \
        (_hdr_p)->len = (unsigned)(((_val))); \
    } while (0) /* inner_udp.len[16;0] */

#define PIF_HEADER_GET_inner_udp___checksum(_hdr_p) (((_hdr_p)->checksum)) /* inner_udp.checksum [16;0] */

#define PIF_HEADER_SET_inner_udp___checksum(_hdr_p, _val) \
    do { \
        (_hdr_p)->checksum = (unsigned)(((_val))); \
    } while (0) /* inner_udp.checksum[16;0] */


/*
 * Metadata
 */

/* bg_md (10B) */
struct pif_header_bg_md {
    unsigned int far_id:32;
    unsigned int qer_id:32;
    unsigned int encap_flag:1;
    unsigned int intf:4;
    unsigned int bypass_modify_mac:1;
    unsigned int _pad:4;
    unsigned int qfi:6;
};

/* bg_md field accessor macros */
#define PIF_HEADER_GET_bg_md___far_id(_hdr_p) (((_hdr_p)->far_id)) /* bg_md.far_id [32;0] */

#define PIF_HEADER_SET_bg_md___far_id(_hdr_p, _val) \
    do { \
        (_hdr_p)->far_id = (unsigned)(((_val))); \
    } while (0) /* bg_md.far_id[32;0] */

#define PIF_HEADER_GET_bg_md___qer_id(_hdr_p) (((_hdr_p)->qer_id)) /* bg_md.qer_id [32;0] */

#define PIF_HEADER_SET_bg_md___qer_id(_hdr_p, _val) \
    do { \
        (_hdr_p)->qer_id = (unsigned)(((_val))); \
    } while (0) /* bg_md.qer_id[32;0] */

#define PIF_HEADER_GET_bg_md___encap_flag(_hdr_p) (((_hdr_p)->encap_flag)) /* bg_md.encap_flag [1;0] */

#define PIF_HEADER_SET_bg_md___encap_flag(_hdr_p, _val) \
    do { \
        (_hdr_p)->encap_flag = (unsigned)(((_val))); \
    } while (0) /* bg_md.encap_flag[1;0] */

#define PIF_HEADER_GET_bg_md___intf(_hdr_p) (((_hdr_p)->intf)) /* bg_md.intf [4;0] */

#define PIF_HEADER_SET_bg_md___intf(_hdr_p, _val) \
    do { \
        (_hdr_p)->intf = (unsigned)(((_val))); \
    } while (0) /* bg_md.intf[4;0] */

#define PIF_HEADER_GET_bg_md___bypass_modify_mac(_hdr_p) (((_hdr_p)->bypass_modify_mac)) /* bg_md.bypass_modify_mac [1;0] */

#define PIF_HEADER_SET_bg_md___bypass_modify_mac(_hdr_p, _val) \
    do { \
        (_hdr_p)->bypass_modify_mac = (unsigned)(((_val))); \
    } while (0) /* bg_md.bypass_modify_mac[1;0] */

#define PIF_HEADER_GET_bg_md____pad(_hdr_p) (((_hdr_p)->_pad)) /* bg_md._pad [4;0] */

#define PIF_HEADER_SET_bg_md____pad(_hdr_p, _val) \
    do { \
        (_hdr_p)->_pad = (unsigned)(((_val))); \
    } while (0) /* bg_md._pad[4;0] */

#define PIF_HEADER_GET_bg_md___qfi(_hdr_p) (((_hdr_p)->qfi)) /* bg_md.qfi [6;0] */

#define PIF_HEADER_SET_bg_md___qfi(_hdr_p, _val) \
    do { \
        (_hdr_p)->qfi = (unsigned)(((_val))); \
    } while (0) /* bg_md.qfi[6;0] */


/* standard_metadata (16B) */
struct pif_header_standard_metadata {
    unsigned int clone_spec:32;
    unsigned int egress_spec:16;
    unsigned int egress_port:16;
    unsigned int ingress_port:16;
    unsigned int packet_length:14;
    unsigned int checksum_error:1;
    unsigned int _padding_0:1;
    unsigned int egress_instance:10;
    unsigned int parser_error_location:8;
    unsigned int instance_type:4;
    unsigned int parser_status:3;
    unsigned int _padding_1:7;
};

/* standard_metadata field accessor macros */
#define PIF_HEADER_GET_standard_metadata___clone_spec(_hdr_p) (((_hdr_p)->clone_spec)) /* standard_metadata.clone_spec [32;0] */

#define PIF_HEADER_SET_standard_metadata___clone_spec(_hdr_p, _val) \
    do { \
        (_hdr_p)->clone_spec = (unsigned)(((_val))); \
    } while (0) /* standard_metadata.clone_spec[32;0] */

#define PIF_HEADER_GET_standard_metadata___egress_spec(_hdr_p) (((_hdr_p)->egress_spec)) /* standard_metadata.egress_spec [16;0] */

#define PIF_HEADER_SET_standard_metadata___egress_spec(_hdr_p, _val) \
    do { \
        (_hdr_p)->egress_spec = (unsigned)(((_val))); \
    } while (0) /* standard_metadata.egress_spec[16;0] */

#define PIF_HEADER_GET_standard_metadata___egress_port(_hdr_p) (((_hdr_p)->egress_port)) /* standard_metadata.egress_port [16;0] */

#define PIF_HEADER_SET_standard_metadata___egress_port(_hdr_p, _val) \
    do { \
        (_hdr_p)->egress_port = (unsigned)(((_val))); \
    } while (0) /* standard_metadata.egress_port[16;0] */

#define PIF_HEADER_GET_standard_metadata___ingress_port(_hdr_p) (((_hdr_p)->ingress_port)) /* standard_metadata.ingress_port [16;0] */

#define PIF_HEADER_SET_standard_metadata___ingress_port(_hdr_p, _val) \
    do { \
        (_hdr_p)->ingress_port = (unsigned)(((_val))); \
    } while (0) /* standard_metadata.ingress_port[16;0] */

#define PIF_HEADER_GET_standard_metadata___packet_length(_hdr_p) (((_hdr_p)->packet_length)) /* standard_metadata.packet_length [14;0] */

#define PIF_HEADER_SET_standard_metadata___packet_length(_hdr_p, _val) \
    do { \
        (_hdr_p)->packet_length = (unsigned)(((_val))); \
    } while (0) /* standard_metadata.packet_length[14;0] */

#define PIF_HEADER_GET_standard_metadata___checksum_error(_hdr_p) (((_hdr_p)->checksum_error)) /* standard_metadata.checksum_error [1;0] */

#define PIF_HEADER_SET_standard_metadata___checksum_error(_hdr_p, _val) \
    do { \
        (_hdr_p)->checksum_error = (unsigned)(((_val))); \
    } while (0) /* standard_metadata.checksum_error[1;0] */

#define PIF_HEADER_GET_standard_metadata____padding_0(_hdr_p) (((_hdr_p)->_padding_0)) /* standard_metadata._padding_0 [1;0] */

#define PIF_HEADER_SET_standard_metadata____padding_0(_hdr_p, _val) \
    do { \
        (_hdr_p)->_padding_0 = (unsigned)(((_val))); \
    } while (0) /* standard_metadata._padding_0[1;0] */

#define PIF_HEADER_GET_standard_metadata___egress_instance(_hdr_p) (((_hdr_p)->egress_instance)) /* standard_metadata.egress_instance [10;0] */

#define PIF_HEADER_SET_standard_metadata___egress_instance(_hdr_p, _val) \
    do { \
        (_hdr_p)->egress_instance = (unsigned)(((_val))); \
    } while (0) /* standard_metadata.egress_instance[10;0] */

#define PIF_HEADER_GET_standard_metadata___parser_error_location(_hdr_p) (((_hdr_p)->parser_error_location)) /* standard_metadata.parser_error_location [8;0] */

#define PIF_HEADER_SET_standard_metadata___parser_error_location(_hdr_p, _val) \
    do { \
        (_hdr_p)->parser_error_location = (unsigned)(((_val))); \
    } while (0) /* standard_metadata.parser_error_location[8;0] */

#define PIF_HEADER_GET_standard_metadata___instance_type(_hdr_p) (((_hdr_p)->instance_type)) /* standard_metadata.instance_type [4;0] */

#define PIF_HEADER_SET_standard_metadata___instance_type(_hdr_p, _val) \
    do { \
        (_hdr_p)->instance_type = (unsigned)(((_val))); \
    } while (0) /* standard_metadata.instance_type[4;0] */

#define PIF_HEADER_GET_standard_metadata___parser_status(_hdr_p) (((_hdr_p)->parser_status)) /* standard_metadata.parser_status [3;0] */

#define PIF_HEADER_SET_standard_metadata___parser_status(_hdr_p, _val) \
    do { \
        (_hdr_p)->parser_status = (unsigned)(((_val))); \
    } while (0) /* standard_metadata.parser_status[3;0] */

#define PIF_HEADER_GET_standard_metadata____padding_1(_hdr_p) (((_hdr_p)->_padding_1)) /* standard_metadata._padding_1 [7;0] */

#define PIF_HEADER_SET_standard_metadata____padding_1(_hdr_p, _val) \
    do { \
        (_hdr_p)->_padding_1 = (unsigned)(((_val))); \
    } while (0) /* standard_metadata._padding_1[7;0] */


/* scalars (16B) */
struct pif_header_scalars {
    unsigned int metadata_t__far_id:32;
    unsigned int metadata_t__l4_inner_src_port:16;
    unsigned int metadata_t__l4_inner_dst_port:16;
    unsigned int metadata_t__l4_src_port:16;
    unsigned int metadata_t__l4_dst_port:16;
    unsigned int metadata_t__qfi:6;
    unsigned int metadata_t__intf:4;
    unsigned int metadata_t__bypass_modify_mac:1;
    unsigned int metadata_t__decap_flag:1;
    unsigned int metadata_t__encap_flag:1;
    unsigned int _padding_0:19;
};

/* scalars field accessor macros */
#define PIF_HEADER_GET_scalars___metadata_t__far_id(_hdr_p) (((_hdr_p)->metadata_t__far_id)) /* scalars.metadata_t__far_id [32;0] */

#define PIF_HEADER_SET_scalars___metadata_t__far_id(_hdr_p, _val) \
    do { \
        (_hdr_p)->metadata_t__far_id = (unsigned)(((_val))); \
    } while (0) /* scalars.metadata_t__far_id[32;0] */

#define PIF_HEADER_GET_scalars___metadata_t__l4_inner_src_port(_hdr_p) (((_hdr_p)->metadata_t__l4_inner_src_port)) /* scalars.metadata_t__l4_inner_src_port [16;0] */

#define PIF_HEADER_SET_scalars___metadata_t__l4_inner_src_port(_hdr_p, _val) \
    do { \
        (_hdr_p)->metadata_t__l4_inner_src_port = (unsigned)(((_val))); \
    } while (0) /* scalars.metadata_t__l4_inner_src_port[16;0] */

#define PIF_HEADER_GET_scalars___metadata_t__l4_inner_dst_port(_hdr_p) (((_hdr_p)->metadata_t__l4_inner_dst_port)) /* scalars.metadata_t__l4_inner_dst_port [16;0] */

#define PIF_HEADER_SET_scalars___metadata_t__l4_inner_dst_port(_hdr_p, _val) \
    do { \
        (_hdr_p)->metadata_t__l4_inner_dst_port = (unsigned)(((_val))); \
    } while (0) /* scalars.metadata_t__l4_inner_dst_port[16;0] */

#define PIF_HEADER_GET_scalars___metadata_t__l4_src_port(_hdr_p) (((_hdr_p)->metadata_t__l4_src_port)) /* scalars.metadata_t__l4_src_port [16;0] */

#define PIF_HEADER_SET_scalars___metadata_t__l4_src_port(_hdr_p, _val) \
    do { \
        (_hdr_p)->metadata_t__l4_src_port = (unsigned)(((_val))); \
    } while (0) /* scalars.metadata_t__l4_src_port[16;0] */

#define PIF_HEADER_GET_scalars___metadata_t__l4_dst_port(_hdr_p) (((_hdr_p)->metadata_t__l4_dst_port)) /* scalars.metadata_t__l4_dst_port [16;0] */

#define PIF_HEADER_SET_scalars___metadata_t__l4_dst_port(_hdr_p, _val) \
    do { \
        (_hdr_p)->metadata_t__l4_dst_port = (unsigned)(((_val))); \
    } while (0) /* scalars.metadata_t__l4_dst_port[16;0] */

#define PIF_HEADER_GET_scalars___metadata_t__qfi(_hdr_p) (((_hdr_p)->metadata_t__qfi)) /* scalars.metadata_t__qfi [6;0] */

#define PIF_HEADER_SET_scalars___metadata_t__qfi(_hdr_p, _val) \
    do { \
        (_hdr_p)->metadata_t__qfi = (unsigned)(((_val))); \
    } while (0) /* scalars.metadata_t__qfi[6;0] */

#define PIF_HEADER_GET_scalars___metadata_t__intf(_hdr_p) (((_hdr_p)->metadata_t__intf)) /* scalars.metadata_t__intf [4;0] */

#define PIF_HEADER_SET_scalars___metadata_t__intf(_hdr_p, _val) \
    do { \
        (_hdr_p)->metadata_t__intf = (unsigned)(((_val))); \
    } while (0) /* scalars.metadata_t__intf[4;0] */

#define PIF_HEADER_GET_scalars___metadata_t__bypass_modify_mac(_hdr_p) (((_hdr_p)->metadata_t__bypass_modify_mac)) /* scalars.metadata_t__bypass_modify_mac [1;0] */

#define PIF_HEADER_SET_scalars___metadata_t__bypass_modify_mac(_hdr_p, _val) \
    do { \
        (_hdr_p)->metadata_t__bypass_modify_mac = (unsigned)(((_val))); \
    } while (0) /* scalars.metadata_t__bypass_modify_mac[1;0] */

#define PIF_HEADER_GET_scalars___metadata_t__decap_flag(_hdr_p) (((_hdr_p)->metadata_t__decap_flag)) /* scalars.metadata_t__decap_flag [1;0] */

#define PIF_HEADER_SET_scalars___metadata_t__decap_flag(_hdr_p, _val) \
    do { \
        (_hdr_p)->metadata_t__decap_flag = (unsigned)(((_val))); \
    } while (0) /* scalars.metadata_t__decap_flag[1;0] */

#define PIF_HEADER_GET_scalars___metadata_t__encap_flag(_hdr_p) (((_hdr_p)->metadata_t__encap_flag)) /* scalars.metadata_t__encap_flag [1;0] */

#define PIF_HEADER_SET_scalars___metadata_t__encap_flag(_hdr_p, _val) \
    do { \
        (_hdr_p)->metadata_t__encap_flag = (unsigned)(((_val))); \
    } while (0) /* scalars.metadata_t__encap_flag[1;0] */

#define PIF_HEADER_GET_scalars____padding_0(_hdr_p) (((_hdr_p)->_padding_0)) /* scalars._padding_0 [19;0] */

#define PIF_HEADER_SET_scalars____padding_0(_hdr_p, _val) \
    do { \
        (_hdr_p)->_padding_0 = (unsigned)(((_val))); \
    } while (0) /* scalars._padding_0[19;0] */



/*
 * Registers
 */

#endif /* __PIF_HEADERS_H__ */
