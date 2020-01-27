#include <stdio.h>
#include "stackmin2.h"

int main() {
  StackWithMin2* stack = initStackWithMin2();
  int outVal, ret;

  pushStackWithMin2(stack, 4);
  ret = minElmStackWithMin2(stack, &outVal);  
  printf("%d %d\n", ret, outVal);

  pushStackWithMin2(stack, 3);
  ret = minElmStackWithMin2(stack, &outVal);  
  printf("%d %d\n", ret, outVal);

  pushStackWithMin2(stack, 5);
  ret = minElmStackWithMin2(stack, &outVal);  
  printf("%d %d\n", ret, outVal);

  ret = popStackWithMin2(stack, &outVal);
  printf("%d %d\n", ret, outVal);
  ret = minElmStackWithMin2(stack, &outVal);  
  printf("%d %d\n", ret, outVal);

}
