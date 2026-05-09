#include <stdio.h>
#include <stdlib.h>

void swap_pairs(int *arr, int size) {
  for (int i = 0; i < size - 1; i += 2) {
    int temp = arr[i];
    arr[i] = arr[i + 1];
    arr[i + 1] = temp;
  }
}

int main() {
  int size = 12;
  int *arr = (int *)malloc(size * sizeof(int));
  if (arr == NULL) {
    printf("failed to allocate memory");
    return 1;
  }

  for (int i = 0; i < size; i++) {
    arr[i] = i + 1;
  }

  printf("base array: ");
  for (int i = 0; i < size; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");

  swap_pairs(arr, size);

  printf("mod array: ");
  for (int i = 0; i < size; i++) {
    printf("%d ", arr[i]);
  }

  free(arr);
  return 0;
}
