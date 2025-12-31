#!/usr/bin/env bash
declare -A test_cases=(
    [123]=321
    [-123]=-321
    [120]=21
    [0]=0
    [1534236469]=0
    [-1534236469]=0
    [2147483647]=0
    [-2147483648]=0
    [10]=1
    [-10]=-1
    [100]=1
    [901000]=109
)

INT_MAX_10=214748364
INT_MIN_10=-214748364

passed=0

for test_case in "${!test_cases[@]}"; do
    x=$test_case
    reversed=0
    while ((x != 0)); do
        if ((reversed > INT_MAX_10 || reversed < INT_MIN_10)); then
            reversed=0
            break
        fi
        ((reversed = (reversed * 10) + (x % 10)))
        ((x = x / 10))
    done
    printf "<%d> <%d> <%d> " "$test_case" "$reversed" "${test_cases[$test_case]}"

    (($reversed == ${test_cases[$test_case]})) && printf "PASS\n" || printf "FAIL\n"
done
