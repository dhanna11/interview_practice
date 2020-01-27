#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

bool one_away(const char* s0, const char* s1) {
  int n0 = strlen(s0);
  int n1 = strlen(s1);
  bool foundedit = false;
  if (abs(n0 - n1) > 1) {
    return false;
  }

  const char* str0 = (n0 >= n1) ? s0 : s1;
  const char* str1 = (n0 >= n1) ? s1 : s0;
  int len = (n0 >= n1) ? n1 : n0;
  bool removal = (abs(n0-n1)) == 1;
  for (int i = 0, j=0; j < len; i++,j++) {
    if (str0[i] != str1[j]) {
      if (foundedit)
	return false;
      foundedit = true;
      if (removal)
	j--; // A litle confusing. Could replace for loop with while loop
    }
  }
  return true;
}

int main() {
  char* s0 = "Pale";
  char* s1 = "Ple";
  printf("%d", one_away(s0, s1));
  s0 = "Bake";
  s1 = "Pale";
  printf("%d", one_away(s0,s1));
  s0 = "";
  s1 = "";
  printf("%d", one_away(s0,s1));
  s0 = "abcd";
  s1 = "abce";
  printf("%d", one_away(s0,s1));
}
