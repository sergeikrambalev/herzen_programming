#include <stdio.h>
#include <string.h>

union Data {
  int integer;
  float floating;
  char string[20];
};

void print_data(union Data *data, int type) {
  switch (type) {
  case 1:
    printf("integer: %d\n", data->integer);
    break;
  case 2:
    printf("float: %.2f\n", data->floating);
    break;
  case 3:
    printf("string: %s\n", data->string);
    break;
  default:
    printf("unknown format");
  }
}

int main() {
  union Data data;
  union Data *data_ptr = &data;

  data_ptr->integer = 42;
  printf("data set to int\n");
  print_data(data_ptr, 1);
  print_data(data_ptr, 2);
  print_data(data_ptr, 3);
  printf("\n");

  data_ptr->floating = 3.14;
  printf("data set to float\n");
  print_data(data_ptr, 1);
  print_data(data_ptr, 2);
  print_data(data_ptr, 3);

  printf("\n");

  strcpy(data_ptr->string, "lorem ipsum");
  printf("data set to string\n");
  print_data(data_ptr, 1);
  print_data(data_ptr, 2);
  print_data(data_ptr, 3);

  return 0;
}
