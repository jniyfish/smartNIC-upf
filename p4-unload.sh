#!/bin/bash

set -e
set -u
set -o pipefail

echo -e '\033[0;91m=== unloading... ===\033[0m'
/opt/netronome/p4/bin/rtecli design-unload