/* Copyright (C) 2015-2016,  Netronome Systems, Inc.  All rights reserved. */

#ifndef __PIF_PLUGIN_metadata_H__
#define __PIF_PLUGIN_metadata_H__
/*
 * Access function prototypes
 */

/* get bg_md.far_id */
uint32_t pif_plugin_meta_get__bg_md__far_id(EXTRACTED_HEADERS_T *extracted_headers);

/* set bg_md.far_id */
void pif_plugin_meta_set__bg_md__far_id(EXTRACTED_HEADERS_T *extracted_headers, uint32_t val);

/* get bg_md.qer_id */
uint32_t pif_plugin_meta_get__bg_md__qer_id(EXTRACTED_HEADERS_T *extracted_headers);

/* set bg_md.qer_id */
void pif_plugin_meta_set__bg_md__qer_id(EXTRACTED_HEADERS_T *extracted_headers, uint32_t val);

/* get bg_md.encap_flag */
uint32_t pif_plugin_meta_get__bg_md__encap_flag(EXTRACTED_HEADERS_T *extracted_headers);

/* set bg_md.encap_flag */
void pif_plugin_meta_set__bg_md__encap_flag(EXTRACTED_HEADERS_T *extracted_headers, uint32_t val);

/* get bg_md.intf */
uint32_t pif_plugin_meta_get__bg_md__intf(EXTRACTED_HEADERS_T *extracted_headers);

/* set bg_md.intf */
void pif_plugin_meta_set__bg_md__intf(EXTRACTED_HEADERS_T *extracted_headers, uint32_t val);

/* get bg_md.bypass_modify_mac */
uint32_t pif_plugin_meta_get__bg_md__bypass_modify_mac(EXTRACTED_HEADERS_T *extracted_headers);

/* set bg_md.bypass_modify_mac */
void pif_plugin_meta_set__bg_md__bypass_modify_mac(EXTRACTED_HEADERS_T *extracted_headers, uint32_t val);

/* get bg_md._pad */
uint32_t pif_plugin_meta_get__bg_md___pad(EXTRACTED_HEADERS_T *extracted_headers);

/* set bg_md._pad */
void pif_plugin_meta_set__bg_md___pad(EXTRACTED_HEADERS_T *extracted_headers, uint32_t val);

/* get bg_md.qfi */
uint32_t pif_plugin_meta_get__bg_md__qfi(EXTRACTED_HEADERS_T *extracted_headers);

/* set bg_md.qfi */
void pif_plugin_meta_set__bg_md__qfi(EXTRACTED_HEADERS_T *extracted_headers, uint32_t val);

/* get standard_metadata.clone_spec */
uint32_t pif_plugin_meta_get__standard_metadata__clone_spec(EXTRACTED_HEADERS_T *extracted_headers);

/* set standard_metadata.clone_spec */
void pif_plugin_meta_set__standard_metadata__clone_spec(EXTRACTED_HEADERS_T *extracted_headers, uint32_t val);

/* get standard_metadata.egress_spec */
uint32_t pif_plugin_meta_get__standard_metadata__egress_spec(EXTRACTED_HEADERS_T *extracted_headers);

/* set standard_metadata.egress_spec */
void pif_plugin_meta_set__standard_metadata__egress_spec(EXTRACTED_HEADERS_T *extracted_headers, uint32_t val);

/* get standard_metadata.egress_port */
uint32_t pif_plugin_meta_get__standard_metadata__egress_port(EXTRACTED_HEADERS_T *extracted_headers);

/* set standard_metadata.egress_port */
void pif_plugin_meta_set__standard_metadata__egress_port(EXTRACTED_HEADERS_T *extracted_headers, uint32_t val);

/* get standard_metadata.ingress_port */
uint32_t pif_plugin_meta_get__standard_metadata__ingress_port(EXTRACTED_HEADERS_T *extracted_headers);

/* set standard_metadata.ingress_port */
void pif_plugin_meta_set__standard_metadata__ingress_port(EXTRACTED_HEADERS_T *extracted_headers, uint32_t val);

/* get standard_metadata.packet_length */
uint32_t pif_plugin_meta_get__standard_metadata__packet_length(EXTRACTED_HEADERS_T *extracted_headers);

/* set standard_metadata.packet_length */
void pif_plugin_meta_set__standard_metadata__packet_length(EXTRACTED_HEADERS_T *extracted_headers, uint32_t val);

/* get standard_metadata.checksum_error */
uint32_t pif_plugin_meta_get__standard_metadata__checksum_error(EXTRACTED_HEADERS_T *extracted_headers);

/* set standard_metadata.checksum_error */
void pif_plugin_meta_set__standard_metadata__checksum_error(EXTRACTED_HEADERS_T *extracted_headers, uint32_t val);

/* get standard_metadata.egress_instance */
uint32_t pif_plugin_meta_get__standard_metadata__egress_instance(EXTRACTED_HEADERS_T *extracted_headers);

/* set standard_metadata.egress_instance */
void pif_plugin_meta_set__standard_metadata__egress_instance(EXTRACTED_HEADERS_T *extracted_headers, uint32_t val);

/* get standard_metadata.parser_error_location */
uint32_t pif_plugin_meta_get__standard_metadata__parser_error_location(EXTRACTED_HEADERS_T *extracted_headers);

/* set standard_metadata.parser_error_location */
void pif_plugin_meta_set__standard_metadata__parser_error_location(EXTRACTED_HEADERS_T *extracted_headers, uint32_t val);

/* get standard_metadata.instance_type */
uint32_t pif_plugin_meta_get__standard_metadata__instance_type(EXTRACTED_HEADERS_T *extracted_headers);

/* set standard_metadata.instance_type */
void pif_plugin_meta_set__standard_metadata__instance_type(EXTRACTED_HEADERS_T *extracted_headers, uint32_t val);

/* get standard_metadata.parser_status */
uint32_t pif_plugin_meta_get__standard_metadata__parser_status(EXTRACTED_HEADERS_T *extracted_headers);

/* set standard_metadata.parser_status */
void pif_plugin_meta_set__standard_metadata__parser_status(EXTRACTED_HEADERS_T *extracted_headers, uint32_t val);

/* get scalars.metadata_t@far_id */
uint32_t pif_plugin_meta_get__scalars__metadata_t__far_id(EXTRACTED_HEADERS_T *extracted_headers);

/* set scalars.metadata_t@far_id */
void pif_plugin_meta_set__scalars__metadata_t__far_id(EXTRACTED_HEADERS_T *extracted_headers, uint32_t val);

/* get scalars.metadata_t@l4_inner_src_port */
uint32_t pif_plugin_meta_get__scalars__metadata_t__l4_inner_src_port(EXTRACTED_HEADERS_T *extracted_headers);

/* set scalars.metadata_t@l4_inner_src_port */
void pif_plugin_meta_set__scalars__metadata_t__l4_inner_src_port(EXTRACTED_HEADERS_T *extracted_headers, uint32_t val);

/* get scalars.metadata_t@l4_inner_dst_port */
uint32_t pif_plugin_meta_get__scalars__metadata_t__l4_inner_dst_port(EXTRACTED_HEADERS_T *extracted_headers);

/* set scalars.metadata_t@l4_inner_dst_port */
void pif_plugin_meta_set__scalars__metadata_t__l4_inner_dst_port(EXTRACTED_HEADERS_T *extracted_headers, uint32_t val);

/* get scalars.metadata_t@l4_src_port */
uint32_t pif_plugin_meta_get__scalars__metadata_t__l4_src_port(EXTRACTED_HEADERS_T *extracted_headers);

/* set scalars.metadata_t@l4_src_port */
void pif_plugin_meta_set__scalars__metadata_t__l4_src_port(EXTRACTED_HEADERS_T *extracted_headers, uint32_t val);

/* get scalars.metadata_t@l4_dst_port */
uint32_t pif_plugin_meta_get__scalars__metadata_t__l4_dst_port(EXTRACTED_HEADERS_T *extracted_headers);

/* set scalars.metadata_t@l4_dst_port */
void pif_plugin_meta_set__scalars__metadata_t__l4_dst_port(EXTRACTED_HEADERS_T *extracted_headers, uint32_t val);

/* get scalars.metadata_t@qfi */
uint32_t pif_plugin_meta_get__scalars__metadata_t__qfi(EXTRACTED_HEADERS_T *extracted_headers);

/* set scalars.metadata_t@qfi */
void pif_plugin_meta_set__scalars__metadata_t__qfi(EXTRACTED_HEADERS_T *extracted_headers, uint32_t val);

/* get scalars.metadata_t@intf */
uint32_t pif_plugin_meta_get__scalars__metadata_t__intf(EXTRACTED_HEADERS_T *extracted_headers);

/* set scalars.metadata_t@intf */
void pif_plugin_meta_set__scalars__metadata_t__intf(EXTRACTED_HEADERS_T *extracted_headers, uint32_t val);

/* get scalars.metadata_t@bypass_modify_mac */
uint32_t pif_plugin_meta_get__scalars__metadata_t__bypass_modify_mac(EXTRACTED_HEADERS_T *extracted_headers);

/* set scalars.metadata_t@bypass_modify_mac */
void pif_plugin_meta_set__scalars__metadata_t__bypass_modify_mac(EXTRACTED_HEADERS_T *extracted_headers, uint32_t val);

/* get scalars.metadata_t@decap_flag */
uint32_t pif_plugin_meta_get__scalars__metadata_t__decap_flag(EXTRACTED_HEADERS_T *extracted_headers);

/* set scalars.metadata_t@decap_flag */
void pif_plugin_meta_set__scalars__metadata_t__decap_flag(EXTRACTED_HEADERS_T *extracted_headers, uint32_t val);

/* get scalars.metadata_t@encap_flag */
uint32_t pif_plugin_meta_get__scalars__metadata_t__encap_flag(EXTRACTED_HEADERS_T *extracted_headers);

/* set scalars.metadata_t@encap_flag */
void pif_plugin_meta_set__scalars__metadata_t__encap_flag(EXTRACTED_HEADERS_T *extracted_headers, uint32_t val);






/*
 * Access function implementations
 */

#include "pif_parrep.h"
#include "pif_headers.h"

__forceinline uint32_t pif_plugin_meta_get__bg_md__far_id(EXTRACTED_HEADERS_T *extracted_headers)
{
    __lmem struct pif_header_bg_md *md = (__lmem struct pif_header_bg_md *)(((__lmem uint32_t *)extracted_headers) + PIF_PARREP_bg_md_OFF_LW);
    return PIF_HEADER_GET_bg_md___far_id(md);
}

__forceinline void pif_plugin_meta_set__bg_md__far_id(EXTRACTED_HEADERS_T *extracted_headers,uint32_t val)
{
    __lmem struct pif_header_bg_md *md = (__lmem struct pif_header_bg_md *)(((__lmem uint32_t *)extracted_headers) + PIF_PARREP_bg_md_OFF_LW);
    PIF_HEADER_SET_bg_md___far_id(md, val);
}

__forceinline uint32_t pif_plugin_meta_get__bg_md__qer_id(EXTRACTED_HEADERS_T *extracted_headers)
{
    __lmem struct pif_header_bg_md *md = (__lmem struct pif_header_bg_md *)(((__lmem uint32_t *)extracted_headers) + PIF_PARREP_bg_md_OFF_LW);
    return PIF_HEADER_GET_bg_md___qer_id(md);
}

__forceinline void pif_plugin_meta_set__bg_md__qer_id(EXTRACTED_HEADERS_T *extracted_headers,uint32_t val)
{
    __lmem struct pif_header_bg_md *md = (__lmem struct pif_header_bg_md *)(((__lmem uint32_t *)extracted_headers) + PIF_PARREP_bg_md_OFF_LW);
    PIF_HEADER_SET_bg_md___qer_id(md, val);
}

__forceinline uint32_t pif_plugin_meta_get__bg_md__encap_flag(EXTRACTED_HEADERS_T *extracted_headers)
{
    __lmem struct pif_header_bg_md *md = (__lmem struct pif_header_bg_md *)(((__lmem uint32_t *)extracted_headers) + PIF_PARREP_bg_md_OFF_LW);
    return PIF_HEADER_GET_bg_md___encap_flag(md);
}

__forceinline void pif_plugin_meta_set__bg_md__encap_flag(EXTRACTED_HEADERS_T *extracted_headers,uint32_t val)
{
    __lmem struct pif_header_bg_md *md = (__lmem struct pif_header_bg_md *)(((__lmem uint32_t *)extracted_headers) + PIF_PARREP_bg_md_OFF_LW);
    PIF_HEADER_SET_bg_md___encap_flag(md, val);
}

__forceinline uint32_t pif_plugin_meta_get__bg_md__intf(EXTRACTED_HEADERS_T *extracted_headers)
{
    __lmem struct pif_header_bg_md *md = (__lmem struct pif_header_bg_md *)(((__lmem uint32_t *)extracted_headers) + PIF_PARREP_bg_md_OFF_LW);
    return PIF_HEADER_GET_bg_md___intf(md);
}

__forceinline void pif_plugin_meta_set__bg_md__intf(EXTRACTED_HEADERS_T *extracted_headers,uint32_t val)
{
    __lmem struct pif_header_bg_md *md = (__lmem struct pif_header_bg_md *)(((__lmem uint32_t *)extracted_headers) + PIF_PARREP_bg_md_OFF_LW);
    PIF_HEADER_SET_bg_md___intf(md, val);
}

__forceinline uint32_t pif_plugin_meta_get__bg_md__bypass_modify_mac(EXTRACTED_HEADERS_T *extracted_headers)
{
    __lmem struct pif_header_bg_md *md = (__lmem struct pif_header_bg_md *)(((__lmem uint32_t *)extracted_headers) + PIF_PARREP_bg_md_OFF_LW);
    return PIF_HEADER_GET_bg_md___bypass_modify_mac(md);
}

__forceinline void pif_plugin_meta_set__bg_md__bypass_modify_mac(EXTRACTED_HEADERS_T *extracted_headers,uint32_t val)
{
    __lmem struct pif_header_bg_md *md = (__lmem struct pif_header_bg_md *)(((__lmem uint32_t *)extracted_headers) + PIF_PARREP_bg_md_OFF_LW);
    PIF_HEADER_SET_bg_md___bypass_modify_mac(md, val);
}

__forceinline uint32_t pif_plugin_meta_get__bg_md___pad(EXTRACTED_HEADERS_T *extracted_headers)
{
    __lmem struct pif_header_bg_md *md = (__lmem struct pif_header_bg_md *)(((__lmem uint32_t *)extracted_headers) + PIF_PARREP_bg_md_OFF_LW);
    return PIF_HEADER_GET_bg_md____pad(md);
}

__forceinline void pif_plugin_meta_set__bg_md___pad(EXTRACTED_HEADERS_T *extracted_headers,uint32_t val)
{
    __lmem struct pif_header_bg_md *md = (__lmem struct pif_header_bg_md *)(((__lmem uint32_t *)extracted_headers) + PIF_PARREP_bg_md_OFF_LW);
    PIF_HEADER_SET_bg_md____pad(md, val);
}

__forceinline uint32_t pif_plugin_meta_get__bg_md__qfi(EXTRACTED_HEADERS_T *extracted_headers)
{
    __lmem struct pif_header_bg_md *md = (__lmem struct pif_header_bg_md *)(((__lmem uint32_t *)extracted_headers) + PIF_PARREP_bg_md_OFF_LW);
    return PIF_HEADER_GET_bg_md___qfi(md);
}

__forceinline void pif_plugin_meta_set__bg_md__qfi(EXTRACTED_HEADERS_T *extracted_headers,uint32_t val)
{
    __lmem struct pif_header_bg_md *md = (__lmem struct pif_header_bg_md *)(((__lmem uint32_t *)extracted_headers) + PIF_PARREP_bg_md_OFF_LW);
    PIF_HEADER_SET_bg_md___qfi(md, val);
}

__forceinline uint32_t pif_plugin_meta_get__standard_metadata__clone_spec(EXTRACTED_HEADERS_T *extracted_headers)
{
    __lmem struct pif_header_standard_metadata *md = (__lmem struct pif_header_standard_metadata *)(((__lmem uint32_t *)extracted_headers) + PIF_PARREP_standard_metadata_OFF_LW);
    return PIF_HEADER_GET_standard_metadata___clone_spec(md);
}

__forceinline void pif_plugin_meta_set__standard_metadata__clone_spec(EXTRACTED_HEADERS_T *extracted_headers,uint32_t val)
{
    __lmem struct pif_header_standard_metadata *md = (__lmem struct pif_header_standard_metadata *)(((__lmem uint32_t *)extracted_headers) + PIF_PARREP_standard_metadata_OFF_LW);
    PIF_HEADER_SET_standard_metadata___clone_spec(md, val);
}

__forceinline uint32_t pif_plugin_meta_get__standard_metadata__egress_spec(EXTRACTED_HEADERS_T *extracted_headers)
{
    __lmem struct pif_header_standard_metadata *md = (__lmem struct pif_header_standard_metadata *)(((__lmem uint32_t *)extracted_headers) + PIF_PARREP_standard_metadata_OFF_LW);
    return PIF_HEADER_GET_standard_metadata___egress_spec(md);
}

__forceinline void pif_plugin_meta_set__standard_metadata__egress_spec(EXTRACTED_HEADERS_T *extracted_headers,uint32_t val)
{
    __lmem struct pif_header_standard_metadata *md = (__lmem struct pif_header_standard_metadata *)(((__lmem uint32_t *)extracted_headers) + PIF_PARREP_standard_metadata_OFF_LW);
    PIF_HEADER_SET_standard_metadata___egress_spec(md, val);
}

__forceinline uint32_t pif_plugin_meta_get__standard_metadata__egress_port(EXTRACTED_HEADERS_T *extracted_headers)
{
    __lmem struct pif_header_standard_metadata *md = (__lmem struct pif_header_standard_metadata *)(((__lmem uint32_t *)extracted_headers) + PIF_PARREP_standard_metadata_OFF_LW);
    return PIF_HEADER_GET_standard_metadata___egress_port(md);
}

__forceinline void pif_plugin_meta_set__standard_metadata__egress_port(EXTRACTED_HEADERS_T *extracted_headers,uint32_t val)
{
    __lmem struct pif_header_standard_metadata *md = (__lmem struct pif_header_standard_metadata *)(((__lmem uint32_t *)extracted_headers) + PIF_PARREP_standard_metadata_OFF_LW);
    PIF_HEADER_SET_standard_metadata___egress_port(md, val);
}

__forceinline uint32_t pif_plugin_meta_get__standard_metadata__ingress_port(EXTRACTED_HEADERS_T *extracted_headers)
{
    __lmem struct pif_header_standard_metadata *md = (__lmem struct pif_header_standard_metadata *)(((__lmem uint32_t *)extracted_headers) + PIF_PARREP_standard_metadata_OFF_LW);
    return PIF_HEADER_GET_standard_metadata___ingress_port(md);
}

__forceinline void pif_plugin_meta_set__standard_metadata__ingress_port(EXTRACTED_HEADERS_T *extracted_headers,uint32_t val)
{
    __lmem struct pif_header_standard_metadata *md = (__lmem struct pif_header_standard_metadata *)(((__lmem uint32_t *)extracted_headers) + PIF_PARREP_standard_metadata_OFF_LW);
    PIF_HEADER_SET_standard_metadata___ingress_port(md, val);
}

__forceinline uint32_t pif_plugin_meta_get__standard_metadata__packet_length(EXTRACTED_HEADERS_T *extracted_headers)
{
    __lmem struct pif_header_standard_metadata *md = (__lmem struct pif_header_standard_metadata *)(((__lmem uint32_t *)extracted_headers) + PIF_PARREP_standard_metadata_OFF_LW);
    return PIF_HEADER_GET_standard_metadata___packet_length(md);
}

__forceinline void pif_plugin_meta_set__standard_metadata__packet_length(EXTRACTED_HEADERS_T *extracted_headers,uint32_t val)
{
    __lmem struct pif_header_standard_metadata *md = (__lmem struct pif_header_standard_metadata *)(((__lmem uint32_t *)extracted_headers) + PIF_PARREP_standard_metadata_OFF_LW);
    PIF_HEADER_SET_standard_metadata___packet_length(md, val);
}

__forceinline uint32_t pif_plugin_meta_get__standard_metadata__checksum_error(EXTRACTED_HEADERS_T *extracted_headers)
{
    __lmem struct pif_header_standard_metadata *md = (__lmem struct pif_header_standard_metadata *)(((__lmem uint32_t *)extracted_headers) + PIF_PARREP_standard_metadata_OFF_LW);
    return PIF_HEADER_GET_standard_metadata___checksum_error(md);
}

__forceinline void pif_plugin_meta_set__standard_metadata__checksum_error(EXTRACTED_HEADERS_T *extracted_headers,uint32_t val)
{
    __lmem struct pif_header_standard_metadata *md = (__lmem struct pif_header_standard_metadata *)(((__lmem uint32_t *)extracted_headers) + PIF_PARREP_standard_metadata_OFF_LW);
    PIF_HEADER_SET_standard_metadata___checksum_error(md, val);
}

__forceinline uint32_t pif_plugin_meta_get__standard_metadata__egress_instance(EXTRACTED_HEADERS_T *extracted_headers)
{
    __lmem struct pif_header_standard_metadata *md = (__lmem struct pif_header_standard_metadata *)(((__lmem uint32_t *)extracted_headers) + PIF_PARREP_standard_metadata_OFF_LW);
    return PIF_HEADER_GET_standard_metadata___egress_instance(md);
}

__forceinline void pif_plugin_meta_set__standard_metadata__egress_instance(EXTRACTED_HEADERS_T *extracted_headers,uint32_t val)
{
    __lmem struct pif_header_standard_metadata *md = (__lmem struct pif_header_standard_metadata *)(((__lmem uint32_t *)extracted_headers) + PIF_PARREP_standard_metadata_OFF_LW);
    PIF_HEADER_SET_standard_metadata___egress_instance(md, val);
}

__forceinline uint32_t pif_plugin_meta_get__standard_metadata__parser_error_location(EXTRACTED_HEADERS_T *extracted_headers)
{
    __lmem struct pif_header_standard_metadata *md = (__lmem struct pif_header_standard_metadata *)(((__lmem uint32_t *)extracted_headers) + PIF_PARREP_standard_metadata_OFF_LW);
    return PIF_HEADER_GET_standard_metadata___parser_error_location(md);
}

__forceinline void pif_plugin_meta_set__standard_metadata__parser_error_location(EXTRACTED_HEADERS_T *extracted_headers,uint32_t val)
{
    __lmem struct pif_header_standard_metadata *md = (__lmem struct pif_header_standard_metadata *)(((__lmem uint32_t *)extracted_headers) + PIF_PARREP_standard_metadata_OFF_LW);
    PIF_HEADER_SET_standard_metadata___parser_error_location(md, val);
}

__forceinline uint32_t pif_plugin_meta_get__standard_metadata__instance_type(EXTRACTED_HEADERS_T *extracted_headers)
{
    __lmem struct pif_header_standard_metadata *md = (__lmem struct pif_header_standard_metadata *)(((__lmem uint32_t *)extracted_headers) + PIF_PARREP_standard_metadata_OFF_LW);
    return PIF_HEADER_GET_standard_metadata___instance_type(md);
}

__forceinline void pif_plugin_meta_set__standard_metadata__instance_type(EXTRACTED_HEADERS_T *extracted_headers,uint32_t val)
{
    __lmem struct pif_header_standard_metadata *md = (__lmem struct pif_header_standard_metadata *)(((__lmem uint32_t *)extracted_headers) + PIF_PARREP_standard_metadata_OFF_LW);
    PIF_HEADER_SET_standard_metadata___instance_type(md, val);
}

__forceinline uint32_t pif_plugin_meta_get__standard_metadata__parser_status(EXTRACTED_HEADERS_T *extracted_headers)
{
    __lmem struct pif_header_standard_metadata *md = (__lmem struct pif_header_standard_metadata *)(((__lmem uint32_t *)extracted_headers) + PIF_PARREP_standard_metadata_OFF_LW);
    return PIF_HEADER_GET_standard_metadata___parser_status(md);
}

__forceinline void pif_plugin_meta_set__standard_metadata__parser_status(EXTRACTED_HEADERS_T *extracted_headers,uint32_t val)
{
    __lmem struct pif_header_standard_metadata *md = (__lmem struct pif_header_standard_metadata *)(((__lmem uint32_t *)extracted_headers) + PIF_PARREP_standard_metadata_OFF_LW);
    PIF_HEADER_SET_standard_metadata___parser_status(md, val);
}

__forceinline uint32_t pif_plugin_meta_get__scalars__metadata_t__far_id(EXTRACTED_HEADERS_T *extracted_headers)
{
    __lmem struct pif_header_scalars *md = (__lmem struct pif_header_scalars *)(((__lmem uint32_t *)extracted_headers) + PIF_PARREP_scalars_OFF_LW);
    return PIF_HEADER_GET_scalars___metadata_t__far_id(md);
}

__forceinline void pif_plugin_meta_set__scalars__metadata_t__far_id(EXTRACTED_HEADERS_T *extracted_headers,uint32_t val)
{
    __lmem struct pif_header_scalars *md = (__lmem struct pif_header_scalars *)(((__lmem uint32_t *)extracted_headers) + PIF_PARREP_scalars_OFF_LW);
    PIF_HEADER_SET_scalars___metadata_t__far_id(md, val);
}

__forceinline uint32_t pif_plugin_meta_get__scalars__metadata_t__l4_inner_src_port(EXTRACTED_HEADERS_T *extracted_headers)
{
    __lmem struct pif_header_scalars *md = (__lmem struct pif_header_scalars *)(((__lmem uint32_t *)extracted_headers) + PIF_PARREP_scalars_OFF_LW);
    return PIF_HEADER_GET_scalars___metadata_t__l4_inner_src_port(md);
}

__forceinline void pif_plugin_meta_set__scalars__metadata_t__l4_inner_src_port(EXTRACTED_HEADERS_T *extracted_headers,uint32_t val)
{
    __lmem struct pif_header_scalars *md = (__lmem struct pif_header_scalars *)(((__lmem uint32_t *)extracted_headers) + PIF_PARREP_scalars_OFF_LW);
    PIF_HEADER_SET_scalars___metadata_t__l4_inner_src_port(md, val);
}

__forceinline uint32_t pif_plugin_meta_get__scalars__metadata_t__l4_inner_dst_port(EXTRACTED_HEADERS_T *extracted_headers)
{
    __lmem struct pif_header_scalars *md = (__lmem struct pif_header_scalars *)(((__lmem uint32_t *)extracted_headers) + PIF_PARREP_scalars_OFF_LW);
    return PIF_HEADER_GET_scalars___metadata_t__l4_inner_dst_port(md);
}

__forceinline void pif_plugin_meta_set__scalars__metadata_t__l4_inner_dst_port(EXTRACTED_HEADERS_T *extracted_headers,uint32_t val)
{
    __lmem struct pif_header_scalars *md = (__lmem struct pif_header_scalars *)(((__lmem uint32_t *)extracted_headers) + PIF_PARREP_scalars_OFF_LW);
    PIF_HEADER_SET_scalars___metadata_t__l4_inner_dst_port(md, val);
}

__forceinline uint32_t pif_plugin_meta_get__scalars__metadata_t__l4_src_port(EXTRACTED_HEADERS_T *extracted_headers)
{
    __lmem struct pif_header_scalars *md = (__lmem struct pif_header_scalars *)(((__lmem uint32_t *)extracted_headers) + PIF_PARREP_scalars_OFF_LW);
    return PIF_HEADER_GET_scalars___metadata_t__l4_src_port(md);
}

__forceinline void pif_plugin_meta_set__scalars__metadata_t__l4_src_port(EXTRACTED_HEADERS_T *extracted_headers,uint32_t val)
{
    __lmem struct pif_header_scalars *md = (__lmem struct pif_header_scalars *)(((__lmem uint32_t *)extracted_headers) + PIF_PARREP_scalars_OFF_LW);
    PIF_HEADER_SET_scalars___metadata_t__l4_src_port(md, val);
}

__forceinline uint32_t pif_plugin_meta_get__scalars__metadata_t__l4_dst_port(EXTRACTED_HEADERS_T *extracted_headers)
{
    __lmem struct pif_header_scalars *md = (__lmem struct pif_header_scalars *)(((__lmem uint32_t *)extracted_headers) + PIF_PARREP_scalars_OFF_LW);
    return PIF_HEADER_GET_scalars___metadata_t__l4_dst_port(md);
}

__forceinline void pif_plugin_meta_set__scalars__metadata_t__l4_dst_port(EXTRACTED_HEADERS_T *extracted_headers,uint32_t val)
{
    __lmem struct pif_header_scalars *md = (__lmem struct pif_header_scalars *)(((__lmem uint32_t *)extracted_headers) + PIF_PARREP_scalars_OFF_LW);
    PIF_HEADER_SET_scalars___metadata_t__l4_dst_port(md, val);
}

__forceinline uint32_t pif_plugin_meta_get__scalars__metadata_t__qfi(EXTRACTED_HEADERS_T *extracted_headers)
{
    __lmem struct pif_header_scalars *md = (__lmem struct pif_header_scalars *)(((__lmem uint32_t *)extracted_headers) + PIF_PARREP_scalars_OFF_LW);
    return PIF_HEADER_GET_scalars___metadata_t__qfi(md);
}

__forceinline void pif_plugin_meta_set__scalars__metadata_t__qfi(EXTRACTED_HEADERS_T *extracted_headers,uint32_t val)
{
    __lmem struct pif_header_scalars *md = (__lmem struct pif_header_scalars *)(((__lmem uint32_t *)extracted_headers) + PIF_PARREP_scalars_OFF_LW);
    PIF_HEADER_SET_scalars___metadata_t__qfi(md, val);
}

__forceinline uint32_t pif_plugin_meta_get__scalars__metadata_t__intf(EXTRACTED_HEADERS_T *extracted_headers)
{
    __lmem struct pif_header_scalars *md = (__lmem struct pif_header_scalars *)(((__lmem uint32_t *)extracted_headers) + PIF_PARREP_scalars_OFF_LW);
    return PIF_HEADER_GET_scalars___metadata_t__intf(md);
}

__forceinline void pif_plugin_meta_set__scalars__metadata_t__intf(EXTRACTED_HEADERS_T *extracted_headers,uint32_t val)
{
    __lmem struct pif_header_scalars *md = (__lmem struct pif_header_scalars *)(((__lmem uint32_t *)extracted_headers) + PIF_PARREP_scalars_OFF_LW);
    PIF_HEADER_SET_scalars___metadata_t__intf(md, val);
}

__forceinline uint32_t pif_plugin_meta_get__scalars__metadata_t__bypass_modify_mac(EXTRACTED_HEADERS_T *extracted_headers)
{
    __lmem struct pif_header_scalars *md = (__lmem struct pif_header_scalars *)(((__lmem uint32_t *)extracted_headers) + PIF_PARREP_scalars_OFF_LW);
    return PIF_HEADER_GET_scalars___metadata_t__bypass_modify_mac(md);
}

__forceinline void pif_plugin_meta_set__scalars__metadata_t__bypass_modify_mac(EXTRACTED_HEADERS_T *extracted_headers,uint32_t val)
{
    __lmem struct pif_header_scalars *md = (__lmem struct pif_header_scalars *)(((__lmem uint32_t *)extracted_headers) + PIF_PARREP_scalars_OFF_LW);
    PIF_HEADER_SET_scalars___metadata_t__bypass_modify_mac(md, val);
}

__forceinline uint32_t pif_plugin_meta_get__scalars__metadata_t__decap_flag(EXTRACTED_HEADERS_T *extracted_headers)
{
    __lmem struct pif_header_scalars *md = (__lmem struct pif_header_scalars *)(((__lmem uint32_t *)extracted_headers) + PIF_PARREP_scalars_OFF_LW);
    return PIF_HEADER_GET_scalars___metadata_t__decap_flag(md);
}

__forceinline void pif_plugin_meta_set__scalars__metadata_t__decap_flag(EXTRACTED_HEADERS_T *extracted_headers,uint32_t val)
{
    __lmem struct pif_header_scalars *md = (__lmem struct pif_header_scalars *)(((__lmem uint32_t *)extracted_headers) + PIF_PARREP_scalars_OFF_LW);
    PIF_HEADER_SET_scalars___metadata_t__decap_flag(md, val);
}

__forceinline uint32_t pif_plugin_meta_get__scalars__metadata_t__encap_flag(EXTRACTED_HEADERS_T *extracted_headers)
{
    __lmem struct pif_header_scalars *md = (__lmem struct pif_header_scalars *)(((__lmem uint32_t *)extracted_headers) + PIF_PARREP_scalars_OFF_LW);
    return PIF_HEADER_GET_scalars___metadata_t__encap_flag(md);
}

__forceinline void pif_plugin_meta_set__scalars__metadata_t__encap_flag(EXTRACTED_HEADERS_T *extracted_headers,uint32_t val)
{
    __lmem struct pif_header_scalars *md = (__lmem struct pif_header_scalars *)(((__lmem uint32_t *)extracted_headers) + PIF_PARREP_scalars_OFF_LW);
    PIF_HEADER_SET_scalars___metadata_t__encap_flag(md, val);
}

#endif /* __PIF_PLUGIN_metadata_H__ */
