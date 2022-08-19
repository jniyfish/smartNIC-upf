#!/bin/bash

set -e
set -u
set -o pipefail

echo -e '\033[0;91m=== Loading firmware... ===\033[0m'
/opt/netronome/p4/bin/rtecli -p 20206 design-load -p output/pif_design.json -f output/main.nffw

#/opt/netronome/p4/bin/rtecli -p 20206 design-load -p output/pif_design.json -c init-with-key.p4cfg -f output/main.nffw
#/opt/netronome/p4/bin/rtecli -p 20206 design-load -p output/pif_design.json -c init-with-key.p4cfg -f output/main.nffw
#/opt/netronome/p4/bin/rtecli -p 20206 design-load -p output/pif_design.json -c init-with-key.p4cfg -f output/main.nffw
echo -e '\033[0;91m=== DONE! ===\033[0m'
