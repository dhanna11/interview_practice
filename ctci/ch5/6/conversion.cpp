#include <iostream>

int countSetBits(int num) {
  int count = 0;

  while (num > 0) {
    count++;
    num = num & (num-1);
  }
  return count;
}

int conversion(int a, int b) {
  int result = a ^ b;
  return countSetBits(result);
}

int main() {
  std::cout << conversion(29,15) << std::endl;
}
