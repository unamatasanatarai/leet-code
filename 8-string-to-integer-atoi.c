#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INT_MAX_DIV10 INT_MAX / 10
#define INT_MAX_LASTD INT_MAX % 10

int myAtoiPointer(char *s) {
  if (!s) {
    return 0;
  }
  int r = 0;
  int sign = 1;
  char c;

  while ((c = *s) == ' ') {
    s++;
  }

  if (c == '-' || c == '+') {
    if (c == '-')
      sign = -1;
    s++;
    c = *s;
  }

  while (c >= '0' && c <= '9') {
    int digit = c - '0';

    if (r > INT_MAX_DIV10 || (r == INT_MAX_DIV10 && digit > INT_MAX_LASTD)) {
      return sign == 1 ? INT_MAX : INT_MIN;
    }

    r = r * 10 + digit;
    s++;
    c = *s;
  }

  return r * sign;
}

int myAtoi(char *s) {
  if (!s) {
    return 0;
  }
  int r = 0;
  int sign = 1;
  unsigned int idx = 0;

  while (s[idx] && s[idx] == ' ') {
    idx++;
  }

  if (s[idx] == '-' || s[idx] == '+') {
    sign = s[idx] == '-' ? -1 : 1;
    idx++;
  }

  while (s[idx] >= '0' && s[idx] <= '9') {

    if (r > INT_MAX_DIV10 ||
        (r == INT_MAX_DIV10 && (s[idx] - '0') > INT_MAX % 10)) {
      return sign == 1 ? INT_MAX : INT_MIN;
    }

    r = r * 10 + (s[idx] - '0');

    idx++;
  }

  return r * sign;
}

int main() {
  struct TestCase {
    const char *input;
    int expected;
  };

  struct TestCase tests[] = {
      {"42", 42},
      {"-9", -9},
      {"-+9", 0},
      {"   -42", -42},
      {"+123", 123},
      {"0", 0},
      {"000123", 123},
      {"   000", 0},
      {"2147483647", INT_MAX},  //  2^31 - 1
      {"-2147483648", INT_MIN}, // -2^31

      {"2147483646", 2147483646}, // overflow positive
      {"2147483648", INT_MAX},    // overflow positive
      {"-2147483649", INT_MIN},   // overflow negative
      {"9999999999", INT_MAX},
      {"-9999999999", INT_MIN},
      {"100000000000", INT_MAX},

      {"   4193 with words", 4193},
      {"   +  007", 0},
      {"  -00123abc", -123},

      {"words and 987", 0},
      {"+-12", 0},
      {"-+12", 0},
      {"++123", 0},
      {"--13", 0},
      {"+ 123", 0},
      {"  +abc", 0},

      {"", 0},
      {"   ", 0},
      {"\t\n\r\f\v  ", 0},

      // Very long valid number (should clamp)
      {"9223372036854775807", INT_MAX}, // within long long, but > INT_MAX
      {"-9223372036854775808", INT_MIN},

      // Numbers with trailing junk (stop at first non-digit)
      {"123456789012345", INT_MAX},
      {"-12345abc", -12345},
      {"42 is the answer", 42},
      {"-88 meters", -88},

      // Edge cases around zero
      {"+0", 0},
      {"-0", 0},
      {"  +00000", 0},
      {"-000", 0},

      // Multiple signs or malformed signs
      {"+++123", 0},
      {" - -123", 0},
      {"1+23", 1}, // stops after first number
  };

  int total = sizeof(tests) / sizeof(tests[0]);
  int passed = 0;

  printf("Test cases for myAtoi(char* s) - LeetCode 8\n");
  printf("-----------------------------------------\n\n");

  for (int i = 0; i < total; i++) {
    const char *input = tests[i].input;
    int expected = tests[i].expected;

    int result = myAtoiPointer((char *)input);

    printf("Input: <%s> expected: <%d>, got: <%d>", input, expected, result);

    if (result == expected) {
      printf("  → PASS\n");
      passed++;
    } else {
      printf("  → FAIL\n");
      exit(1);
    }
  }

  printf("\nSummary\n");
  printf("-----------------------------------------\n");
  printf("Total tests : %3d\n", total);
  printf("Passed      : %3d\n", passed);
  printf("Failed      : %3d\n", total - passed);
  printf("Pass rate   : %.1f%%\n", (passed * 100.0) / total);

  return 0;
}
