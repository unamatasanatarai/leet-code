#include <stdio.h>
#include <string.h>

int romanToInt(char *s) {
  int size = strlen(s);

  static const int trans[] = {
      ['I'] = 1,   ['V'] = 5,   ['X'] = 10,   ['L'] = 50,
      ['C'] = 100, ['D'] = 500, ['M'] = 1000,
  };

  if (size == 1) {
    return trans[(unsigned char)s[0]];
  }

  int total = 0;
  for (int i = 0; i < size; i++) {
    int current = trans[(unsigned char)s[i]];
    int next = trans[(unsigned char)s[i + 1]];
    if (current < next) {
      total += next - current;
      i++;
    } else {
      total += current;
    }
  }

  return total;
}

typedef struct {
  char *input;
  int expected;
} TestCase;

TestCase test_cases[] = {
    {"I", 1},
    {"II", 2},
    {"III", 3},
    {"IV", 4},
    {"V", 5},
    {"VI", 6},
    {"IX", 9},
    {"X", 10},
    {"XL", 40},
    {"XLIX", 49},
    {"L", 50},
    {"LVIII", 58},
    {"XC", 90},
    {"XCIX", 99},
    {"C", 100},
    {"CD", 400},
    {"D", 500},
    {"CM", 900},
    {"M", 1000},
    {"MCMXCIV", 1994},
    {"MMMCMXCIX", 3999}, // Maximum valid value
    {"MDCCLXXVI", 1776},
    {"MCMLIV", 1954},
    {"MMXXV", 2025},
    {"XIV", 14},
    {"XIX", 19},
    {"XLII", 42},
    {"CDXLIV", 444},
    {"CMXCIX", 999},
    {"MMM", 3000},
    {"MMMDCCCLXXXVIII", 3888}, // A longer valid one
};

int num_tests = sizeof(test_cases) / sizeof(test_cases[0]);

int main() {
  int passed = 0;
  int failed = 0;

  for (int i = 0; i < num_tests; i++) {
    char *input = test_cases[i].input;
    int expected = test_cases[i].expected;

    printf("\nTesting: \"%s\"\n", input);

    int result = romanToInt(input);

    if (result == expected) {
      printf("   Input:    \"%s\"\n", input);
      printf("   Expected: %d\n", expected);
      printf("   Got:      %d\n", result);
      passed++;
    } else {
      printf("! FAILED\n");
      printf("   Input:    \"%s\"\n", input);
      printf("   Expected: %d\n", expected);
      printf("   Got:      %d\n", result);
      failed++;
      return 1;
    }
  }

  printf("\n= * 40 \n");
  printf("SUMMARY: %d passed, %d failed\n", passed, failed);
  if (failed == 0) {
    printf("🎉 All tests passed!\n");
  }

  return 0;
}
