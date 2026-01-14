#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// for n = 8, maximum arrays is 1430
#define MAX_RESULTS 1430

typedef struct State
{
    int left;
    int right;
    int depth;
    char ch;
} state_t;

char **generateParenthesis(int n, int *returnSize)
{
    char buff[2 * n + 1];
    char **results = malloc(sizeof(char *) * MAX_RESULTS);
    state_t stack[2 * 1430];

    int top = 0;
    stack[top++] = (state_t){0, 0, 0, 0};
    *returnSize = 0;

    while (top)
    {
        state_t s = stack[--top];

        if (s.depth)
        {
            buff[s.depth - 1] = s.ch;
        }

        if (s.left == n && s.right == n)
        {
            buff[s.depth] = '\0';

            char *ret = malloc(s.depth + 1);
            memcpy(ret, buff, s.depth + 1);
            results[(*returnSize)] = ret;
            (*returnSize)++;
            continue;
        }

        if (s.left < n)
        {
            stack[top++] = (state_t){s.left + 1, s.right, s.depth + 1, '('};
        }

        if (s.right < s.left && s.right < n)
        {
            stack[top++] = (state_t){s.left, s.right + 1, s.depth + 1, ')'};
        }
    }
    return results;
}

// ---------- helper: check valid parentheses ----------
bool is_valid_parentheses(const char *s)
{
    int balance = 0;
    for (int i = 0; s[i] != '\0'; i++)
    {
        if (s[i] == '(')
        {
            balance++;
        }
        else
        {
            balance--;
        }
        if (balance < 0)
        {
            return false;
        }
    }
    return balance == 0;
}

// ---------- helper: check uniqueness ----------
bool all_unique(char **arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (strcmp(arr[i], arr[j]) == 0)
            {
                return false;
            }
        }
    }
    return true;
}

// ---------- test harness ----------
int main(void)
{
    // Expected Catalan counts
    int test_cases[][2] = {
        {0, 1}, {1, 1}, {2, 2}, {3, 5}, {4, 14}, {5, 42}, {6, 132}, {7, 429}, {8, 1430},
    };

    int num_tests = sizeof(test_cases) / sizeof(test_cases[0]);
    int passed = 0;

    for (int i = 0; i < num_tests; i++)
    {
        int n = test_cases[i][0];
        int expected_count = test_cases[i][1];

        int resultSize = 0;
        char **result = generateParenthesis(n, &resultSize);

        bool correct_count = (resultSize == expected_count);

        bool all_valid = true;
        for (int j = 0; j < resultSize; j++)
        {
            if (!is_valid_parentheses(result[j]))
            {
                all_valid = false;
                break;
            }
        }

        bool unique = all_unique(result, resultSize);

        bool ok = correct_count && all_valid && unique;

        printf("Test %2d: n=%d -> count exp=%d, got=%d | valid=%s | unique=%s :: %s\n", i + 1, n, expected_count,
               resultSize, all_valid ? "true" : "false", unique ? "true" : "false", ok ? "PASSED" : "FAILED");

        if (!ok)
        {
            printf("First failure — stopping.\n");
            break;
        }
        else
        {
            passed++;
        }

        // free allocated memory
        for (int j = 0; j < resultSize; j++)
        {
            free(result[j]);
        }
        free(result);
    }

    printf("\nSummary: %d / %d tests passed\n", passed, num_tests);
    return 0;
}
