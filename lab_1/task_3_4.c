#include <stdio.h>
#include <stdlib.h>

int main() {
  int m, n;

  printf("size[x y]: ");
  if (scanf("%d %d", &m, &n) != 2 || m < 0 || n < 0) {
    return 1;
  }
  double **matrix = (double **)malloc(m * sizeof(double *));
  for (int i = 0; i < m; i++) {
    matrix[i] = (double *)malloc(n * sizeof(double));
  }

  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      scanf("%lf", &matrix[i][j]);
    }
  }

  for (int i = 0; i < m; i++) {
    double sum = 0.0;
    for (int j = 0; j < n; j++) {
      sum += matrix[i][j];
    }
    double avg = sum / n;
    matrix[i][0] = avg;
  }

  for (int i = 0; i < m; i++) {
    for (int j = 0; j < m; j++) {
      printf("%lf ", matrix[i][j]);
    }
    printf("\n");
  }

  for (int i = 0; i < m; i++) {
    free(matrix[i]);
  }
  free(matrix);

  return 0;
}
