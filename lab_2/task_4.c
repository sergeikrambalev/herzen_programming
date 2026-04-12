#include <stdio.h>
#include <stdlib.h>

int main() {
  int n;
  scanf("%d", &n);

  int *arr = (int *)malloc(n * sizeof(int));

  for (int i = 0; i < n; i++) {
    scanf("%d", arr + i);
  }

  int sum = 0;
  int *ptr = arr;
  for (int i = 0; i < n; i++) {
    sum += *ptr;
    ptr++;
  }

  printf("%d", sum);
  free(arr);

  return 0;
}
