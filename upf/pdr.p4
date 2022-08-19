#ifndef __Pdr__
#define __Pdr__

#include "defines.p4"
#include "headers.p4"

control PdrIngress(
        inout headers_t hdr,
        inout local_metadata_t ig_md,
        in ingress_intrinsic_metadata_t ig_intr_md) {
    // A workaround for outer header removal
    action gtp_decap() {
        hdr.ipv4.setInvalid();
        // hdr.ipv6.setInvalid();
        hdr.udp.setInvalid();
        hdr.gtpu.setInvalid();
        hdr.gtpu_option.setInvalid();
        hdr.gtpu_ex.setInvalid();
    }

    action set_src_intf(bit<4> src_intf) {
        ig_md.intf = src_intf;
        src_intf_counter.count();
    }

    action set_rules(
            TYPE_FAR_ID far_id,
            // bit<32> urr_id,
            // bit<32> qer_id,
            // bit<8>  bar_id,
            bool  must_decap) {
        ig_md.far_id = far_id;
        ig_md.decap_flag = must_decap;
        pdr_ingress_counter.count();
    }

    @name(".src_intf_table")
    table src_intf_table {
        key = {
            ig_intr_md.ingress_port: exact;
        }
        actions = {
            set_src_intf;
            @defaultonly NoAction;
        }
        size = MAX_PORTS;
        const default_action = NoAction;
        counters = src_intf_counter;
    }

    // At least one of the match field must be ternary to have priority
    @name(".pdr_ingress")
    table pdr_ingress_table {
        key = {
            hdr.ipv4.src_addr:          ternary;
            hdr.ipv4.dst_addr:          ternary;
            hdr.inner_ipv4.src_addr:    ternary;
            // hdr.ipv6.src_addr:          exact;
            hdr.gtpu.teid:              ternary;
            ig_md.intf:                 exact;
        }
        actions = {
            set_rules;
            @defaultonly NoAction;
        }
        size = 24500;
        const default_action = NoAction;
        counters = pdr_ingress_counter;
    }

    apply {
        src_intf_table.apply();
        pdr_ingress_table.apply();
        if(hdr.inner_ipv4.isValid()){
            ul_sdf_filter_table.apply();
        }
        else{
            dl_sdf_filter_table.apply();
        }
        if (ig_md.decap_flag == true) {
            gtp_decap();
        }
    }
}

#endif