#include <stdlib.h>
#include <stdio.h>

#define min(a,b) \
   ({ __typeof__ (a) _a = (a); \
       __typeof__ (b) _b = (b); \
     _a < _b ? _a : _b; })


// Public types
struct StackWithMin2;
typedef struct StackWithMin2 StackWithMin2;

// Public member funcs
StackWithMin2* initStackWithMin2();
int pushStackWithMin2(StackWithMin2* stack, int elm);
int popStackWithMin2(StackWithMin2* stack, int* outVal);
int minElmStackWithMin2(StackWithMin2* stack, int* outVal);

// Struct definitions

typedef struct StackNode {
  int elm;
  struct StackNode* next;
} StackNode;

typedef struct {
  StackNode* top;
  int count;
} Stack;

struct StackWithMin2{
  Stack primaryStack;
  Stack minStack;
};

// Function definitions
static void initStack(Stack* stack) {
  stack->top = NULL;
  stack->count = 0;
}

StackWithMin2* initStackWithMin2() {
  StackWithMin2* stack = malloc(sizeof(StackWithMin2));
  initStack(&stack->primaryStack);
  initStack(&stack->minStack);
  return stack;
}

static void pushStack(Stack* stack, int elm) {
  StackNode* newTop = malloc(sizeof(StackNode));
  newTop->elm = elm;
  newTop->next = stack->top;
  stack->top = newTop;
  stack->count++;
}

static void pushPrimaryStack(StackWithMin2* stack, int elm) {
  pushStack(&stack->primaryStack, elm);
}

static void pushMinStack(StackWithMin2* stack, int elm) {
  pushStack(&stack->minStack, elm);
}

static int stackCount(Stack* stack) {
  if (!stack)
    return -1;
  return stack->count;
}

static int primaryStackCount(StackWithMin2* stackWithMin2) {
  return stackCount(&stackWithMin2->primaryStack);
}

static int minStackCount(StackWithMin2* stackWithMin2) {
  return stackCount(&stackWithMin2->minStack);
}

static int peekStack(Stack *stack, int* outVal) {
  if (!stack)
    return -1;
  *outVal = stack->top->elm;
  return 0;
}

static int peekPrimaryStack(StackWithMin2* stackWithMin2, int *outVal) {
  return peekStack(&stackWithMin2->primaryStack, outVal);
}

static int peekMinStack(StackWithMin2* stackWithMin2, int *outVal) {
  return peekStack(&stackWithMin2->minStack, outVal);
}

int peekStackWithMin2(StackWithMin2* stackWithMin2, int* outVal) {
  return peekPrimaryStack(stackWithMin2, outVal);
}

int pushStackWithMin2(StackWithMin2* stack, int elm) {
  if (!stack)
    return -1;
  
  pushPrimaryStack(stack, elm);
  if (minStackCount(stack) == 0) {
    printf("found new min\n");
    pushMinStack(stack, elm);
    return 0;
  }
  
  int minElement;
  if (peekMinStack(stack, &minElement))
    return -1;
  
  if (elm < minElement)
    pushMinStack(stack, elm);
  
  return 0;
}

static int popStack(Stack* stack, int *outVal) {
  if (!stack)
    return -1;
  *outVal = stack->top->elm;
  StackNode* next = stack->top->next;
  free(stack->top);
  stack->top = next;
  stack->count--;
  return 0;
}

static int popPrimaryStack(StackWithMin2* stackWithMin2, int* outVal) {
  return popStack(&stackWithMin2->primaryStack, outVal);
}

static int popMinStack(StackWithMin2* stackWithMin2, int* outVal) {
  return popStack(&stackWithMin2->primaryStack, outVal);
}

int popStackWithMin2(StackWithMin2* stack, int* outVal) {
  if (!stack)
    return -1;

  
  if (popPrimaryStack(stack, outVal))
    return -1;

  if (minStackCount(stack) > 0) {
    int minElement;
    if (peekMinStack(stack, &minElement))
      return -1;
  
    if (minElement == *outVal)
      popMinStack(stack, &minElement);
  }
  
  return 0;
}

int minElmStackWithMin2(StackWithMin2* stack, int* outVal) {
  if (!stack)
    return -1;

  if (peekMinStack(stack, outVal))
      return -1;
  return 0;
}
