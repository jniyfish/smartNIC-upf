/* Copyright (C) 2015-2016,  Netronome Systems, Inc.  All rights reserved. */

#ifndef __PIF_PLUGIN_ARP_H__
#define __PIF_PLUGIN_ARP_H__

/* This file is generated, edit at your peril */

/*
 * Header type definition
 */

/* arp (8B) */
struct pif_plugin_arp {
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



#define PIF_PLUGIN_arp_T __lmem struct pif_plugin_arp

/*
 * Access function prototypes
 */

int pif_plugin_hdr_arp_present(EXTRACTED_HEADERS_T *extracted_headers);

PIF_PLUGIN_arp_T *pif_plugin_hdr_get_arp(EXTRACTED_HEADERS_T *extracted_headers);

PIF_PLUGIN_arp_T *pif_plugin_hdr_readonly_get_arp(EXTRACTED_HEADERS_T *extracted_headers);

int pif_plugin_hdr_arp_add(EXTRACTED_HEADERS_T *extracted_headers);

int pif_plugin_hdr_arp_remove(EXTRACTED_HEADERS_T *extracted_headers);






/*
 * Access function implementations
 */

#include "pif_parrep.h"

__forceinline int pif_plugin_hdr_arp_present(EXTRACTED_HEADERS_T *extracted_headers)
{
    __lmem struct pif_parrep_ctldata *_ctl = (__lmem struct pif_parrep_ctldata *)extracted_headers;
    return PIF_PARREP_arp_VALID(_ctl);
}

__forceinline PIF_PLUGIN_arp_T *pif_plugin_hdr_get_arp(EXTRACTED_HEADERS_T *extracted_headers)
{
    __lmem struct pif_parrep_ctldata *_ctl = (__lmem struct pif_parrep_ctldata *)extracted_headers;
    PIF_PARREP_SET_arp_DIRTY(_ctl);
    return (PIF_PLUGIN_arp_T *)(((__lmem uint32_t *)extracted_headers) + PIF_PARREP_arp_OFF_LW);
}

__forceinline PIF_PLUGIN_arp_T *pif_plugin_hdr_readonly_get_arp(EXTRACTED_HEADERS_T *extracted_headers)
{
    __lmem struct pif_parrep_ctldata *_ctl = (__lmem struct pif_parrep_ctldata *)extracted_headers;
    return (PIF_PLUGIN_arp_T *)(((__lmem uint32_t *)extracted_headers) + PIF_PARREP_arp_OFF_LW);
}

__forceinline int pif_plugin_hdr_arp_add(EXTRACTED_HEADERS_T *extracted_headers)
{
    __lmem struct pif_parrep_ctldata *_ctl = (__lmem struct pif_parrep_ctldata *)extracted_headers;
    if (PIF_PARREP_T7_VALID(_ctl))
        return -1; /* either already present or incompatible header combination */
    PIF_PARREP_SET_arp_VALID(_ctl);
    return 0;
}

__forceinline int pif_plugin_hdr_arp_remove(EXTRACTED_HEADERS_T *extracted_headers)
{
    __lmem struct pif_parrep_ctldata *_ctl = (__lmem struct pif_parrep_ctldata *)extracted_headers;
    if (!PIF_PARREP_arp_VALID(_ctl))
        return -1; /* header is not present */
    PIF_PARREP_CLEAR_arp_VALID(_ctl);
    return 0;
}

#endif /* __PIF_PLUGIN_ARP_H__ */
