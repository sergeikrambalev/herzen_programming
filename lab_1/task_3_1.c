#include <stdio.h>

int main() {
  double X[2];
  scanf("%lf %lf", &X[0], &X[1]);
  printf("%lf %lf", X[0] * X[0], X[1] * X[1]);

  return 0;
}
