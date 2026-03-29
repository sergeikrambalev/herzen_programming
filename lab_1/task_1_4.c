#include <math.h>
#include <stdio.h>

int main() {
  double a[3] = {0.12, 0.12, 0.27};
  double b[3] = {3.5, 3.5, 3.9};
  double c[3] = {2.4, 2.4, 2.8};
  double x[3] = {1.4, 1.6, 1.8};

  for (int i = 0; i < 3; i++) {
    double h =
        -1 * ((x[i] - a[i]) / pow(pow(x[i], 2) + pow(a[i], 2), 1.0 / 3.0)) -
        ((4 * pow(pow(pow(x[i], 2) + pow(b[i], 2), 3), 1.0 / 4.0)) /
         (2 + a[i] + b[i] + pow(pow(x[i] - c[i], 2), 1.0 / 3.0)));
    printf("%f\n", h);
  }
  return 0;
}
