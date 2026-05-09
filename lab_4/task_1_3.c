#include <stdio.h>
#include <stdlib.h>

double **matrix_alloc(int rows, int cols) {
  if (rows <= 0 || cols <= 0) {
    return NULL;
  }

  double **matrix = (double **)malloc(rows * sizeof(double *));
  if (matrix == NULL) {
    return NULL;
  }

  for (int i = 0; i < rows; i++) {
    matrix[i] = (double *)malloc(cols * sizeof(double));
    if (matrix[i] == NULL) {
      for (int j = 0; j < i; j++) {
        free(matrix[j]);
      }
      free(matrix);
      return NULL;
    }
  }

  return matrix;
}

void matrix_fill(double **matrix, int rows, int cols) {
  printf("Filling %dx%d matrix\n", rows, cols);
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      printf("[%d][%d]: ", i, j);
      scanf("%lf", &matrix[i][j]);
    }
  }
}

void matrix_print(double **matrix, int rows, int cols) {
  printf("Matrix %dx%d:\n", rows, cols);
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      printf("%g\t", matrix[i][j]);
    }
    printf("\n");
  }
}

void matrix_free(double **matrix, int rows) {
  for (int i = 0; i < rows; i++) {
    free(matrix[i]);
  }
  free(matrix);
}

int main() {
  int rows, cols;
  printf("Input number of rows: ");
  scanf("%d", &rows);
  printf("Input number of columns: ");
  scanf("%d", &cols);

  double **matrix = matrix_alloc(rows, cols);
  if (matrix == NULL) {
    printf("Failed to allocate memory");
    return 1;
  }

  matrix_fill(matrix, rows, cols);

  matrix_print(matrix, rows, cols);

  matrix_free(matrix, rows);

  return 0;
}
