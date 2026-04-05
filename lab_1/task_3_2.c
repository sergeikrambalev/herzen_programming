#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  int *arr = NULL;
  int size = 0;
  int capacity = 0;
  char buffer[100];

  while (1) {
    if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
      break;
    }
    size_t len = strlen(buffer);
    if (len > 0 && buffer[len - 1] == '\n') {
      buffer[len - 1] = '\0';
    }
    if (strlen(buffer) == 0) {
      break;
    }

    int num;
    if (sscanf(buffer, "%d", &num) != 1) {
      continue;
    }
    if (size == capacity) {
      if (capacity == 0)
        capacity = 10;
      else
        capacity *= 2;
      int *new_arr = (int *)realloc(arr, capacity * sizeof(int));
      arr = new_arr;
    }
    arr[size++] = num;
  }

  for (int i = 0; i < size / 2; i++) {
    int temp = arr[i];
    arr[i] = arr[size - 1 - i];
    arr[size - 1 - i] = temp;
  }

  if (size > 0) {
    for (int i = 0; i < size; i++) {
      printf("%d ", arr[i]);
    }
  }

  free(arr);

  return 0;
}
