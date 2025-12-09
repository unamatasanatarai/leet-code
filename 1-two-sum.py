from typing import List


class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        for i in range(0, len(nums)):
            for j in range(i + 1, len(nums)):
                if nums[i] + nums[j] == target:
                    return [i, j]

        return [0, 0]


class Solution2:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        for i in range(len(nums)):
            sub = target - nums[i]
            if sub in nums and i != nums.index(sub):
                return [i, nums.index(sub)]
        return [0, 0]


class Solution3:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        seen = {}
        for i in range(len(nums)):
            seen[nums[i]] = i

        for i in range(len(nums)):
            diff = target - nums[i]
            if diff in seen and seen[diff] != i:
                return [i, seen[diff]]
        return [0, 0]


task = Solution3()
cases = [
    [[2, 7, 11, 15], 9, [0, 1]],
    [[3, 2, 4], 6, [1, 2]],
    [[3, 3], 6, [0, 1]],
    [[3, 2, 3], 6, [0, 2]],
    [[1, 1, 1, 1, 1, 4, 1, 1, 1, 1, 1, 7, 1, 1, 1, 1, 1], 11, [5, 11]],
]

for case in cases:
    res = sorted(task.twoSum(case[0], case[1]))
    print(
        f"in: {case[0]}, case: {case[1]}, expect: {sorted(case[2])}, res: {res}, ?: {sorted(case[2]) == res}"
    )
