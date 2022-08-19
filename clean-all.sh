#!/bin/bash

set -o pipefail
set -u

echo -e '\033[32m=== make clean ===\033[0m'
make --makefile=Makefile-nfp4build clean > /dev/null

echo -e '\033[32m=== rm Makefile-nfp4build ===\033[0m'
rm Makefile-nfp4build

echo -e '\033[32m=== rmdir output/ ===\033[0m'
rmdir output

echo -e '\033[32m=== rm lib/*.pyc ===\033[0m'
rm -rf lib/*.pyc

echo -e '\033[32m=== rm gen-py/ ===\033[0m'
rm -rf gen-py/

echo -e '\033[32m=== rm venv/ ===\033[0m'
rm -rf venv/

echo -e '\033[32m=== Empty tmp.p4cfg ===\033[0m'
echo 'empty' > tmp.p4cfg

# no-key/
echo -e '\033[32m=== make clean (no-key/) ===\033[0m'
make --makefile=no-key/Makefile-nfp4build OUTDIR=output clean > /dev/null
echo -e '\033[32m=== rm Makefile-nfp4build (no-key/) ===\033[0m'
rm no-key/Makefile-nfp4build
echo -e '\033[32m=== Empty tmp.p4cfg (no-key/) ===\033[0m'
echo 'empty' > no-key/tmp.p4cfg
