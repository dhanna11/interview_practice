#include <stdio.h>

void rotatematrix(int len, int mat[len][len]) {

}

void printmat(int * arr, int m) {
  for (int i = 0; i < m; i++) {
    printf("\n");
    for (int j = 0; j < m; j++) 
      printf("%d ", *((arr+i*m) + j));
  }
}
  

int main() {
  int arr[][3] = {{0, 1, 2}, {3, 4, 5}, {6, 7, 8}}; 
  printmat((int*)arr, 3);
  rotatematrix(3, arr);
  printmat((int*)arr, 3);
}
