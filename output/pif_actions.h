/* Copyright (C) 2015-2016,  Netronome Systems, Inc.  All rights reserved. */

#ifndef __PIF_ACTIONS_H__
#define __PIF_ACTIONS_H__

/* Warning: generated file - your edits to this file may be lost */

/* Action operation IDs */

#define PIF_ACTION_ID_ingress__gtp_encap 0
#define PIF_ACTION_ID_ingress__set_src_intf 1
#define PIF_ACTION_ID_ingress__act 2
#define PIF_ACTION_ID_ingress__gtp_decap 3
#define PIF_ACTION_ID_ingress__set_rules 4
#define PIF_ACTION_ID_MAX 4

/* Match action data structure */

__packed struct pif_action_actiondata_ingress__gtp_encap {
    uint32_t teid;
    uint32_t ran_ip;
    uint32_t upf_ip;
    uint32_t __pif_rule_no;
    uint32_t __pif_table_no;
};

__packed struct pif_action_actiondata_ingress__set_src_intf {
    uint32_t src_mac_1; /* src_mac[48:16] */
    uint32_t dst_mac_1; /* dst_mac[48:16] */
    uint32_t __pif_rule_no;
    uint32_t __pif_table_no;
    uint16_t src_mac_0; /* src_mac[16:0] */
    uint16_t port;
    uint8_t __pif_padding; /* padding */
    uint8_t src_intf;
    uint16_t dst_mac_0; /* dst_mac[16:0] */
};

__packed struct pif_action_actiondata_ingress__act {
    uint32_t __pif_rule_no;
    uint32_t __pif_table_no;
};

__packed struct pif_action_actiondata_ingress__gtp_decap {
    uint32_t __pif_rule_no;
    uint32_t __pif_table_no;
};

__packed struct pif_action_actiondata_ingress__set_rules {
    uint32_t far_id;
    uint32_t __pif_rule_no;
    uint32_t __pif_table_no;
    uint8_t __pif_padding[3]; /* padding */
    uint8_t must_decap;
};

#endif /* __PIF_ACTIONS_H__ */
