#include <stdio.h>
#include <stdlib.h>

int **read_mat(const char *filename, int *rows, int *cols) {
  FILE *f = fopen(filename, "r");
  if (!f) {
    fprintf(stderr, "Failed to open file '%s'\n", filename);
    return NULL;
  }

  if (fscanf(f, "%d %d", rows, cols) != 2) {
    fprintf(stderr, "Wrong data format: matrix size not detected\n");
    fclose(f);
    return NULL;
  }

  if (*rows <= 0 || *cols <= 0) {
    fprintf(stderr,
            "Wrong data format: matrix size must be positive, got %dX%d\n",
            *rows, *cols);
    fclose(f);
    return NULL;
  }

  int **mat = malloc(*rows * sizeof(int *));
  if (!mat) {
    fprintf(stderr, "Failed to allocate memory for matrix\n");
    fclose(f);
    return NULL;
  }

  for (int i = 0; i < *rows; i++) {
    mat[i] = malloc(*cols * sizeof(int));
    if (!mat[i]) {
      fprintf(stderr, "Failed to allocate memory for matrix\n");
      for (int j = 0; j < i; j++) {
        free(mat[j]);
      }
      free(mat);
      fclose(f);
      return NULL;
    }

    for (int j = 0; j < *cols; j++) {
      if (fscanf(f, "%d", &mat[i][j]) != 1) {
        fprintf(stderr, "Wrong data format\n");
        for (int k = 0; k < i; k++) {
          free(mat[k]);
        }
        free(mat);
        fclose(f);
        return NULL;
      }
    }
  }

  fclose(f);
  return mat;
}

void free_mat(int **mat, int rows) {
  if (mat) {
    for (int i = 0; i < rows; i++) {
      free(mat[i]);
    }
    free(mat);
  }
}

int **mult_mat(int **A, int rA, int cA, int **B, int rB, int cB) {
  if (cA != rB) {
    return NULL;
  }

  int **C = malloc(rA * sizeof(int *));
  if (!C) {
    fprintf(stderr, "Failed to allocate memory for matrix\n");
    return NULL;
  }

  for (int i = 0; i < rA; i++) {
    C[i] = malloc(cB * sizeof(int));
    if (!C[i]) {
      fprintf(stderr, "Failed to allocate memory for matrix\n");
      for (int j = 0; j < i; j++) {
        free(C[j]);
      }
      free(C);
      return NULL;
    }

    for (int j = 0; j < cB; j++) {
      C[i][j] = 0;
      for (int k = 0; k < cA; k++) {
        C[i][j] += A[i][k] * B[k][j];
      }
    }
  }

  return C;
}

void print_mat(int **mat, int rows, int cols) {
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      printf("%d", mat[i][j]);
      if (j < cols - 1) {
        printf(" ");
      }
    }
    printf("\n");
  }
}

int main(int argc, char *argv[]) {
  if (argc != 3) {
    fprintf(stderr, "Usage: %s <f1> <f2>\n", argv[0]);
    return 1;
  }

  int rA, cA, rB, cB;
  int **A = read_mat(argv[1], &rA, &cA);
  if (!A)
    return 1;
  int **B = read_mat(argv[2], &rB, &cB);
  if (!B) {
    free_mat(A, rA);
    return 1;
  }

  if (cA != rB) {
    printf("Matrices cannot be multiplied: %d != %d\n", cA, rB);
    free_mat(A, rA);
    free_mat(B, rB);
    return 0;
  }

  int **C = mult_mat(A, rA, cA, B, rB, cB);
  if (!C) {
    free_mat(A, rA);
    free_mat(B, rB);
    return 1;
  }

  print_mat(C, rA, cB);

  free_mat(A, rA);
  free_mat(B, rB);
  free_mat(C, rA);
  return 0;
}
