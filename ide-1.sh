#!/bin/bash

set -u
set -o pipefail

echo -e '\033[32m=== Stop nfp-sdk6-rte-debug ===\033[0m'
sudo systemctl stop nfp-sdk6-rte-debug
echo

echo -e '\033[32m=== nfp-sdk6-rte-debug-status ===\033[0m'
sudo systemctl status nfp-sdk6-rte-debug | cat | head -n 7
echo

echo -e '\033[32m=== Stop nfp-hwdbg-srv ===\033[0m'
sudo systemctl stop nfp-hwdbg-srv
echo

echo -e '\033[32m=== nfp-hwdbg-srv-status ===\033[0m'
sudo systemctl status nfp-hwdbg-srv | cat | head -n 7
echo
