#include <math.h>
#include <stdio.h>

int main() {
  double x = 9.17, y = -2.48;

  double u = (1 + pow(sin(x + y), 2)) /
             (2 + fabs(x - ((2 * pow(x, 2)) / (1 + fabs(sin(x + y))))));
  printf("%f", u);
}

