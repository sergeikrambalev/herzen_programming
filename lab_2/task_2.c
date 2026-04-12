#include <stdio.h>

int main() {
  int x, y;
  int *a = &x, *b = &y;
  scanf("%d %d", a, b);
  printf("%d %d, ", *a, *b);
  int tmp = *a;
  *a = *b;
  *b = tmp;
  printf("%d %d", *a, *b);
  return 0;
}
