#include <stddef.h>
#include <stdbool.h>
#include <stdlib.h>
#include "UBA.h"
#include "Stack.h"

typedef struct SetOfStacks{
  size_t maxSubStackSize;
  size_t currentSubStack;
  struct Uba *uba;
} SetOfStacks;

SetOfStacks* newSetOfStacks(size_t maxSubStackSize) {
  SetOfStacks *s = malloc(sizeof(SetOfStacks));
  s->uba = newUba(1);
  s->maxSubStackSize = maxSubStackSize;
  s->currentSubStack = 0;
  UbaEmplace(s->uba, newStack());
  return s;
}

Stack* getCurrentSubStack(SetOfStacks *s) {
  return (Stack*)UbaBack(s->uba);
}

bool currentSubStackIsEmpty(SetOfStacks *s) {
  return (countStack(getCurrentSubStack(s)) == 0); 
}

int deallocateCurrentSubStack(SetOfStacks *s) {
  // Don't deallocate 0'th stack
  if (s->currentSubStack == 0)
    return 0;
  if (UbaRemove(s->uba, s->currentSubStack))
    return -1;
  s->currentSubStack--;
  return 0;
}

int popCurrentSubStack(SetOfStacks *s, void** outVal) {
  if (popStack(getCurrentSubStack(s), outVal)) {
    printf("error calling popCurrentSubStack");
    return -1;
  }
  return 0;			  
}

int popSetOfStacks(SetOfStacks *s, void** outVal) {
  if (currentSubStackIsEmpty(s))
    if (deallocateCurrentSubStack(s))
      return -1;
  if (popCurrentSubStack(s, outVal))
    return -1;
  return 0;
}

bool currentSubStackIsFull(SetOfStacks *s) {
  return (countStack(getCurrentSubStack(s)) == s->maxSubStackSize);
}

int allocateNewCurrentSubStack(SetOfStacks *s) {
  if (UbaEmplace(s->uba, newStack()))
    return -1;
  s->currentSubStack++;
  return 0;
}

int pushCurrentSubStack(SetOfStacks *s, void* elm) {
  if (pushStack(getCurrentSubStack(s), elm))
    return -1;
  return 0;
}

int pushSetOfStacks(SetOfStacks *s, void* elm) {
  if (currentSubStackIsFull(s))
    if (allocateNewCurrentSubStack(s))
      return -1;
  if (pushCurrentSubStack(s, elm))
    return -1;
  return 0;
}




