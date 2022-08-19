/* Copyright (C) 2015-2016,  Netronome Systems, Inc.  All rights reserved. */

#ifndef __PIF_PLUGIN_GTPU_OPTION_H__
#define __PIF_PLUGIN_GTPU_OPTION_H__

/* This file is generated, edit at your peril */

/*
 * Header type definition
 */

/* gtpu_option (4B) */
struct pif_plugin_gtpu_option {
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



#define PIF_PLUGIN_gtpu_option_T __lmem struct pif_plugin_gtpu_option

/*
 * Access function prototypes
 */

int pif_plugin_hdr_gtpu_option_present(EXTRACTED_HEADERS_T *extracted_headers);

PIF_PLUGIN_gtpu_option_T *pif_plugin_hdr_get_gtpu_option(EXTRACTED_HEADERS_T *extracted_headers);

PIF_PLUGIN_gtpu_option_T *pif_plugin_hdr_readonly_get_gtpu_option(EXTRACTED_HEADERS_T *extracted_headers);

int pif_plugin_hdr_gtpu_option_add(EXTRACTED_HEADERS_T *extracted_headers);

int pif_plugin_hdr_gtpu_option_remove(EXTRACTED_HEADERS_T *extracted_headers);






/*
 * Access function implementations
 */

#include "pif_parrep.h"

__forceinline int pif_plugin_hdr_gtpu_option_present(EXTRACTED_HEADERS_T *extracted_headers)
{
    __lmem struct pif_parrep_ctldata *_ctl = (__lmem struct pif_parrep_ctldata *)extracted_headers;
    return PIF_PARREP_gtpu_option_VALID(_ctl);
}

__forceinline PIF_PLUGIN_gtpu_option_T *pif_plugin_hdr_get_gtpu_option(EXTRACTED_HEADERS_T *extracted_headers)
{
    __lmem struct pif_parrep_ctldata *_ctl = (__lmem struct pif_parrep_ctldata *)extracted_headers;
    PIF_PARREP_SET_gtpu_option_DIRTY(_ctl);
    return (PIF_PLUGIN_gtpu_option_T *)(((__lmem uint32_t *)extracted_headers) + PIF_PARREP_gtpu_option_OFF_LW);
}

__forceinline PIF_PLUGIN_gtpu_option_T *pif_plugin_hdr_readonly_get_gtpu_option(EXTRACTED_HEADERS_T *extracted_headers)
{
    __lmem struct pif_parrep_ctldata *_ctl = (__lmem struct pif_parrep_ctldata *)extracted_headers;
    return (PIF_PLUGIN_gtpu_option_T *)(((__lmem uint32_t *)extracted_headers) + PIF_PARREP_gtpu_option_OFF_LW);
}

__forceinline int pif_plugin_hdr_gtpu_option_add(EXTRACTED_HEADERS_T *extracted_headers)
{
    __lmem struct pif_parrep_ctldata *_ctl = (__lmem struct pif_parrep_ctldata *)extracted_headers;
    if (PIF_PARREP_T4_VALID(_ctl))
        return -1; /* either already present or incompatible header combination */
    PIF_PARREP_SET_gtpu_option_VALID(_ctl);
    return 0;
}

__forceinline int pif_plugin_hdr_gtpu_option_remove(EXTRACTED_HEADERS_T *extracted_headers)
{
    __lmem struct pif_parrep_ctldata *_ctl = (__lmem struct pif_parrep_ctldata *)extracted_headers;
    if (!PIF_PARREP_gtpu_option_VALID(_ctl))
        return -1; /* header is not present */
    PIF_PARREP_CLEAR_gtpu_option_VALID(_ctl);
    return 0;
}

#endif /* __PIF_PLUGIN_GTPU_OPTION_H__ */
