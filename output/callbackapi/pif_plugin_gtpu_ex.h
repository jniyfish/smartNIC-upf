/* Copyright (C) 2015-2016,  Netronome Systems, Inc.  All rights reserved. */

#ifndef __PIF_PLUGIN_GTPU_EX_H__
#define __PIF_PLUGIN_GTPU_EX_H__

/* This file is generated, edit at your peril */

/*
 * Header type definition
 */

/* gtpu_ex (4B) */
struct pif_plugin_gtpu_ex {
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



#define PIF_PLUGIN_gtpu_ex_T __lmem struct pif_plugin_gtpu_ex

/*
 * Access function prototypes
 */

int pif_plugin_hdr_gtpu_ex_present(EXTRACTED_HEADERS_T *extracted_headers);

PIF_PLUGIN_gtpu_ex_T *pif_plugin_hdr_get_gtpu_ex(EXTRACTED_HEADERS_T *extracted_headers);

PIF_PLUGIN_gtpu_ex_T *pif_plugin_hdr_readonly_get_gtpu_ex(EXTRACTED_HEADERS_T *extracted_headers);

int pif_plugin_hdr_gtpu_ex_add(EXTRACTED_HEADERS_T *extracted_headers);

int pif_plugin_hdr_gtpu_ex_remove(EXTRACTED_HEADERS_T *extracted_headers);






/*
 * Access function implementations
 */

#include "pif_parrep.h"

__forceinline int pif_plugin_hdr_gtpu_ex_present(EXTRACTED_HEADERS_T *extracted_headers)
{
    __lmem struct pif_parrep_ctldata *_ctl = (__lmem struct pif_parrep_ctldata *)extracted_headers;
    return PIF_PARREP_gtpu_ex_VALID(_ctl);
}

__forceinline PIF_PLUGIN_gtpu_ex_T *pif_plugin_hdr_get_gtpu_ex(EXTRACTED_HEADERS_T *extracted_headers)
{
    __lmem struct pif_parrep_ctldata *_ctl = (__lmem struct pif_parrep_ctldata *)extracted_headers;
    PIF_PARREP_SET_gtpu_ex_DIRTY(_ctl);
    return (PIF_PLUGIN_gtpu_ex_T *)(((__lmem uint32_t *)extracted_headers) + PIF_PARREP_gtpu_ex_OFF_LW);
}

__forceinline PIF_PLUGIN_gtpu_ex_T *pif_plugin_hdr_readonly_get_gtpu_ex(EXTRACTED_HEADERS_T *extracted_headers)
{
    __lmem struct pif_parrep_ctldata *_ctl = (__lmem struct pif_parrep_ctldata *)extracted_headers;
    return (PIF_PLUGIN_gtpu_ex_T *)(((__lmem uint32_t *)extracted_headers) + PIF_PARREP_gtpu_ex_OFF_LW);
}

__forceinline int pif_plugin_hdr_gtpu_ex_add(EXTRACTED_HEADERS_T *extracted_headers)
{
    __lmem struct pif_parrep_ctldata *_ctl = (__lmem struct pif_parrep_ctldata *)extracted_headers;
    if (PIF_PARREP_T5_VALID(_ctl))
        return -1; /* either already present or incompatible header combination */
    PIF_PARREP_SET_gtpu_ex_VALID(_ctl);
    return 0;
}

__forceinline int pif_plugin_hdr_gtpu_ex_remove(EXTRACTED_HEADERS_T *extracted_headers)
{
    __lmem struct pif_parrep_ctldata *_ctl = (__lmem struct pif_parrep_ctldata *)extracted_headers;
    if (!PIF_PARREP_gtpu_ex_VALID(_ctl))
        return -1; /* header is not present */
    PIF_PARREP_CLEAR_gtpu_ex_VALID(_ctl);
    return 0;
}

#endif /* __PIF_PLUGIN_GTPU_EX_H__ */
