#include <stdio.h>

unsigned long long fact_iter(int n) {
  if (n < 0)
    return 0;
  if (n == 0 || n == 1)
    return 1;

  unsigned long long result = 1;
  for (int i = 2; i <= n; i++) {
    result *= i;
  }
  return result;
}

unsigned long long fact_rec(int n) {
  if (n < 0)
    return 0;
  if (n == 0 || n == 1)
    return 1;

  return n * fact_rec(n - 1);
}

int main() {
  unsigned long long f1, f2;
  for (int i = 0; i <= 10; i++) {
    f1 = fact_iter(i);
    f2 = fact_rec(i);
    printf("%d! = %llu | %llu\n", i, f1, f2);
  }
  return 0;
}
