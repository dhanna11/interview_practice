#include <stdlib.h>
#include <stdio.h>

#define min(a,b) \
   ({ __typeof__ (a) _a = (a); \
       __typeof__ (b) _b = (b); \
     _a < _b ? _a : _b; })


typedef struct StackNodeWithMin {
  int elm;
  int min;
  struct StackNodeWithMin* next;
} StackNodeWithMin;

typedef struct Stack {
  StackNodeWithMin* head;
} Stack;

void initStack(Stack** stack) {
  *stack = malloc(sizeof(Stack*));
  (*stack)->head = NULL;
}

int push(Stack* stack, int elm) {
  if (!stack)
    return -1;

  StackNodeWithMin *newhead = malloc(sizeof(StackNodeWithMin));
  newhead->elm = elm;
  newhead->min = (!stack->head) ? elm : min(elm, stack->head->min);
  newhead->next = stack->head;
  stack->head = newhead;
}

int pop(Stack* stack, int* outVal) {
  if (!stack || !stack->head)
    return -1;

  StackNodeWithMin* ret = stack->head;
  *outVal = ret->elm;
  stack->head = ret->next;
  free(ret);
  return 0;
}

int minelm(Stack* stack, int* outVal) {
  if (!stack || !stack->head)
    return -1;
  
  *outVal = stack->head->min;
  return 0;
}


int main () {
  Stack *stack;
  initStack(&stack);
  push(stack,3);
  push(stack,2);
  push(stack,4);
  int outVal;
  minelm(stack, &outVal);
  printf("%d\n", outVal);
  pop(stack, &outVal);
  printf("%d\n", outVal);
  pop(stack, &outVal);
  printf("%d\n", outVal);
  pop(stack, &outVal);
  printf("%d\n", outVal);
};
  
