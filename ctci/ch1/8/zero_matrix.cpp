#include <iostream>
#include <vector>

template<size_t rows, size_t cols>
void print_matrix(int (&matrix)[rows][cols]) {
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      std::cout << matrix[i][j] << ' '; 
    }
    std::cout << std::endl;
  }
}

template<size_t rows, size_t cols>
void zero_matrix(int (&matrix)[rows][cols]) {
  std::vector<bool> row_vec(rows, false);
  std::vector<bool> col_vec(cols, false);

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      if (matrix[i][j] == 0) {
	row_vec[i] = true;
	col_vec[j] = true;
      }
    }
  }

  for(int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      if (row_vec[i] || col_vec[j]) {
	matrix[i][j] = 0;
      }
    }
  }
}

int main() {
  int m0[3][3] = {
    {0,1,2},
    {3,4,5},
    {6,7,8}
  };

  zero_matrix(m0);
  print_matrix(m0);
  return 0;

}
