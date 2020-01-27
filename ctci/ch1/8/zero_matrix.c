#include <stdio.h>
void print_matrix(int N, int *mat) {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++)
      printf("%d", *(mat + i * N + j));
    printf("\n");
  }
}

void zero_matrix(int M, int N, int *mat) {
  int zero_row = -1;
  int zero_col = -1;

  for (int i = 0; i < M; i++) {
    for (int j = 0; j < N; j++) {
      if (*(mat+i*M +j) == 0) {
	zero_row = i;
	zero_col = j;
	break;
      }
    }
  }

  if (zero_row == -1) return;

  for (int i = 0; i < M; i++) {
    if (i == zero_row)
      continue;
    for(int j = 0; j < N; j++) {
      if (j == zero_col)
	continue;
      if (*(mat + i*M + j) == 0) {
	*(mat + i*M + zero_col) = 0;
	*(mat + zero_row*M + j) = 0;
      }
    }
  }
  for (int i = 0; i < M; i++) {
    for (int j = 0; j < N; j++) {
      if ((*(mat + i*M + zero_col) == 0) || *(mat + zero_row*M + j) == 0) {
	*(mat + i*M +j) = 0;
      }	
    }
  }
  return;
}


int main() {
  int mat[9] = {1,0,3,4,5,6,7,8,0};
  zero_matrix(3,3, mat);
  print_matrix(3, mat);

}
