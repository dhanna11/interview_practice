#include <stdlib.h>
#include "Stack.h"

typedef struct StackNode{
  void* elm;
  struct StackNode* next;
} StackNode;

typedef struct Stack {
  struct StackNode* top;
  size_t count;
} Stack;

int pushStack(Stack *s, void* elm) {
  StackNode* newNode = malloc(sizeof(StackNode));
  newNode->elm = elm;
  newNode->next = s->top;
  s->top = newNode;
  s->count++;
  return 0;
}

int popStack(Stack *s, void** outVal) {
  if (s->count == 0)
    return -1;
  *outVal = s->top->elm;
  StackNode* next = s->top->next;
  free(s->top);
  s->top = next;
  return 0;
}

void initStack(Stack* s) {
  s->top = NULL;
  s->count = 0;
}

Stack* newStack() {
  Stack* new = malloc(sizeof(Stack));
  initStack(new);
  return new;
}

int countStack(Stack* s) {
  return s->count;
}
