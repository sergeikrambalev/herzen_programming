#include <stdio.h>
#include <stdlib.h>

int main() {
  int n;
  scanf("%d", &n);

  int *arr = (int *)malloc(n * sizeof(int));

  for (int i = 0; i < n; i++) {
    scanf("%d", arr + i);
  }

  int *ptr = arr + n - 1;
  for (int i = 0; i < n; i++) {
    printf("%d ", *ptr);
    ptr--;
  }

  free(arr);

  return 0;
}
