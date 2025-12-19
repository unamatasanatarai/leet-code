from typing import List


# Left → first place x could go (first occurance)
def bisect_left(arr, search):
    lft, rght = 0, len(arr)

    while lft < rght:
        mid = (lft + rght) // 2

        if arr[mid] < search:
            lft = mid + 1
        else:
            rght = mid

    return lft


def insert(arr, idx, val):
    arr.append(0)
    for i in range(len(arr) - 1, idx, -1):
        arr[i] = arr[i - 1]
    arr[idx] = val

class Solution:
    #brute force
    def countSmaller(self, nums: List[int]) -> List[int]:
        nums_len = len(nums)
        if nums_len == 0:
            return []
        if nums_len == 1:
            return [0]

        nums_sorted = [nums[-1]]
        result = [0]

        for i in range(nums_len - 2, -1, -1):
            num = nums[i]
            idx = bisect_left(nums_sorted, num)
            insert(nums_sorted, idx, num)
            result.append(idx)

        return result[::-1]


test_cases = [
    # original (fixed)
    [[5, 2, 6, 1], [2, 1, 1, 0]],
    [[], []],
    [[1], [0]],
    [[1, 2, 3, 4, 5], [0, 0, 0, 0, 0]],
    [[5, 4, 3, 2, 1], [4, 3, 2, 1, 0]],
    [[3, 3, 3, 3], [0, 0, 0, 0]],
    [[1, 3, 2, 4], [0, 1, 0, 0]],
    [[8, 4, 2, 1, 9, 3], [4, 3, 1, 0, 1, 0]],
    [[10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0],
     [10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0]],
    [[1, 1, 1, 2, 2, 2], [0, 0, 0, 0, 0, 0]],
    [[2, 0, 4, 1, 3], [2, 0, 2, 0, 0]],
    [[-1, -2, -3, -4], [3, 2, 1, 0]],
    [[-5, -5, 0, 0, 5], [0, 0, 0, 0, 0]],
    [[7, 1, 5, 3, 6, 4], [5, 0, 2, 0, 1, 0]],
    [[1, 9, 3, 8, 2, 7, 4, 6, 5],
     [0, 7, 1, 5, 0, 3, 0, 1, 0]],
    [[4, 4, 4, 4, 4], [0, 0, 0, 0, 0]],
    [[6, 5, 4, 3, 2, 1, 7], [5, 4, 3, 2, 1, 0, 0]],
    [[2, 3, 1, 4, 0], [2, 2, 1, 1, 0]],
    [[9, 8, 7, 6, 5, 4, 3, 2, 1], [8, 7, 6, 5, 4, 3, 2, 1, 0]],
    [[1, 2, 3, 2, 1], [0, 1, 2, 1, 0]],
]

passed = 0
failed = 0

sol = Solution()

for input, expected in test_cases:
    print(f"\nTesting: {input}")
    result = sol.countSmaller(input)

    if result == expected:
        print(f"   Input:    {input}")
        print(f"   Expected: {expected}")
        print(f"   Got:      {result}\n")
        passed += 1
    else:
        print("! FAILED")
        print(f"   Input:    {input}")
        print(f"   Expected: {expected}")
        print(f"   Got:      {result}\n")
        failed += 1
        exit()

print("\n" + "=" * 40)
print(f"SUMMARY: {passed} passed, {failed} failed")
if failed == 0:
    print("🎉 All tests passed!")
