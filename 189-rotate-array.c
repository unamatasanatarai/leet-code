#include <stdio.h>
#include <stdlib.h>

void rotate(int *nums, int numsSize, int k) {
  if (numsSize == 0) {
    return;
  }
  k %= numsSize;
  if (k == 0) {
    return;
  }

  int start, stop;
  start = 0;
  stop = numsSize - 1;
  while (start < stop) {
    nums[start] ^= nums[stop];
    nums[stop] ^= nums[start];
    nums[start] ^= nums[stop];
    start++;
    stop--;
  }

  start = 0;
  stop = k - 1;
  while (start < stop) {
    nums[start] ^= nums[stop];
    nums[stop] ^= nums[start];
    nums[start] ^= nums[stop];
    start++;
    stop--;
  }

  start = k;
  stop = numsSize - 1;
  while (start < stop) {
    nums[start] ^= nums[stop];
    nums[stop] ^= nums[start];
    nums[start] ^= nums[stop];
    start++;
    stop--;
  }
}

int main() {
  int nums[] = {1, 2, 3};
  int k = 2;
  int numsSize = sizeof(nums) / sizeof(nums[0]);
  int i;

  for (i = 0; i < numsSize; i++) {
    printf("%d ", nums[i]);
  }
  printf("\n");
  rotate(nums, numsSize, k);
  for (i = 0; i < numsSize; i++) {
    printf("%d ", nums[i]);
  }
  printf("\n");
  return 0;
}
