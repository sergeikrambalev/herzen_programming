#include <ctype.h>
#include <stdio.h>
#include <string.h>

#define MY_SIZE 32

int main() {
  char my_string[MY_SIZE];

  printf("Enter string (max 10 symbols): ");
  scanf("%31s", my_string);
  printf("\nRead string: \"%s\"\n\n", my_string);

  int len1 = 0;
  for (int i = 0; my_string[i] != '\0'; i++) {
    len1++;
  }
  printf("1. Length by indexes: %d\n", len1);

  char *p = my_string;
  int len2 = 0;
  while (*p != '\0') {
    len2++;
    p++;
  }
  printf("2. Length by pointer: %d\n", len2);

  size_t len3 = strlen(my_string);
  printf("3. Length by strlen: %zu\n", len3);

  if (len1 == len2 && len2 == (int)len3) {
    printf("All length match.\n");
  }

  char copy[MY_SIZE];
  strcpy(copy, my_string);
  printf("4. Copied string: \"%s\"\n", copy);

  char str1[MY_SIZE] = "Hello";
  char str2[] = "world";
  char concat[MY_SIZE * 2];
  strcpy(concat, str1);
  strcpy(concat, str2);
  printf("5. Conctenated string: \"%s\" + \"%s\" = \"%s\"\n", str1, str2,
         concat);

  int cmp = strcmp(my_string, copy);
  printf("6. Comparing strings: strcmp(original, copy)=%d, ", cmp);
  if (cmp == 0) {
    printf("strings match\n");
  } else if (cmp < 0) {
    printf("original string is shorter\n");
  } else {
    printf("original string is longer\n");
  }

  char lower[MY_SIZE], upper[MY_SIZE];
  for (int i = 0; my_string[i] != '\0'; i++) {
    lower[i] = tolower((unsigned char)my_string[i]);
    upper[i] = toupper((unsigned char)my_string[i]);
  }
  lower[len1] = '\0';
  upper[len1] = '\0';
  printf("7. Register change: \"%s\", \"%s\"", lower, upper);
  return 0;
}
