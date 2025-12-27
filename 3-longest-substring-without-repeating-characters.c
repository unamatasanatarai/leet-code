#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct TestCase {
  int expected;
  char *text;
};

int max(int a, int b) {
  return a > b ? a : b;
}

int lengthOfLongestSubstring(char *s) {
  int s_len = strlen(s);
  int result = 0;
  int lft = 0;
  int seen[128];
  for (int i = 0; i < 128; i++) {
    seen[i] = -1;
  }

  unsigned char c;
  for (int rght = 0; rght < s_len; rght++) {
    c = (unsigned char)s[rght];
    lft = max(lft, seen[c] + 1);
    result = max(result, rght - lft + 1);
    seen[c] = rght;
  }
  return result;
}

int lengthOfLongestSubstringBruteForced(char *s) {
  int s_len = strlen(s);
  int max = 0;
  int lft = 0;

  int seen[128];
  for (int i = 0; i < 128; i++) {
    seen[i] = -1;
  }

  for (int rght = 0; rght < s_len; rght++) {
    unsigned char c = (unsigned char)s[rght];

    if (seen[c] >= lft) {
      lft = seen[c] + 1;
    }

    seen[c] = rght;
    max = max > rght - lft + 1 ? max : rght - lft + 1;
  }

  return max;
}

int main() {
  struct TestCase test_cases[] = {
      {3, "abcabcbb"},
      {1, "bbbbb"},
      {3, "pwwkew"},
      {0, ""},
      {1, " "},
      {9, "000qwerpoiuqwerpoiuqwerpoiu"},
      {55, "hijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789hijklmnopqrs"
           "tuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789hijklmnopqrstuvwxyzABCDE"
           "FGHIJKLMNOPQRSTUVWXYZ0123456789hijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQ"
           "RSTUVWXYZ0123456789hijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ012"
           "3456789hijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789"},
  };

  int size = sizeof(test_cases) / sizeof(test_cases[0]);
  for (int i = 0; i < size; i++) {
    int r = lengthOfLongestSubstring(test_cases[i].text);
    int ok = r == test_cases[i].expected;
    printf("r: %d e: %d str: '%s' !: %s \n", r, test_cases[i].expected,
           test_cases[i].text, (ok) ? "PASS" : "FAIL");
  }
}
