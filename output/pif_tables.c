/* Copyright (C) 2015-2016,  Netronome Systems, Inc.  All rights reserved. */

#include <pif_common.h>

/* Table related defines */

/* Table 0 : ingress::route */
#define PIF_TABLE_ACTIONDATA_SIZE_0 32
#define PIF_TABLE_MAX_ENTRIES_0 1025
#define PIF_TABLE_SHIFT_0 5

/* Table 1 : ingress::pdr_ingress_table_dl */
#define PIF_TABLE_ACTIONDATA_SIZE_1 32
#define PIF_TABLE_MAX_ENTRIES_1 1025
#define PIF_TABLE_SHIFT_1 5

/* Table 2 : ingress::src_intf_table */
#define PIF_TABLE_ACTIONDATA_SIZE_2 16
#define PIF_TABLE_MAX_ENTRIES_2 33
#define PIF_TABLE_SHIFT_2 4

/* Table 3 : ingress::pdr_ingress_table_ul */
#define PIF_TABLE_ACTIONDATA_SIZE_3 32
#define PIF_TABLE_MAX_ENTRIES_3 1025
#define PIF_TABLE_SHIFT_3 5

/* Table 4 : ingress::far_egress_table */
#define PIF_TABLE_ACTIONDATA_SIZE_4 32
#define PIF_TABLE_MAX_ENTRIES_4 1025
#define PIF_TABLE_SHIFT_4 5

/* DCFL related table storage */
__export __emem __align256K uint32_t dcfl_ct_0[DCFL_TABLE_SIZE / 4];
__export __emem __align256K uint32_t dcfl_ct_1[DCFL_TABLE_SIZE / 4];
__export __emem __align256K uint32_t dcfl_ct_2[DCFL_TABLE_SIZE / 4];
__export __emem __align256K uint32_t dcfl_ct_3[DCFL_TABLE_SIZE / 4];
__export __emem __align256K uint32_t dcfl_ct_4[DCFL_TABLE_SIZE / 4];

/* PIF related table storage */
__export __emem uint32_t pif_actiondata_table_0_ingress__route[2 * PIF_TABLE_MAX_ENTRIES_0 * (PIF_TABLE_ACTIONDATA_SIZE_0 / 4)];
__export __emem uint32_t pif_actiondata_table_1_ingress__pdr_ingress_table_dl[2 * PIF_TABLE_MAX_ENTRIES_1 * (PIF_TABLE_ACTIONDATA_SIZE_1 / 4)];
__export __emem uint32_t pif_actiondata_table_2_ingress__src_intf_table[2 * PIF_TABLE_MAX_ENTRIES_2 * (PIF_TABLE_ACTIONDATA_SIZE_2 / 4)];
__export __emem uint32_t pif_actiondata_table_3_ingress__pdr_ingress_table_ul[2 * PIF_TABLE_MAX_ENTRIES_3 * (PIF_TABLE_ACTIONDATA_SIZE_3 / 4)];
__export __emem uint32_t pif_actiondata_table_4_ingress__far_egress_table[2 * PIF_TABLE_MAX_ENTRIES_4 * (PIF_TABLE_ACTIONDATA_SIZE_4 / 4)];

__export __emem struct pif_actiondata_table_desc pif_actiondata_table_descs[PIF_TABLE_COUNT] = {
        {
            /* .table_address = */ 0,
            /* .rule_count = */ 0,
            /* .reserved = */ 0,
            /* .record_shift = */  PIF_TABLE_SHIFT_0,
            /* .flags = */ 0,
        },
        {
            /* .table_address = */ 0,
            /* .rule_count = */ 0,
            /* .reserved = */ 0,
            /* .record_shift = */  PIF_TABLE_SHIFT_1,
            /* .flags = */ 0,
        },
        {
            /* .table_address = */ 0,
            /* .rule_count = */ 0,
            /* .reserved = */ 0,
            /* .record_shift = */  PIF_TABLE_SHIFT_2,
            /* .flags = */ 0,
        },
        {
            /* .table_address = */ 0,
            /* .rule_count = */ 0,
            /* .reserved = */ 0,
            /* .record_shift = */  PIF_TABLE_SHIFT_3,
            /* .flags = */ 0,
        },
        {
            /* .table_address = */ 0,
            /* .rule_count = */ 0,
            /* .reserved = */ 0,
            /* .record_shift = */  PIF_TABLE_SHIFT_4,
            /* .flags = */ 0,
        },
    };
