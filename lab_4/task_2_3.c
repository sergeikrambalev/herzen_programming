#include <ctype.h>
#include <stdio.h>
#include <string.h>

#define STR_SIZE 64

int main() {
  char str[STR_SIZE];
  printf("Input string: ");
  fgets(str, STR_SIZE, stdin);
  str[strcspn(str, "\n")] = '\0';

  printf("Symbols classification:\n");
  for (int i = 0; str[i] != '\0'; i++) {
    unsigned char c = (unsigned char)str[i];

    printf("'%c' - ", str[i]);

    if (isalpha(c)) {
      if (isupper(c))
        printf("upper letter\n");
      else
        printf("lower letter\n");
    } else if (isdigit(c)) {
      printf("number\n");
    } else if (isspace(c)) {
      printf("space\n");
    } else if (ispunct(c)) {
      printf("punctuation\n");
    } else if (iscntrl(c)) {
      printf("control\n");
    }
  }

  return 0;
}
