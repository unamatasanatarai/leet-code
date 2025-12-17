#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct TestCase {
  int expected;
  const char *text;
};

int lengthOfLastWordBruteForce(const char *s) {
  int len = strlen(s) - 1;
  int cnt = 0;
  for (int i = len; i >= 0; i--) {
    char c = s[i];

    if (c == ' ' && cnt == 0) {
      continue;
    }

    if (c == ' ' && cnt != 0) {
      return cnt;
    }
    cnt++;
  }
  return cnt;
}

int lengthOfLastWord(const char *s) {
  // 1. find the length of the string by moving pointer to the right
  // 2. trim trailing whitespace by moving to the left and comparing against ' '
  // (od of word)
  // 3. find next whitespace (begining of word)
  // 4. return 2-3
  const char *end = s;
  while (*end)
    end++;

  while (end > s && *(end - 1) == ' ')
    end--;
  const char *start = end;
  while (start > s && *(start - 1) != ' ')
    start--;
  return end - start;
}

int main() {
  struct TestCase test_cases[] = {
      {0, "   "},
      {4, "   fly me   to   the moon  "},
      {5, "Hello World"},
      {6, "luffy is still joyboy"},
      {1, "a"},
      {1, "a "},
      {0, "   "},
      {0, ""},
      {4, "word"},
      {4, "last    "},
      {4, "    first last"},
      {4, "multiple   spaces   here"},
      {1, "a b c d e"},
      {26, "abcdefghijklmnopqrstuvwxyz"},
  };

  int size = sizeof(test_cases) / sizeof(test_cases[0]);
  for (int i = 0; i < size; i++) {
    int r = lengthOfLastWord(test_cases[i].text);
    int ok = r == test_cases[i].expected;
    printf("r: %d e: %d str: '%s' !: %s \n", r, test_cases[i].expected,
           test_cases[i].text, (ok) ? "PASS" : "FAIL");
  }
}
