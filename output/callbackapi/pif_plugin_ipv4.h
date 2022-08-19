/* Copyright (C) 2015-2016,  Netronome Systems, Inc.  All rights reserved. */

#ifndef __PIF_PLUGIN_IPV4_H__
#define __PIF_PLUGIN_IPV4_H__

/* This file is generated, edit at your peril */

/*
 * Header type definition
 */

/* ipv4 (20B) */
struct pif_plugin_ipv4 {
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



#define PIF_PLUGIN_ipv4_T __lmem struct pif_plugin_ipv4

/*
 * Access function prototypes
 */

int pif_plugin_hdr_ipv4_present(EXTRACTED_HEADERS_T *extracted_headers);

PIF_PLUGIN_ipv4_T *pif_plugin_hdr_get_ipv4(EXTRACTED_HEADERS_T *extracted_headers);

PIF_PLUGIN_ipv4_T *pif_plugin_hdr_readonly_get_ipv4(EXTRACTED_HEADERS_T *extracted_headers);

int pif_plugin_hdr_ipv4_add(EXTRACTED_HEADERS_T *extracted_headers);

int pif_plugin_hdr_ipv4_remove(EXTRACTED_HEADERS_T *extracted_headers);






/*
 * Access function implementations
 */

#include "pif_parrep.h"

__forceinline int pif_plugin_hdr_ipv4_present(EXTRACTED_HEADERS_T *extracted_headers)
{
    __lmem struct pif_parrep_ctldata *_ctl = (__lmem struct pif_parrep_ctldata *)extracted_headers;
    return PIF_PARREP_ipv4_VALID(_ctl);
}

__forceinline PIF_PLUGIN_ipv4_T *pif_plugin_hdr_get_ipv4(EXTRACTED_HEADERS_T *extracted_headers)
{
    __lmem struct pif_parrep_ctldata *_ctl = (__lmem struct pif_parrep_ctldata *)extracted_headers;
    PIF_PARREP_SET_ipv4_DIRTY(_ctl);
    return (PIF_PLUGIN_ipv4_T *)(((__lmem uint32_t *)extracted_headers) + PIF_PARREP_ipv4_OFF_LW);
}

__forceinline PIF_PLUGIN_ipv4_T *pif_plugin_hdr_readonly_get_ipv4(EXTRACTED_HEADERS_T *extracted_headers)
{
    __lmem struct pif_parrep_ctldata *_ctl = (__lmem struct pif_parrep_ctldata *)extracted_headers;
    return (PIF_PLUGIN_ipv4_T *)(((__lmem uint32_t *)extracted_headers) + PIF_PARREP_ipv4_OFF_LW);
}

__forceinline int pif_plugin_hdr_ipv4_add(EXTRACTED_HEADERS_T *extracted_headers)
{
    __lmem struct pif_parrep_ctldata *_ctl = (__lmem struct pif_parrep_ctldata *)extracted_headers;
    if (PIF_PARREP_T1_VALID(_ctl))
        return -1; /* either already present or incompatible header combination */
    PIF_PARREP_SET_ipv4_VALID(_ctl);
    return 0;
}

__forceinline int pif_plugin_hdr_ipv4_remove(EXTRACTED_HEADERS_T *extracted_headers)
{
    __lmem struct pif_parrep_ctldata *_ctl = (__lmem struct pif_parrep_ctldata *)extracted_headers;
    if (!PIF_PARREP_ipv4_VALID(_ctl))
        return -1; /* header is not present */
    PIF_PARREP_CLEAR_ipv4_VALID(_ctl);
    return 0;
}

#endif /* __PIF_PLUGIN_IPV4_H__ */
