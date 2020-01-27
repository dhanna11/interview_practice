#include <string.h>
#include <stdio.h>
#include <stdlib.h>

/* Implement a C function that takes a null-terminated string and returns a new heap-allocated null-terminated string containing every other character from original string (e.g., “house” -> “hue”). */

char* strdup_every_other_char(const char* s) {
  /* new_str length = ceiling(strlen(s) / 2) + 1 (for null byte)
     I used calloc because I'm lazy.
     Could use malloc and set null byte maually if we prefer more
     idomatic code.
   */
  size_t len = strlen(s);
  char* new_str = calloc(sizeof(char), (len + 1) / 2 + 1);
  for (size_t i = 0; i < len; i+=2) {
    new_str[i/2] = s[i];
  }
  return new_str;
}

int main () {
  printf("%s \n", strdup_every_other_char(""));
  printf("%s \n", strdup_every_other_char("h"));
  printf("%s \n", strdup_every_other_char("ho"));
  printf("%s \n", strdup_every_other_char("hou"));
  printf("%s \n", strdup_every_other_char("hous"));
  printf("%s \n", strdup_every_other_char("house"));
  printf("%s \n", strdup_every_other_char("houses"));
  printf("%s \n", strdup_every_other_char("ababababa"));
  printf("%s \n", strdup_every_other_char("ababababab"));
  printf("%s \n", strdup_every_other_char("abababababa"));
  printf("%s \n", strdup_every_other_char("babababab"));
  printf("%s \n", strdup_every_other_char("bababababa"));
  printf("%s \n", strdup_every_other_char("bababababab"));
}
