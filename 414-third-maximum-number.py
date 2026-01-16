from typing import List


class Solution:
    def thirdMax(self, nums: List[int]) -> int:
        if not len(nums):
            return 0

        m = float("-inf")
        first = second = third = m

        for num in nums:
            if num == first or num == second or num == third:
                continue

            if num > first:
                first, second, third = num, first, second
            elif num > second:
                second, third = num, second
            elif num > third:
                third = num

        return first if third == m else third


test_cases = [
    # Basic cases
    ([3, 2, 1], 1),
    ([1, 2], 2),  # only 2 distinct → return max
    ([2, 2, 3, 1], 1),
    ([1, 1, 1], 1),  # only 1 distinct
    ([5], 5),  # single element
    ([], 0),  # edge: empty → usually return any sentinel (problem dependent)
    # With duplicates
    ([2, 2, 2, 1, 5, 5, 3], 2),
    ([10, 9, 9, 8, 8, 7, 7], 8),
    ([4, 4, 4, 4], 4),
    # All same
    ([7, 7, 7, 7, 7], 7),
    ([-1, -1, -1], -1),
    # Negative numbers
    ([-1, -2, -3], -3),
    ([-5, -5, 0, 3, 1], 0),
    ([-10, -20, -5, -30], -20),
    # Mixed positive / negative / zero
    ([0, 0, 0], 0),
    ([1, 0, -1], -1),
    ([100, -100, 50, -50, 0], 0),
    # Large numbers / close values
    ([999999999, 999999998, 999999997], 999999997),
    ([1, 2, 3, 4, 5, 6, 7], 5),
    # Already sorted / reverse sorted
    ([1, 2, 3, 4, 5], 3),
    ([5, 4, 3, 2, 1], 3),
    ([10, 8, 6, 4, 2], 6),
    # Many duplicates, few distinct
    ([7] * 100 + [8, 9], 7),
    ([1, 1, 1, 2, 2, 3, 3], 1),
    # Three same max values + smaller
    ([42, 42, 42, 10, 5], 5),
    # Very long but only 2 distinct
    ([100] * 500 + [-999] * 300, 100),
    # Only two distinct values
    ([3, 3, 3, 1, 1, 1], 3),
    ([-(2**31) - 1, -(2**31) - 1, -(2**31) - 2], -(2**31) - 1),
]

# ────────────────────────────────────────────────
#          Test runner
# ────────────────────────────────────────────────

solution = Solution()
passed = 0
failed_tests = []

print("Testing thirdMax()\n" + "═" * 50)

for i, (nums, expected) in enumerate(test_cases, 1):
    result = solution.thirdMax(nums)
    ok = result == expected

    status = "PASSED" if ok else "FAILED"
    print(
        f"Test {i:2d} | nums = {nums} → exp = {expected:2} | got = {result:2}  → {status}"
    )

    if ok:
        passed += 1
    else:
        failed_tests.append((i, nums, expected, result))

print("\n" + "═" * 50)
print(
    f"Summary: {passed}/{len(test_cases)} tests passed ({passed / len(test_cases) * 100:.1f}%)"
)

if failed_tests:
    print("\nFailed tests:")
    for idx, nums, exp, got in failed_tests:
        print(f"  Test {idx:2d} | input: {nums}")
        print(f"         | exp: {exp}   got: {got}")
