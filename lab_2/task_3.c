#include <stdio.h>

int main() {
  int x, y;
  int *a = &x, *b = &y;
  scanf("%d %d", a, b);
  if (*a > *b)
    printf("%d", *a);
  else
    printf("%d", *b);
  return 0;
}
