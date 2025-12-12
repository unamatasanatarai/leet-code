from typing import List


class Solution:
    def rotate(self, nums: List[int], k: int) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        l = len(nums)
        k = k % l
        if k == 0:
            return

        start = 0
        end = l - 1
        while start < end:
            nums[start], nums[end] = nums[end], nums[start]
            start += 1
            end -= 1

        start = 0
        end = k - 1
        while start < end:
            nums[start], nums[end] = nums[end], nums[start]
            start += 1
            end -= 1

        start = k
        end = l - 1
        while start < end:
            nums[start], nums[end] = nums[end], nums[start]
            start += 1
            end -= 1


tests = [
    [
        [1, 2, 3],
        0,
        [1, 2, 3],
    ],
    [
        [1, 2, 3],
        1,
        [3, 1, 2],
    ],
    [
        [1, 2, 3],
        2,
        [2, 3, 1],
    ],
    [
        [1, 2, 3],
        3,
        [1, 2, 3],
    ],
    [
        [1, 2, 3, 4, 5, 6, 7],
        3,
        [5, 6, 7, 1, 2, 3, 4],
    ],
    [
        [-1, -100, 3, 99],
        2,
        [3, 99, -1, -100],
    ],
]

sol = Solution()
for test in tests:
    print("---------")
    print(f"< {test[0]}, k: {test[1]}")
    sol.rotate(test[0], test[1])
    ok = test[0] == test[2]
    print(f"> {test[2]}, ok: {ok}")
    print(f": {test[0]}")

    if not ok:
        print("^^^")
        exit(1)
