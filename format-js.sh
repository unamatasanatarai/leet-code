#!/usr/bin/env bash

[[ -z $1 ]] && echo "Usage: $0 file.js" && exit 1

prettier --tab-width 4 --write "$1"

