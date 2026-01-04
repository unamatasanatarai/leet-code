#!/usr/bin/env bash

declare -a cols

while IFS=' ' read -ra fields; do
  for ((i=0; i<${#fields[@]}; i++)); do
      cols[i]+=" ${fields[i]}"
  done
done < 194-transpose-file.txt

for ((i=0; i<${#cols[@]}; i++)); do
  printf '%s\n' "${cols[i]:1}"
done
