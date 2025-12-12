#!/usr/bin/env bash

[[ -z $1 ]] && echo "Usage: $0 file.c" && exit 1
clang-format-mp-20 -i -style=LLVM "$1"

