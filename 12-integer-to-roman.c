#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *intToRoman(int num) {
  if (num <= 0 || num > 3999) {
    return "";
  }

  static char res[20];
  char *ptr = res;

  const char *thousands[] = {"", "M", "MM", "MMM"};
  const char *hundreds[] = {"",  "C",  "CC",  "CCC",  "CD", "D", "DC", "DCC", "DCCC", "CM"};
  const char *tens[] = {"",  "X",  "XX",  "XXX",  "XL", "L", "LX", "LXX", "LXXX", "XC"};
  const char *ones[] = {"",  "I",  "II",  "III",  "IV", "V", "VI", "VII", "VIII", "IX"};

  strcpy(ptr, thousands[num / 1000]);
  ptr += strlen(ptr);
  strcpy(ptr, hundreds[num % 1000 / 100]);
  ptr += strlen(ptr);
  strcpy(ptr, tens[num % 100 / 10]);
  ptr += strlen(ptr);
  strcpy(ptr, ones[num % 10]);
  ptr += strlen(ptr);
  *ptr += '\0';

  return res;
}

int main() {
  struct TestCase {
    int input;
    const char *expected;
  } test_cases[] = {{0, ""},           {787878, ""},     {1, "I"},
                    {2, "II"},         {3, "III"},       {4, "IV"},
                    {5, "V"},          {6, "VI"},        {7, "VII"},
                    {8, "VIII"},       {9, "IX"},        {10, "X"},
                    {14, "XIV"},       {19, "XIX"},      {40, "XL"},
                    {44, "XLIV"},      {49, "XLIX"},     {50, "L"},
                    {58, "LVIII"},     {90, "XC"},       {94, "XCIV"},
                    {99, "XCIX"},      {100, "C"},       {400, "CD"},
                    {444, "CDXLIV"},   {500, "D"},       {900, "CM"},
                    {944, "CMXLIV"},   {1000, "M"},      {1987, "MCMLXXXVII"},
                    {1994, "MCMXCIV"}, {2024, "MMXXIV"}, {3999, "MMMCMXCIX"}};

  int total = sizeof(test_cases) / sizeof(test_cases[0]);
  int passed = 0;

  for (int i = 0; i < total; i++) {
    char *result = intToRoman(test_cases[i].input);

    int ok = (strcmp(result, test_cases[i].expected) == 0);

    printf("Test %d: in: <%d> exp: <%s> got: <%s> :: %s\n", i + 1,
           test_cases[i].input, test_cases[i].expected, result,
           ok ? "PASSED" : "FAILED");

    if (ok) {
      passed++;
    } else {
      exit(1);
    }
  }

  printf("\nSummary: %d / %d tests passed\n", passed, total);
  return (passed == total);
}
