def a2t(top, left, arr):
    left = f'"{left}'
    print('   "', " ".join(list(top)))
    print(f"-{'-'.join(['-'] * (len(top) + 2))}")

    for i in range(len(arr)):
        row = arr[i]
        print(f"{left[i]}| {' '.join(map(str, row))}")


class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        plen = len(p)
        slen = len(s)
        dp = [[0] * (plen + 1) for _ in [0] * (slen + 1)]
        dp[0][0] = 1

        # Patterns like a*, a*b*, a*b*c* can match empty string
        for j in range(1, plen):
            if p[j] == "*":
                dp[0][j + 1] = dp[0][j - 1]

        for i in range(slen):
            for j in range(plen):
                if p[j] == "." or p[j] == s[i]:
                    dp[i + 1][j + 1] = dp[i][j]
                elif p[j] == "*":
                    # zero occurances
                    dp[i + 1][j + 1] = dp[i + 1][j - 1]
                    # 1+ occurances
                    if p[j - 1] == "." or p[j - 1] == s[i]:
                        if dp[i][j + 1] == 1:
                            dp[i + 1][j + 1] = 1

        a2t(p, s, dp)
        return dp[-1][-1] == 1

class Solution2:
    def isMatch(self, s: str, p: str) -> bool:
        plen = len(p)
        plenr = range(plen)

        dp = [False] * (plen + 1)
        dp[0] = True
        j=1
        for j in plenr:
            if p[j] == "*":
                dp[j + 1] = dp[j - 1]

        for char in s:
            new_dp = [False] * (plen + 1)
            for j in plenr:
                if p[j] == "." or p[j] == char:
                    new_dp[j + 1] = dp[j]
                elif p[j] == "*":
                    # zero occurances
                    new_dp[j + 1] = new_dp[j - 1]
                    # 1+ occurances
                    if p[j - 1] == "." or p[j - 1] == char:
                        new_dp[j + 1] = new_dp[j + 1] or dp[j + 1]
            dp = new_dp
        
        return dp[-1]

tests = [
    # leet
    ["aaa", "ab*a*c*a", True],
    # Edges
    ["", "", True],
    ["", "u*", True],
    ["", "*", False],
    ["", ".*", True],
    ["", ".", False],
    ["x", ".", True],
    ["aa", "", False],
    # Simple
    ["aa", "a", False],
    ["aa", "aa", True],
    ["ab", "ab", True],
    ["ab", "a.", True],
    ["ab", ".", False],
    ["a", ".", True],
    # *
    ["aa", "a*", True],
    ["aaaa", "a*", True],
    ["", "a*", True],
    ["b", "a*b", True],
    ["ba", "a*", False],
    ["miss", "mis*", True],
    ["aaa", "ab*a*c*a", True],
    # .
    ["ab", ".*", True],
    ["abc", "...", True],
    ["abcd", "...", False],
    ["", ".", False],
    ["x", ".", True],
    # .* mix
    ["aab", "c*a*b", True],
    ["mississippi", "mis*is*p*.", False],
    ["mississippi", "mis*is*ip*.", True],
    ["ab", ".*c", False],
    ["aaa", ".*", True],
    ["abc", ".*c", True],
    ["xyzzz", ".*z*", True],
    # empty string cases
    ["", "", True],
    ["", "a", False],
    ["", ".*", True],
    ["", "c*", True],
    ["", "c*d*e*", True],
    ["a", "", False],
    # tricky cases
    ["aaa", "ab*a*c*a", True],
    ["abcd", "d*", False],
    ["aaa", "aaaa", False],
    ["aaaaaaaaaaaaab", "a*a*a*a*a*a*a*a*a*a*b", True],
    ["abcd", ".*d", True],
    ["abbb", "ab*", True],
    ["abbb", "ab*bb", True],
    ["ab", ".*..", True],
]

re = Solution2()
allgood = True
for i in tests:
    m = re.isMatch(i[0], i[1])
    print(f"s: {i[0]}, p: {i[1]}, ex: {i[2]}, res:{m}, pass: {i[2] == m}")
    if m != i[2]:
        print("XXXXXXXXXXXXXXXXX")
        exit(1)
