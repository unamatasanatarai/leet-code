#!/usr/bin/env bash

declare -A test_cases=(
    ["a"]="a"
    ["flowe,flow,fligh"]="fl"
    ["dog,racecar,car"]=""
    ["alone"]="alone"
    ["test,test,test"]="test"
    ["ab,abc,abcd"]="ab"
    ["prefix,prefixes,prefixing"]="prefix"
    ["abc,def,ghi"]=""
    ["x,y,z"]=""
    [",abc,abcd"]=""
    ["abc,,abcd"]=""
    ["", "", ""]=""
    ["Flower,flow,flight"]=""
    ["Case,Casefold,Casey"]="Case"
    ["aa,a"]="a"
    ["a,aa"]="a"
    ["aaa,aa,a"]="a"
    ["interview,interrupt,integrate"]="int"
    ["b,ba,bac"]="b"
    ["longprefix1,longprefix2,longprefix3"]="longprefix"
    ["12345,123,123abc"]="123"
    ["@home,@host,@hover"]="@ho"
    [" hello, hello world, hello"]=" hello"
)

passed=0
failed=0
test_number=0
for test_case in "${!test_cases[@]}"; do
    ((test_number++))
    IFS=',' read -ra words <<<"$test_case"

    # let's compare first character. If at least one is different, return false
    prefix="${words[0]}"
    expected="${test_cases[$test_case]}"
    first=${prefix:0:1}

    printf "%02d. in: <%s> exp: <%s> " "$test_number" "$test_case" "$expected"

    [[ "${#words[@]}" == 1 ]] && ((passed += 1)) && echo "found: <$prefix>" && continue

    ## if prefix is empty and other elements are empty
    if [[ -z "$prefix" ]]; then
        total=${#words[@]}
        cnt=0
        for word in "${words[@]}"; do
            [[ -z "$word" ]] && ((cnt++))
        done
        [[ $total == $cnt ]] && ((passed += 1)) && echo "found: <$prefix>" && continue 2
    fi

    # afterwords, take word, and start trimming from the right
    for ((len = "${#prefix}"; len > 0; len--)); do
        match_cnt=0
        prefix="${prefix:0:$len}"
        for word in "${words[@]}"; do
            if [[ "$prefix" == "${word:0:$len}" ]]; then
                ((match_cnt += 1))
            fi
            if [[ $match_cnt == ${#words[@]} && "$expected" == "$prefix" ]]; then
                echo "found: <$prefix>"
                ((passed += 1))
                continue 3
            fi
        done
    done
    prefix="${prefix:0:$len}"
    if [[ "$expected" == "" ]]; then
        ((passed += 1))
        echo "found: <$prefix>"
    fi
done

echo "total: ${#test_cases[@]}"
echo "Passed: $passed"
echo "Failed: $failed"
