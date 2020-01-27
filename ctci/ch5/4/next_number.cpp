#include <iostream>

int setBit(int num, int i) {
  return num | (1 << i);
}

int clearBit(int num, int i) {
  return num & ~(1 << i);
}

int getBit(int num, int i) {
  return num & (1 << i);
}

int bitIsSet(int num, int i) {
  return (num >> i) & 1; 
}

int lowestSetBitIdx(int num) {
  for (int i = 0; i < 32; i++) {
    if (getBit(num, i)) {
      return i;
    }
  }
  return 0;
}

int countSetBits(unsigned int num) {
  int count = 0;
  while (num != 0) {
    if (num &1)
      count++;
    
    num>>=1;
  }
  return count;
}

int next_smallest(int num) {
  for (int i = 0; i < 30; i++) {
    if (!bitIsSet(num, i) && bitIsSet(num, i + 1)) {
      return num - (1 << i);
    }
  }
  return num;
}

int next_largest(int num) {
  int nextLargest = num;
  int idx;
  for (idx = 0; idx < 30; idx++) {
    if (bitIsSet(num, idx) && !bitIsSet(num, idx+1))
      break;
  }
  nextLargest += 1 << idx;
  for (int i = 0; i < idx - 1; i++) {
    if (!bitIsSet(nextLargest, i) && bitIsSet(nextLargest, i + 1)) {
      nextLargest -= 1 << i;
    }
  }
  return nextLargest;
}

int main() {
  std::cout << next_smallest(6) << std::endl;
  std::cout << next_smallest(7) << std::endl;
  std::cout << next_smallest(8) << std::endl;
  std::cout << next_smallest(9) << std::endl;
  std::cout << next_smallest(10) << std::endl;
  std::cout << next_smallest(11) << std::endl;
}
