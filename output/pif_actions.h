/* Copyright (C) 2015-2016,  Netronome Systems, Inc.  All rights reserved. */

#ifndef __PIF_ACTIONS_H__
#define __PIF_ACTIONS_H__

/* Warning: generated file - your edits to this file may be lost */

/* Action operation IDs */

#define PIF_ACTION_ID_ingress__gtp_decap 0
#define PIF_ACTION_ID_ingress__set_src_intf 1
#define PIF_ACTION_ID_ingress__drop 2
#define PIF_ACTION_ID_ingress__set_egress_port_and_encap 3
#define PIF_ACTION_ID_ingress__set_rules 4
#define PIF_ACTION_ID_MAX 4

/* Match action data structure */

__packed struct pif_action_actiondata_ingress__gtp_decap {
    uint32_t __pif_rule_no;
    uint32_t __pif_table_no;
};

__packed struct pif_action_actiondata_ingress__set_src_intf {
    uint32_t __pif_rule_no;
    uint32_t __pif_table_no;
    uint8_t __pif_padding[3]; /* padding */
    uint8_t src_intf;
};

__packed struct pif_action_actiondata_ingress__drop {
    uint32_t __pif_rule_no;
    uint32_t __pif_table_no;
};

__packed struct pif_action_actiondata_ingress__set_egress_port_and_encap {
    uint32_t __pif_rule_no;
    uint32_t __pif_table_no;
    uint8_t __pif_padding; /* padding */
    uint8_t do_encap;
    uint16_t port;
};

__packed struct pif_action_actiondata_ingress__set_rules {
    uint32_t far_id;
    uint32_t __pif_rule_no;
    uint32_t __pif_table_no;
    uint8_t __pif_padding[3]; /* padding */
    uint8_t must_decap;
};

#endif /* __PIF_ACTIONS_H__ */
