#include "utils.h"
#include <stdio.h>

void pa(const int arr[], size_t size) {
  for (size_t i = 0; i < size; i++)
    printf("%d ", arr[i]);
  printf("\n");
}
