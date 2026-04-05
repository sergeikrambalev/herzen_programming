#include <stdio.h>

int main() {
  int m;
  printf("max value: ");
  scanf("%d", &m);

  int p0 = 1, p1 = 1, p2 = 1;
  int pn;

  for (int i = 1;; i++) {
    if (i == 1)
      printf("%d", p0);
    else if (i == 2 || i == 3)
      printf(", %d", p1);
    else {
      pn = p1 + p0;
      if (pn <= m) {
        printf(", %d", pn);
        p0 = p1;
        p1 = p2;
        p2 = pn;
      } else
        break;
    }
  }

  return 0;
}
