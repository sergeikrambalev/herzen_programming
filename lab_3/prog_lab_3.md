# Тема: Указатели и динамическая память

## Комплект 1: Структуры
### Задача 1
#### Постановка задачи
Создать некоторую структуру с указателем на некоторую функцию
в качестве поля. Вызвать эту функцию через имя переменной этой
структуры и поле указателя на функцию.
#### Список идентификаторов
| имя переменной     | тип данных | описание                                                          |
| ------------------ | ---------- | ----------------------------------------------------------------- |
| add                | int        | функция, складывающая 2 целых числа                               |
| Summator           | struct     | структура, имеющая некоторое имя и выполняющая некоторую операцию |
| Summator.name      | int        | имя структуры                                                     |
| Summator.operation | int        | операция, выполняемая структурой                                  |
#### Код программы
```c
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
```
#### Результаты работы программы
```
Summator: 5+10=15
```

### Задача 2
#### Постановка задачи
Создать структуру для вектора в 3-х мерном пространстве. Реализо-
вать и использховать в своей программе следующие операции над
векторами:
• скалярное умножение векторов;
• векторное произведение;
• модуль вектора;
• распечатка вектора в консоли.
В структуре вектора указать имя вектора в качестве отдельного поля
этой структуры.
#### Список идентификаторов
| имя переменной | тип данных | описание                                  |
| -------------- | ---------- | ----------------------------------------- |
| Vector3        | struct     | структура вектора в 3-мерном пространстве |
| create_vector  | Vector3    | создание вектора                          |
| print_vec      | void       | вывод вектора и его координат             |
| dot_product    | double     | скалярное произведение двух векторов      |
| cross_product  | Vector3    | векторное произведение двух векторов      |
| vec_len        | double     | длина векктора                            |
| vec_sum        | Vector3    | сумма двух векторов                       |
| vec_mul        | Vector3    | произведение вектора на скаляр            |
#### Код программы
```c
#include <math.h>
#include <stdio.h>
#include <string.h>

typedef struct Vector3 {
  char name[10];
  double x, y, z;
} Vector3;

Vector3 create_vector(const char *name, double x, double y, double z) {
  Vector3 vec;
  strcpy(vec.name, name);
  vec.x = x;
  vec.y = y;
  vec.z = z;
  return vec;
}

void print_vec(Vector3 vec) {
  printf("%s = (%.2f, %.2f, %.2f)\n", vec.name, vec.x, vec.y, vec.z);
}

double dot_product(Vector3 vec1, Vector3 vec2) {
  return vec1.x * vec2.x + vec1.y * vec2.y + vec1.z * vec2.z;
}

Vector3 cross_product(Vector3 vec1, Vector3 vec2) {
  Vector3 result;
  strcpy(result.name, "cross_product");
  result.x = vec1.y * vec2.z - vec1.z * vec2.y;
  result.y = vec1.z * vec2.x - vec1.x * vec2.z;
  result.z = vec1.x * vec2.y - vec1.y * vec2.x;
  return result;
}

double vec_len(Vector3 vec) {
  return sqrt(vec.x * vec.x + vec.y * vec.y + vec.z * vec.z);
}

Vector3 vec_sum(Vector3 vec1, Vector3 vec2) {
  Vector3 result;
  sprintf(result.name, "%s+%s", vec1.name, vec2.name);
  result.x = vec1.x + vec2.x;
  result.y = vec1.y + vec2.y;
  result.z = vec1.z + vec2.z;
  return result;
}

Vector3 vec_mul(Vector3 vec, double scalar) {
  Vector3 result;
  sprintf(result.name, "%s*%.1f", vec.name, scalar);
  result.x = vec.x * scalar;
  result.y = vec.y * scalar;
  result.z = vec.z * scalar;
  return result;
}

int main() {
  Vector3 vec1 = create_vector("vec1", 1.0, 2.0, 3.0);
  Vector3 vec2 = create_vector("vec2", 2.0, -1.0, 3.0);

  print_vec(vec1);
  print_vec(vec2);

  printf("Dot product of %s and %s: %.2f\n", vec1.name, vec2.name,
         dot_product(vec1, vec2));

  Vector3 cross = cross_product(vec1, vec2);
  printf("Cross product of %s and %s: ", vec1.name, vec2.name);
  print_vec(cross);

  printf("Length of %s: %.2f\n", vec1.name, vec_len(vec1));
  printf("Length of %s: %.2f\n", vec2.name, vec_len(vec2));

  Vector3 sum = vec_sum(vec1, vec2);
  printf("Sum of %s and %s: ", vec1.name, vec2.name);
  print_vec(sum);

  Vector3 mult = vec_mul(vec1, 2.5);
  printf("%s multiplied by 2.5: ", vec1.name);
  print_vec(mult);

  return 0;
}
```
#### Результаты работы программы
```
vec1 = (1.00, 2.00, 3.00)  
vec2 = (2.00, -1.00, 3.00)  
Dot product of vec1 and vec2: 9.00  
Cross product of vec1 and vec2: cross_product = (9.00, 3.00, -5.00)  
Length of vec1: 3.74  
Length of vec2: 3.74  
Sum of vec1 and vec2: vec1+vec2 = (3.00, 1.00, 6.00)  
vec1 multiplied by 2.5: vec1*2.5 = (2.50, 5.00, 7.50)
```

### Задача 3
#### Постановка задачи
Вычислить, используя структуру комплексного числа, комплексную
экспоненту exp(z) некоторого z ∈ C.
#### Список идентификаторов
| имя переменной | тип данных | описание                                    |
| -------------- | ---------- | ------------------------------------------- |
| Complex        | struct     | структура комплексного числа                |
| cx_create      | Complex    | создание комплексного числа                 |
| cx_print       | void       | вывод комплексного числа                    |
| cx_add         | Complex    | сумма двух комплексных чисел                |
| cx_mul         | Complex    | произведение двух комплексных чисел         |
| cx_div         | Complex    | деление комплексного числа на скаляр        |
| cx_pow         | Complex    | возведение скалярного числа в степень       |
| cx_exp         | Complex    | вычисление экспоненты от комплексного числа |
#### Код программы
```c
#include <math.h>
#include <stdio.h>

typedef struct {
  double re;
  double im;
} Complex;

Complex cx_create(double re, double im) {
  Complex c;
  c.re = re;
  c.im = im;
  return c;
}

void cx_print(const char *name, Complex c) {
  if (c.im > 0) {
    printf("%s = %.6f + %.6fi\n", name, c.re, c.im);
  } else {
    printf("%s = %.6f - %.6fi\n", name, c.re, c.im);
  }
}

Complex cx_add(Complex a, Complex b) {
  Complex result;
  result.re = a.re + b.re;
  result.im = a.im + b.im;
  return result;
}

Complex cx_mul(Complex a, Complex b) {
  Complex result;
  result.re = a.re * b.re - a.im * b.im;
  result.im = a.re * b.im + a.im * b.re;
  return result;
}

Complex cx_div(Complex c, double scalar) {
  Complex result;
  result.re = c.re / scalar;
  result.im = c.im / scalar;
  return result;
}

Complex cx_pow(Complex c, int n) {
  Complex result = cx_create(1, 0);
  Complex base = c;
  if (n == 0)
    return result;
  for (int i = 0; i < n; i++) {
    result = cx_mul(result, base);
  }
  return result;
}

Complex cx_exp(Complex c, int max_terms) {
  Complex sum = cx_create(1, 0);
  Complex term = cx_create(1, 0);

  for (int n = 1; n <= max_terms; n++) {
    term = cx_mul(term, c);
    term = cx_div(term, n);
    sum = cx_add(sum, term);
  }

  return sum;
}

int main() {
  Complex c1 = cx_create(1, 0);
  cx_print("c1", c1);
  Complex c1_exp = cx_exp(c1, 30);
  cx_print("exp(c1)", c1_exp);

  Complex c2 = cx_create(0, 1);
  cx_print("c2", c2);
  Complex c2_exp = cx_exp(c2, 30);
  cx_print("exp(c2)", c2_exp);

  Complex c3 = cx_create(1, 1);
  cx_print("c3", c3);
  Complex c3_exp = cx_exp(c3, 30);
  cx_print("exp(c3)", c3_exp);
}
}
```
#### Результаты работы программы
```
c1 = 1.000000 - 0.000000i  
exp(c1) = 2.718282 - 0.000000i  
c2 = 0.000000 + 1.000000i  
exp(c2) = 0.540302 + 0.841471i  
c3 = 1.000000 + 1.000000i  
exp(c3) = 1.468694 + 2.287355i
```

### Задача 4
#### Постановка задачи
Используя так называемые "битовые" поля в структуре C, создать эко-
номную структуру в оперативной памяти для заполнения даты неко-
торого события, например даты рождения человека.
#### Список идентификаторов
| имя переменной | тип данных | описание                              |
| -------------- | ---------- | ------------------------------------- |
| Date           | struct     | структура даты (день, месяц, год)     |
| date_set       | void       | задает значения полей струкутры       |
| date_get       | void       | извлекает значения из полей структуры |
| date_print     | void       | выводит значения полей структуры      |
#### Код программы
```c
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
```
#### Результаты работы программы
```
03.07.2006
```

### Задача 5
#### Постановка задачи
Реализовать в виде структур двунаправленный связный список и со-
вершить отдельно его обход в прямом и обратном направлениях с рас-
печаткой значений каждого элемента списка.
#### Список идентификаторов
| имя переменной | тип данных | описание                                           |
| -------------- | ---------- | -------------------------------------------------- |
| Node           | struct     | элемент двусвязного списка                         |
| DLList         | struct     | двусвязный список                                  |
| dllist_init    | void       | инициализация полей двусвязного списка             |
| node_create    | Node       | создание элемента двусвязного списка               |
| append         | void       | добавление элемента в конец двусвязного списка     |
| prepend        | void       | добавление элемента в начало двусвязного списка    |
| insert_at      | void       | добавление элемента в двусвязный список по индексу |
| remove_at      | int        | удаление элемента из двусвязного списка по индексу |
| get_at         | int        | получение элемента двусвязного списка по индексу   |
| clear_list     | void       | очистка и освобождение двусвязного списка          |
| trav_fwd       | void       | обход двусвязного списка с начала                  |
| trav_bwd       | void       | обход двусвязного списка с конца                   |
#### Код программы
```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
  int data;
  struct Node *prev;
  struct Node *next;
};

typedef struct {
  struct Node *head;
  struct Node *tail;
  int size;
} DLList;

void dllist_init(DLList *list) {
  list->head = NULL;
  list->tail = NULL;
  list->size = 0;
}

struct Node *node_create(int value) {
  struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
  if (new_node == NULL) {
    printf("failed to allocate memory for new node");
    exit(1);
  }
  new_node->data = value;
  new_node->prev = NULL;
  new_node->next = NULL;
  return new_node;
}

void append(DLList *list, int value) {
  struct Node *new_node = node_create(value);
  if (list->head == NULL) {
    list->head = new_node;
    list->tail = new_node;
  } else {
    new_node->prev = list->tail;
    list->tail->next = new_node;
    list->tail = new_node;
  }
  list->size++;
}

void prepend(DLList *list, int value) {
  struct Node *new_node = node_create(value);
  if (list->head == NULL) {
    list->head = new_node;
    list->tail = new_node;
  } else {
    new_node->next = list->head;
    list->head->prev = new_node;
    list->head = new_node;
  }
  list->size++;
}

void insert_at(DLList *list, int id, int value) {
  if (id < 0 || id > list->size) {
    printf("list index out of range");
    return;
  }
  if (id == 0) {
    prepend(list, value);
  } else if (id == list->size) {
    append(list, value);
  } else {
    struct Node *new_node = node_create(value);
    struct Node *current = list->head;
    for (int i = 0; i < id; i++) {
      current = current->next;
    }
    new_node->prev = current->prev;
    new_node->next = current;
    current->prev->next = new_node;
    current->prev = new_node;
    list->size++;
  }
}

int remove_at(DLList *list, int id) {
  if (id < 0 || id >= list->size) {
    printf("list index out of range");
    return 0;
  }
  struct Node *to_delete;
  if (id == 0) {
    to_delete = list->head;
    list->head = list->head->next;
    if (list->head != NULL) {
      list->head->prev = NULL;
    } else {
      list->tail = NULL;
    }
  } else if (id == list->size - 1) {
    to_delete = list->tail;
    for (int i = 0; i < id; i++) {
      to_delete = to_delete->next;
    }
    to_delete->prev->next = to_delete->next;
    to_delete->next->prev = to_delete->prev;
  }
  free(to_delete);
  list->size--;
  return 1;
}

int get_at(DLList *list, int id) {
  if (id < 0 || id >= list->size) {
    printf("list index out of range");
    return 0;
  }

  struct Node *current;
  if (id < list->size / 2) {
    current = list->head;
    for (int i = 0; i < id; i++) {
      current = current->next;
    }
  } else {
    current = list->tail;
    for (int i = list->size - 1; i > id; i--) {
      current = current->prev;
    }
  }
  return current->data;
}

void clear_list(DLList *list) {
  struct Node *current = list->head;
  struct Node *next;

  while (current->next != NULL) {
    next = current->next;
    free(current);
    current = next;
  }

  list->head = NULL;
  list->tail = NULL;
  list->size = 0;
}

void trav_fwd(DLList *list) {
  if (list->head == NULL) {
    printf("list is empty");
    return;
  }
  struct Node *current = list->head;
  int count = 0;

  while (current != NULL) {
    printf("%d", current->data);
    if (current->next != NULL) {
      printf("<->");
    }
    current = current->next;
    count++;
  }
  printf("\ntraversed %d elements\n", count);
}

void trav_bwd(DLList *list) {
  if (list->tail == NULL) {
    printf("list is empty");
    return;
  }
  struct Node *current = list->tail;
  int count = 0;

  while (current != NULL) {
    printf("%d", current->data);
    if (current->prev != NULL) {
      printf("<->");
    }
    current = current->prev;
    count++;
  }
  printf("\ntraversed %d elements\n", count);
}

int main() {
  DLList list;
  dllist_init(&list);

  append(&list, 10);
  append(&list, 20);

  prepend(&list, 5);

  insert_at(&list, 2, 15);

  trav_fwd(&list);
  trav_bwd(&list);

  clear_list(&list);
  return 0;
}
```
#### Результаты работы программы
```
5<->10<->15<->20  
traversed 4 elements  
20<->15<->10<->5  
traversed 4 elements
```

## Комплект 2: Объединения и перечисления
### Задача 1
#### Постановка задачи
Напишите программу, которая использует указатель на некоторое объ-
единение union.
#### Список идентификаторов
| имя переменной | тип данных | описание                     |
| -------------- | ---------- | ---------------------------- |
| Data           | union      | объединение данных           |
| print_data     | void       | вывод данных выбранного типа |

#### Код программы
```c
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
```
#### Результаты работы программы
```
data set to int  
integer: 42  
float: 0.00  
string: *  
  
data set to float  
integer: 1078523331  
float: 3.14  
string: ��H@  
  
data set to string  
integer: 1701998444  
float: 71554253729174499885056.00  
string: lorem ipsum
```

### Задача 2
#### Постановка задачи
Напишите программу, которая использует union для побайтовой рас-
печатки типа unsigned long.
#### Список идентификаторов
| имя переменной | тип данных | описание                         |
| -------------- | ---------- | -------------------------------- |
| Number         | union      | объединение значения и его битов |
#### Код программы
```c
#include <stdio.h>

union Number {
  unsigned long value;
  unsigned char bytes[sizeof(unsigned long)];
};

int main() {
  union Number num;
  num.value = 0x123456ABCDEF;

  for (int i = 0; i < sizeof(unsigned long); i++) {
    printf("%02X", num.bytes[i]);
  }

  return 0;
}
```
#### Результаты работы программы
```
EFCDAB5634120000
```

### Задача 3
#### Постановка задачи
Создайте перечислимый тип данных (enum) для семи дней недели и
распечатайте на экране его значения, как целые числа.
#### Список идентификаторов
| имя переменной | тип данных | описание                 |
| -------------- | ---------- | ------------------------ |
| Days           | enum       | перечисление дней недели |
#### Код программы
```c
#include <stdio.h>

enum Days { MONDAY, TUESDAY, WEDNESDAY, THURSDAY, FRIDAY, SATURDAY, SUNDAY };

int main() {
  printf("monday: %d\n", MONDAY);
  printf("tuesday: %d\n", TUESDAY);
  printf("wednesday: %d\n", WEDNESDAY);
  printf("thursday: %d\n", THURSDAY);
  printf("friday: %d\n", FRIDAY);
  printf("saturday: %d\n", SATURDAY);
  printf("sunday: %d", SUNDAY);

  return 0;
}
```
#### Результаты работы программы
```
monday: 0  
tuesday: 1  
wednesday: 2  
thursday: 3  
friday: 4  
saturday: 5  
sunday: 6
```

### Задача 4
#### Постановка задачи
Создайте так называемое размеченное объединение union, которое
заключено в виде поля структуры struct вместе с ещё одним полем,
которое является перечислением enum и служит индикатором того,
что именно на текущий момент хранится в таком вложенном объеди-
нении. Создать и заполнить динамический массив таких структур с
объединениями внутри, заполняя вспомогательное поле перечисления
enum для сохранения информации о хранимом в каждом размеченном
объединении типе данных. Реализовать распечатку данных массива
таких структур в консоль.
#### Список идентификаторов
| имя переменной | тип данных | описание                                                  |
| -------------- | ---------- | --------------------------------------------------------- |
| Type           | enum       | типы данных                                               |
| Value          | union      | значения соответствующие разным типам данных              |
| Variant        | struct     | структура содержащая тип и значение соответствующего типа |
#### Код программы
```c
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
```
#### Результаты работы программы
```
number of elements: 3  
  
select type for element 1 [1-int|2-float|3-string]: 1  
input int value: 123  
  
select type for element 2 [1-int|2-float|3-string]: 2  
input float value: 2.5  
  
select type for element 3 [1-int|2-float|3-string]: 3  
input string value: test  
  
collected elements:  
element 1 (int): 123  
element 2 (float): 2.50  
element 3 (string): test
```

## Информация о студенте
Крамбалев Сергей Дмитриевич, 1 курс, группа ИВТ-25