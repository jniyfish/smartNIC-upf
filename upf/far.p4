#ifndef __FAR__
#define __FAR__

#include "defines.p4"
#include "headers.p4"

control FarIngress(
        inout headers_t hdr,
        inout local_metadata_t ig_md,
        inout ingress_intrinsic_metadata_for_deparser_t ig_intr_dprsr_md,
        inout ingress_intrinsic_metadata_for_tm_t ig_intr_tm_md) {
    DirectCounter<bit<32>>(CounterType_t.PACKETS) far_ingress_counter;
    action set_egress_port_and_encap(PortId_t port, bool do_encap) {
        ig_intr_tm_md.ucast_egress_port = port;
        ig_intr_dprsr_md.drop_ctl = 0x0;
        ig_md.encap_flag = do_encap;
        far_ingress_counter.count();
    }

    action drop() {
        ig_intr_dprsr_md.drop_ctl = 0x1;
        far_ingress_counter.count();
    }

    @name(".far_ingress")
    table far_ingress_table {
        key = {
            ig_md.far_id:   exact;
        }

        actions = {
            set_egress_port_and_encap;
            drop;
            @defaultonly NoAction;
        }
        // size = 32768;
        size = 16384;
        const default_action = NoAction;
        counters = far_ingress_counter;
    }

    apply {
        far_ingress_table.apply();
    }
}

control FarEgress(
        inout headers_t hdr,
        inout local_metadata_t eg_md,
        in    egress_intrinsic_metadata_t eg_intr_md) {
    DirectCounter<bit<32>>(CounterType_t.PACKETS) far_egress_counter;
    DirectCounter<bit<32>>(CounterType_t.PACKETS) upf_ip_counter;
    DirectCounter<bit<32>>(CounterType_t.PACKETS) port_mac_counter;
    DirectCounter<bit<32>>(CounterType_t.PACKETS) upf_mac_counter;

    action set_gtp_ext(inout bit<6> qfi) {
        hdr.gtpu_option.setValid();
        hdr.gtpu_ex.setValid();

        hdr.gtpu.ex_flag = 1; 

        hdr.gtpu_ex.len = 1; // Assume only one extension header
        hdr.gtpu_ex.pdu_type = DL_PDU_SESSION_INFO;
        hdr.gtpu_ex.spare = 0;
        hdr.gtpu_ex.qfi = 9; // default qfi is 9

        // Currently GTP-U option field encapsulation only support PDU Session Container
        hdr.gtpu_option.seq_num = 0;
        hdr.gtpu_option.n_pdu_num = 0;
        hdr.gtpu_option.type = GTP_PDU_SES_CONT_TYPE;

        hdr.gtpu.msglen = hdr.inner_ipv4.len + (GTP_OPTION_FIELDS_SIZE + GTP_EXT_HDR_SIZE); 
        // hdr.gtpu.msglen indicates the length after TEID field

        hdr.udp.len = hdr.inner_ipv4.len + (UDP_HDR_SIZE + GTP_HDR_SIZE + GTP_OPTION_FIELDS_SIZE + GTP_EXT_HDR_SIZE);

        hdr.ipv4.len = hdr.inner_ipv4.len + (IPV4_HDR_SIZE + UDP_HDR_SIZE + GTP_HDR_SIZE + GTP_OPTION_FIELDS_SIZE + GTP_EXT_HDR_SIZE);
    }

    action gtp_encap(teid_t teid, ipv4_addr_t ran_ip) {
        hdr.ipv4.setValid();
        hdr.udp.setValid();
        hdr.gtpu.setValid();

        hdr.gtpu.version = GTPU_VERSION;
        hdr.gtpu.pt = GTP_PROTOCOL_TYPE_GTP;
        hdr.gtpu.spare = 0;
        // need to use metadata to check whether ex_flag is need to set as 0 or 1
        hdr.gtpu.ex_flag = 0; 
        // hdr.gtpu.ex_flag = 1; 
        hdr.gtpu.seq_flag = 0;
        hdr.gtpu.npdu_flag = 0;
        hdr.gtpu.msgtype = GTP_GPDU;
        // hdr.gtpu.msglen indicates the length after TEID field
        hdr.gtpu.msglen = hdr.inner_ipv4.len; 
        hdr.gtpu.teid = teid;

        hdr.udp.src_port = UDP_PORT_GTPU;
        hdr.udp.dst_port = UDP_PORT_GTPU;
        hdr.udp.len = hdr.inner_ipv4.len + (UDP_HDR_SIZE + GTP_HDR_SIZE);
        hdr.udp.checksum = 0; // Update later

        hdr.ipv4.version = IP_VERSION_4;
        hdr.ipv4.ihl = IPV4_MIN_IHL;
        hdr.ipv4.dscp = 0;
        hdr.ipv4.len = hdr.inner_ipv4.len + (IPV4_HDR_SIZE + UDP_HDR_SIZE + GTP_HDR_SIZE);
        hdr.ipv4.identification = 0x1513;
        hdr.ipv4.flags = 0;
        hdr.ipv4.frag_offset = 0;
        hdr.ipv4.ttl = DEFAULT_IPV4_TTL;
        hdr.ipv4.protocol = IP_PROTO_UDP;
        hdr.ipv4.src_addr = 0; // Update later
        hdr.ipv4.dst_addr = ran_ip; // From outer header creation
        hdr.ipv4.hdr_checksum = 0; // Update later

        // set_gtp_ext(eg_md.qfi); // for UERANSIM

        far_egress_counter.count();
    }

    action assign_upf_ip(ipv4_addr_t upf_ip) {
        hdr.ipv4.src_addr = upf_ip;
        upf_ip_counter.count();
    }

    action assign_upf_mac(mac_addr_t upf_mac) {
        hdr.ethernet.src_addr = upf_mac;
        upf_mac_counter.count();
    }

    action assign_mac(mac_addr_t end_mac) {
        hdr.ethernet.dst_addr = end_mac;
        port_mac_counter.count();
    }

    @name(".far_egress")
    table far_egress_table {
        key = {
            eg_md.far_id: exact;
        }

        actions = {
            gtp_encap;
            @defaultonly NoAction;
        }
        // size = 32768;
        size = 16384;
        const default_action = NoAction;
        counters = far_egress_counter;
    }

    // This is a workaround since tofino p4rt
    // doesn't support default entry yet.
    @name(".upf_mac_table")
    table upf_mac_assign_table {
        key = {
            eg_md.bypass_modify_mac: exact;
        }
        actions = {
            assign_upf_mac;
            @defaultonly NoAction;
        }
        size = 1;
        const default_action = NoAction;
        counters = upf_mac_counter;
    }

    // TODO: change match key to another flag as
    //       UPF may connects to another GTP network
    @name(".upf_ip_table")
    table upf_ip_assign_table {
        key = {
            eg_md.encap_flag: exact;
        }
        actions = {
            assign_upf_ip;
            @defaultonly NoAction;
        }
        size = 1;
        const default_action = NoAction;
        counters = upf_ip_counter;
    }


    
    // This table is to mapping port to mac since
    // every packet should go with a FAR. The packet
    // must forward to a gateway or drop, so the mac
    // address always changes.
    @name(".port_mac_table")
    table port_to_mac_table {
        key = {
            eg_md.ingress_port: exact;
            eg_intr_md.egress_port: exact;
        }
        actions = {
            assign_mac;
            @defaultonly NoAction;
        }
        size = MAX_PORTS;
        const default_action = NoAction;
        counters = port_mac_counter;
    }
    
    apply {
        far_egress_table.apply();
        // if(eg_md.qfi != 0)
        //     set_gtp_ext(eg_md.qfi);
        upf_mac_assign_table.apply();
        upf_ip_assign_table.apply();
        port_to_mac_table.apply();
    }
}

#endif