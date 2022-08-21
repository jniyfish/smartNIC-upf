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


static int pif_action_exec_ingress__gtp_encap(__lmem uint32_t *_pif_parrep, __xread uint32_t *_pif_actdatabuf, unsigned _pif_debug)
{
    int _pif_return = PIF_RETURN_FORWARD;
    __xread struct pif_action_actiondata_ingress__gtp_encap *_pif_act_data = (__xread struct pif_action_actiondata_ingress__gtp_encap *)_pif_actdatabuf;
    __lmem struct pif_parrep_ctldata *_pif_ctldata = (__lmem struct pif_parrep_ctldata *)(_pif_parrep + PIF_PARREP_CTLDATA_OFF_LW);
    __lmem struct pif_header_udp *udp;
    __lmem struct pif_header_inner_ipv4 *inner_ipv4;
    __lmem struct pif_header_ipv4 *ipv4;
    __lmem struct pif_header_gtpu *gtpu;
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
        __debug_label("pif_table_hit_ingress__gtp_encap");
        local_csr_write(local_csr_mailbox_2, temp0);
        local_csr_write(local_csr_mailbox_3, temp1);
    }
#endif
#ifdef PIF_DEBUG
    __debug_label("pif_action_state_ingress__gtp_encap");
#endif

    udp = (__lmem struct pif_header_udp *) (_pif_parrep + PIF_PARREP_udp_OFF_LW);
    inner_ipv4 = (__lmem struct pif_header_inner_ipv4 *) (_pif_parrep + PIF_PARREP_inner_ipv4_OFF_LW);
    ipv4 = (__lmem struct pif_header_ipv4 *) (_pif_parrep + PIF_PARREP_ipv4_OFF_LW);
    gtpu = (__lmem struct pif_header_gtpu *) (_pif_parrep + PIF_PARREP_gtpu_OFF_LW);
    PIF_PARREP_SET_gtpu_DIRTY(_pif_ctldata);
    PIF_PARREP_SET_ipv4_DIRTY(_pif_ctldata);
    PIF_PARREP_SET_udp_DIRTY(_pif_ctldata);

    PIF_FLCALC_UPD_INCR_CLEAR(PIF_FLCALC_CALC);
    {
        /* add_header(ipv4) */

        /* primitive body */
        {
            /* zero headers for P4-14 spec compliance */
            if (!PIF_PARREP_ipv4_VALID(_pif_ctldata)) {
                int i;
                for (i = 0; i < PIF_PARREP_ipv4_LEN_LW; i++)
                    ((__lmem uint32_t *)ipv4)[i] = 0;
            }
            PIF_PARREP_SET_ipv4_VALID(_pif_ctldata);
        }
    }
    {
        /* add_header(udp) */

        /* primitive body */
        {
            /* zero headers for P4-14 spec compliance */
            if (!PIF_PARREP_udp_VALID(_pif_ctldata)) {
                int i;
                for (i = 0; i < PIF_PARREP_udp_LEN_LW; i++)
                    ((__lmem uint32_t *)udp)[i] = 0;
            }
            PIF_PARREP_SET_udp_VALID(_pif_ctldata);
        }
    }
    {
        /* add_header(gtpu) */

        /* primitive body */
        {
            /* zero headers for P4-14 spec compliance */
            if (!PIF_PARREP_gtpu_VALID(_pif_ctldata)) {
                int i;
                for (i = 0; i < PIF_PARREP_gtpu_LEN_LW; i++)
                    ((__lmem uint32_t *)gtpu)[i] = 0;
            }
            PIF_PARREP_SET_gtpu_VALID(_pif_ctldata);
        }
    }
    {
        /* modify_field(gtpu.version,0x01) */

        /* primitive body */
        gtpu->version = 0x1;

    }
    {
        /* modify_field(gtpu.pt,0x01) */

        /* primitive body */
        gtpu->pt = 0x1;

    }
    {
        /* modify_field(gtpu.spare,0x00) */

        /* primitive body */
        gtpu->spare = 0x0;

    }
    {
        /* modify_field(gtpu.ex_flag,0x00) */

        /* primitive body */
        gtpu->ex_flag = 0x0;

    }
    {
        /* modify_field(gtpu.seq_flag,0x00) */

        /* primitive body */
        gtpu->seq_flag = 0x0;

    }
    {
        /* modify_field(gtpu.npdu_flag,0x00) */

        /* primitive body */
        gtpu->npdu_flag = 0x0;

    }
    {
        /* modify_field(gtpu.msgtype,0xff) */

        /* primitive body */
        gtpu->msgtype = 0xff;

    }
    {
        /* modify_field(gtpu.msglen,inner_ipv4.len) */

        /* primitive body */
        gtpu->msglen = inner_ipv4->len;

    }
    {
        /* modify_field(gtpu.teid,teid) */

        /* primitive body */
        gtpu->teid = _pif_act_data->teid;

    }
    {
        /* modify_field(udp.src_port,0x0868) */

        /* primitive body */
        udp->src_port = 0x868;

    }
    {
        /* modify_field(udp.dst_port,0x0868) */

        /* primitive body */
        udp->dst_port = 0x868;

    }
    {
        /* modify_field(udp.len,_expression_gtp_encap_0) */
        unsigned int pif_expression__expression_gtp_encap_0_register_2;

        /* primitive body */
        //expression _expression_gtp_encap_0: ((((inner_ipv4.len) + (0x0010))) & (0xffff))
        {
        unsigned int pif_expression__expression_gtp_encap_0_register_0;
        unsigned int pif_expression__expression_gtp_encap_0_register_1;
        //subexpression 4: 0x0010
        // constant : 0x10

        //subexpression 1: (inner_ipv4.len)+(0x0010)
        pif_expression__expression_gtp_encap_0_register_1 = inner_ipv4->len;
        pif_expression__expression_gtp_encap_0_register_2 = 0x10;
        pif_expression__expression_gtp_encap_0_register_0 = pif_expression__expression_gtp_encap_0_register_1 + pif_expression__expression_gtp_encap_0_register_2;
        pif_expression__expression_gtp_encap_0_register_0 &= 0xffff;
        //subexpression 2: 0xffff
        // constant : 0xffff

        //subexpression 0: (((inner_ipv4.len)+(0x0010)))&(0xffff)
        pif_expression__expression_gtp_encap_0_register_1 = 0xffff;
        pif_expression__expression_gtp_encap_0_register_2 = pif_expression__expression_gtp_encap_0_register_0 & pif_expression__expression_gtp_encap_0_register_1;
        }

        udp->len = pif_expression__expression_gtp_encap_0_register_2;

    }
    {
        /* modify_field(udp.checksum,0x0000) */

        /* primitive body */
        udp->checksum = 0x0;

    }
    {
        /* modify_field(ipv4.version,0x04) */

        /* primitive body */
        ipv4->version = 0x4;

    }
    {
        /* modify_field(ipv4.ihl,0x05) */

        /* primitive body */
        ipv4->ihl = 0x5;

    }
    {
        /* modify_field(ipv4.dscp,0x00) */

        /* primitive body */
        ipv4->dscp = 0x0;

    }
    {
        /* modify_field(ipv4.len,_expression_gtp_encap_1) */
        unsigned int pif_expression__expression_gtp_encap_1_register_2;

        /* primitive body */
        //expression _expression_gtp_encap_1: ((((inner_ipv4.len) + (0x0024))) & (0xffff))
        {
        unsigned int pif_expression__expression_gtp_encap_1_register_0;
        unsigned int pif_expression__expression_gtp_encap_1_register_1;
        //subexpression 4: 0x0024
        // constant : 0x24

        //subexpression 1: (inner_ipv4.len)+(0x0024)
        pif_expression__expression_gtp_encap_1_register_1 = inner_ipv4->len;
        pif_expression__expression_gtp_encap_1_register_2 = 0x24;
        pif_expression__expression_gtp_encap_1_register_0 = pif_expression__expression_gtp_encap_1_register_1 + pif_expression__expression_gtp_encap_1_register_2;
        pif_expression__expression_gtp_encap_1_register_0 &= 0xffff;
        //subexpression 2: 0xffff
        // constant : 0xffff

        //subexpression 0: (((inner_ipv4.len)+(0x0024)))&(0xffff)
        pif_expression__expression_gtp_encap_1_register_1 = 0xffff;
        pif_expression__expression_gtp_encap_1_register_2 = pif_expression__expression_gtp_encap_1_register_0 & pif_expression__expression_gtp_encap_1_register_1;
        }

        ipv4->len = pif_expression__expression_gtp_encap_1_register_2;

    }
    {
        /* modify_field(ipv4.identification,0x1513) */

        /* primitive body */
        ipv4->identification = 0x1513;

    }
    {
        /* modify_field(ipv4.flags,0x00) */

        /* primitive body */
        ipv4->flags = 0x0;

    }
    {
        /* modify_field(ipv4.frag_offset,0x0000) */

        /* primitive body */
        ipv4->frag_offset = 0x0;

    }
    {
        /* modify_field(ipv4.ttl,0x40) */

        /* primitive body */
        ipv4->ttl = 0x40;

    }
    {
        /* modify_field(ipv4.protocol,0x11) */

        /* primitive body */
        ipv4->protocol = 0x11;

    }
    {
        /* modify_field(ipv4.src_addr,upf_ip) */

        /* primitive body */
        ipv4->src_addr = _pif_act_data->upf_ip;

    }
    {
        /* modify_field(ipv4.dst_addr,ran_ip) */

        /* primitive body */
        ipv4->dst_addr = _pif_act_data->ran_ip;

    }
    {
        /* modify_field(ipv4.hdr_checksum,0x0000) */

        /* primitive body */
        ipv4->hdr_checksum = 0x0;

    }
    return _pif_return;
}

static int pif_action_exec_ingress__set_src_intf(__lmem uint32_t *_pif_parrep, __xread uint32_t *_pif_actdatabuf, unsigned _pif_debug)
{
    int _pif_return = PIF_RETURN_FORWARD;
    __xread struct pif_action_actiondata_ingress__set_src_intf *_pif_act_data = (__xread struct pif_action_actiondata_ingress__set_src_intf *)_pif_actdatabuf;
    __lmem struct pif_parrep_ctldata *_pif_ctldata = (__lmem struct pif_parrep_ctldata *)(_pif_parrep + PIF_PARREP_CTLDATA_OFF_LW);
    __lmem struct pif_header_ethernet *ethernet;
    __lmem struct pif_header_standard_metadata *standard_metadata;
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

    ethernet = (__lmem struct pif_header_ethernet *) (_pif_parrep + PIF_PARREP_ethernet_OFF_LW);
    standard_metadata = (__lmem struct pif_header_standard_metadata *) (_pif_parrep + PIF_PARREP_standard_metadata_OFF_LW);
    scalars = (__lmem struct pif_header_scalars *) (_pif_parrep + PIF_PARREP_scalars_OFF_LW);
    PIF_PARREP_SET_ethernet_DIRTY(_pif_ctldata);

    {
        /* modify_field(scalars.metadata_t@intf,src_intf) */

        /* primitive body */
        scalars->metadata_t__intf = _pif_act_data->src_intf;

    }
    {
        /* modify_field(ethernet.src_addr,src_mac) */

        /* primitive body */
        ethernet->src_addr = ((_pif_act_data->src_mac_1 >> 16) & 0xffff);
        ethernet->__src_addr_1 = ((_pif_act_data->src_mac_1 & 0xffff) << 16) | _pif_act_data->src_mac_0;

    }
    {
        /* modify_field(ethernet.dst_addr,dst_mac) */

        /* primitive body */
        ethernet->dst_addr = _pif_act_data->dst_mac_1;
        ethernet->__dst_addr_1 = _pif_act_data->dst_mac_0;

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
    case PIF_ACTION_ID_ingress__gtp_encap:
        ret = pif_action_exec_ingress__gtp_encap(parrep, _actdata + PIF_ACTION_OPDATA_LW, opdata->dbg_flags);
        break;
    case PIF_ACTION_ID_ingress__set_src_intf:
        ret = pif_action_exec_ingress__set_src_intf(parrep, _actdata + PIF_ACTION_OPDATA_LW, opdata->dbg_flags);
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
