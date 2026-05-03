#include <stdio.h>

typedef struct {
  unsigned int day : 5;
  unsigned int month : 4;
  unsigned int year : 12;
} Date;

void date_set(Date *date, unsigned int day, unsigned int month,
              unsigned int year) {
  if (day >= 1 && day <= 31 && month >= 1 && month <= 12 && year <= 4095) {
    date->day = day;
    date->month = month;
    date->year = year;
  } else {
    printf("incorrect date input");
    date->day = 1;
    date->month = 1;
    date->year = 2000;
  }
}

void date_get(Date date, int *day, int *month, int *year) {
  *day = date.day;
  *month = date.month;
  *year = date.year;
}

void date_print(Date date) {
  printf("%02d.%02d.%04d", date.day, date.month, date.year);
}

int main() {
  Date birthday;
  date_set(&birthday, 3, 7, 2006);
  date_print(birthday);
}
