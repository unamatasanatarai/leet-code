#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * Note: The returned array must be malloced, assume caller calls free().
 */
char **letterCombinations(char *digits, int *returnSize) {

  *returnSize = 0;
  if (!digits || digits[0] == '\0')
    return 0;

  static const char *map[] = {"",    "",    "abc",  "def", "ghi",
                              "jkl", "mno", "pqrs", "tuv", "wxyz"};
  static const int map_lenghts[] = {0, 0, 3, 3, 3, 3, 3, 4, 3, 4};

  int digits_len = strlen(digits);
  char *cpy = digits;
  int result_len = 1;
  while (*cpy) {
    int digit = *cpy - '0';
    if (digit < 2) {
      return 0;
    }
    result_len *= map_lenghts[digit];
    cpy++;
  }
  *returnSize = result_len;

  char **result = malloc(sizeof(char *) * result_len);

  for (int i = 0; i < result_len; i++) {
    result[i] = malloc(sizeof(char) * digits_len + 1);
    result[i][digits_len] = '\0';
  }

  int repeat = result_len;
  for (int i = 0; i < digits_len; i++) {
    int digit = digits[i] - '0';
    const char *letters = map[digit];
    int letters_len = strlen(letters);
    repeat /= letters_len;

    for (int j = 0; j < result_len; j++) {
      result[j][i] = letters[(j / repeat) % letters_len];
    }
  }

  return result;
}

struct TestCase {
  char *input;
  char *expected[256];
  int expectedSize;
  int checkContent;
};

int main(void) {
  struct TestCase tests[] = {

      {"", {}, 0, 1},
      {"1", {}, 0, 1},
      {"0", {}, 0, 1},

      {"2", {"a", "b", "c"}, 3, 1},
      {"7", {"p", "q", "r", "s"}, 4, 1},
      {"9", {"w", "x", "y", "z"}, 4, 1},

      {"23", {"ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"}, 9, 1},

      {"79",
       {"pw", "px", "py", "pz", "qw", "qx", "qy", "qz", "rw", "rx", "ry", "rz",
        "sw", "sx", "sy", "sz"},
       16,
       1},

      {"234",
       {"adg", "adh", "adi", "aeg", "aeh", "aei", "afg", "afh", "afi",

        "bdg", "bdh", "bdi", "beg", "beh", "bei", "bfg", "bfh", "bfi",

        "cdg", "cdh", "cdi", "ceg", "ceh", "cei", "cfg", "cfh", "cfi"},
       27,
       1},

      {"29",
       {"aw", "ax", "ay", "az", "bw", "bx", "by", "bz", "cw", "cx", "cy", "cz"},
       12,
       1},

      {"7249",
       {"pagw", "pagx", "pagy", "pagz", "pahw", "pahx", "pahy", "pahz", "paiw",
        "paix", "paiy", "paiz", "pbgw", "pbgx", "pbgy", "pbgz", "pbhw", "pbhx",
        "pbhy", "pbhz", "pbiw", "pbix", "pbiy", "pbiz", "pcgw", "pcgx", "pcgy",
        "pcgz", "pchw", "pchx", "pchy", "pchz", "pciw", "pcix", "pciy", "pciz",

        "qagw", "qagx", "qagy", "qagz", "qahw", "qahx", "qahy", "qahz", "qaiw",
        "qaix", "qaiy", "qaiz", "qbgw", "qbgx", "qbgy", "qbgz", "qbhw", "qbhx",
        "qbhy", "qbhz", "qbiw", "qbix", "qbiy", "qbiz", "qcgw", "qcgx", "qcgy",
        "qcgz", "qchw", "qchx", "qchy", "qchz", "qciw", "qcix", "qciy", "qciz",

        "ragw", "ragx", "ragy", "ragz", "rahw", "rahx", "rahy", "rahz", "raiw",
        "raix", "raiy", "raiz", "rbgw", "rbgx", "rbgy", "rbgz", "rbhw", "rbhx",
        "rbhy", "rbhz", "rbiw", "rbix", "rbiy", "rbiz", "rcgw", "rcgx", "rcgy",
        "rcgz", "rchw", "rchx", "rchy", "rchz", "rciw", "rcix", "rciy", "rciz",

        "sagw", "sagx", "sagy", "sagz", "sahw", "sahx", "sahy", "sahz", "saiw",
        "saix", "saiy", "saiz", "sbgw", "sbgx", "sbgy", "sbgz", "sbhw", "sbhx",
        "sbhy", "sbhz", "sbiw", "sbix", "sbiy", "sbiz", "scgw", "scgx", "scgy",
        "scgz", "schw", "schx", "schy", "schz", "sciw", "scix", "sciy", "sciz"},
       144,
       1},

      {"777", {}, 64, 0}, // size-only validation

      {"9999", {}, 256, 0}};

  int total = sizeof(tests) / sizeof(tests[0]);
  int passed = 0;

  for (int i = 0; i < total; i++) {
    int returnSize = 0;
    char **out = letterCombinations(tests[i].input, &returnSize);

    int ok = (returnSize == tests[i].expectedSize);

    if (ok && tests[i].checkContent) {
      for (int j = 0; j < returnSize; j++) {
        if (strcmp(out[j], tests[i].expected[j]) != 0) {
          ok = 0;
          break;
        }
      }
    }

    printf("in: <%s> :: %s\n", tests[i].input[0] ? tests[i].input : "\"\"",
           ok ? "PASSED" : "FAILED");

    if (!ok)
      exit(1);

    for (int j = 0; j < returnSize; j++)
      free(out[j]);
    free(out);

    passed++;
  }

  printf("\nSummary: %d / %d tests passed\n", passed, total);
  return passed == total;
}
