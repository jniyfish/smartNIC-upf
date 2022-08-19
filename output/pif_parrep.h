/* Copyright (C) 2015-2016,  Netronome Systems, Inc.  All rights reserved. */

#ifndef __PIF_PARREP_H__
#define __PIF_PARREP_H__

/* Generated C source defining layout of parsed representation */
/* Warning: your edits to this file may be lost */

/*
 * Parsed representation control data
 */
struct pif_parrep_ctldata {
    unsigned int valid:1;
    unsigned int t0_valid:1;
    unsigned int t0_dirty:1;
    unsigned int t0_orig_len:1;
    unsigned int t1_valid:1;
    unsigned int t1_dirty:1;
    unsigned int t1_orig_len:1;
    unsigned int t2_valid:1;
    unsigned int t2_dirty:1;
    unsigned int t2_orig_len:1;
    unsigned int t3_valid:1;
    unsigned int t3_dirty:1;
    unsigned int t3_orig_len:1;
    unsigned int t4_valid:1;
    unsigned int t4_dirty:1;
    unsigned int t4_orig_len:1;
    unsigned int t5_valid:1;
    unsigned int t5_dirty:1;
    unsigned int t5_orig_len:1;
    unsigned int t6_valid:1;
    unsigned int t6_dirty:1;
    unsigned int t6_orig_len:1;
    unsigned int t7_valid:1;
    unsigned int t7_type:2;
    unsigned int t7_dirty:1;
    unsigned int t7_orig_len:5;
};

#define PIF_PARREP_CTLDATA_OFF_LW 0
#define PIF_PARREP_CTLDATA_LEN_LW 1

/*
 * Parsed representation layout
 */

/* Parsed represention tier types */
/* tier 7 */
#define PIF_PARREP_TYPE_arp 0
#define PIF_PARREP_TYPE_inner_tcp 1
#define PIF_PARREP_TYPE_tcp 2
#define PIF_PARREP_TYPE_inner_udp 3

/* Parse state values */
#define PIF_PARREP_STATE_exit -1
#define PIF_PARREP_STATE_parse_inner_ipv4 9
#define PIF_PARREP_STATE_parse_ipv4 1
#define PIF_PARREP_STATE_parse_tcp 4
#define PIF_PARREP_STATE_parse_gtpu 5
#define PIF_PARREP_STATE_parse_inner_tcp 10
#define PIF_PARREP_STATE_parse_udp 3
#define PIF_PARREP_STATE_parse_gtpu_ex 6
#define PIF_PARREP_STATE_parse_arp 2
#define PIF_PARREP_STATE_start 0
#define PIF_PARREP_STATE_parse_gtpu_seq 7
#define PIF_PARREP_STATE_parse_pdu_ses_container 8
#define PIF_PARREP_STATE_parse_inner_udp 11
#define PIF_PARREP_MAX_STATE 11

/* Tier 0 */
#define PIF_PARREP_T0_OFF_LW 1
#define PIF_PARREP_T0_LEN_LW 4
#define PIF_PARREP_ethernet_OFF_LW (PIF_PARREP_T0_OFF_LW)
#define PIF_PARREP_ethernet_LEN_LW 4
#define PIF_PARREP_ethernet_LEN_B 14

/* Tier 1 */
#define PIF_PARREP_T1_OFF_LW 5
#define PIF_PARREP_T1_LEN_LW 5
#define PIF_PARREP_ipv4_OFF_LW (PIF_PARREP_T1_OFF_LW)
#define PIF_PARREP_ipv4_LEN_LW 5
#define PIF_PARREP_ipv4_LEN_B 20

/* Tier 2 */
#define PIF_PARREP_T2_OFF_LW 10
#define PIF_PARREP_T2_LEN_LW 2
#define PIF_PARREP_udp_OFF_LW (PIF_PARREP_T2_OFF_LW)
#define PIF_PARREP_udp_LEN_LW 2
#define PIF_PARREP_udp_LEN_B 8

/* Tier 3 */
#define PIF_PARREP_T3_OFF_LW 12
#define PIF_PARREP_T3_LEN_LW 2
#define PIF_PARREP_gtpu_OFF_LW (PIF_PARREP_T3_OFF_LW)
#define PIF_PARREP_gtpu_LEN_LW 2
#define PIF_PARREP_gtpu_LEN_B 8

/* Tier 4 */
#define PIF_PARREP_T4_OFF_LW 14
#define PIF_PARREP_T4_LEN_LW 1
#define PIF_PARREP_gtpu_option_OFF_LW (PIF_PARREP_T4_OFF_LW)
#define PIF_PARREP_gtpu_option_LEN_LW 1
#define PIF_PARREP_gtpu_option_LEN_B 4

/* Tier 5 */
#define PIF_PARREP_T5_OFF_LW 15
#define PIF_PARREP_T5_LEN_LW 1
#define PIF_PARREP_gtpu_ex_OFF_LW (PIF_PARREP_T5_OFF_LW)
#define PIF_PARREP_gtpu_ex_LEN_LW 1
#define PIF_PARREP_gtpu_ex_LEN_B 4

/* Tier 6 */
#define PIF_PARREP_T6_OFF_LW 16
#define PIF_PARREP_T6_LEN_LW 5
#define PIF_PARREP_inner_ipv4_OFF_LW (PIF_PARREP_T6_OFF_LW)
#define PIF_PARREP_inner_ipv4_LEN_LW 5
#define PIF_PARREP_inner_ipv4_LEN_B 20

/* Tier 7 */
#define PIF_PARREP_T7_OFF_LW 21
#define PIF_PARREP_T7_LEN_LW 5
#define PIF_PARREP_arp_OFF_LW (PIF_PARREP_T7_OFF_LW)
#define PIF_PARREP_arp_LEN_LW 2
#define PIF_PARREP_arp_LEN_B 8
#define PIF_PARREP_inner_tcp_OFF_LW (PIF_PARREP_T7_OFF_LW)
#define PIF_PARREP_inner_tcp_LEN_LW 5
#define PIF_PARREP_inner_tcp_LEN_B 20
#define PIF_PARREP_tcp_OFF_LW (PIF_PARREP_T7_OFF_LW)
#define PIF_PARREP_tcp_LEN_LW 5
#define PIF_PARREP_tcp_LEN_B 20
#define PIF_PARREP_inner_udp_OFF_LW (PIF_PARREP_T7_OFF_LW)
#define PIF_PARREP_inner_udp_LEN_LW 2
#define PIF_PARREP_inner_udp_LEN_B 8

/*
 * Metadata
 */

#define PIF_PARREP_bg_md_OFF_LW 26
#define PIF_PARREP_bg_md_LEN_LW 3

#define PIF_PARREP_standard_metadata_OFF_LW 29
#define PIF_PARREP_standard_metadata_LEN_LW 4

#define PIF_PARREP_scalars_OFF_LW 33
#define PIF_PARREP_scalars_LEN_LW 4

#define PIF_PARREP_LEN_LW 37

/* Parsing branches to a constant control entry point */
#define PIF_PARREP_NO_VARIABLE_EXIT

/* Control data macros */
#define PIF_PARREP_VALID(_ctl) (_ctl->valid)
#define PIF_PARREP_SET_VALID(_ctl) \
    do { _ctl->valid = 1; } while (0)

/* Tier 0 */
#define PIF_PARREP_T0_TYPE(ctl) ( ((ctl)->t0_type))
#define PIF_PARREP_T0_VALID(ctl) ( ((ctl)->t0_valid))
#define PIF_PARREP_ethernet_VALID(ctl) ( ((ctl)->t0_valid) )
#define PIF_PARREP_SET_ethernet_VALID(ctl) \
    do { \
        (ctl)->t0_valid = 1; \
    } while(0);
#define PIF_PARREP_CLEAR_ethernet_VALID(ctl) \
    do { \
        (ctl)->t0_valid = 0; \
    } while(0);

#define PIF_PARREP_ethernet_DIRTY(_ctl) ((_ctl)->t0_dirty)
#define PIF_PARREP_T0_DIRTY(_ctl) ((_ctl)->t0_dirty)
#define PIF_PARREP_CLEAR_T0_DIRTY(_ctl)     do { \
        (_ctl)->t0_dirty = 0; \
    } while(0);
#define PIF_PARREP_SET_T0_DIRTY(_ctl)     do { \
        (_ctl)->t0_dirty = 0; \
    } while(0);
#define PIF_PARREP_SET_ethernet_DIRTY(_ctl) \
    do { \
        (_ctl)->t0_dirty = 1; \
    } while(0);

#define PIF_PARREP_T0_ORIG_LEN(ctl) (((ctl)->t0_orig_len) ? PIF_PARREP_ethernet_LEN_B : 0)
#define PIF_PARREP_SET_T0_ORIG_LEN(ctl, len) \
    do { \
        (ctl)->t0_orig_len = (len == 0 ? 0 : 1); \
    } while(0);
#define PIF_PARREP_ethernet_ORIG_LEN(ctl) (((ctl)->t0_orig_len) ? PIF_PARREP_ethernet_LEN_B : 0)
#define PIF_PARREP_CLEAR_ethernet_ORIG_LEN(ctl) \
    do { \
        (ctl)->t0_orig_len = 0; \
    } while(0);
#define PIF_PARREP_SET_ethernet_ORIG_LEN(ctl, len) \
    do { \
        (ctl)->t0_orig_len = 1; \
    } while(0);

/* Tier 1 */
#define PIF_PARREP_T1_TYPE(ctl) ( ((ctl)->t1_type))
#define PIF_PARREP_T1_VALID(ctl) ( ((ctl)->t1_valid))
#define PIF_PARREP_ipv4_VALID(ctl) ( ((ctl)->t1_valid) )
#define PIF_PARREP_SET_ipv4_VALID(ctl) \
    do { \
        (ctl)->t1_valid = 1; \
    } while(0);
#define PIF_PARREP_CLEAR_ipv4_VALID(ctl) \
    do { \
        (ctl)->t1_valid = 0; \
    } while(0);

#define PIF_PARREP_ipv4_DIRTY(_ctl) ((_ctl)->t1_dirty)
#define PIF_PARREP_T1_DIRTY(_ctl) ((_ctl)->t1_dirty)
#define PIF_PARREP_CLEAR_T1_DIRTY(_ctl)     do { \
        (_ctl)->t1_dirty = 0; \
    } while(0);
#define PIF_PARREP_SET_T1_DIRTY(_ctl)     do { \
        (_ctl)->t1_dirty = 0; \
    } while(0);
#define PIF_PARREP_SET_ipv4_DIRTY(_ctl) \
    do { \
        (_ctl)->t1_dirty = 1; \
    } while(0);

#define PIF_PARREP_T1_ORIG_LEN(ctl) (((ctl)->t1_orig_len) ? PIF_PARREP_ipv4_LEN_B : 0)
#define PIF_PARREP_SET_T1_ORIG_LEN(ctl, len) \
    do { \
        (ctl)->t1_orig_len = (len == 0 ? 0 : 1); \
    } while(0);
#define PIF_PARREP_ipv4_ORIG_LEN(ctl) (((ctl)->t1_orig_len) ? PIF_PARREP_ipv4_LEN_B : 0)
#define PIF_PARREP_CLEAR_ipv4_ORIG_LEN(ctl) \
    do { \
        (ctl)->t1_orig_len = 0; \
    } while(0);
#define PIF_PARREP_SET_ipv4_ORIG_LEN(ctl, len) \
    do { \
        (ctl)->t1_orig_len = 1; \
    } while(0);

/* Tier 2 */
#define PIF_PARREP_T2_TYPE(ctl) ( ((ctl)->t2_type))
#define PIF_PARREP_T2_VALID(ctl) ( ((ctl)->t2_valid))
#define PIF_PARREP_udp_VALID(ctl) ( ((ctl)->t2_valid) )
#define PIF_PARREP_SET_udp_VALID(ctl) \
    do { \
        (ctl)->t2_valid = 1; \
    } while(0);
#define PIF_PARREP_CLEAR_udp_VALID(ctl) \
    do { \
        (ctl)->t2_valid = 0; \
    } while(0);

#define PIF_PARREP_udp_DIRTY(_ctl) ((_ctl)->t2_dirty)
#define PIF_PARREP_T2_DIRTY(_ctl) ((_ctl)->t2_dirty)
#define PIF_PARREP_CLEAR_T2_DIRTY(_ctl)     do { \
        (_ctl)->t2_dirty = 0; \
    } while(0);
#define PIF_PARREP_SET_T2_DIRTY(_ctl)     do { \
        (_ctl)->t2_dirty = 0; \
    } while(0);
#define PIF_PARREP_SET_udp_DIRTY(_ctl) \
    do { \
        (_ctl)->t2_dirty = 1; \
    } while(0);

#define PIF_PARREP_T2_ORIG_LEN(ctl) (((ctl)->t2_orig_len) ? PIF_PARREP_udp_LEN_B : 0)
#define PIF_PARREP_SET_T2_ORIG_LEN(ctl, len) \
    do { \
        (ctl)->t2_orig_len = (len == 0 ? 0 : 1); \
    } while(0);
#define PIF_PARREP_udp_ORIG_LEN(ctl) (((ctl)->t2_orig_len) ? PIF_PARREP_udp_LEN_B : 0)
#define PIF_PARREP_CLEAR_udp_ORIG_LEN(ctl) \
    do { \
        (ctl)->t2_orig_len = 0; \
    } while(0);
#define PIF_PARREP_SET_udp_ORIG_LEN(ctl, len) \
    do { \
        (ctl)->t2_orig_len = 1; \
    } while(0);

/* Tier 3 */
#define PIF_PARREP_T3_TYPE(ctl) ( ((ctl)->t3_type))
#define PIF_PARREP_T3_VALID(ctl) ( ((ctl)->t3_valid))
#define PIF_PARREP_gtpu_VALID(ctl) ( ((ctl)->t3_valid) )
#define PIF_PARREP_SET_gtpu_VALID(ctl) \
    do { \
        (ctl)->t3_valid = 1; \
    } while(0);
#define PIF_PARREP_CLEAR_gtpu_VALID(ctl) \
    do { \
        (ctl)->t3_valid = 0; \
    } while(0);

#define PIF_PARREP_gtpu_DIRTY(_ctl) ((_ctl)->t3_dirty)
#define PIF_PARREP_T3_DIRTY(_ctl) ((_ctl)->t3_dirty)
#define PIF_PARREP_CLEAR_T3_DIRTY(_ctl)     do { \
        (_ctl)->t3_dirty = 0; \
    } while(0);
#define PIF_PARREP_SET_T3_DIRTY(_ctl)     do { \
        (_ctl)->t3_dirty = 0; \
    } while(0);
#define PIF_PARREP_SET_gtpu_DIRTY(_ctl) \
    do { \
        (_ctl)->t3_dirty = 1; \
    } while(0);

#define PIF_PARREP_T3_ORIG_LEN(ctl) (((ctl)->t3_orig_len) ? PIF_PARREP_gtpu_LEN_B : 0)
#define PIF_PARREP_SET_T3_ORIG_LEN(ctl, len) \
    do { \
        (ctl)->t3_orig_len = (len == 0 ? 0 : 1); \
    } while(0);
#define PIF_PARREP_gtpu_ORIG_LEN(ctl) (((ctl)->t3_orig_len) ? PIF_PARREP_gtpu_LEN_B : 0)
#define PIF_PARREP_CLEAR_gtpu_ORIG_LEN(ctl) \
    do { \
        (ctl)->t3_orig_len = 0; \
    } while(0);
#define PIF_PARREP_SET_gtpu_ORIG_LEN(ctl, len) \
    do { \
        (ctl)->t3_orig_len = 1; \
    } while(0);

/* Tier 4 */
#define PIF_PARREP_T4_TYPE(ctl) ( ((ctl)->t4_type))
#define PIF_PARREP_T4_VALID(ctl) ( ((ctl)->t4_valid))
#define PIF_PARREP_gtpu_option_VALID(ctl) ( ((ctl)->t4_valid) )
#define PIF_PARREP_SET_gtpu_option_VALID(ctl) \
    do { \
        (ctl)->t4_valid = 1; \
    } while(0);
#define PIF_PARREP_CLEAR_gtpu_option_VALID(ctl) \
    do { \
        (ctl)->t4_valid = 0; \
    } while(0);

#define PIF_PARREP_gtpu_option_DIRTY(_ctl) ((_ctl)->t4_dirty)
#define PIF_PARREP_T4_DIRTY(_ctl) ((_ctl)->t4_dirty)
#define PIF_PARREP_CLEAR_T4_DIRTY(_ctl)     do { \
        (_ctl)->t4_dirty = 0; \
    } while(0);
#define PIF_PARREP_SET_T4_DIRTY(_ctl)     do { \
        (_ctl)->t4_dirty = 0; \
    } while(0);
#define PIF_PARREP_SET_gtpu_option_DIRTY(_ctl) \
    do { \
        (_ctl)->t4_dirty = 1; \
    } while(0);

#define PIF_PARREP_T4_ORIG_LEN(ctl) (((ctl)->t4_orig_len) ? PIF_PARREP_gtpu_option_LEN_B : 0)
#define PIF_PARREP_SET_T4_ORIG_LEN(ctl, len) \
    do { \
        (ctl)->t4_orig_len = (len == 0 ? 0 : 1); \
    } while(0);
#define PIF_PARREP_gtpu_option_ORIG_LEN(ctl) (((ctl)->t4_orig_len) ? PIF_PARREP_gtpu_option_LEN_B : 0)
#define PIF_PARREP_CLEAR_gtpu_option_ORIG_LEN(ctl) \
    do { \
        (ctl)->t4_orig_len = 0; \
    } while(0);
#define PIF_PARREP_SET_gtpu_option_ORIG_LEN(ctl, len) \
    do { \
        (ctl)->t4_orig_len = 1; \
    } while(0);

/* Tier 5 */
#define PIF_PARREP_T5_TYPE(ctl) ( ((ctl)->t5_type))
#define PIF_PARREP_T5_VALID(ctl) ( ((ctl)->t5_valid))
#define PIF_PARREP_gtpu_ex_VALID(ctl) ( ((ctl)->t5_valid) )
#define PIF_PARREP_SET_gtpu_ex_VALID(ctl) \
    do { \
        (ctl)->t5_valid = 1; \
    } while(0);
#define PIF_PARREP_CLEAR_gtpu_ex_VALID(ctl) \
    do { \
        (ctl)->t5_valid = 0; \
    } while(0);

#define PIF_PARREP_gtpu_ex_DIRTY(_ctl) ((_ctl)->t5_dirty)
#define PIF_PARREP_T5_DIRTY(_ctl) ((_ctl)->t5_dirty)
#define PIF_PARREP_CLEAR_T5_DIRTY(_ctl)     do { \
        (_ctl)->t5_dirty = 0; \
    } while(0);
#define PIF_PARREP_SET_T5_DIRTY(_ctl)     do { \
        (_ctl)->t5_dirty = 0; \
    } while(0);
#define PIF_PARREP_SET_gtpu_ex_DIRTY(_ctl) \
    do { \
        (_ctl)->t5_dirty = 1; \
    } while(0);

#define PIF_PARREP_T5_ORIG_LEN(ctl) (((ctl)->t5_orig_len) ? PIF_PARREP_gtpu_ex_LEN_B : 0)
#define PIF_PARREP_SET_T5_ORIG_LEN(ctl, len) \
    do { \
        (ctl)->t5_orig_len = (len == 0 ? 0 : 1); \
    } while(0);
#define PIF_PARREP_gtpu_ex_ORIG_LEN(ctl) (((ctl)->t5_orig_len) ? PIF_PARREP_gtpu_ex_LEN_B : 0)
#define PIF_PARREP_CLEAR_gtpu_ex_ORIG_LEN(ctl) \
    do { \
        (ctl)->t5_orig_len = 0; \
    } while(0);
#define PIF_PARREP_SET_gtpu_ex_ORIG_LEN(ctl, len) \
    do { \
        (ctl)->t5_orig_len = 1; \
    } while(0);

/* Tier 6 */
#define PIF_PARREP_T6_TYPE(ctl) ( ((ctl)->t6_type))
#define PIF_PARREP_T6_VALID(ctl) ( ((ctl)->t6_valid))
#define PIF_PARREP_inner_ipv4_VALID(ctl) ( ((ctl)->t6_valid) )
#define PIF_PARREP_SET_inner_ipv4_VALID(ctl) \
    do { \
        (ctl)->t6_valid = 1; \
    } while(0);
#define PIF_PARREP_CLEAR_inner_ipv4_VALID(ctl) \
    do { \
        (ctl)->t6_valid = 0; \
    } while(0);

#define PIF_PARREP_inner_ipv4_DIRTY(_ctl) ((_ctl)->t6_dirty)
#define PIF_PARREP_T6_DIRTY(_ctl) ((_ctl)->t6_dirty)
#define PIF_PARREP_CLEAR_T6_DIRTY(_ctl)     do { \
        (_ctl)->t6_dirty = 0; \
    } while(0);
#define PIF_PARREP_SET_T6_DIRTY(_ctl)     do { \
        (_ctl)->t6_dirty = 0; \
    } while(0);
#define PIF_PARREP_SET_inner_ipv4_DIRTY(_ctl) \
    do { \
        (_ctl)->t6_dirty = 1; \
    } while(0);

#define PIF_PARREP_T6_ORIG_LEN(ctl) (((ctl)->t6_orig_len) ? PIF_PARREP_inner_ipv4_LEN_B : 0)
#define PIF_PARREP_SET_T6_ORIG_LEN(ctl, len) \
    do { \
        (ctl)->t6_orig_len = (len == 0 ? 0 : 1); \
    } while(0);
#define PIF_PARREP_inner_ipv4_ORIG_LEN(ctl) (((ctl)->t6_orig_len) ? PIF_PARREP_inner_ipv4_LEN_B : 0)
#define PIF_PARREP_CLEAR_inner_ipv4_ORIG_LEN(ctl) \
    do { \
        (ctl)->t6_orig_len = 0; \
    } while(0);
#define PIF_PARREP_SET_inner_ipv4_ORIG_LEN(ctl, len) \
    do { \
        (ctl)->t6_orig_len = 1; \
    } while(0);

/* Tier 7 */
#define PIF_PARREP_T7_TYPE(ctl) ( ((ctl)->t7_type))
#define PIF_PARREP_T7_VALID(ctl) ( ((ctl)->t7_valid & 0x1) )
#define PIF_PARREP_arp_VALID(ctl) ( ((ctl)->t7_valid & 0x1) && ((ctl)->t7_type == PIF_PARREP_TYPE_arp) )
#define PIF_PARREP_SET_arp_VALID(ctl) \
    do { \
        (ctl)->t7_valid = 1; \
        (ctl)->t7_type = PIF_PARREP_TYPE_arp; \
    } while(0);
#define PIF_PARREP_CLEAR_arp_VALID(ctl) \
    do { \
        (ctl)->t7_valid = 0; \
    } while(0);
#define PIF_PARREP_inner_tcp_VALID(ctl) ( ((ctl)->t7_valid & 0x1) && ((ctl)->t7_type == PIF_PARREP_TYPE_inner_tcp) )
#define PIF_PARREP_SET_inner_tcp_VALID(ctl) \
    do { \
        (ctl)->t7_valid = 1; \
        (ctl)->t7_type = PIF_PARREP_TYPE_inner_tcp; \
    } while(0);
#define PIF_PARREP_CLEAR_inner_tcp_VALID(ctl) \
    do { \
        (ctl)->t7_valid = 0; \
    } while(0);
#define PIF_PARREP_tcp_VALID(ctl) ( ((ctl)->t7_valid & 0x1) && ((ctl)->t7_type == PIF_PARREP_TYPE_tcp) )
#define PIF_PARREP_SET_tcp_VALID(ctl) \
    do { \
        (ctl)->t7_valid = 1; \
        (ctl)->t7_type = PIF_PARREP_TYPE_tcp; \
    } while(0);
#define PIF_PARREP_CLEAR_tcp_VALID(ctl) \
    do { \
        (ctl)->t7_valid = 0; \
    } while(0);
#define PIF_PARREP_inner_udp_VALID(ctl) ( ((ctl)->t7_valid & 0x1) && ((ctl)->t7_type == PIF_PARREP_TYPE_inner_udp) )
#define PIF_PARREP_SET_inner_udp_VALID(ctl) \
    do { \
        (ctl)->t7_valid = 1; \
        (ctl)->t7_type = PIF_PARREP_TYPE_inner_udp; \
    } while(0);
#define PIF_PARREP_CLEAR_inner_udp_VALID(ctl) \
    do { \
        (ctl)->t7_valid = 0; \
    } while(0);

#define PIF_PARREP_arp_DIRTY(_ctl) ((_ctl)->t7_dirty)
#define PIF_PARREP_inner_tcp_DIRTY(_ctl) ((_ctl)->t7_dirty)
#define PIF_PARREP_tcp_DIRTY(_ctl) ((_ctl)->t7_dirty)
#define PIF_PARREP_inner_udp_DIRTY(_ctl) ((_ctl)->t7_dirty)
#define PIF_PARREP_T7_DIRTY(_ctl) ((_ctl)->t7_dirty)
#define PIF_PARREP_CLEAR_T7_DIRTY(_ctl)     do { \
        (_ctl)->t7_dirty = 0; \
    } while(0);
#define PIF_PARREP_SET_T7_DIRTY(_ctl)     do { \
        (_ctl)->t7_dirty = 0; \
    } while(0);
#define PIF_PARREP_SET_arp_DIRTY(_ctl) \
    do { \
        (_ctl)->t7_dirty = 1; \
    } while(0);
#define PIF_PARREP_SET_inner_tcp_DIRTY(_ctl) \
    do { \
        (_ctl)->t7_dirty = 1; \
    } while(0);
#define PIF_PARREP_SET_tcp_DIRTY(_ctl) \
    do { \
        (_ctl)->t7_dirty = 1; \
    } while(0);
#define PIF_PARREP_SET_inner_udp_DIRTY(_ctl) \
    do { \
        (_ctl)->t7_dirty = 1; \
    } while(0);

#define PIF_PARREP_T7_ORIG_LEN(ctl) ((ctl)->t7_orig_len)
#define PIF_PARREP_SET_T7_ORIG_LEN(ctl, len) \
    do { \
        (ctl)->t7_orig_len = len; \
    } while(0);
#define PIF_PARREP_INC_T7_ORIG_LEN(ctl, len) \
    do { \
        (ctl)->t7_orig_len += len; \
    } while(0);
#define PIF_PARREP_arp_ORIG_LEN(ctl) ((ctl)->t7_orig_len)
#define PIF_PARREP_CLEAR_arp_ORIG_LEN(ctl) \
    do { \
        (ctl)->t7_orig_len = 0; \
    } while(0);
#define PIF_PARREP_SET_arp_ORIG_LEN(ctl, len) \
    do { \
        (ctl)->t7_orig_len = len; \
    } while(0);
#define PIF_PARREP_INC_arp_ORIG_LEN(ctl, len) \
    do { \
        (ctl)->t7_orig_len += len; \
    } while(0);
#define PIF_PARREP_inner_tcp_ORIG_LEN(ctl) ((ctl)->t7_orig_len)
#define PIF_PARREP_CLEAR_inner_tcp_ORIG_LEN(ctl) \
    do { \
        (ctl)->t7_orig_len = 0; \
    } while(0);
#define PIF_PARREP_SET_inner_tcp_ORIG_LEN(ctl, len) \
    do { \
        (ctl)->t7_orig_len = len; \
    } while(0);
#define PIF_PARREP_INC_inner_tcp_ORIG_LEN(ctl, len) \
    do { \
        (ctl)->t7_orig_len += len; \
    } while(0);
#define PIF_PARREP_tcp_ORIG_LEN(ctl) ((ctl)->t7_orig_len)
#define PIF_PARREP_CLEAR_tcp_ORIG_LEN(ctl) \
    do { \
        (ctl)->t7_orig_len = 0; \
    } while(0);
#define PIF_PARREP_SET_tcp_ORIG_LEN(ctl, len) \
    do { \
        (ctl)->t7_orig_len = len; \
    } while(0);
#define PIF_PARREP_INC_tcp_ORIG_LEN(ctl, len) \
    do { \
        (ctl)->t7_orig_len += len; \
    } while(0);
#define PIF_PARREP_inner_udp_ORIG_LEN(ctl) ((ctl)->t7_orig_len)
#define PIF_PARREP_CLEAR_inner_udp_ORIG_LEN(ctl) \
    do { \
        (ctl)->t7_orig_len = 0; \
    } while(0);
#define PIF_PARREP_SET_inner_udp_ORIG_LEN(ctl, len) \
    do { \
        (ctl)->t7_orig_len = len; \
    } while(0);
#define PIF_PARREP_INC_inner_udp_ORIG_LEN(ctl, len) \
    do { \
        (ctl)->t7_orig_len += len; \
    } while(0);



void pif_value_set_scan_configs();

#endif /* __PIF_PARREP_H__ */
