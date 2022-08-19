/* Copyright (C) 2015-2016,  Netronome Systems, Inc.  All rights reserved. */

#ifndef __PIF_PLUGIN_INNER_TCP_H__
#define __PIF_PLUGIN_INNER_TCP_H__

/* This file is generated, edit at your peril */

/*
 * Header type definition
 */

/* inner_tcp (20B) */
struct pif_plugin_inner_tcp {
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



#define PIF_PLUGIN_inner_tcp_T __lmem struct pif_plugin_inner_tcp

/*
 * Access function prototypes
 */

int pif_plugin_hdr_inner_tcp_present(EXTRACTED_HEADERS_T *extracted_headers);

PIF_PLUGIN_inner_tcp_T *pif_plugin_hdr_get_inner_tcp(EXTRACTED_HEADERS_T *extracted_headers);

PIF_PLUGIN_inner_tcp_T *pif_plugin_hdr_readonly_get_inner_tcp(EXTRACTED_HEADERS_T *extracted_headers);

int pif_plugin_hdr_inner_tcp_add(EXTRACTED_HEADERS_T *extracted_headers);

int pif_plugin_hdr_inner_tcp_remove(EXTRACTED_HEADERS_T *extracted_headers);






/*
 * Access function implementations
 */

#include "pif_parrep.h"

__forceinline int pif_plugin_hdr_inner_tcp_present(EXTRACTED_HEADERS_T *extracted_headers)
{
    __lmem struct pif_parrep_ctldata *_ctl = (__lmem struct pif_parrep_ctldata *)extracted_headers;
    return PIF_PARREP_inner_tcp_VALID(_ctl);
}

__forceinline PIF_PLUGIN_inner_tcp_T *pif_plugin_hdr_get_inner_tcp(EXTRACTED_HEADERS_T *extracted_headers)
{
    __lmem struct pif_parrep_ctldata *_ctl = (__lmem struct pif_parrep_ctldata *)extracted_headers;
    PIF_PARREP_SET_inner_tcp_DIRTY(_ctl);
    return (PIF_PLUGIN_inner_tcp_T *)(((__lmem uint32_t *)extracted_headers) + PIF_PARREP_inner_tcp_OFF_LW);
}

__forceinline PIF_PLUGIN_inner_tcp_T *pif_plugin_hdr_readonly_get_inner_tcp(EXTRACTED_HEADERS_T *extracted_headers)
{
    __lmem struct pif_parrep_ctldata *_ctl = (__lmem struct pif_parrep_ctldata *)extracted_headers;
    return (PIF_PLUGIN_inner_tcp_T *)(((__lmem uint32_t *)extracted_headers) + PIF_PARREP_inner_tcp_OFF_LW);
}

__forceinline int pif_plugin_hdr_inner_tcp_add(EXTRACTED_HEADERS_T *extracted_headers)
{
    __lmem struct pif_parrep_ctldata *_ctl = (__lmem struct pif_parrep_ctldata *)extracted_headers;
    if (PIF_PARREP_T7_VALID(_ctl))
        return -1; /* either already present or incompatible header combination */
    PIF_PARREP_SET_inner_tcp_VALID(_ctl);
    return 0;
}

__forceinline int pif_plugin_hdr_inner_tcp_remove(EXTRACTED_HEADERS_T *extracted_headers)
{
    __lmem struct pif_parrep_ctldata *_ctl = (__lmem struct pif_parrep_ctldata *)extracted_headers;
    if (!PIF_PARREP_inner_tcp_VALID(_ctl))
        return -1; /* header is not present */
    PIF_PARREP_CLEAR_inner_tcp_VALID(_ctl);
    return 0;
}

#endif /* __PIF_PLUGIN_INNER_TCP_H__ */
