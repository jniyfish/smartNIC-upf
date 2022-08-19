#!/bin/bash

set -o pipefail

echo -e '\033[32m=== make clean ===\033[0m'
make --makefile=Makefile-nfp4build clean &> /dev/null

echo -e '\033[32m=== Check P4C_BIN_DIR environment variable ===\033[0m'
if [[ $P4C_BIN_DIR ]]; then
    echo "\$P4C_BIN_DIR: $P4C_BIN_DIR"
else
    echo "\$P4C_BIN_DIR is empty..."
    echo -e '\033[91mexport P4C_BIN_DIR=/opt/netronome/p4/bin\033[0m'
    exit 1
fi

echo -e '\033[32m=== Building firmware... ===\033[0m'
/opt/netronome/p4/bin/nfp4build -o output/main.nffw -4 main.p4 --nfp4c_p4_version 16 -e -l lithium \
    --sku AMDA0096-0001:0 \
    --shared-codestore \
    --no-debug-info \
    --nfp4c_p4_compiler p4c-nfp \
    --nfirc_default_table_size 65536 \
    --nfirc_all_header_ops \
    --nfirc_implicit_header_valid \
    --nfirc_zero_new_headers \
    --nfirc_multicast_group_count 16 \
    --nfirc_multicast_group_size 16 \
    --nfirc_no_mac_ingress_timestamp \
    > /dev/null

echo -e '\033[32m=== Done! ===\033[0m'
