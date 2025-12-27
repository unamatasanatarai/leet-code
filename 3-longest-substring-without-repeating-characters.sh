#!/usr/bin/env bash

test_cases=(
    "abcabcbb|3"
    "bbbbb|1"
    "pwwkew|3"
    "|0"
    " |1"
    "000qwerpoiuqwerpoiuqwerpoiu|9"
    "hijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789hijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789hijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789hijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789hijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789hijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789|55"
)

for test_case in "${test_cases[@]}"; do
    IFS='|' read -r s expected <<<"$test_case"

    s_len=${#s}
    result=0
    lft=0

    # this is uber important, as this is a loop afterall
    unset seen
    declare -A seen

    for ((rght = 0; rght < s_len; rght++)); do
        c="${s:$rght:1}"

        if [[ -v seen[$c] ]]; then
            tmp=$((seen[$c] + 1))
            if (("$lft" < $tmp)); then
                lft="$tmp"
            fi
        fi

        tmp=$((rght - lft + 1))
        if (("$result" < $tmp)); then
            result=$tmp
        fi

        seen[$c]=$rght
    done

    echo -n "<$s> <$expected> : <$result> = "
    [[ "$result" -eq "$expected" ]] && echo "PASS" || echo "FAIL"
done
