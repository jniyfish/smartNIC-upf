#ifndef __DEFINES__
#define __DEFINES__

#ifndef IP_VERSION_4
#define IP_VERSION_4 4
#endif
// TODO: Use compiler argument -DCPU_PORT to assign
#define CPU_PORT 192
// Montara 192, Mavericks 320
#define IPV4_HDR_SIZE 20
#define UDP_HDR_SIZE 8
#define MAX_PORTS     192

typedef bit<48>  mac_addr_t;
typedef bit<32>  ipv4_addr_t;
// typedef bit<128> ipv6_addr_t;
typedef bit<32>  teid_t;
//typedef bit<12>  vlan_id_t;

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

