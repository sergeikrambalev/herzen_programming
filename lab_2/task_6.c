#include <stdio.h>

int main() {
  int x;
  scanf("%d", &x);

  unsigned char *ptr = (unsigned char *)&x;

  for (size_t i = 0; i < sizeof(int); i++) {
    printf("%zu: %u\n", i, ptr[i]);
  }

  return 0;
}
