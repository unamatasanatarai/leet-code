#include <stdio.h>
#include <stdlib.h>
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    int* result = (int*)malloc(2 * sizeof(int));
    *returnSize = 2;
    for (int i = 0; i < numsSize; i++){
      int diff = target - nums[i];
      for (int j = i + 1; j < numsSize; j++){
        if (nums[j] == diff){
          result[0] = i;
          result[1] = j;
          return result;
      }
    }
  }
  return NULL;
}
// helper to check result (order-insensitive)
int matches(int* res, int* expected) {
    return (res[0] == expected[0] && res[1] == expected[1]) ||
           (res[0] == expected[1] && res[1] == expected[0]);
}

int main() {

    // ---------- Case 1 ----------
    int nums1[] = {2,7,11,15};
    int exp1[] = {0,1};
    int rs1;
    int* r1 = twoSum(nums1, 4, 9, &rs1);
    printf("Case 1: expected [%d,%d], got [%d,%d] -> %s\n",
           exp1[0], exp1[1], r1[0], r1[1],
           matches(r1, exp1) ? "PASS" : "FAIL");
    free(r1);

    // ---------- Case 2 ----------
    int nums2[] = {3,2,4};
    int exp2[] = {1,2};
    int rs2;
    int* r2 = twoSum(nums2, 3, 6, &rs2);
    printf("Case 2: expected [%d,%d], got [%d,%d] -> %s\n",
           exp2[0], exp2[1], r2[0], r2[1],
           matches(r2, exp2) ? "PASS" : "FAIL");
    free(r2);

    // ---------- Case 3 ----------
    int nums3[] = {3,3};
    int exp3[] = {0,1};
    int rs3;
    int* r3 = twoSum(nums3, 2, 6, &rs3);
    printf("Case 3: expected [%d,%d], got [%d,%d] -> %s\n",
           exp3[0], exp3[1], r3[0], r3[1],
           matches(r3, exp3) ? "PASS" : "FAIL");
    free(r3);

    // ---------- Case 4 ----------
    int nums4[] = {3,2,3};
    int exp4[] = {0,2};
    int rs4;
    int* r4 = twoSum(nums4, 3, 6, &rs4);
    printf("Case 4: expected [%d,%d], got [%d,%d] -> %s\n",
           exp4[0], exp4[1], r4[0], r4[1],
           matches(r4, exp4) ? "PASS" : "FAIL");
    free(r4);

    // ---------- Case 5 ----------
    int nums5[] = {1,1,1,1,1,4,1,1,1,1,1,7,1,1,1,1,1};
    int exp5[] = {5,11};
    int rs5;
    int* r5 = twoSum(nums5, 17, 11, &rs5);
    printf("Case 5: expected [%d,%d], got [%d,%d] -> %s\n",
           exp5[0], exp5[1], r5[0], r5[1],
           matches(r5, exp5) ? "PASS" : "FAIL");
    free(r5);

    return 0;
}
