#!/usr/bin/env bash

file="193-valid-phone-numbers.txt"
regex='^([0-9]{3}-[0-9]{3}-[0-9]{4}|\([0-9]{3}\) [0-9]{3}-[0-9]{4})$'
while IFS= read -r line; do
    [[ $line =~ $regex ]] && printf "%s\n" "$line"
done <$file
