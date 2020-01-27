#include <stdio.h>
#include "SetOfStacks.h"


// FIXME: Test this more. 
int main() {
  SetOfStacks *setOfStacks = newSetOfStacks(10);
  if(pushSetOfStacks(setOfStacks, (void*)5))
    printf("Error pushing");
  void *outVal;
  if(popSetOfStacks(setOfStacks, &outVal))
    printf("Error popping");
  
  printf("%d", (int)outVal);
}
