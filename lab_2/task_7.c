#include <stdio.h>
#include <stdlib.h>

int main() {
  int *matrix[2];
  for (int i = 0; i < 2; i++) {
    matrix[i] = (int *)malloc(3 * sizeof(int));
  }

  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 3; j++) {
      scanf("%d", &matrix[i][j]);
    }
  }

  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 3; j++) {
      printf("%d ", matrix[i][j]);
    }
    printf("\n");
  }

  for (int i = 0; i < 2; i++) {
    free(matrix[i]);
  }

  return 0;
}
