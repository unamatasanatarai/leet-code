class Solution:
    def isValid(self, s: str) -> bool:
        if not len(s):
            return True

        if len(s) == 1:
            return False

        stack = []
        pairs = {
            "(": ")",
            "{": "}",
            "[": "]",
        }

        for i in s:
            if i == "[" or i == "{" or i == "(":
                stack.append(i)
                continue
            if 0 == len(stack) or i != pairs[stack.pop()]:
                return False

        return len(stack) == 0


test_cases = [
    ("()", True),
    ("()[]{}", True),
    ("(]", False),
    ("([)]", False),
    ("{[]}", True),
    ("", True),  # empty string is valid
    ("(", False),  # single opening
    (")", False),  # single closing
    ("(()", False),  # missing closing
    ("())", False),  # extra closing
    ("((()))", True),  # nested same type
    ("{[()]}", True),  # nested mixed types
    ("{[(])}", False),  # incorrect nesting
    ("[]{}()", True),  # sequential valid pairs
    ("[", False),
    ("]", False),
    ("(((((((((())))))))))", True),  # deep nesting
    ("(((((((((()))))))))))", False),  # one extra closing
    ("()(()", False),
    ("(()())", True),
    ("{", False),
    ("}", False),
]

solution = Solution()
passed = 0

for i, (input_s, expected) in enumerate(test_cases, 1):
    result = solution.isValid(input_s)
    ok = result == expected

    print(
        f"Test {i:2d}: in: {repr(input_s)} → exp: {expected} | res: {result} :: "
        f"{'PASSED' if ok else 'FAILED'}"
    )

    if ok:
        passed += 1
    else:
        print("First failure — stopping.")
        break

print(f"\nSummary: {passed} / {len(test_cases)} tests passed")
