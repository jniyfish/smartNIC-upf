#!/bin/bash

set -u
set -o pipefail

echo -e '\033[32m=== hwdbg-srv-status ===\033[0m'
# sudo systemctl status nfp-hwdbg-srv | cat
tmp=$(sudo systemctl status nfp-hwdbg-srv | cat)
echo "$tmp" | grep '●'
echo "$tmp" | grep 'inactive (dead)' --color
echo "$tmp" | grep 'active (running)' --color
echo "$tmp" | grep 'failed' --color
echo

echo -e '\033[32m=== nfp-sdk6-rte-debug-status ===\033[0m'
# sudo systemctl status nfp-sdk6-rte-debug | cat #--no-pager
tmp=$(sudo systemctl status nfp-sdk6-rte-debug | cat)
echo "$tmp" | grep '●'
echo "$tmp" | grep 'inactive (dead)' --color
echo "$tmp" | grep 'active (running)' --color
echo "$tmp" | grep 'failed' --color
echo

# echo -e '\033[32m=== nfp-sdk6-rte-sim-status ===\033[0m'
# sudo systemctl status nfp-sdk6-rte-sim | cat
# echo

echo -e '\033[32m=== nfp-sdk6-rte-status ===\033[0m'
# sudo systemctl status nfp-sdk6-rte | cat | head -n 7
tmp=$(sudo systemctl status nfp-sdk6-rte | cat)
echo "$tmp" | grep '●'
echo "$tmp" | grep 'inactive (dead)' --color
echo "$tmp" | grep 'active (running)' --color
echo "$tmp" | grep 'failed' --color
echo

echo -e '\033[32m=== sudo nfp-nffw status ===\033[0m'
sudo nfp-nffw status | head -n 7
echo

echo -e '\033[32m=== nfp-hwinfo ===\033[0m'
sudo /opt/netronome/bin/nfp-hwinfo | head -n 8
echo
