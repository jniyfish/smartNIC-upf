/* Copyright (C) 2015-2016,  Netronome Systems, Inc.  All rights reserved. */

#ifndef __PIF_GLOBAL_H__
#define __PIF_GLOBAL_H__

#define PIF_GLOBAL_FLOWKEY_MAX_LW 6
__packed_bits struct pif_global_flowkey_metadata {
    unsigned int standard_metadata__ingress_port:16;
    unsigned int scalars__metadata_t__l4_src_port:16;
};

__packed_bits struct pif_global_flowkey_ipv4 {
    unsigned int ipv4__dst_addr:32;
    unsigned int ipv4__src_addr:32;
};

__packed_bits struct pif_global_flowkey_inner_ipv4 {
    unsigned int inner_ipv4__dst_addr:32;
    unsigned int inner_ipv4__src_addr:32;
};


void pif_global_metadata_init(__lmem uint32_t *parrep);

unsigned int pif_global_get_stdmd_egress_spec(__lmem uint32_t *parrep);
unsigned int pif_global_get_stdmd_egress_port(__lmem uint32_t *parrep);
void pif_global_set_stdmd_egress_port(__lmem uint32_t *parrep, unsigned int port_spec);
void pif_global_set_stdmd_instance_type(__lmem uint32_t *parrep, unsigned int instance_type);
void pif_global_set_stdmd_egress_instance(__lmem uint32_t *parrep, unsigned int egress_instance);
void pif_global_set_stdmd_parser_status(__lmem uint32_t *parrep, unsigned int success);
void pif_global_set_stdmd_parser_error_location(__lmem uint32_t *parrep, unsigned int node);
void pif_global_set_pktmd_nic_vlan(__lmem uint32_t *parrep);
void pif_global_get_nic_rxoffload(__lmem uint32_t *parrep);
void pif_global_set_flow_id(__lmem uint32_t *parrep, __mem __addr40 void *act_buf);
void pif_global_get_wq_metawords(__lmem uint32_t *parrep, __gpr uint32_t *mw0,  __gpr uint32_t *mw1);

#endif /* __PIF_GLOBAL_H__ */
