#include <stdio.h>
#include <stdlib.h>

int main() {
  int N;

  printf("Input number of rows: ");
  scanf("%d", &N);

  if (N <= 0) {
    printf("N must be positive");
    return 1;
  }

  int **triangle = (int **)malloc(N * sizeof(int *));
  if (triangle == NULL) {
    printf("Failed to allocate memory");
    return 1;
  }

  for (int i = 0; i < N; i++) {
    int size = i + 1;

    triangle[i] = (int *)malloc(size * sizeof(int));
    if (triangle[i] == NULL) {
      printf("Failed to alloacte memory");

      for (int j = 0; j < i; j++) {
        free(triangle[i]);
      }
      free(triangle);
      return 1;
    }

    triangle[i][0] = 1;
    triangle[i][size - 1] = 1;

    for (int j = 1; j < size - 1; j++) {
      triangle[i][j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
    }
  }

  printf("Generated Pascal triangle:\n");
  for (int i = 0; i < N; i++) {
    int size = i + 1;
    for (int j = 0; j < size; j++) {
      printf("%d ", triangle[i][j]);
    }
    printf("\n");
  }

  for (int i = 0; i < N; i++) {
    free(triangle[i]);
  }
  free(triangle);
  return 0;
}
