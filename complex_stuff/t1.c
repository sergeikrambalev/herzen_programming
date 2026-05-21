#include <stdbool.h>
#include <stdio.h>

#define MAX_SIZE 256

typedef struct {
  char data[MAX_SIZE];
  int top;
} Stack;

void stack_init(Stack *s) { s->top = -1; }

bool stack_push(Stack *s, char c) {
  if (s->top >= MAX_SIZE - 1)
    return false;
  s->data[++(s->top)] = c;
  return true;
}

char stack_pop(Stack *s) {
  if (s->top < 0)
    return '\0';
  return s->data[(s->top)--];
}

char stack_peek(Stack *s) {
  if (s->top < 0)
    return '\0';
  return s->data[s->top];
}

bool stack_is_empty(Stack *s) { return s->top < 0; }

int is_opening(char c) { return c == '(' || c == '[' || c == '{'; }

char matching_close(char open) {
  if (open == '(')
    return ')';
  if (open == '[')
    return ']';
  if (open == '{')
    return '}';
  return '\0';
}

bool check_balance(const char *str) {
  Stack s;
  stack_init(&s);

  for (int i = 0; str[i] != '\0'; i++) {
    char c = str[i];

    if (is_opening(c))
      stack_push(&s, c);

    else if (c == ')' || c == ']' || c == '}') {
      if (stack_is_empty(&s))
        return false;

      char open = stack_pop(&s);
      if (matching_close(open) != c)
        return false;
    }
  }

  return stack_is_empty(&s);
}

int main() {
  char expr[MAX_SIZE];

  printf("Enter bracket expression: ");
  fgets(expr, MAX_SIZE, stdin);

  if (check_balance(expr))
    printf("Expression is balanced.");
  else
    printf("Expression is NOT balanced.");

  return 0;
}
