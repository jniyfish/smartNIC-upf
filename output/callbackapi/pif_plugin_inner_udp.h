/* Copyright (C) 2015-2016,  Netronome Systems, Inc.  All rights reserved. */

#ifndef __PIF_PLUGIN_INNER_UDP_H__
#define __PIF_PLUGIN_INNER_UDP_H__

/* This file is generated, edit at your peril */

/*
 * Header type definition
 */

/* inner_udp (8B) */
struct pif_plugin_inner_udp {
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



#define PIF_PLUGIN_inner_udp_T __lmem struct pif_plugin_inner_udp

/*
 * Access function prototypes
 */

int pif_plugin_hdr_inner_udp_present(EXTRACTED_HEADERS_T *extracted_headers);

PIF_PLUGIN_inner_udp_T *pif_plugin_hdr_get_inner_udp(EXTRACTED_HEADERS_T *extracted_headers);

PIF_PLUGIN_inner_udp_T *pif_plugin_hdr_readonly_get_inner_udp(EXTRACTED_HEADERS_T *extracted_headers);

int pif_plugin_hdr_inner_udp_add(EXTRACTED_HEADERS_T *extracted_headers);

int pif_plugin_hdr_inner_udp_remove(EXTRACTED_HEADERS_T *extracted_headers);






/*
 * Access function implementations
 */

#include "pif_parrep.h"

__forceinline int pif_plugin_hdr_inner_udp_present(EXTRACTED_HEADERS_T *extracted_headers)
{
    __lmem struct pif_parrep_ctldata *_ctl = (__lmem struct pif_parrep_ctldata *)extracted_headers;
    return PIF_PARREP_inner_udp_VALID(_ctl);
}

__forceinline PIF_PLUGIN_inner_udp_T *pif_plugin_hdr_get_inner_udp(EXTRACTED_HEADERS_T *extracted_headers)
{
    __lmem struct pif_parrep_ctldata *_ctl = (__lmem struct pif_parrep_ctldata *)extracted_headers;
    PIF_PARREP_SET_inner_udp_DIRTY(_ctl);
    return (PIF_PLUGIN_inner_udp_T *)(((__lmem uint32_t *)extracted_headers) + PIF_PARREP_inner_udp_OFF_LW);
}

__forceinline PIF_PLUGIN_inner_udp_T *pif_plugin_hdr_readonly_get_inner_udp(EXTRACTED_HEADERS_T *extracted_headers)
{
    __lmem struct pif_parrep_ctldata *_ctl = (__lmem struct pif_parrep_ctldata *)extracted_headers;
    return (PIF_PLUGIN_inner_udp_T *)(((__lmem uint32_t *)extracted_headers) + PIF_PARREP_inner_udp_OFF_LW);
}

__forceinline int pif_plugin_hdr_inner_udp_add(EXTRACTED_HEADERS_T *extracted_headers)
{
    __lmem struct pif_parrep_ctldata *_ctl = (__lmem struct pif_parrep_ctldata *)extracted_headers;
    if (PIF_PARREP_T7_VALID(_ctl))
        return -1; /* either already present or incompatible header combination */
    PIF_PARREP_SET_inner_udp_VALID(_ctl);
    return 0;
}

__forceinline int pif_plugin_hdr_inner_udp_remove(EXTRACTED_HEADERS_T *extracted_headers)
{
    __lmem struct pif_parrep_ctldata *_ctl = (__lmem struct pif_parrep_ctldata *)extracted_headers;
    if (!PIF_PARREP_inner_udp_VALID(_ctl))
        return -1; /* header is not present */
    PIF_PARREP_CLEAR_inner_udp_VALID(_ctl);
    return 0;
}

#endif /* __PIF_PLUGIN_INNER_UDP_H__ */
