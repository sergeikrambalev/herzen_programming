#include <math.h>
#include <stdio.h>

int main() {
  double r1 = 1.524, r2 = 1.0;  // Mars, Earth, [AU]
  double T1 = 1.8808, T2 = 1.0; // Mars, Earth, [earth years]
  double w1 = 2.0 * M_PI / T1, w2 = 2.0 * M_PI / T2;

  printf("t (years) \t X (au) \t Y (au)\n");

  for (double t = 0.0; t <= 5.0; t += 0.05) {
    double x = r1 * cos(w1 * t) - r2 * cos(w2 * t);
    double y = r1 * sin(w1 * t) - r2 * sin(w2 * t);
    printf("%8.3f \t %8.5f \t %8.5f\n", t, x, y);
  }

  return 0;
}
