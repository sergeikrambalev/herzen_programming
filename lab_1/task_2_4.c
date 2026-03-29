#include <stdio.h>

int main() {
  int n;
  int sum = 11;

  while (sum > 10) {
    printf("input 3-digit number: ");
    scanf("%d", &n);
    sum = 0;
    while (n > 0) {
      sum += n % 10;
      n /= 10;
    }
  }
  printf("sum is %d, end", sum);

  return 0;
}
