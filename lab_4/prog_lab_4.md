# Тема: Введение в функции. Базовая работа со строками (однобайтовыми).

## Комплект 1: Введение в функции.
### Задача 1
#### Постановка задачи
Реализовать и сравнить два способа вычисления факториала:
итеративный и рекурсивный.
#### Список идентификаторов
| имя переменной | тип данных         | описание                                  |
| -------------- | ------------------ | ----------------------------------------- |
| fact_iter      | unsigned long long | функция, вычисляющая факториал итеративно |
| fact_rec       | unsigned long long | функция, вычисляющая факториал рекурсивно |
#### Код программы
```c
#include <stdio.h>

unsigned long long fact_iter(int n) {
  if (n < 0)
    return 0;
  if (n == 0 || n == 1)
    return 1;

  unsigned long long result = 1;
  for (int i = 2; i <= n; i++) {
    result *= i;
  }
  return result;
}

unsigned long long fact_rec(int n) {
  if (n < 0)
    return 0;
  if (n == 0 || n == 1)
    return 1;

  return n * fact_rec(n - 1);
}

int main() {
  unsigned long long f1, f2;
  for (int i = 0; i <= 10; i++) {
    f1 = fact_iter(i);
    f2 = fact_rec(i);
    printf("%d! = %llu | %llu\n", i, f1, f2);
  }
  return 0;
}
```
#### Результаты работы программы
```
0! = 1 | 1  
1! = 1 | 1  
2! = 2 | 2  
3! = 6 | 6  
4! = 24 | 24  
5! = 120 | 120  
6! = 720 | 720  
7! = 5040 | 5040  
8! = 40320 | 40320  
9! = 362880 | 362880  
10! = 3628800 | 3628800
```

### Задача 2
#### Постановка задачи
Отработать передачу динамического массива в функцию и изме-
нение данных “по месту”.
#### Список идентификаторов
| имя переменной | тип данных | описание                                               |
| -------------- | ---------- | ------------------------------------------------------ |
| swap_pairs     | void       | функция, выполняющая попарный обмен соседних элементов |
| arr            | int        | динамический массив из 12 элементов                    |
#### Код программы
```c
#include <stdio.h>
#include <stdlib.h>

void swap_pairs(int *arr, int size) {
  for (int i = 0; i < size - 1; i += 2) {
    int temp = arr[i];
    arr[i] = arr[i + 1];
    arr[i + 1] = temp;
  }
}

int main() {
  int size = 12;
  int *arr = (int *)malloc(size * sizeof(int));
  if (arr == NULL) {
    printf("failed to allocate memory");
    return 1;
  }

  for (int i = 0; i < size; i++) {
    arr[i] = i + 1;
  }

  printf("base array: ");
  for (int i = 0; i < size; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");

  swap_pairs(arr, size);

  printf("mod array: ");
  for (int i = 0; i < size; i++) {
    printf("%d ", arr[i]);
  }

  free(arr);
  return 0;
}
```
#### Результаты работы программы
```
base array: 1 2 3 4 5 6 7 8 9 10 11 12    
mod array: 2 1 4 3 6 5 8 7 10 9 12 11
```

### Задача 3
#### Постановка задачи
Выделять, заполнять, печатать и освобождать двумерный дина-
мический массив без утечек памяти.
#### Список идентификаторов
| имя переменной | тип данных | описание                                                                  |
| -------------- | ---------- | ------------------------------------------------------------------------- |
| matrix_alloc   | double     | функция, выделяющая память под матрицу (или возвращающая NULL при ошибке) |
| matrix_fill    | void       | функция, поэлементно заполняющая матрицу вводом пользователя              |
| matrix_print   | void       | функция, выводящая матрицу                                                |
| matrix_free    | void       | функция, освобождающая память, занятую матрицей                           |
#### Код программы
```c
#include <stdio.h>
#include <stdlib.h>

double **matrix_alloc(int rows, int cols) {
  if (rows <= 0 || cols <= 0) {
    return NULL;
  }

  double **matrix = (double **)malloc(rows * sizeof(double *));
  if (matrix == NULL) {
    return NULL;
  }

  for (int i = 0; i < rows; i++) {
    matrix[i] = (double *)malloc(cols * sizeof(double));
    if (matrix[i] == NULL) {
      for (int j = 0; j < i; j++) {
        free(matrix[j]);
      }
      free(matrix);
      return NULL;
    }
  }

  return matrix;
}

void matrix_fill(double **matrix, int rows, int cols) {
  printf("Filling %dx%d matrix\n", rows, cols);
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      printf("[%d][%d]: ", i, j);
      scanf("%lf", &matrix[i][j]);
    }
  }
}

void matrix_print(double **matrix, int rows, int cols) {
  printf("Matrix %dx%d:\n", rows, cols);
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      printf("%g\t", matrix[i][j]);
    }
    printf("\n");
  }
}

void matrix_free(double **matrix, int rows) {
  for (int i = 0; i < rows; i++) {
    free(matrix[i]);
  }
  free(matrix);
}

int main() {
  int rows, cols;
  printf("Input number of rows: ");
  scanf("%d", &rows);
  printf("Input number of columns: ");
  scanf("%d", &cols);

  double **matrix = matrix_alloc(rows, cols);
  if (matrix == NULL) {
    printf("Failed to allocate memory");
    return 1;
  }

  matrix_fill(matrix, rows, cols);

  matrix_print(matrix, rows, cols);

  matrix_free(matrix, rows);

  return 0;
}
```
#### Результаты работы программы
```
Input number of rows: 3  
Input number of columns: 3  
Filling 3x3 matrix  
[0][0]: 1  
[0][1]: 2  
[0][2]: 3  
[1][0]: 4  
[1][1]: 5  
[1][2]: 6  
[2][0]: 7  
[2][1]: 8  
[2][2]: 9  
Matrix 3x3:  
1       2       3  
4       5       6  
7       8       9
```

### Задача 4
#### Постановка задачи
Вычислять смешанное произведение через разбиение задачи на
небольшие понятные функции.
#### Список идентификаторов
| имя переменной | тип данных | описание               |
| -------------- | ---------- | ---------------------- |
| cross3         | void       | векторное произведение |
| dot3           | double     | скалярное произвадение |
| triple3        | double     | смешанное произведение |
#### Код программы
```c
#include <stdio.h>

void cross3(const double a[3], const double b[3], double out[3]) {
  out[0] = a[1] * b[2] - a[2] * b[1];
  out[1] = a[2] * b[0] - a[0] * b[2];
  out[2] = a[0] * b[1] - a[1] * b[0];
}

double dot3(const double a[3], const double b[3]) {
  return a[0] * b[0] + a[1] * b[1] + a[2] * b[2];
}

double triple3(const double a[3], const double b[3], const double c[3]) {
  double tmp[3];
  cross3(b, c, tmp);
  return dot3(a, tmp);
}

int main() {
  double a[3], b[3], c[3];

  printf("Input Vector3 A (x y z): ");
  scanf("%lf %lf %lf", &a[0], &a[1], &a[2]);
  printf("Input Vector3 B (x y z): ");
  scanf("%lf %lf %lf", &b[0], &b[1], &b[2]);
  printf("Input Vector3 C (x y z): ");
  scanf("%lf %lf %lf", &c[0], &c[1], &c[2]);

  double result = triple3(a, b, c);
  printf("Mixed product [a,b,c] = %.4f", result);
  return 0;
}
```
#### Результаты работы программы
```
Input Vector3 A (x y z): 1 0 0  
Input Vector3 B (x y z): 0 1 0  
Input Vector3 C (x y z): 0 0 1  
Mixed product [a,b,c] = 1.0000
```

## Комплект 2: Базовые операции со строками.
### Задача 1
#### Постановка задачи
Освоить базовые операции с C-строкой в максимально пошаго-
вом режиме.
#### Список идентификаторов
| имя переменной | тип данных | описание                                       |
| -------------- | ---------- | ---------------------------------------------- |
| my_string      | char       | исходная строка                                |
| len1           | int        | размер исходной строки (по индексам)           |
| len2           | int        | размер исходной строки (по указателю)          |
| len3           | size_t     | размер исходной строки (библиотечная функция)  |
| copy           | char       | скопированная исходная строка                  |
| concat         | char       | результат конкатенации строк                   |
| cmp            | int        | результат библиотечной функции сравнения строк |
| lower          | char       | исходная строка в нижнем регистре              |
| upper          | char       | исходная строка в верхнем регистре             |
#### Код программы
```c
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
```
#### Результаты работы программы
```
Enter string (max 10 symbols): AbC12  
  
Read string: "AbC12"  
  
1. Length by indexes: 5  
2. Length by pointer: 5  
3. Length by strlen: 5  
All length match.  
4. Copied string: "AbC12"  
5. Conctenated string: "Hello" + "world" = "world"  
6. Comparing strings: strcmp(original, copy)=0, strings match  
7. Register change: "abc12", "ABC12"
```

### Задача 2
#### Постановка задачи
Безопасно преобразовывать текст в int и double, чтобы програм-
ма корректно реагировала на ошибочный ввод.
#### Список идентификаторов
| имя переменной | тип данных | описание                                       |
| -------------- | ---------- | ---------------------------------------------- |
| int_str        | char       | строка, содержащая целое число                 |
| double_str     | char       | строка, содержащая число с плавающей точкой    |
| int_val        | long       | целое число, полученное из строки              |
| double_val     | double     | число с плавающей точкой, полученное из строки |
#### Код программы
```c
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
```
#### Результаты работы программы
```
Input integer number: -42  
Input floating point number: 3.14  
  
Converting integer from "-42"  
Success: -42  
  
Converting double from "3.14"  
Success: 3.140000
```

### Задача 3
#### Постановка задачи
Научиться классифицировать каждый символ строки с помощью
функций из ctype.h.
#### Список идентификаторов
| имя переменной | тип данных    | описание         |
| -------------- | ------------- | ---------------- |
| str            | char          | введенная строка |
| c              | unsigned char | символ строки    |
#### Код программы
```c
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
```
#### Результаты работы программы
```
Input string: A7,    
Symbols classification:  
'A' - upper letter  
'7' - number  
',' - punctuation  
' ' - space
```

## Информация о студенте
Крамбалев Сергей Дмитриевич, 1 курс, группа ИВТ-25