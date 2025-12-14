#include <stdio.h>
#include <stdlib.h>

double findMedianSortedArrays(int *nums1, int nums1Size, int *nums2,
                              int nums2Size) {
  int nums_len = nums1Size + nums2Size;
  int *nums = (int *)malloc(nums_len * sizeof(int));
  int *nums_p = nums;

  for (int i = 0; i < nums1Size; i++) {
    *nums_p++ = nums1[i];
  }

  for (int i = 0; i < nums2Size; i++) {
    *nums_p++ = nums2[i];
  }

  for (int i = 1; i < nums_len; i++) {
    int cur_val = nums[i];
    int loc = i - 1;
    while (loc >= 0 && nums[loc] > cur_val) {
      nums[loc + 1] = nums[loc];
      loc--;
    }
    nums[loc + 1] = cur_val;
  }

  double mid = nums_len / 2.0;
  int mid_floor = nums_len / 2;
  if (mid > mid_floor) {
    return nums[mid_floor];
  }
  double r = (nums[mid_floor - 1] + nums[mid_floor]) / 2.0;
  free(nums);
  return r;
}

int main() {
  int a1[] = {1, 2};
  int a2[] = {3, 4};
  printf("%f", findMedianSortedArrays(a1, 2, a2, 2));
  return 0;
}
