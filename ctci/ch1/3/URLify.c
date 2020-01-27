#include <stddef.h>
#include <string.h>
#include <stdio.h>

void URLify(char *s, size_t l) {
  int count = 0;
  for(size_t i = 0; i < l; i++) {
    if ((s[i] == ' '))
      count +=1;
  }
  int oldidx = l-1;
  int newidx = oldidx + count*2; // Thinking about loop invariants caused me to write this. Terminates early instead of using for-loop
  
  while (count > 0) {
    if (s[oldidx] == ' ' ) {
      s[newidx] = '0';
      s[newidx-1] = '2';
      s[newidx-2] = '%';
      count--;
    }
    else {
      s[newidx] = s[oldidx];
    }
    oldidx--;
    newidx = oldidx + count*2;
  }

}

int main() {
  char* s = "Mr John Smith    ";
  char s0[18];
  strcpy(s0, s);
  size_t l = 13;
  URLify(s0,l);
  printf("%s", s0);
}
