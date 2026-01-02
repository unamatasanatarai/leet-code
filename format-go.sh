#!/usr/bin/env bash

[[ -z $1 ]] && echo "Usage: $0 file.go" && exit 1

go fmt "$1"
