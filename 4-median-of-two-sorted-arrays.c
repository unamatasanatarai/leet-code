#include "utils.h"
#include <stdio.h>
#include <stdlib.h>

double findMedianSortedArrays(int *nums1, int nums1Size, int *nums2,
                              int nums2Size) {
  int nums_len = nums1Size + nums2Size;
  int *nums = (int *)malloc(nums_len * sizeof(int));

  int i = 0, j = 0, k = 0;
  while (i < nums1Size && j < nums2Size) {
    nums[k++] = (nums1[i] <= nums2[j]) ? nums1[i++] : nums2[j++];
  }

  while (i < nums1Size) {
    nums[k++] = nums1[i++];
  }

  while (j < nums2Size) {
    nums[k++] = nums2[j++];
  }

  int mid_floor = nums_len / 2;
  if (nums_len % 2 == 1) {
    double result = nums[mid_floor];
    free(nums);
    return result;
  }
  double result = (nums[mid_floor - 1] + nums[mid_floor]) / 2.0;
  free(nums);
  return result;
}

int main() {
  int a1[] = {1, 2};
  int a1size = 2;
  int a2[] = {3, 4};
  int a2size = 2;
  printf("%f\n", findMedianSortedArrays(a1, a1size, a2, a2size));
  return 0;
}
