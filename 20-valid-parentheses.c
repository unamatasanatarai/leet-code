#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

bool isValid(const char *s)
{
    if (!s[0])
        return true;

    int n = 0;
    while (s[n])
        n++;
    if (n & 1)
        return false;

    char stack[n];
    int top = 0;

    for (int i = 0; i < n; i++)
    {
        char c = s[i];
        if (c == '(')
        {
            stack[top++] = ')';
        }
        else if (c == '[')
        {
            stack[top++] = ']';
        }
        else if (c == '{')
        {
            stack[top++] = '}';
        }
        else
        {
            if (top == 0 || stack[--top] != c)
            {
                return false;
            }
        }
    }

    return top == 0;
}

#ifndef MAIN_BENCH
int main(void)
{
    struct
    {
        const char *input;
        bool expected;
    } tests[] = {
        {"()", true},
        {"()[]{}", true},
        {"(]", false},
        {"([)]", false},
        {"{[]}", true},
        {"", true},
        {"(", false},
        {")", false},
        {"(()", false},
        {"())", false},
        {"((()))", true},
        {"{[()]}", true},
        {"{[(])}", false},
        {"[]{}()", true},
        {"[", false},
        {"]", false},
        {"(((((((((())))))))))", true},
        {"(((((((((()))))))))))", false},
        {"()(()", false},
        {"(()())", true},
        {"{", false},
        {"}", false},
        {"){", false},
    };

    const int n_tests = sizeof(tests) / sizeof(tests[0]);
    int passed = 0;

    for (int i = 0; i < n_tests; i++)
    {
        bool result = isValid(tests[i].input);

        bool ok = (result == tests[i].expected);

        printf("Test %2d: %-22s → exp: %-5s | res: %-5s  → %s\n", i + 1, tests[i].input[0] ? tests[i].input : "(empty)",
               tests[i].expected ? "true" : "false", result ? "true" : "false", ok ? "PASSED" : "FAILED");

        if (ok)
        {
            passed++;
        }
        else
        {
            printf("   ↑ first failure — stopping early\n");
            break;
        }
    }

    printf("\nSummary: %d / %d tests passed\n", passed, n_tests);

    return 0;
}
#endif
