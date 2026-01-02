class Solution:
    def intToRoman(self, num: int) -> str:
        if num == 0:
            return ""

        values = [1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1]
        symbols = ["M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"]

        res = []
        for v, s in zip(values, symbols):
            count, num = divmod(num, v)
            res.append(s * count)

        return "".join(res)

    def intToRomanCased(self, num: int) -> str:
        ones = ["I", "X", "C", "M"]
        fives = ["V", "L", "D"]
        i = 0
        ans = []

        while num > 0:
            n = num % 10
            if 1 <= n <= 3:
                ans.append(ones[i] * n)
            elif n == 4:
                ans.append(ones[i] + fives[i])
            elif 5 <= n <= 8:
                ans.append(fives[i] + ones[i] * (n - 5))
            elif n == 9:
                ans.append(ones[i] + ones[i + 1])

            i += 1
            num //= 10

        return "".join(ans[::-1])

    def intToRomanTable(self, num: int) -> str:
        singles = ["", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"]
        tens = ["", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"]
        hundreds = ["", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"]
        thousands = ["", "M", "MM", "MMM"]

        return (
            thousands[num // 1000]
            + hundreds[(num % 1000) // 100]
            + tens[(num % 100) // 10]
            + singles[num % 10]
        )

    def intToRomanBruteForce(self, num: int) -> str:
        values = [
            (1000, "M"),
            (900, "CM"),
            (500, "D"),
            (400, "CD"),
            (100, "C"),
            (90, "XC"),
            (50, "L"),
            (40, "XL"),
            (10, "X"),
            (9, "IX"),
            (5, "V"),
            (4, "IV"),
            (1, "I"),
        ]

        result = []

        for value, symbol in values:
            while num >= value:
                result.append(symbol)
                num -= value

        return "".join(result)


test_cases = [
    (1, ["I"]),
    (2, ["II"]),
    (3, ["III"]),
    (4, ["IV"]),
    (5, ["V"]),
    (6, ["VI"]),
    (7, ["VII"]),
    (8, ["VIII"]),
    (9, ["IX"]),
    (10, ["X"]),
    (14, ["XIV"]),
    (19, ["XIX"]),
    (40, ["XL"]),
    (44, ["XLIV"]),
    (49, ["XLIX"]),
    (50, ["L"]),
    (58, ["LVIII"]),
    (90, ["XC"]),
    (94, ["XCIV"]),
    (99, ["XCIX"]),
    (100, ["C"]),
    (400, ["CD"]),
    (444, ["CDXLIV"]),
    (500, ["D"]),
    (900, ["CM"]),
    (944, ["CMXLIV"]),
    (1000, ["M"]),
    (1987, ["MCMLXXXVII"]),
    (1994, ["MCMXCIV"]),
    (2024, ["MMXXIV"]),
    (3999, ["MMMCMXCIX"]),
]

solution = Solution()
passed = 0

for i, (input_num, expected) in enumerate(test_cases, 1):
    result = solution.intToRoman(input_num)
    ok = result in expected

    print(
        f"in: <{input_num}> exp: <{expected}> res: <{result}> :: {'PASSED' if ok else 'FAILED'}"
    )

    if ok:
        passed += 1
    else:
        exit()

print(f"Summary: {passed} / {len(test_cases)} tests passed")
