#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum { TYPE_INT, TYPE_FLOAT, TYPE_STRING } Type;

typedef union {
  int int_value;
  float float_value;
  char *string_value;
} Value;

typedef struct {
  Type type;
  Value data;
} Variant;

int main() {
  int n;
  printf("number of elements: ");
  scanf("%d", &n);
  getchar();

  Variant *arr = (Variant *)malloc(n * sizeof(Variant));

  for (int i = 0; i < n; i++) {
    int choice;
    printf("\nselect type for element %d [1-int|2-float|3-string]: ", i + 1);
    scanf("%d", &choice);
    getchar();

    arr[i].type = choice - 1;
    switch (arr[i].type) {
    case TYPE_INT:
      printf("input int value: ");
      scanf("%d", &arr[i].data.int_value);
      break;
    case TYPE_FLOAT:
      printf("input float value: ");
      scanf("%f", &arr[i].data.float_value);
      break;
    case TYPE_STRING:
      arr[i].data.string_value = (char *)malloc(100 * sizeof(char));
      printf("input string value: ");
      fgets(arr[i].data.string_value, 100, stdin);
      arr[i].data.string_value[strcspn(arr[i].data.string_value, "\n")] = '\0';
      break;
    }
  }

  printf("\ncollected elements:\n");
  for (int i = 0; i < n; i++) {
    printf("element %d ", i + 1);
    switch (arr[i].type) {
    case TYPE_INT:
      printf("(int): %d\n", arr[i].data.int_value);
      break;
    case TYPE_FLOAT:
      printf("(float): %.2f\n", arr[i].data.float_value);
      break;
    case TYPE_STRING:
      printf("(string): %s\n", arr[i].data.string_value);
      break;
    }
  }

  for (int i = 0; i < n; i++) {
    if (arr[i].type == TYPE_STRING && arr[i].data.string_value != NULL) {
      free(arr[i].data.string_value);
    }
  }
  free(arr);

  return 0;
}
