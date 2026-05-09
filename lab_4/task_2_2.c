#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STR_SIZE 32

int main() {
  char int_str[STR_SIZE];
  char double_str[STR_SIZE];

  printf("Input integer number: ");
  scanf("%31s", int_str);
  printf("Input floating point number: ");
  scanf("%31s", double_str);

  printf("\nConverting integer from \"%s\"\n", int_str);
  errno = 0;
  char *endptr_int;
  long int_val = strtol(int_str, &endptr_int, 10);

  int success_int = 1;
  if (endptr_int == int_str) {
    printf("Error: failed to convert\n");
    success_int = 0;
  }
  if (errno == ERANGE) {
    printf("Error: overflow\n");
    success_int = 0;
  }
  if (*endptr_int != '\0') {
    printf("Error: excess symbols after number: \"%s\"\n", endptr_int);
    success_int = 0;
  }

  if (success_int) {
    printf("Success: %ld\n", int_val);
  }

  printf("\nConverting double from \"%s\"\n", double_str);
  errno = 0;
  char *endptr_double;
  double double_val = strtod(double_str, &endptr_double);

  int success_double = 1;
  if (endptr_double == double_str) {
    printf("Error: failed to convert\n");
    success_double = 0;
  }
  if (errno == ERANGE) {
    printf("Error: overflow\n");
    success_double = 0;
  }
  if (*endptr_double != '\0') {
    printf("Error: excess symbols after number: \"%s\"\n", endptr_double);
    success_double = 0;
  }

  if (success_double) {
    printf("Success: %f\n", double_val);
  }

  return 0;
}
