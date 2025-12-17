#!/usr/bin/env bash

cases=(
    "   |0"
    "   fly me   to   the moon  |4"
    "Hello World|5"
    "luffy is still joyboy|6"
    "a|1"
    "a |1"
    "   |0"
    "|0"
    "word|4"
    "last    |4"
    "    first last|4"
    "multiple   spaces   here|4"
    "a b c d e|1"
    "abcdefghijklmnopqrstuvwxyz|26"
)

echo "BRUTE FORCE"
for case in "${cases[@]}"; do
    IFS="|" read -r str expected <<<"$case"

    len="${#str}"
    cnt=0
    for ((i = $len - 1; i >= 0; i--)); do
        char="${str:i:1}"
        [[ "$char" == " " ]] && [[ $cnt == 0 ]] && continue
        [[ "$char" == " " ]] && [[ $cnt > 0 ]] && break
        ((cnt += 1))
    done
    echo "Input: '$str' Expected: $expected Counted: $cnt"
done

echo "CLEVER"
for case in "${cases[@]}"; do
    IFS="|" read -r str expected <<<"$case"

    wip="${str%"${str##*[![:space:]]}"}"

    last_word="${wip##* }"

    [[ -z "$last_word" ]] && cnt=0 || cnt=${#last_word}

    echo "Input: '$str' Expected: $expected Counted: $cnt"
done
