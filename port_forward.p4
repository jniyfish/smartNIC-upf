/* -*- P4_16 -*- */

#include "v1model.p4"

/*************************************************************************
 ***********************  H E A D E R S  *********************************
 *************************************************************************/
#define IP_VERSION_4 4
#define IPV4_HDR_SIZE 20
#define UDP_HDR_SIZE 8
typedef bit<48>  mac_addr_t;
typedef bit<32>  ipv4_addr_t;
typedef bit<32>  teid_t;
#define UDP_PORT_GTPU 2152
#define GTP_HDR_SIZE 8
#define GTP_OPTION_FIELDS_SIZE 4
#define GTP_EXT_HDR_SIZE 4
#define GTPU_VERSION 0x01
#define GTP_PROTOCOL_TYPE_GTP 0x01
#define GTP_GPDU 0xff
#define GTP_PDU_SES_CONT_TYPE 0x85
#define UL_PDU_SESSION_INFO 1
#define DL_PDU_SESSION_INFO 0
#define TYPE_FAR_ID bit<32>
#define TYPE_QER_ID bit<32>

const ipv4_addr_t DNS_SERVER = 0x08080808;
typedef bit<16> ether_type_t;
const ether_type_t ETH_TYPE_IPV4 = 16w0x0800;
const ether_type_t ETH_TYPE_ARP  = 16w0x0806;
const ether_type_t ETH_TYPE_IPV6 = 16w0x86dd;
const ether_type_t ETH_TYPE_VLAN = 16w0x8100;

typedef bit<8> ip_protocol_t;
const ip_protocol_t IP_PROTO_ICMP = 1;
const ip_protocol_t IP_PROTO_TCP = 6;
const ip_protocol_t IP_PROTO_UDP = 17;
const ip_protocol_t IP_PROTO_SCTP = 132;

const bit<8> DEFAULT_IPV4_TTL = 64;
const bit<4> IPV4_MIN_IHL = 5;




/*************************************************************************
 ***********************  H E A D E R S  *********************************
 *************************************************************************/
header ethernet_h {
    mac_addr_t dst_addr;
    mac_addr_t src_addr;
    bit<16> ether_type;
}

header arp_h {
    bit<16> hw_type;
    bit<16> proto_type;
    bit<8>  hw_addr_len;
    bit<8>  proto_addr_len;
    bit<16> opcode;
}

header ipv4_h {
    bit<4>  version;
    bit<4>  ihl;
    bit<6>  dscp;
    bit<2>  ecn;
    bit<16> len;
    bit<16> identification;
    bit<3>  flags;
    bit<13> frag_offset;
    bit<8>  ttl;
    bit<8>  protocol;
    bit<16> hdr_checksum;
    ipv4_addr_t src_addr;
    ipv4_addr_t dst_addr;
}

header udp_h {
    bit<16> src_port;
    bit<16> dst_port;
    bit<16> len;
    bit<16> checksum;
}

header tcp_h {
    bit<16> src_port;
    bit<16> dst_port;
    bit<32> seqNo;
    bit<32> ackNo;
    bit<4> dataOffset;
    bit<3> res;
    bit<3> ecn;
    bit<6> ctrl;
    bit<16> window;
    bit<16> checksum;
    bit<16> urgentPtr;
}

// GTP-U v1
header gtpu_h {
    bit<3>  version;
    bit<1>  pt;
    bit<1>  spare;
    bit<1>  ex_flag;
    bit<1>  seq_flag;
    bit<1>  npdu_flag;
    bit<8>  msgtype;
    bit<16> msglen;
    teid_t teid;
}

header gtpu_option_h {
    bit<16> seq_num;
    bit<8> n_pdu_num;
    bit<8> type;
}

header gtpu_ex_h {
    bit<8> len;
    bit<4> pdu_type;
    bit<6> spare;
    bit<6> qfi;
    bit<8> next_type;
}

struct metadata_t {
    bit<16>     l4_src_port;
    bit<16>     l4_dst_port;
    bit<16>     l4_inner_src_port;
    bit<16>     l4_inner_dst_port;
    TYPE_FAR_ID     far_id;
    bit<8>       decap_flag;
    bit<1>         encap_flag;
    bit<8>      intf;
    //PortId_t    ingress_port;
    bit<1>      bypass_modify_mac;
    bit<6> qfi;
}

struct headers_t {
    ethernet_h ethernet;
    arp_h arp;
    ipv4_h  ipv4;
    tcp_h tcp;
    udp_h   udp; 
    gtpu_h  gtpu;
    gtpu_option_h gtpu_option;
    gtpu_ex_h gtpu_ex;
    ipv4_h  inner_ipv4;
    udp_h   inner_udp;
    tcp_h   inner_tcp;
}


/*************************************************************************
 ***********************  P A R S E R  ***********************************
 *************************************************************************/

parser MyParser(
    packet_in packet,
    out   headers_t hdr,
    inout metadata_t meta,   //custom
    inout standard_metadata_t standard_metadata //v1model metadata
    ) {

    state start {
        transition parse_ethernet;
    }

    state parse_ethernet {
        packet.extract(hdr.ethernet);
        transition select(hdr.ethernet.ether_type) {
            ETH_TYPE_ARP: parse_arp;
            ETH_TYPE_IPV4: parse_ipv4;
            default: accept;
        }
    }

    state parse_arp {
        packet.extract(hdr.arp);
        transition accept;
    }

    state parse_ipv4 {
        packet.extract(hdr.ipv4);
        transition select(hdr.ipv4.protocol) {
            IP_PROTO_UDP: parse_udp;
            IP_PROTO_TCP: parse_tcp;
            default: accept;
        }
    }


    state parse_tcp {
        packet.extract(hdr.tcp);
        meta.l4_src_port = hdr.tcp.src_port;
        meta.l4_dst_port = hdr.tcp.dst_port;
        transition accept;
    }

    state parse_udp {
        packet.extract(hdr.udp);
        meta.l4_src_port = hdr.udp.src_port;
        meta.l4_dst_port = hdr.udp.dst_port;
        transition select(hdr.udp.dst_port) {
            UDP_PORT_GTPU: parse_gtpu;
            default: accept;
        }
    }

    state parse_gtpu {
        packet.extract(hdr.gtpu);
        transition select(hdr.gtpu.ex_flag, hdr.gtpu.seq_flag, hdr.gtpu.npdu_flag) {
            (1, _, _): parse_gtpu_ex;
            (_, 1, _): parse_gtpu_seq;
            default: parse_inner_ipv4;
        }
    }

    state parse_gtpu_seq {
        packet.extract(hdr.gtpu_option);
        transition parse_inner_ipv4;
    }

    state parse_gtpu_ex {
        packet.extract(hdr.gtpu_option);
        transition select(hdr.gtpu_option.type) {
            GTP_PDU_SES_CONT_TYPE: parse_pdu_ses_container;
            default: parse_inner_ipv4;
        }
    }

    state parse_pdu_ses_container {
        packet.extract(hdr.gtpu_ex);
        transition parse_inner_ipv4;
    }

    state parse_inner_ipv4 {
        packet.extract(hdr.inner_ipv4);
        transition select(hdr.inner_ipv4.protocol) {
            IP_PROTO_UDP: parse_inner_udp;
            IP_PROTO_TCP: parse_inner_tcp;
            // IP_PROTO_ICMP: parse_inner_icmp;
            default: accept;
        }
        // transition accept;
    }

    state parse_inner_udp {
        packet.extract(hdr.inner_udp);
        meta.l4_inner_src_port = hdr.inner_udp.src_port;
        meta.l4_inner_dst_port = hdr.inner_udp.dst_port;
        transition accept;
    }

    state parse_inner_tcp {
        packet.extract(hdr.inner_tcp);
        meta.l4_inner_src_port = hdr.inner_tcp.src_port;
        meta.l4_inner_dst_port = hdr.inner_tcp.dst_port;
        transition accept;
    }


}

/*************************************************************************
 ************   C H E C K S U M    V E R I F I C A T I O N   *************
 *************************************************************************/
control MyVerifyChecksum(
    inout headers_t   hdr,
    inout metadata_t  meta)
{
    apply {  }
}

/*************************************************************************
 **************  I N G R E S S   P R O C E S S I N G   *******************
 *************************************************************************/

control MyIngress(
    inout headers_t     hdr,
    inout metadata_t    meta,
    inout standard_metadata_t  standard_metadata)
{
    /*****************   PDR   *******************/
    // A workaround for outer header removal
    action gtp_decap() {
        hdr.ipv4.setInvalid();
        // hdr.ipv6.setInvalid();
        hdr.udp.setInvalid();
        hdr.gtpu.setInvalid();
        //hdr.gtpu_option.setInvalid();
        //hdr.gtpu_ex.setInvalid();
    }

    action set_src_intf(bit<16> port) {
        standard_metadata.egress_spec = port;
    }

    action set_rules(
            TYPE_FAR_ID far_id,
            bit<8>  must_decap) {
        meta.far_id = far_id;
        meta.decap_flag = must_decap;
    }

    table src_intf_table {
        key = {
            standard_metadata.ingress_port: exact;
        }
        actions = {
            set_src_intf;
            @defaultonly NoAction;
        }
        size = 32;
        const default_action = NoAction;
    }

    // At least one of the match field must be ternary to have priority
    table pdr_ingress_table {
        key = {
            hdr.ipv4.src_addr:          exact;
            meta.intf:                 exact;
        }
        actions = {
            set_rules;
            @defaultonly NoAction;
        }
        size = 24500;
        const default_action = NoAction;
    }
    /******************* FAR   ******************/

    action set_egress_port_and_encap(bit<16> port, bit<1> do_encap) {
        //ig_intr_tm_md.ucast_egress_port = port;
        //ig_intr_dprsr_md.drop_ctl = 0x0;
        meta.encap_flag = do_encap;
        standard_metadata.egress_spec = port;
    }

    action drop() {
        exit;
    }

    action gtp_encap(teid_t teid, ipv4_addr_t ran_ip, ipv4_addr_t upf_ip) {
        hdr.ipv4.setValid();
        hdr.udp.setValid();
        hdr.gtpu.setValid();
        hdr.inner_ipv4.setValid();


        hdr.inner_ipv4.version=hdr.ipv4.version;
        hdr.inner_ipv4.ihl=hdr.ipv4.ihl;
        hdr.inner_ipv4.dscp=hdr.ipv4.dscp;
        hdr.inner_ipv4.ecn=hdr.ipv4.ecn;
        hdr.inner_ipv4.len=hdr.ipv4.len;
        hdr.inner_ipv4.identification=hdr.ipv4.identification;
        hdr.inner_ipv4.flags=hdr.ipv4.flags;
        hdr.inner_ipv4.frag_offset=hdr.ipv4.frag_offset;
        hdr.inner_ipv4.ttl=hdr.ipv4.ttl;
        hdr.inner_ipv4.protocol=hdr.ipv4.protocol;
        hdr.inner_ipv4.hdr_checksum=hdr.ipv4.hdr_checksum;
        hdr.inner_ipv4.src_addr=hdr.ipv4.src_addr;
        hdr.inner_ipv4.dst_addr=hdr.ipv4.dst_addr;

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
        hdr.ipv4.src_addr = upf_ip; // Update later
        hdr.ipv4.dst_addr = ran_ip; // From outer header creation
        hdr.ipv4.hdr_checksum = 0; // Update later
    }

    table far_egress_table {
        key = {
            meta.far_id: exact;
        }

        actions = {
            gtp_encap;
            @defaultonly NoAction;
        }
        // size = 32768;
        size = 16384;
        const default_action = NoAction;
    }

    /******************* Apply ******************/
    apply {
        src_intf_table.apply();
    }
}

/*************************************************************************
 ****************  E G R E S S   P R O C E S S I N G   *******************
 *************************************************************************/
control MyEgress(
    inout headers_t        hdr,
    inout metadata_t       meta,
    inout standard_metadata_t standard_metadata)
{
    apply {
    }
}

/*************************************************************************
 *************   C H E C K S U M    C O M P U T A T I O N   **************
 *************************************************************************/
control MyComputeChecksum(
    inout headers_t  hdr,
    inout metadata_t meta)
{
     apply {
        // Compute Outer IPv4 checksum
        update_checksum(hdr.ipv4.isValid(),{
                hdr.ipv4.version,
                hdr.ipv4.ihl,
                hdr.ipv4.dscp,
                hdr.ipv4.ecn,
                hdr.ipv4.len,
                hdr.ipv4.identification,
                hdr.ipv4.flags,
                hdr.ipv4.frag_offset,
                hdr.ipv4.ttl,
                hdr.ipv4.protocol,
                hdr.ipv4.src_addr,
                hdr.ipv4.dst_addr
            },
            hdr.ipv4.hdr_checksum,
            HashAlgorithm.csum16
        );

        // Outer UDP checksum currently remains 0,
        // which is legal for IPv4

        // Compute IPv4 checksum
        update_checksum(hdr.inner_ipv4.isValid(),{
                hdr.inner_ipv4.version,
                hdr.inner_ipv4.ihl,
                hdr.inner_ipv4.dscp,
                hdr.inner_ipv4.ecn,
                hdr.inner_ipv4.len,
                hdr.inner_ipv4.identification,
                hdr.inner_ipv4.flags,
                hdr.inner_ipv4.frag_offset,
                hdr.inner_ipv4.ttl,
                hdr.inner_ipv4.protocol,
                hdr.inner_ipv4.src_addr,
                hdr.inner_ipv4.dst_addr
            },
            hdr.inner_ipv4.hdr_checksum,
            HashAlgorithm.csum16
        );
    }
}

/*************************************************************************
 ***********************  D E P A R S E R  *******************************
 *************************************************************************/
control MyDeparser(
    packet_out packet,
    in headers_t hdr)
{
    apply {
        packet.emit(hdr.ethernet);
        packet.emit(hdr.arp);
        packet.emit(hdr.ipv4);
        packet.emit(hdr.udp);
        packet.emit(hdr.tcp);
        packet.emit(hdr.gtpu);
        packet.emit(hdr.gtpu_option);
        packet.emit(hdr.gtpu_ex);
        packet.emit(hdr.inner_ipv4);
        packet.emit(hdr.inner_udp);
        packet.emit(hdr.inner_tcp);
    }
}

V1Switch(
    MyParser(),
    MyVerifyChecksum(),
    MyIngress(),
    MyEgress(),
    MyComputeChecksum(),
    MyDeparser()
) main;
