/* Copyright (C) 2015-2016,  Netronome Systems, Inc.  All rights reserved. */

#include <nfp/mem_atomic.h>
#include <nfp/mem_ring.h>
#include <nfp/me.h>
#include <nfp/cls.h>
#include "pif_common.h"
#include "pkt_clone.h"

#ifdef PIF_DEBUG
    __export __emem_n(0) uint64_t pif_act_stats[PIF_ACTION_ID_MAX + 1];
#endif

extern __nnr uint32_t calc_fld_bmsk;

#define BITRANGE(var, width, offset) \
    (((var) >> (offset)) & ((1 << (width)) - 1))


static int pif_action_exec_ingress__gtp_decap(__lmem uint32_t *_pif_parrep, __xread uint32_t *_pif_actdatabuf, unsigned _pif_debug)
{
    int _pif_return = PIF_RETURN_FORWARD;
    __xread struct pif_action_actiondata_ingress__gtp_decap *_pif_act_data = (__xread struct pif_action_actiondata_ingress__gtp_decap *)_pif_actdatabuf;
    __lmem struct pif_parrep_ctldata *_pif_ctldata = (__lmem struct pif_parrep_ctldata *)(_pif_parrep + PIF_PARREP_CTLDATA_OFF_LW);
    __lmem struct pif_header_udp *udp;
    __lmem struct pif_header_ipv4 *ipv4;
    __lmem struct pif_header_gtpu_ex *gtpu_ex;
    __lmem struct pif_header_gtpu *gtpu;
    __lmem struct pif_header_gtpu_option *gtpu_option;
#ifdef PIF_DEBUG
    if (_pif_debug & PIF_ACTION_OPDATA_DBGFLAG_BREAK) {
        /* copy the table number and rule number into mailboxes */
        unsigned int temp0, temp1;
        temp0 = local_csr_read(local_csr_mailbox_2);
        temp1 = local_csr_read(local_csr_mailbox_3);
        local_csr_write(local_csr_mailbox_2, _pif_act_data->__pif_rule_no);
        local_csr_write(local_csr_mailbox_3, _pif_act_data->__pif_table_no);
#if SIMULATION == 1
        __asm { /* add nops so mailboxes have time to propagate */
        nop;
        nop;
        nop;
        nop;
        nop;
        nop;
        nop;
        nop;
        }
#endif
        __debug_label("pif_table_hit_ingress__gtp_decap");
        local_csr_write(local_csr_mailbox_2, temp0);
        local_csr_write(local_csr_mailbox_3, temp1);
    }
#endif
#ifdef PIF_DEBUG
    __debug_label("pif_action_state_ingress__gtp_decap");
#endif

    udp = (__lmem struct pif_header_udp *) (_pif_parrep + PIF_PARREP_udp_OFF_LW);
    ipv4 = (__lmem struct pif_header_ipv4 *) (_pif_parrep + PIF_PARREP_ipv4_OFF_LW);
    gtpu_ex = (__lmem struct pif_header_gtpu_ex *) (_pif_parrep + PIF_PARREP_gtpu_ex_OFF_LW);
    gtpu = (__lmem struct pif_header_gtpu *) (_pif_parrep + PIF_PARREP_gtpu_OFF_LW);
    gtpu_option = (__lmem struct pif_header_gtpu_option *) (_pif_parrep + PIF_PARREP_gtpu_option_OFF_LW);
    PIF_PARREP_SET_udp_DIRTY(_pif_ctldata);
    PIF_PARREP_SET_gtpu_ex_DIRTY(_pif_ctldata);
    PIF_PARREP_SET_gtpu_DIRTY(_pif_ctldata);
    PIF_PARREP_SET_ipv4_DIRTY(_pif_ctldata);
    PIF_PARREP_SET_gtpu_option_DIRTY(_pif_ctldata);

    {
        /* remove_header(ipv4) */

        /* primitive body */
        {
            PIF_PARREP_CLEAR_ipv4_VALID(_pif_ctldata);
        }
    }
    {
        /* remove_header(udp) */

        /* primitive body */
        {
            PIF_PARREP_CLEAR_udp_VALID(_pif_ctldata);
        }
    }
    {
        /* remove_header(gtpu) */

        /* primitive body */
        {
            PIF_PARREP_CLEAR_gtpu_VALID(_pif_ctldata);
        }
    }
    {
        /* remove_header(gtpu_option) */

        /* primitive body */
        {
            PIF_PARREP_CLEAR_gtpu_option_VALID(_pif_ctldata);
        }
    }
    {
        /* remove_header(gtpu_ex) */

        /* primitive body */
        {
            PIF_PARREP_CLEAR_gtpu_ex_VALID(_pif_ctldata);
        }
    }
    return _pif_return;
}

static int pif_action_exec_ingress__set_src_intf(__lmem uint32_t *_pif_parrep, __xread uint32_t *_pif_actdatabuf, unsigned _pif_debug)
{
    int _pif_return = PIF_RETURN_FORWARD;
    __xread struct pif_action_actiondata_ingress__set_src_intf *_pif_act_data = (__xread struct pif_action_actiondata_ingress__set_src_intf *)_pif_actdatabuf;
    __lmem struct pif_parrep_ctldata *_pif_ctldata = (__lmem struct pif_parrep_ctldata *)(_pif_parrep + PIF_PARREP_CTLDATA_OFF_LW);
    __lmem struct pif_header_scalars *scalars;
#ifdef PIF_DEBUG
    if (_pif_debug & PIF_ACTION_OPDATA_DBGFLAG_BREAK) {
        /* copy the table number and rule number into mailboxes */
        unsigned int temp0, temp1;
        temp0 = local_csr_read(local_csr_mailbox_2);
        temp1 = local_csr_read(local_csr_mailbox_3);
        local_csr_write(local_csr_mailbox_2, _pif_act_data->__pif_rule_no);
        local_csr_write(local_csr_mailbox_3, _pif_act_data->__pif_table_no);
#if SIMULATION == 1
        __asm { /* add nops so mailboxes have time to propagate */
        nop;
        nop;
        nop;
        nop;
        nop;
        nop;
        nop;
        nop;
        }
#endif
        __debug_label("pif_table_hit_ingress__set_src_intf");
        local_csr_write(local_csr_mailbox_2, temp0);
        local_csr_write(local_csr_mailbox_3, temp1);
    }
#endif
#ifdef PIF_DEBUG
    __debug_label("pif_action_state_ingress__set_src_intf");
#endif

    scalars = (__lmem struct pif_header_scalars *) (_pif_parrep + PIF_PARREP_scalars_OFF_LW);

    {
        /* modify_field(scalars.metadata_t@intf,src_intf) */

        /* primitive body */
        scalars->metadata_t__intf = _pif_act_data->src_intf;

    }
    return _pif_return;
}

static int pif_action_exec_ingress__drop(__lmem uint32_t *_pif_parrep, __xread uint32_t *_pif_actdatabuf, unsigned _pif_debug)
{
    int _pif_return = PIF_RETURN_FORWARD;
    __xread struct pif_action_actiondata_ingress__drop *_pif_act_data = (__xread struct pif_action_actiondata_ingress__drop *)_pif_actdatabuf;
    __lmem struct pif_parrep_ctldata *_pif_ctldata = (__lmem struct pif_parrep_ctldata *)(_pif_parrep + PIF_PARREP_CTLDATA_OFF_LW);
#ifdef PIF_DEBUG
    if (_pif_debug & PIF_ACTION_OPDATA_DBGFLAG_BREAK) {
        /* copy the table number and rule number into mailboxes */
        unsigned int temp0, temp1;
        temp0 = local_csr_read(local_csr_mailbox_2);
        temp1 = local_csr_read(local_csr_mailbox_3);
        local_csr_write(local_csr_mailbox_2, _pif_act_data->__pif_rule_no);
        local_csr_write(local_csr_mailbox_3, _pif_act_data->__pif_table_no);
#if SIMULATION == 1
        __asm { /* add nops so mailboxes have time to propagate */
        nop;
        nop;
        nop;
        nop;
        nop;
        nop;
        nop;
        nop;
        }
#endif
        __debug_label("pif_table_hit_ingress__drop");
        local_csr_write(local_csr_mailbox_2, temp0);
        local_csr_write(local_csr_mailbox_3, temp1);
    }
#endif
#ifdef PIF_DEBUG
    __debug_label("pif_action_state_ingress__drop");
#endif


    {
        /* exit() */

        /* primitive body */
        _pif_return = PIF_RETURN_EXIT;
    }
    return _pif_return;
}

static int pif_action_exec_ingress__set_egress_port_and_encap(__lmem uint32_t *_pif_parrep, __xread uint32_t *_pif_actdatabuf, unsigned _pif_debug)
{
    int _pif_return = PIF_RETURN_FORWARD;
    __xread struct pif_action_actiondata_ingress__set_egress_port_and_encap *_pif_act_data = (__xread struct pif_action_actiondata_ingress__set_egress_port_and_encap *)_pif_actdatabuf;
    __lmem struct pif_parrep_ctldata *_pif_ctldata = (__lmem struct pif_parrep_ctldata *)(_pif_parrep + PIF_PARREP_CTLDATA_OFF_LW);
    __lmem struct pif_header_scalars *scalars;
    __lmem struct pif_header_standard_metadata *standard_metadata;
#ifdef PIF_DEBUG
    if (_pif_debug & PIF_ACTION_OPDATA_DBGFLAG_BREAK) {
        /* copy the table number and rule number into mailboxes */
        unsigned int temp0, temp1;
        temp0 = local_csr_read(local_csr_mailbox_2);
        temp1 = local_csr_read(local_csr_mailbox_3);
        local_csr_write(local_csr_mailbox_2, _pif_act_data->__pif_rule_no);
        local_csr_write(local_csr_mailbox_3, _pif_act_data->__pif_table_no);
#if SIMULATION == 1
        __asm { /* add nops so mailboxes have time to propagate */
        nop;
        nop;
        nop;
        nop;
        nop;
        nop;
        nop;
        nop;
        }
#endif
        __debug_label("pif_table_hit_ingress__set_egress_port_and_encap");
        local_csr_write(local_csr_mailbox_2, temp0);
        local_csr_write(local_csr_mailbox_3, temp1);
    }
#endif
#ifdef PIF_DEBUG
    __debug_label("pif_action_state_ingress__set_egress_port_and_encap");
#endif

    scalars = (__lmem struct pif_header_scalars *) (_pif_parrep + PIF_PARREP_scalars_OFF_LW);
    standard_metadata = (__lmem struct pif_header_standard_metadata *) (_pif_parrep + PIF_PARREP_standard_metadata_OFF_LW);

    {
        /* modify_field(scalars.metadata_t@encap_flag,do_encap) */

        /* primitive body */
        scalars->metadata_t__encap_flag = _pif_act_data->do_encap;

    }
    {
        /* modify_field(standard_metadata.egress_spec,port) */

        /* primitive body */
        standard_metadata->egress_spec = _pif_act_data->port;

    }
    return _pif_return;
}

static int pif_action_exec_ingress__set_rules(__lmem uint32_t *_pif_parrep, __xread uint32_t *_pif_actdatabuf, unsigned _pif_debug)
{
    int _pif_return = PIF_RETURN_FORWARD;
    __xread struct pif_action_actiondata_ingress__set_rules *_pif_act_data = (__xread struct pif_action_actiondata_ingress__set_rules *)_pif_actdatabuf;
    __lmem struct pif_parrep_ctldata *_pif_ctldata = (__lmem struct pif_parrep_ctldata *)(_pif_parrep + PIF_PARREP_CTLDATA_OFF_LW);
    __lmem struct pif_header_scalars *scalars;
#ifdef PIF_DEBUG
    if (_pif_debug & PIF_ACTION_OPDATA_DBGFLAG_BREAK) {
        /* copy the table number and rule number into mailboxes */
        unsigned int temp0, temp1;
        temp0 = local_csr_read(local_csr_mailbox_2);
        temp1 = local_csr_read(local_csr_mailbox_3);
        local_csr_write(local_csr_mailbox_2, _pif_act_data->__pif_rule_no);
        local_csr_write(local_csr_mailbox_3, _pif_act_data->__pif_table_no);
#if SIMULATION == 1
        __asm { /* add nops so mailboxes have time to propagate */
        nop;
        nop;
        nop;
        nop;
        nop;
        nop;
        nop;
        nop;
        }
#endif
        __debug_label("pif_table_hit_ingress__set_rules");
        local_csr_write(local_csr_mailbox_2, temp0);
        local_csr_write(local_csr_mailbox_3, temp1);
    }
#endif
#ifdef PIF_DEBUG
    __debug_label("pif_action_state_ingress__set_rules");
#endif

    scalars = (__lmem struct pif_header_scalars *) (_pif_parrep + PIF_PARREP_scalars_OFF_LW);

    {
        /* modify_field(scalars.metadata_t@far_id,far_id) */

        /* primitive body */
        scalars->metadata_t__far_id = _pif_act_data->far_id;

    }
    {
        /* modify_field(scalars.metadata_t@decap_flag,must_decap) */

        /* primitive body */
        scalars->metadata_t__decap_flag = _pif_act_data->must_decap;

    }
    return _pif_return;
}

extern __forceinline int pif_action_exec_op(__lmem uint32_t *parrep, __xread uint32_t *_actdata)
{
    __xread union pif_action_opdata *opdata = (__xread union pif_action_opdata *) _actdata;
    int ret = -1;

    if (opdata->action_id > PIF_ACTION_ID_MAX) {
        /* FIXME: TODO: account for bad action id */
        return -1;
    }

    PIF_DEBUG_SET_STATE(PIF_DEBUG_STATE_ACTION, opdata->action_id);
    switch (opdata->action_id) {
    case PIF_ACTION_ID_ingress__gtp_decap:
        ret = pif_action_exec_ingress__gtp_decap(parrep, _actdata + PIF_ACTION_OPDATA_LW, opdata->dbg_flags);
        break;
    case PIF_ACTION_ID_ingress__set_src_intf:
        ret = pif_action_exec_ingress__set_src_intf(parrep, _actdata + PIF_ACTION_OPDATA_LW, opdata->dbg_flags);
        break;
    case PIF_ACTION_ID_ingress__drop:
        ret = pif_action_exec_ingress__drop(parrep, _actdata + PIF_ACTION_OPDATA_LW, opdata->dbg_flags);
        break;
    case PIF_ACTION_ID_ingress__set_egress_port_and_encap:
        ret = pif_action_exec_ingress__set_egress_port_and_encap(parrep, _actdata + PIF_ACTION_OPDATA_LW, opdata->dbg_flags);
        break;
    case PIF_ACTION_ID_ingress__set_rules:
        ret = pif_action_exec_ingress__set_rules(parrep, _actdata + PIF_ACTION_OPDATA_LW, opdata->dbg_flags);
        break;
    }
#ifdef PIF_DEBUG
        mem_incr64((__mem __addr40 uint64_t *)(pif_act_stats + opdata->action_id));
#endif

    return ret;
}
