/* Copyright (C) 2015-2016,  Netronome Systems, Inc.  All rights reserved. */

#ifndef __PIF_FIELD_LISTS_H__
#define __PIF_FIELD_LISTS_H__

/* Generated C source defining layout of field lists in memory */
/* Warning: your edits to this file may be lost */

struct pif_field_list_field_list_2 {
    union {
        struct {
            /* inner_ipv4.src_addr[32;0] */
            unsigned int __inner_ipv4__src_addr:32;
            /* inner_ipv4.dst_addr[32;0] */
            unsigned int __inner_ipv4__dst_addr:32;
            /* inner_ipv4.len[16;0] */
            unsigned int __inner_ipv4__len:16;
            /* inner_ipv4.identification[16;0] */
            unsigned int __inner_ipv4__identification:16;
            unsigned int _padding_0:3;
            /* inner_ipv4.frag_offset[13;0] */
            unsigned int __inner_ipv4__frag_offset:13;
            /* inner_ipv4.ttl[8;0] */
            unsigned int __inner_ipv4__ttl:8;
            /* inner_ipv4.protocol[8;0] */
            unsigned int __inner_ipv4__protocol:8;
            unsigned int _padding_1:13;
            /* inner_ipv4.dscp[6;0] */
            unsigned int __inner_ipv4__dscp:6;
            /* inner_ipv4.version[4;0] */
            unsigned int __inner_ipv4__version:4;
            /* inner_ipv4.ihl[4;0] */
            unsigned int __inner_ipv4__ihl:4;
            /* inner_ipv4.flags[3;0] */
            unsigned int __inner_ipv4__flags:3;
            /* inner_ipv4.ecn[2;0] */
            unsigned int __inner_ipv4__ecn:2;
        };
        uint32_t _raw[5];
    };
};

struct pif_field_list_field_list_2_packed {
    union {
        __packed struct {
            /* inner_ipv4.version[4;0] */
            unsigned int __inner_ipv4__version:4;
            /* inner_ipv4.ihl[4;4] */
            unsigned int __inner_ipv4__ihl:4;
            /* inner_ipv4.dscp[6;8] */
            unsigned int __inner_ipv4__dscp:6;
            /* inner_ipv4.ecn[2;14] */
            unsigned int __inner_ipv4__ecn:2;
            /* inner_ipv4.len[16;16] */
            unsigned int __inner_ipv4__len:16;
            /* inner_ipv4.identification[16;32] */
            unsigned int __inner_ipv4__identification:16;
            /* inner_ipv4.flags[3;48] */
            unsigned int __inner_ipv4__flags:3;
            /* inner_ipv4.frag_offset[13;51] */
            unsigned int __inner_ipv4__frag_offset:13;
            /* inner_ipv4.ttl[8;64] */
            unsigned int __inner_ipv4__ttl:8;
            /* inner_ipv4.protocol[8;72] */
            unsigned int __inner_ipv4__protocol:8;
            /* inner_ipv4.src_addr[32;80] */
            unsigned int __inner_ipv4__src_addr:32;
            /* inner_ipv4.dst_addr[32;112] */
            unsigned int __inner_ipv4__dst_addr:32;
            unsigned int _padding:16;
        };
        uint32_t _raw[5];
    };
};

struct pif_field_list_field_list_1 {
    union {
        struct {
            /* ipv4.src_addr[32;0] */
            unsigned int __ipv4__src_addr:32;
            /* ipv4.dst_addr[32;0] */
            unsigned int __ipv4__dst_addr:32;
            /* ipv4.len[16;0] */
            unsigned int __ipv4__len:16;
            /* ipv4.identification[16;0] */
            unsigned int __ipv4__identification:16;
            unsigned int _padding_0:3;
            /* ipv4.frag_offset[13;0] */
            unsigned int __ipv4__frag_offset:13;
            /* ipv4.ttl[8;0] */
            unsigned int __ipv4__ttl:8;
            /* ipv4.protocol[8;0] */
            unsigned int __ipv4__protocol:8;
            unsigned int _padding_1:13;
            /* ipv4.dscp[6;0] */
            unsigned int __ipv4__dscp:6;
            /* ipv4.version[4;0] */
            unsigned int __ipv4__version:4;
            /* ipv4.ihl[4;0] */
            unsigned int __ipv4__ihl:4;
            /* ipv4.flags[3;0] */
            unsigned int __ipv4__flags:3;
            /* ipv4.ecn[2;0] */
            unsigned int __ipv4__ecn:2;
        };
        uint32_t _raw[5];
    };
};

struct pif_field_list_field_list_1_packed {
    union {
        __packed struct {
            /* ipv4.version[4;0] */
            unsigned int __ipv4__version:4;
            /* ipv4.ihl[4;4] */
            unsigned int __ipv4__ihl:4;
            /* ipv4.dscp[6;8] */
            unsigned int __ipv4__dscp:6;
            /* ipv4.ecn[2;14] */
            unsigned int __ipv4__ecn:2;
            /* ipv4.len[16;16] */
            unsigned int __ipv4__len:16;
            /* ipv4.identification[16;32] */
            unsigned int __ipv4__identification:16;
            /* ipv4.flags[3;48] */
            unsigned int __ipv4__flags:3;
            /* ipv4.frag_offset[13;51] */
            unsigned int __ipv4__frag_offset:13;
            /* ipv4.ttl[8;64] */
            unsigned int __ipv4__ttl:8;
            /* ipv4.protocol[8;72] */
            unsigned int __ipv4__protocol:8;
            /* ipv4.src_addr[32;80] */
            unsigned int __ipv4__src_addr:32;
            /* ipv4.dst_addr[32;112] */
            unsigned int __ipv4__dst_addr:32;
            unsigned int _padding:16;
        };
        uint32_t _raw[5];
    };
};

#endif /* __PIF_FIELD_LISTS_H__ */
