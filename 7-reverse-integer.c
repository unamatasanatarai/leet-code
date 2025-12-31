#include <limits.h>
#include <stdio.h>

const int INT_MAX_10 = INT_MAX/10;
const int INT_MIN_10 = INT_MIN/10;

int reverse(int x) {
  int reversed = 0;
  while (x) {
    if (INT_MAX_10 < reversed || INT_MIN_10 > reversed) {
      return 0;
    }
    reversed = reversed * 10 + (x % 10);
    x /= 10;
  }
  return reversed;
}

int main() {
  struct TestCase {
    int input;
    int expected;
  };

  struct TestCase tests[] = {
      {123, 321},      {-123, -321},     {120, 21},       {0, 0},
      {1534236469, 0}, {-1534236469, 0}, {2147483647, 0}, {-2147483648, 0},
      {10, 1},         {-10, -1},        {100, 1},        {901000, 109},
      {INT_MAX, 0},    {INT_MIN, 0},
  };

  int total = sizeof(tests) / sizeof(tests[0]);
  int passed = 0;

  printf("Test cases for reverse(int x):\n\n");

  for (int i = 0; i < total; i++) {
    int input = tests[i].input;
    int expected = tests[i].expected;
    int result = reverse(input);

    printf("in: %d, expected: %d, result: %d", input, expected, result);

    if (result == expected) {
      printf("  ---> PASS\n");
      passed++;
    } else {
      printf("  ---> FAIL\n");
    }
  }

  printf("\nSummary\n");
  printf("Total passed: %d\n", passed);
  printf("Total failed: %d\n", total - passed);
  printf("Total tests: %d\n", total);

  return 0;
}
