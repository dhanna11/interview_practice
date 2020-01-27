#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char*  stringcompression(char* s) {
  if (!s) return NULL;
  if (!*s) return NULL;
  int n = strlen(s);
  char *compressed_str = calloc(sizeof(char), n); // temp buffer
  char *compressed_str_ptr = compressed_str;
  int compressed_str_size = 0;
  char current_char = *s;
  int current_char_count = 1;
  compressed_str_ptr += sprintf(compressed_str_ptr, "%c", current_char);

  for (char* ptr = s + 1; *ptr != '\0'; ptr++) {
    if (*ptr == current_char) 
      current_char_count++;
    else {
      int m = sprintf(compressed_str_ptr, "%d", current_char_count);
      compressed_str_size += m;
      compressed_str_ptr += m;
    
      current_char = *ptr;
      current_char_count = 1;
      m = sprintf(compressed_str_ptr, "%c", current_char);
      compressed_str_size += m;
      compressed_str_ptr += m;
      
      if (compressed_str_size > n) {
	free(compressed_str);
	return s;
      }
    }
  }
  sprintf(compressed_str_ptr,"%d", current_char_count);
  char * finalStr = malloc(sizeof(char)* compressed_str_size+1);
  strcpy(finalStr, compressed_str);
  free(compressed_str);
  return finalStr;
}

int main() {
  char* s0 = "aaabbbc";
  printf("%s\n", stringcompression(s0));
  char* s1 = "aaabbbcccc";
  printf("%s\n", stringcompression(s1));
  char *s2 = "abcd";
  printf("%s\n", stringcompression(s2));
  char *s3 = NULL;
  printf("%s \n", stringcompression(s3));
}
