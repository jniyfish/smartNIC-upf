/* Copyright (C) 2015-2016,  Netronome Systems, Inc.  All rights reserved. */

#ifndef __PIF_PLUGIN_GTPU_H__
#define __PIF_PLUGIN_GTPU_H__

/* This file is generated, edit at your peril */

/*
 * Header type definition
 */

/* gtpu (8B) */
struct pif_plugin_gtpu {
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



#define PIF_PLUGIN_gtpu_T __lmem struct pif_plugin_gtpu

/*
 * Access function prototypes
 */

int pif_plugin_hdr_gtpu_present(EXTRACTED_HEADERS_T *extracted_headers);

PIF_PLUGIN_gtpu_T *pif_plugin_hdr_get_gtpu(EXTRACTED_HEADERS_T *extracted_headers);

PIF_PLUGIN_gtpu_T *pif_plugin_hdr_readonly_get_gtpu(EXTRACTED_HEADERS_T *extracted_headers);

int pif_plugin_hdr_gtpu_add(EXTRACTED_HEADERS_T *extracted_headers);

int pif_plugin_hdr_gtpu_remove(EXTRACTED_HEADERS_T *extracted_headers);






/*
 * Access function implementations
 */

#include "pif_parrep.h"

__forceinline int pif_plugin_hdr_gtpu_present(EXTRACTED_HEADERS_T *extracted_headers)
{
    __lmem struct pif_parrep_ctldata *_ctl = (__lmem struct pif_parrep_ctldata *)extracted_headers;
    return PIF_PARREP_gtpu_VALID(_ctl);
}

__forceinline PIF_PLUGIN_gtpu_T *pif_plugin_hdr_get_gtpu(EXTRACTED_HEADERS_T *extracted_headers)
{
    __lmem struct pif_parrep_ctldata *_ctl = (__lmem struct pif_parrep_ctldata *)extracted_headers;
    PIF_PARREP_SET_gtpu_DIRTY(_ctl);
    return (PIF_PLUGIN_gtpu_T *)(((__lmem uint32_t *)extracted_headers) + PIF_PARREP_gtpu_OFF_LW);
}

__forceinline PIF_PLUGIN_gtpu_T *pif_plugin_hdr_readonly_get_gtpu(EXTRACTED_HEADERS_T *extracted_headers)
{
    __lmem struct pif_parrep_ctldata *_ctl = (__lmem struct pif_parrep_ctldata *)extracted_headers;
    return (PIF_PLUGIN_gtpu_T *)(((__lmem uint32_t *)extracted_headers) + PIF_PARREP_gtpu_OFF_LW);
}

__forceinline int pif_plugin_hdr_gtpu_add(EXTRACTED_HEADERS_T *extracted_headers)
{
    __lmem struct pif_parrep_ctldata *_ctl = (__lmem struct pif_parrep_ctldata *)extracted_headers;
    if (PIF_PARREP_T3_VALID(_ctl))
        return -1; /* either already present or incompatible header combination */
    PIF_PARREP_SET_gtpu_VALID(_ctl);
    return 0;
}

__forceinline int pif_plugin_hdr_gtpu_remove(EXTRACTED_HEADERS_T *extracted_headers)
{
    __lmem struct pif_parrep_ctldata *_ctl = (__lmem struct pif_parrep_ctldata *)extracted_headers;
    if (!PIF_PARREP_gtpu_VALID(_ctl))
        return -1; /* header is not present */
    PIF_PARREP_CLEAR_gtpu_VALID(_ctl);
    return 0;
}

#endif /* __PIF_PLUGIN_GTPU_H__ */
