from typing import List


class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        stack = [(0, 0, 0, "")]
        buff = [0] * (2 * n)
        results = []
        results_append = results.append
        stack_append = stack.append
        stack_pop = stack.pop

        while stack:
            lft, rght, depth, chr = stack_pop()

            if depth:
                buff[depth - 1] = chr

            if lft == n and rght == n:
                results_append("".join(buff[:depth]))
                continue

            if lft < n:
                stack_append((lft + 1, rght, depth + 1, "("))

            if rght < n and rght < lft:
                stack_append((lft, rght + 1, depth + 1, ")"))
        return results


# Expected Catalan counts for generateParenthesis
# C0=1, C1=1, C2=2, C3=5, C4=14, C5=42, C6=132, C7=429, C8=1430
test_cases = [
    (0, 1),
    (1, 1),
    (2, 2),
    (3, 5),
    (4, 14),
    (5, 42),
    (6, 132),
    (7, 429),
    (8, 1430),
]


def is_valid_parentheses(s: str) -> bool:
    balance = 0
    for ch in s:
        if ch == "(":
            balance += 1
        else:
            balance -= 1
        if balance < 0:
            return False
    return balance == 0


solution = Solution()
passed = 0

for i, (n, expected_count) in enumerate(test_cases, 1):
    result = solution.generateParenthesis(n)

    correct_count = len(result) == expected_count
    all_valid = all(is_valid_parentheses(s) for s in result)
    all_unique = len(result) == len(set(result))

    ok = correct_count and all_valid and all_unique

    print(
        f"Test {i:2d}: n={n} → "
        f"count exp={expected_count}, got={len(result)} | "
        f"valid={all_valid} | unique={all_unique} :: "
        f"{'PASSED' if ok else 'FAILED'}"
    )

    if not ok:
        print("First failure — stopping.")
        break
    else:
        passed += 1

print(f"\nSummary: {passed} / {len(test_cases)} tests passed")
