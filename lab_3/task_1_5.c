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
