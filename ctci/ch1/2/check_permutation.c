#include <stdbool.h>
#include <string.h>
#include <stdio.h>

bool check_permutation(const char* str0, const char* str1) {
  if (strlen(str0) != strlen(str1))
    return false;
  int len = strlen(str0);
  int str0_count[128];
  memset(str0_count, '\0', 128);
  for (int i = 0; i < len; i++) {
    int idx = str0[i] - 'a';
    str0_count[idx] +=1;
  }
  for (int i = 0; i < len; i++) {
    int idx = str1[i] - 'a';
    str0_count[idx] -=1;
    if (str0_count[idx] < 0)
      return false;
  }
  return true;
}

int main() {
  printf("%d", check_permutation("", ""));
  printf("%d", check_permutation("dog", "dog"));
  printf("%d", check_permutation("abcde", "edcba"));
  printf("%d", check_permutation("dogcat", "catdog"));
  printf("%d", check_permutation("dogcat", "catdogf"));
  printf("%d", check_permutation("dogctt", "catdog"));
}
