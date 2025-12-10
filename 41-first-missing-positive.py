from typing import List


class Solution1:
    def firstMissingPositive(self, nums: List[int]) -> int:
        n = len(nums)
        for i in range(n):
            while 1 <= nums[i] <= n and nums[nums[i] - 1] != nums[i]:
                nums[nums[i] - 1], nums[i] = nums[i], nums[nums[i] - 1]

        for i in range(n):
            if nums[i] != i + 1:
                return i + 1
        return n + 1


class Solution:
    def firstMissingPositive(self, nums: List[int]) -> int:
        n = len(nums)
        seen = {x for x in nums if 1 <= x <= n}

        for i in range(1, n + 1):
            if i not in seen:
                return i

        return n + 1


test_cases = [
    {"in": [1, 2, 3, 4, 5, 6, 7, 8, 9], "out": 10},
    {"in": [3, 4, -1, 1], "out": 2},
    {"in": [5, 4, 3, 2], "out": 1},
    {"in": [1, 2, 0], "out": 3},
    {"in": [7, 8, 9], "out": 1},
    {"in": [1, 2, 3, 4, 5], "out": 6},
    {"in": [1], "out": 2},
    {"in": [2], "out": 1},
    {"in": [1, 3, 4, 5], "out": 2},
    {"in": [2, 3, 4, 5], "out": 1},
    {"in": [1, 2, 4, 5, 6], "out": 3},
    {"in": [1, 2, 3, 5], "out": 4},
    {"in": [1, 1, 1], "out": 2},
    {"in": [3, 3, 3, 3], "out": 1},
    {"in": [2, 2, 2, 1], "out": 3},
    {"in": [1, 2, 2, 2], "out": 3},
    {"in": [4, 4, 4, 1, 2, 3], "out": 5},
    {"in": [-1, -2, -3, 0], "out": 1},
    {"in": [0, 0, 0], "out": 1},
    {"in": [-5, -4, -100], "out": 1},
    {"in": [1, 2, 6, 7, 8], "out": 3},
    {"in": [10, 11, 12], "out": 1},
    {"in": [1, 1000, 1001], "out": 2},
    {"in": [5, 6, 7, 8, 100], "out": 1},
    {"in": [1, 2, 3, 4], "out": 5},
    {"in": [1, 2, 3], "out": 4},
    {"in": [1, 3, 2, 4], "out": 5},
    {"in": [2, 1], "out": 3},
    {"in": [3, 1, 2], "out": 4},
    {"in": [0], "out": 1},
    {"in": [-1], "out": 1},
    {"in": [100], "out": 1},
    {"in": [1, 0], "out": 2},
    {"in": [2, 1], "out": 3},
    {"in": [3, 4], "out": 1},
    {"in": list(range(1, 10001)), "out": 10001},
    {"in": list(range(2, 10001)) + [1], "out": 10001},
    {"in": [1, 2, 4, 5, 6, 7, 8, 3], "out": 9},
    {"in": [1, 3, 2, 6, 5, 4, 8, 7], "out": 9},
    {"in": [4, 1, 2, 3, 5, 7, 8, 9], "out": 6},
    {"in": [-1, 4, 2, 1, 9, 10], "out": 3},
    {"in": [0, 2, 2, 1, 1], "out": 3},
    {"in": [1, 2, 3, 10, 11, 12, 13], "out": 4},
]

fmp = Solution()

for idx, tc in enumerate(test_cases):
    arr = tc["in"][:]  # copy
    expected = tc["out"]
    result = fmp.firstMissingPositive(arr)

    print(
        f"idx={idx}, in={tc['in']}, out={expected}, result={result}, match={result == expected}"
    )

    if result != expected:
        print("===")
        exit(1)
