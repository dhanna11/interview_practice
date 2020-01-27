#include <iostream>

int FivesInDecomp(int i) {
  int count = 0;
  while (i % 5 == 0) {
    count++;
    i/=5;
  }
  return count;
}

int factorial_zeros(int n) {
  int totalNum5s = 0;
  for (int i = 5; i <= n; i++) {
    totalNum5s += FivesInDecomp(i);
  }
  return totalNum5s;
}

int factorial_zeros_optimized(int n) {
  int count = 0;
  for (int i = 5; num/ i > 0; i*=5) {
    count += num / i;
  }
  return count;
}

int main() {
  std::cout << factorial_zeros(29) << std::endl;
  
}
