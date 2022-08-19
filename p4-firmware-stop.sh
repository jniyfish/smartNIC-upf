#!/bin/bash

set -u
set -o pipefail

echo -e '\033[32m=== Stop nfp-sdk6-rte ===\033[0m'
sudo systemctl stop nfp-sdk6-rte
echo

echo -e '\033[32m=== nfp-sdk6-rte-status ===\033[0m'
sudo systemctl status nfp-sdk6-rte | cat | head -n 7
echo
