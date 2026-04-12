#include <stdio.h>

int main() {
  int x, y;
  int *a = &x, *b = &y;
  scanf("%d %d", a, b);
  printf("%d", *a + *b);
  return 0;
}
