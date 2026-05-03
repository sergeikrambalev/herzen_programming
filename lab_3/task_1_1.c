#include <stdio.h>

typedef int (*operation)(int, int);

int add(int a, int b) { return a + b; }

struct Summator {
  char name[10];
  operation operation;
};

int main() {
  struct Summator summ;
  sprintf(summ.name, "Summator");
  summ.operation = add;
  int result = summ.operation(5, 10);
  printf("%s: 5+10=%d", summ.name, result);
}
