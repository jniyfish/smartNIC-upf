#! /bin/bash

echo "table: $1"


if [ "$1" = "pdr_ingress_table_ul" ]
then
    echo "src_ip: $2" #inner ip
    echo "intf: $3"
    echo "far_id: $4"
    echo "must_decap: $5"
    ipv4="{\"inner_ipv4.src_addr\":{\"value\":\""
    ipv4+=$2
    ipv4+='"},"scalars.metadata_t@intf":{"value":"'
    ipv4+=$3
    ipv4+="\"}}"
    ipv4+=" -a {\"data\":{\"far_id\":{\"value\":\""
    ipv4+=$4
    ipv4+="\"},\"must_decap\":{\"value\":\""
    ipv4+=$5
    ipv4+="\"}},\"type\":\"ingress::set_rules\"} "
    echo "$ipv4"
    /opt/netronome/p4/bin/rtecli -p 20206 -r 140.113.131.157 tables add \
    -t ingress::pdr_ingress_table_ul \
    -r $2 \
    -m $ipv4 
fi

if [ "$1" = "pdr_ingress_table_dl" ]
then
    echo "src_ip: $2"  #outer ip
    echo "intf: $3"
    echo "far_id: $4"
    echo "must_decap: $5"
    ipv4="{\"ipv4.dst_addr\":{\"value\":\""
    ipv4+=$2
    ipv4+='"},"scalars.metadata_t@intf":{"value":"'
    ipv4+=$3
    ipv4+="\"}}"
    ipv4+=" -a {\"data\":{\"far_id\":{\"value\":\""
    ipv4+=$4
    ipv4+="\"},\"must_decap\":{\"value\":\""
    ipv4+=$5
    ipv4+="\"}},\"type\":\"ingress::set_rules\"} "
    echo "$ipv4"
    /opt/netronome/p4/bin/rtecli -p 20206 -r 140.113.131.157 tables add \
    -t ingress::pdr_ingress_table_dl \
    -r $2 \
    -m $ipv4 
fi

if [ "$1" = "far_egress_table" ]
then
    echo "teid: $2"
    echo "ran_ip: $3"
    echo "upf_ip: $4"
    echo "far_id: $5"
    cmd="{\"scalars.metadata_t@far_id\":{\"value\":\""
    cmd+=$5
    cmd+="\"}}"
    cmd+=" -a {\"data\":{\"teid\":{\"value\":\""
    cmd+=$2
    cmd+="\"},\"ran_ip\":{\"value\":\""
    cmd+=$3
    cmd+="\"},\"upf_ip\":{\"value\":\""
    cmd+=$4
    cmd+="\"}},\"type\":\"ingress::gtp_encap\"} "
    echo "$cmd"
    /opt/netronome/p4/bin/rtecli -p 20206 -r 140.113.131.157 tables add \
    -t ingress::far_egress_table \
    -r $2 \
    -m $cmd
fi

