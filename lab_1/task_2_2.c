#include <math.h>
#include <stdio.h>

int main() {
  double a = 0.0, b = 5.0; // limits
  int n = 5;               // splits

  double h = (b - a) / n; // step
  double sum = 0.0;

  for (int i = 1; i < n; i++) {
    double x = a + i * h;
    sum += exp(x + 2);
  }

  double integral = (h / 2.0) * (exp(a + 2) + 2.0 * sum + exp(b + 2));
  printf("%.10lf", integral);

  return 0;
}
