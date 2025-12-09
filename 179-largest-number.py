from typing import List


class Solution:
    def largestNumber(self, nums: List[int]) -> str:
        strs = list(map(str, nums))
        strs.sort(key=lambda i: i * 10, reverse=True)
        return "0" if strs[0] == "0" else "".join(strs)


task = Solution()
cases = [
    [[10, 2], "210"],
    [[3, 30, 34, 5, 9], "9534330"],
    [[0, 0, 0, 0], "0"],
]

for case in cases:
    res = task.largestNumber(case[0])
    print(f"in: {case[0]}, expect: {case[1]}, res: {res}, ?: {case[1] == res}")
