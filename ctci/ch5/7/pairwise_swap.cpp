#include <iostream>

int pairwiseSwap(int num) {
  int evenMask = 0x55555555;
  int oddMask = 0xAAAAAAAA;

  unsigned int evenBits = num & evenMask;
  unsigned int oddBits = num & oddMask;

  return (evenBits << 1 ) | (oddBits >> 1);
}

int main() {
  std::cout << pairwiseSwap(0x9) << std::endl;
}
