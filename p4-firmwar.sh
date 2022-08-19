#!/bin/bash

set -u
set -o pipefail

echo -e '\033[32m=== Unload Firmware (Basic Firmware) ===\033[0m'
sudo nfp-nffw unload -n 0

echo -e '\033[32m=== Kernel Module ===\033[0m'
sudo modprobe -v -r nfp && sudo modprobe -v nfp nfp_dev_cpp=1 nfp_pf_netdev=0
echo

echo -e '\033[32m=== Start nfp-sdk6-rte ===\033[0m'
sudo systemctl start nfp-sdk6-rte
echo

echo -e '\033[32m=== nfp-sdk6-rte-status ===\033[0m'
sudo systemctl status nfp-sdk6-rte | cat | head -n 7
echo
