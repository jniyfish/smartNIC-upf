/* -*- P4_16 -*- */

#include "v1model.p4"

/*************************************************************************
 ***********************  H E A D E R S  *********************************
 *************************************************************************/
header Ethernet_t {
    bit<48> dstAddr;
    bit<48> srcAddr;
    bit<16> etherType;
}

header ARP_t {
    bit<16> hwType;
    bit<16> protoType;
    bit<8>  hwAddrLen;
    bit<8>  protoAddrLen;
    bit<16> opcode;
    bit<48> srcHwAddr;
    bit<32> srcProtoAddr;
    bit<48> dstHwAddr;
    bit<32> dstProtoAddr;
}

header IPv4_t {
    bit<4> version;
    bit<4> ihl;
    bit<8> diffserv;
    bit<16> totalLen;
    bit<16> identification;
    bit<3> flags;
    bit<13> fragOffset;
    bit<8> ttl;
    bit<8> protocol;
    bit<16> hdrChecksum;
    bit<32> srcAddr;
    bit<32> dstAddr;
}

header ICMP_t {
    bit<8>  type;
    bit<8>  code;
    bit<16> checksum;
    bit<32> theRest;
}

header UDP_t {
    bit<16> srcPort;
    bit<16> dstPort;
    bit<16> len;
    bit<16> checksum;
}

header GRETAP_t {
    bit<1> presentChecksum;
    bit<1> unused;
    bit<1> presentKey;
    bit<1> presentSequenceNumber;
    bit<9> reserved0;
    bit<3> version;
    bit<16> protocolType;
    bit<32> grekey; // $$ 註解
}

header TCP_t {
    bit<16> srcPort;
    bit<16> dstPort;
    bit<32> seqNo;
    bit<32> ackNo;
    bit<4>  dataOffset;
    bit<7>  res;
    bit<1>  ack;
    bit<4>  flags;
    bit<16> window;
    bit<16> checksum;
    bit<16> urgentPtr;
}

header MSS_t {
    bit<8> kind;
    bit<8> len;
    bit<16> mssValue;
}

struct headers_t {
    Ethernet_t ethernet;
    ARP_t arp;
    IPv4_t ipv4;
    ICMP_t icmp;
    TCP_t tcp;
    MSS_t theMSS;
    UDP_t udp;
    GRETAP_t gretap;

    // parse tunnel payload
    Ethernet_t debugEthernet;
    ARP_t debugARP;
    IPv4_t debugIPv4;
    ICMP_t debugICMP;
    UDP_t debugUDP;
    TCP_t debugTCP;
    MSS_t debugMSS;

    // new tunnel payload
    TCP_t newTCP;
    MSS_t newMSS;
    UDP_t newUDP;
}
struct metadata_t {
    bit<32> targetIpAddr;
    bit<16> ig;
    bit<16> l4SrcPort;
    bit<16> l4DstPort;

    // for checksum
    bit<32> pseudoIpv4SrcAddr;
    bit<32> pseudoIpv4DstAddr;
    bit<8> pseudoIpv4Protocol;
    bit<16> pseudoL4Length;
    bit<144> tcpHeaderWithoutChecksum;

    // for DNS checksum
    bit<48> udpHeaderWithoutChecksum;

    bit<4> VNFed;
}

/*************************************************************************
 ***********************  P A R S E R  ***********************************
 *************************************************************************/

#define ETHERTYPE_IPV4 0x0800
#define ETHERTYPE_ARP  0x0806
#define IPPROTO_ICMP   0x01
#define IPPROTO_UDP    0x11
#define IPPROTO_TCP    0x06
#define TUN_UDP_PORT   0xc350 // 50000

parser MyParser(
    packet_in packet,
    out   headers_t hdr,
    inout metadata_t meta,
    inout standard_metadata_t standard_metadata) {

    state start {
        packet.extract(hdr.ethernet);
        transition select(hdr.ethernet.etherType) {
            ETHERTYPE_ARP: parse_arp;
            ETHERTYPE_IPV4: parse_ipv4;
            default: accept;
        }
    }

    state parse_arp {
        packet.extract(hdr.arp);
        meta.targetIpAddr = hdr.arp.dstProtoAddr;
        transition accept;
    }

    state parse_ipv4 {
        packet.extract(hdr.ipv4);
        meta.pseudoL4Length = hdr.ipv4.totalLen - 20;
        meta.pseudoIpv4SrcAddr = hdr.ipv4.srcAddr;
        meta.pseudoIpv4DstAddr = hdr.ipv4.dstAddr;
        meta.pseudoIpv4Protocol = hdr.ipv4.protocol;
        transition select(hdr.ipv4.protocol) {
            IPPROTO_TCP: parse_tcp;
            IPPROTO_ICMP: parse_icmp;
            IPPROTO_UDP: parse_udp;
            default: accept;
        }
    }

    state parse_icmp {
        packet.extract(hdr.icmp);
        transition accept;
    }

    state parse_udp {
        packet.extract(hdr.udp);
        meta.l4SrcPort = hdr.udp.srcPort;
        meta.l4DstPort = hdr.udp.dstPort;
        meta.udpHeaderWithoutChecksum =
            hdr.udp.srcPort ++
            hdr.udp.dstPort ++
            hdr.udp.len;
        transition select(hdr.udp.dstPort) {
            TUN_UDP_PORT: parse_gretap;
            default: accept;
        }
    }

    state parse_tcp {
        packet.extract(hdr.tcp);
        meta.l4SrcPort = hdr.tcp.srcPort;
        meta.l4DstPort = hdr.tcp.dstPort;

        meta.tcpHeaderWithoutChecksum =
            hdr.tcp.srcPort ++
            hdr.tcp.dstPort ++
            hdr.tcp.seqNo ++
            hdr.tcp.ackNo ++
            hdr.tcp.dataOffset ++
            hdr.tcp.res ++
            hdr.tcp.ack ++
            hdr.tcp.flags ++
            hdr.tcp.window ++
            hdr.tcp.urgentPtr;

        // [SYN, ACK] or [SYN]
        transition select(hdr.tcp.flags) {
            4w0x2: parse_tcp_option_mss;
            default: accept;
        }
    }

    state parse_tcp_option_mss {
        packet.extract(hdr.theMSS);
        transition accept;
    }

    // Tunnel parsed payload (BRG -> vCPE)
    state parse_gretap {
        packet.extract(hdr.gretap);
        transition parse_inner_ethernet;
    }
    state parse_inner_ethernet {
        packet.extract(hdr.debugEthernet);
        transition select(hdr.debugEthernet.etherType) {
            ETHERTYPE_ARP: parse_inner_arp;
            ETHERTYPE_IPV4: parse_inner_ipv4;
            default: accept;
        }
    }
    state parse_inner_arp {
        packet.extract(hdr.debugARP);
        meta.targetIpAddr = hdr.debugARP.dstProtoAddr;
        transition accept;
    }
    state parse_inner_ipv4 {
        packet.extract(hdr.debugIPv4);
        meta.pseudoL4Length = hdr.debugIPv4.totalLen - 16w20;
        transition select(hdr.debugIPv4.protocol) {
            IPPROTO_TCP: parse_inner_tcp;
            IPPROTO_ICMP: parse_inner_icmp;
            IPPROTO_UDP: parse_inner_udp;
            default: accept;
        }
    }
    state parse_inner_tcp {
        packet.extract(hdr.debugTCP);
        meta.l4SrcPort = hdr.debugTCP.srcPort;
        meta.l4DstPort = hdr.debugTCP.dstPort;
        // [SYN]
        transition select(hdr.debugTCP.ack, hdr.debugTCP.flags) {
            (1w0x0, 4w0x2): parse_inner_tcp_option_mss;
            default: accept;
        }
    }
    state parse_inner_tcp_option_mss {
        packet.extract(hdr.debugMSS);
        transition accept;
    }
    state parse_inner_icmp {
        packet.extract(hdr.debugICMP);
        transition accept;
    }
    state parse_inner_udp {
        packet.extract(hdr.debugUDP);
        meta.l4SrcPort = hdr.debugUDP.srcPort;
        meta.l4DstPort = hdr.debugUDP.dstPort;
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

#define ARP_OPCODE_REQUEST 1
#define ARP_OPCODE_REPLY   2
#define ICMP_ECHO_REQUEST  8
#define ICMP_ECHO_REPLY    0

control MyIngress(
    inout headers_t     hdr,
    inout metadata_t    meta,
    inout standard_metadata_t  standard_metadata)
{
    action send_arp_reply(bit<48> my_eth) {
        hdr.ethernet.dstAddr = hdr.arp.srcHwAddr;
        hdr.ethernet.srcAddr = my_eth;

        hdr.arp.opcode = ARP_OPCODE_REPLY;
        hdr.arp.dstHwAddr = hdr.arp.srcHwAddr;
        hdr.arp.dstProtoAddr = hdr.arp.srcProtoAddr;
        hdr.arp.srcHwAddr = my_eth;
        hdr.arp.srcProtoAddr = meta.targetIpAddr;

        standard_metadata.egress_spec = standard_metadata.ingress_port;
    }
    table host_arp_tbl {
        key = {
            hdr.arp.opcode: exact;
            hdr.arp.dstProtoAddr: exact;
        }
        actions = {
            send_arp_reply;
        }
    }

    action send_tunnelarp_reply(bit<48> vg_eth) {
        // swap eth
        bit<48> tmp1;
        tmp1 = hdr.ethernet.srcAddr;
        hdr.ethernet.srcAddr = hdr.ethernet.dstAddr;
        hdr.ethernet.dstAddr = tmp1;

        bit<32> tmp2;
        tmp2 = hdr.ipv4.srcAddr;
        hdr.ipv4.srcAddr = hdr.ipv4.dstAddr;
        hdr.ipv4.dstAddr = tmp2;

        bit<16> tmp3;
        tmp3 = hdr.udp.srcPort;
        hdr.udp.srcPort = hdr.udp.dstPort;
        hdr.udp.dstPort = tmp3;

        hdr.debugEthernet.dstAddr = hdr.debugARP.srcHwAddr;
        hdr.debugEthernet.srcAddr = vg_eth;

        hdr.debugARP.opcode = ARP_OPCODE_REPLY;
        hdr.debugARP.dstHwAddr = hdr.debugARP.srcHwAddr;
        hdr.debugARP.dstProtoAddr = hdr.arp.srcProtoAddr;
        hdr.debugARP.srcHwAddr = vg_eth;
        hdr.debugARP.srcProtoAddr = meta.targetIpAddr;

        standard_metadata.egress_spec = standard_metadata.ingress_port;
    }
    table vg_arp_tbl {
        key = {
            hdr.gretap.presentKey: exact;
            hdr.gretap.grekey: exact; // $$ 註解
            hdr.debugARP.opcode: exact;
            hdr.debugARP.dstProtoAddr: exact;
        }
        actions = {
            send_tunnelarp_reply;
        }
    }

    action do_save_icmp_hdr() {
        hdr.debugICMP.setValid();
        hdr.debugICMP = hdr.icmp;
        hdr.icmp.setInvalid();
    }
    action do_save_udp_hdr() {
        hdr.newUDP.setValid();
        hdr.newUDP = hdr.udp;
        hdr.udp.setInvalid();
    }
    action do_save_tcp_hdr() {
        hdr.newTCP.setValid();
        hdr.newTCP = hdr.tcp;
        hdr.tcp.setInvalid();
    }
    action do_save_mss_hdr() {
        hdr.newMSS.setValid();
        hdr.newMSS = hdr.theMSS;
        hdr.theMSS.setInvalid();
    }
    action do_reverse_nat (bit<48> ethSrcAddr,
                            bit<48> ethDstAddr,
                            bit<32> ipSrcAddr,
                            bit<32> ipDstAddr,
                            bit<16> udpSrcPort,
                            bit<16> udpDstPort,
                            bit<32> grekey,
                            bit<16> espec,
                            bit<48> ue_mac,
                            bit<32> ue_ip,
                            bit<16> ue_port,
                            bit<48> vg_mac) {
        // encap
        hdr.debugEthernet.setValid();
        hdr.debugEthernet = hdr.ethernet;

        hdr.ethernet.dstAddr = ethDstAddr;
        hdr.ethernet.srcAddr = ethSrcAddr;
        hdr.ethernet.etherType = 0x0800;

        hdr.debugIPv4.setValid();
        hdr.debugIPv4 = hdr.ipv4;

        // reverse nat
        // Ethernet
        hdr.debugEthernet.srcAddr = vg_mac;
        hdr.debugEthernet.dstAddr = ue_mac;
        // IPv4
        // hdr.debugIPv4.srcAddr 不變
        hdr.debugIPv4.dstAddr = ue_ip;
        // TCP / UDP
        hdr.newTCP.dstPort = ue_port;
        hdr.newUDP.dstPort = ue_port;

        // Outer IPv4
        hdr.ipv4.setValid();
        hdr.ipv4.version = 4;
        hdr.ipv4.ihl = 5;
        hdr.ipv4.totalLen = (bit<16>)(standard_metadata.packet_length + 0x24); // $$ 註解
        // hdr.ipv4.totalLen = (bit<16>)(standard_metadata.packet_length + 0x20); // $$ 反註解
        hdr.ipv4.protocol = 0x11; // UDP
        hdr.ipv4.srcAddr = ipSrcAddr;
        hdr.ipv4.dstAddr = ipDstAddr;
        hdr.ipv4.ttl = 64;
        hdr.ipv4.diffserv = 0;
        hdr.ipv4.identification = 0;
        hdr.ipv4.flags = 0;
        hdr.ipv4.fragOffset = 0;

        // Outer UDP
        hdr.udp.setValid();
        hdr.udp.srcPort = udpSrcPort;
        hdr.udp.dstPort = udpDstPort;
        hdr.udp.len = (bit<16>)(standard_metadata.packet_length + 0x10); // $$ 註解
        // hdr.udp.len = (bit<16>)(standard_metadata.packet_length + 0xC); // $$ 反註解
        hdr.udp.checksum = 0;

        // GRE
        hdr.gretap.setValid();
        hdr.gretap.presentChecksum = 0;
        hdr.gretap.unused = 0;
        hdr.gretap.presentKey = 1; // $$ 改成0
        hdr.gretap.presentSequenceNumber = 0;
        hdr.gretap.reserved0 = 0;
        hdr.gretap.version = 0;
        hdr.gretap.protocolType = 0x6558;
        hdr.gretap.grekey = grekey; // $$ 註解

        // forward to PF
        standard_metadata.egress_spec = espec;
    }
    table nat_session_tbl {
        key = {
            meta.l4SrcPort: exact;
            meta.l4DstPort: exact;
            hdr.ipv4.srcAddr: exact;
            hdr.ipv4.dstAddr: exact;
            hdr.ipv4.protocol: exact;
        }
        actions = {
            do_reverse_nat;
        }
        size = 65535;
    }

    action do_fwd_nat_miss (bit<16> espec) {
        standard_metadata.egress_spec = espec;
    }
    action do_fwd_nat_hit (bit<48> gw_mac, bit<48> host_mac, bit<32> host_ip, bit<16> nat_port, bit<16> espec) {
        // remove headers
        hdr.ethernet.setInvalid();
        hdr.ipv4.setInvalid();
        hdr.udp.setInvalid();
        hdr.gretap.setInvalid();

        // NAT
        hdr.debugEthernet.dstAddr = gw_mac;
        hdr.debugEthernet.srcAddr = host_mac;
        hdr.debugIPv4.srcAddr = host_ip;
        hdr.debugIPv4.ttl = hdr.debugIPv4.ttl - 1;

        hdr.debugUDP.srcPort = nat_port;
        hdr.debugTCP.srcPort = nat_port;

        standard_metadata.egress_spec = espec; // p1
    }
    table vg_tbl {
        key = {
            hdr.gretap.presentKey: exact;
            hdr.gretap.grekey: exact; // $$ 註解

            // five tuple
            meta.l4SrcPort: exact;
            meta.l4DstPort: exact;

            hdr.debugIPv4.srcAddr: exact;
            hdr.debugIPv4.dstAddr: exact;
            hdr.debugIPv4.protocol: exact;
        }
        actions = {
            do_fwd_nat_hit;
            do_fwd_nat_miss;
        }
        size = 65535;
    }

    action decap_fwd_vf(bit<16> espec) {
        // remove headers
        hdr.ethernet.setInvalid();
        hdr.ipv4.setInvalid();
        hdr.udp.setInvalid();
        hdr.gretap.setInvalid();

        // forward to VF
        standard_metadata.egress_spec = espec;
        meta.VNFed = 0xa;
    }
    table dhcp_request_tbl {
        key = {
            hdr.gretap.presentKey: exact;
            hdr.gretap.grekey: exact; // $$ 註解
            hdr.debugUDP.dstPort: exact;
        }
        actions = {
            decap_fwd_vf;
        }
    }

    action encap_fwd_pf (bit<48> ethSrcAddr,
                            bit<48> ethDstAddr,
                            bit<32> ipSrcAddr,
                            bit<32> ipDstAddr,
                            bit<16> udpSrcPort,
                            bit<16> udpDstPort,
                            bit<32> grekey,
                            bit<16> espec) {
        // Inner header
        hdr.debugEthernet.setValid();
        hdr.debugEthernet = hdr.ethernet;
        hdr.debugIPv4.setValid();
        hdr.debugIPv4 = hdr.ipv4;
        hdr.newUDP.setValid();
        hdr.newUDP = hdr.udp;

        // Outer Ethernet
        hdr.ethernet.dstAddr = ethDstAddr;
        hdr.ethernet.srcAddr = ethSrcAddr;
        hdr.ethernet.etherType = 0x0800;

        // Outer IPv4
        hdr.ipv4.setValid();
        hdr.ipv4.version = 4;
        hdr.ipv4.ihl = 5;
        hdr.ipv4.totalLen = (bit<16>)(standard_metadata.packet_length + 0x24); // $$ 註解
        // hdr.ipv4.totalLen = (bit<16>)(standard_metadata.packet_length + 0x20); // $$ 反註解
        hdr.ipv4.protocol = 0x11; // UDP
        hdr.ipv4.srcAddr = ipSrcAddr;
        hdr.ipv4.dstAddr = ipDstAddr;
        hdr.ipv4.ttl = 64;
        hdr.ipv4.diffserv = 0;
        hdr.ipv4.identification = 0;
        hdr.ipv4.flags = 0;
        hdr.ipv4.fragOffset = 0;

        // Outer UDP
        hdr.udp.setValid();
        hdr.udp.srcPort = udpSrcPort;
        hdr.udp.dstPort = udpDstPort;
        hdr.udp.len = (bit<16>)(standard_metadata.packet_length + 0x10); // $$ 註解
        // hdr.udp.len = (bit<16>)(standard_metadata.packet_length + 0xC); // $$ 反註解
        hdr.udp.checksum = 0;

        // GRE
        hdr.gretap.setValid();
        hdr.gretap.presentChecksum = 0;
        hdr.gretap.unused = 0;
        hdr.gretap.presentKey = 1; // $$ 改成0
        hdr.gretap.presentSequenceNumber = 0;
        hdr.gretap.reserved0 = 0;
        hdr.gretap.version = 0;
        hdr.gretap.protocolType = 0x6558;
        hdr.gretap.grekey = grekey; // $$ 註解

        // forward to PF
        standard_metadata.egress_spec = espec;
        meta.VNFed = 0xa;
    }
    table dhcp_reply_tbl {
        key = {
            standard_metadata.ingress_port: exact;
            hdr.udp.dstPort: exact;
        }
        actions = {
            encap_fwd_pf;
        }
    }

    apply {
/**********************************
 ************   VNF   *************
 **********************************/

        // Init
        // 0xa means packet do pass through VNF
        // 0xf means packet don't pass through VNF
        // Why 0xa/0xf? Because default metadata is 0x0
        meta.VNFed = 0xf;

        // 1️⃣ BRG -> vG: VNF UDP Request
        if (hdr.debugUDP.isValid()) {
            dhcp_request_tbl.apply();
        }
        // 2️⃣ BRG <- vG: VNF UDP Reply
        else if (hdr.udp.isValid()) {
            dhcp_reply_tbl.apply();
        }
        // [TODO] BRG -> vG: VNF TCP Request
        // else if (hdr.debugTCP.isValid()) {
        //     vnf_tcp_request_tbl.apply();
        // }
        // [TODO] BRG <- vG: VNF TCP Reply
        // else if (hdr.tcp.isValid()) {
        //     vnf_tcp_reply_tbl.apply();
        // }

/***************************************
 ************   GW & NAT   *************
 ***************************************/
        if (meta.VNFed == 0xf) {
            // ARP request -> Host MAC
            if (hdr.arp.isValid()) {
                host_arp_tbl.apply();
            }
            // Tunnel ARP request -> vG MAC
            else if (hdr.debugARP.isValid()) {
                vg_arp_tbl.apply();
            }
            // [TODO] BRG <- vG: VNF ARP Request
            // else if (hdr.arp.isValid()) { // 其實跟上上面條件一樣
            //     host_arp_tbl.apply(); // 共用 table
            //     // default action to agent
            // }

            // 1️⃣ BRG -> vCPE -> Internet TCP
            else if (hdr.debugIPv4.isValid()) {
                vg_tbl.apply();
            }

            // 2️⃣ Internet TCP -> vCPE -> BRG
            else if (hdr.ipv4.isValid()) {
                if (hdr.udp.isValid()) {
                    do_save_udp_hdr();
                }
                else if (hdr.tcp.isValid()) {
                    do_save_tcp_hdr();
                    if (hdr.theMSS.isValid()) {
                        do_save_mss_hdr();
                    }
                }
                nat_session_tbl.apply();
            }
        }
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
        if (hdr.icmp.isValid()) {
            hdr.ipv4.identification = 0x000;
            hdr.ipv4.flags = 0x000;
        }

        if (hdr.newTCP.isValid()) {
            meta.pseudoIpv4DstAddr = hdr.debugIPv4.dstAddr;

            meta.tcpHeaderWithoutChecksum =
                hdr.newTCP.srcPort ++
                hdr.newTCP.dstPort ++
                hdr.newTCP.seqNo ++
                hdr.newTCP.ackNo ++
                hdr.newTCP.dataOffset ++
                hdr.newTCP.res ++
                hdr.newTCP.ack ++
                hdr.newTCP.flags ++
                hdr.newTCP.window ++
                hdr.newTCP.urgentPtr;

            if (hdr.newMSS.isValid()) {
                hdr.theMSS.mssValue = 0x0582;
                hdr.newMSS.mssValue = 0x0582;
            }
        }

        // DNS
        if (hdr.newUDP.isValid()) {
            meta.pseudoIpv4DstAddr = hdr.debugIPv4.dstAddr;
            meta.udpHeaderWithoutChecksum =
                hdr.newUDP.srcPort ++
                hdr.newUDP.dstPort ++
                hdr.newUDP.len;
        }

        if (hdr.debugMSS.isValid()) {
            hdr.debugMSS.mssValue = 0x0582;
        }
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

        // Internet TCP -> vCPE -> BRG: Tunnel outer IP header
        update_checksum(
            hdr.ipv4.isValid(),
            {
                hdr.ipv4.version,
                hdr.ipv4.ihl,
                hdr.ipv4.diffserv,
                hdr.ipv4.totalLen,
                hdr.ipv4.identification,
                hdr.ipv4.flags,
                hdr.ipv4.fragOffset,
                hdr.ipv4.ttl,
                hdr.ipv4.protocol,
                hdr.ipv4.srcAddr,
                hdr.ipv4.dstAddr
            },
            hdr.ipv4.hdrChecksum,
            HashAlgorithm.csum16
        );

        // BRG -> vCPE -> Internet TCP: IP header
        // Internet TCP -> vCPE -> BRG: Tunnel inner IP header
        update_checksum(
            hdr.debugIPv4.isValid(),
            {
                hdr.debugIPv4.version,
                hdr.debugIPv4.ihl,
                hdr.debugIPv4.diffserv,
                hdr.debugIPv4.totalLen,
                hdr.debugIPv4.identification,
                hdr.debugIPv4.flags,
                hdr.debugIPv4.fragOffset,
                hdr.debugIPv4.ttl,
                hdr.debugIPv4.protocol,
                hdr.debugIPv4.srcAddr,
                hdr.debugIPv4.dstAddr
            },
            hdr.debugIPv4.hdrChecksum,
            HashAlgorithm.csum16
        );

        // BRG -> vCPE -> Internet TCP: TCP header
        update_checksum_with_payload(
            hdr.debugTCP.isValid(),
            { 
                hdr.debugIPv4.srcAddr,
                hdr.debugIPv4.dstAddr,
                8w0,
                hdr.debugIPv4.protocol,
                meta.pseudoL4Length,
                hdr.debugTCP.srcPort,
                hdr.debugTCP.dstPort,
                hdr.debugTCP.seqNo,
                hdr.debugTCP.ackNo,
                hdr.debugTCP.dataOffset,
                hdr.debugTCP.res,
                hdr.debugTCP.ack,
                hdr.debugTCP.flags,
                hdr.debugTCP.window,
                hdr.debugTCP.urgentPtr,
                hdr.debugMSS.kind,
                hdr.debugMSS.len,
                hdr.debugMSS.mssValue
            },
            hdr.debugTCP.checksum,
            HashAlgorithm.csum16
        );

        // Internet TCP -> vCPE -> BRG: Tunnel inner TCP header
        update_checksum_with_payload(
            hdr.newTCP.isValid(),
            {
                meta.pseudoIpv4SrcAddr,
                meta.pseudoIpv4DstAddr,
                8w0,
                meta.pseudoIpv4Protocol,
                meta.pseudoL4Length,
                meta.tcpHeaderWithoutChecksum,
                hdr.theMSS.kind,
                hdr.theMSS.len,
                hdr.theMSS.mssValue
            },
            hdr.newTCP.checksum,
            HashAlgorithm.csum16
        );

        update_checksum_with_payload(
            hdr.debugUDP.isValid(),
            {
                hdr.debugIPv4.srcAddr,
                hdr.debugIPv4.dstAddr,
                8w0,
                hdr.debugIPv4.protocol,
                meta.pseudoL4Length,
                hdr.debugUDP.srcPort,
                hdr.debugUDP.dstPort,
                hdr.debugUDP.len
            },
            hdr.debugUDP.checksum,
            HashAlgorithm.csum16
        );

        // for DHCP reply in innner header
        update_checksum_with_payload(
            hdr.newUDP.isValid(),
            {
                meta.pseudoIpv4SrcAddr,
                meta.pseudoIpv4DstAddr,
                8w0,
                meta.pseudoIpv4Protocol,
                meta.pseudoL4Length,
                meta.udpHeaderWithoutChecksum
            },
            hdr.newUDP.checksum,
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
        packet.emit(hdr.icmp);
        packet.emit(hdr.tcp);
        packet.emit(hdr.theMSS);

        // Tunnel
        packet.emit(hdr.udp);
        packet.emit(hdr.gretap);

        // Tunnel payload (BRG -> vCPE -> Internet)
        packet.emit(hdr.debugEthernet);
        packet.emit(hdr.debugARP);
        packet.emit(hdr.debugIPv4);
        packet.emit(hdr.debugICMP);
        packet.emit(hdr.debugUDP);

        packet.emit(hdr.debugTCP);
        packet.emit(hdr.debugMSS);

        packet.emit(hdr.newTCP);
        packet.emit(hdr.newMSS);

        packet.emit(hdr.newUDP);
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
