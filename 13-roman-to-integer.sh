declare -A trans=(
    [I]=1
    [V]=5
    [X]=10
    [L]=50
    [C]=100
    [D]=500
    [M]=1000
)

declare -A test_cases=(
    ["I"]=1
    ["II"]=2
    ["III"]=3
    ["IV"]=4
    ["V"]=5
    ["VI"]=6
    ["IX"]=9
    ["X"]=10
    ["XI"]=11
    ["XII"]=12
    ["XL"]=40
    ["XLIX"]=49
    ["L"]=50
    ["LVIII"]=58
    ["XC"]=90
    ["XCIX"]=99
    ["C"]=100
    ["CD"]=400
    ["D"]=500
    ["CM"]=900
    ["M"]=1000
    ["MCMXCIV"]=1994
    ["MMMCMXCIX"]=3999
    ["MDCCLXXVI"]=1776
    ["MCMLIV"]=1954
    ["MMXXV"]=2025
    ["XIV"]=14
    ["XIX"]=19
    ["XLII"]=42
    ["CDXLIV"]=444
    ["CMXCIX"]=999
    ["MMM"]=3000
    ["MMMDCCCLXXXVIII"]=3888
)

passed=0
total="${#test_cases[@]}"
for roman in "${!test_cases[@]}"; do
    result=0
    for ((i = 0; i < ${#roman}; i++)); do
        char="${roman:i:1}"
        curr="${trans[$char]}"
        next=0

        if ((i + 1 < ${#roman})); then
            next="${trans[${roman:i+1:1}]}"
        fi

        if ((curr < next)); then
            ((result -= curr))
        else
            ((result += curr))
        fi
    done
    if [[ ${test_cases[$roman]} == $result ]]; then
        ((passed += 1))
    else
        echo failed $roman $result
    fi
done
echo "Passed $passed of $total"
