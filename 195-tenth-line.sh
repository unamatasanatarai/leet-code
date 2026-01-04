#!/usr/bin/env bash

file="195-tenth-line.txt"
count=0
while IFS= read -r line; do
    ((count += 1))
    [[ $count -eq 10 ]] && printf "%s" "$line" && exit
done <$file
