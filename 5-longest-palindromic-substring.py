class Solution:
    def longestPalindrome(self, s: str) -> str:
        if len(s) < 2:
            return s

        t = "^#" + "#".join(s) + "#$"
        n = len(t)
        lengths = [0] * n

        center = rightmost = 0
        best_idx = best_width = 0

        for idx in range(1, n - 1):
            if idx < rightmost:
                mirror = 2 * center - idx
                lengths[idx] = min(rightmost - idx, lengths[mirror])

            idx_len = lengths[idx]
            while t[idx + idx_len + 1] == t[idx - idx_len - 1]:
                idx_len += 1
            lengths[idx] = idx_len

            if idx + idx_len > rightmost:
                center = idx
                rightmost = idx + idx_len
                if idx_len > best_width:
                    best_width = idx_len
                    best_idx = idx

        start = (best_idx - best_width) // 2
        return s[start : start + best_width]

    def longestPalindromeBruteForce(self, s: str) -> str:
        s_copy = f"#{'#'.join(s)}#"
        s_len = len(s_copy)

        if s_len <= 3:
            return s

        idx = 0
        padmax = -1

        for i in range(s_len):
            rght = lft = i

            while lft >= 0 and rght < s_len and s_copy[lft] == s_copy[rght]:
                lft -= 1
                rght += 1

            pad = (rght - lft - 2) // 2

            if pad > padmax:
                idx = (i - pad) // 2
                padmax = pad

        return s[idx : idx + padmax]


test_cases = [
    ("forgeeksskeegfor", ["geeksskeeg"]),
    ("abba", ["abba"]),
    ("abc", ["a", "b", "c"]),
    ("aaabc", ["aaa"]),
    ("a", ["a"]),
    ("abbd", ["bb"]),
    ("babad", ["bab", "aba"]),
    ("aaaa", ["aaaa"]),
    ("racecar", ["racecar"]),
    ("aacabdkacaa", ["aca"]),
    ("cbaaa", ["aaa"]),
    ("Aa", ["A", "a"]),
    ("", [""]),
]

solution = Solution()
passed = 0

for i, (input_str, expected) in enumerate(test_cases, 1):
    result = solution.longestPalindrome(input_str)
    ok = result in expected

    print(
        f"Test {i}: {'PASSED' if ok else 'FAILED'} Input: <{input_str}> Expected: {expected}"
    )
    print(f"  Result:   <{result}>\n")

    if ok:
        passed += 1
    else:
        exit()

print(f"Summary: {passed} / {len(test_cases)} tests passed")
