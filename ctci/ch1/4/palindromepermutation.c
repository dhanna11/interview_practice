#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <stdio.h>

int palindromepermutation(char* s) {
  int bitvector = 0; // Assume 26 char alphabet
  for (int i = 0, n = strlen(s); i < n; i++) {
    if (!isspace(s[i])){
      int index = (s[i] - 'a') % 26;
      bitvector ^= 1 << index;
    }
  }
  return ((bitvector - 1) & bitvector) == 0;
}


int main() {
  char* s0 =  "taco cat";
  printf("%d", palindromepermutation(s0));
  char* s1 =  "taco ca";
  printf("%d", palindromepermutation(s1));
  char* s2 =  "";
  printf("%d", palindromepermutation(s2));
  char* s3 =  "a";
  printf("%d", palindromepermutation(s3));
  char* s4 =  "aa";
  printf("%d", palindromepermutation(s4));
}
