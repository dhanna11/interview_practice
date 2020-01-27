#include <string.h>
#include <stdio.h>
#include <stdbool.h>

bool is_unique(char* str) {
  int charSet[26];
  memset(charSet, 0, 26);
  for (int i = 0; i < strlen(str); i++) {
    char index = str[i] - 'a';
    if (charSet[index] != 0) {
      return false;
    }
    charSet[index] = 1;
  }
  return true;
}

bool is_unique_bitvector(char* str) {
  int charVector = 0;
  for (int i = 0; i < strlen(str); i++) {
    char index = str[i] - 'a';
    if (charVector & (1 << index)) 
      return false; 
    charVector |= 1 << index;
  }
  return true;
}

int main() {
  char* str0 = "abcd";
  char* str1 = "aaa";
  printf("%d\n", is_unique(str0));
  printf("%d\n", is_unique(str1));
  printf("%d\n", is_unique_bitvector(str0));
  printf("%d\n", is_unique_bitvector(str1));
}
