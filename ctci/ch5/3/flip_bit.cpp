#include <iostream>

int getBit(int num, int i) {
  return (num >> i) & 1;
}

int flipBitToWin(int num) {
  int count = 0;
  int prefix_count = 0;
  int postfix_count = 0;
  int zero_count = 0;
  int maxcount = 0;
  for (int i = 31; i >= 0; i--) {
    if (getBit(num, i)) {
      if (zero_count > 1) {
	postfix_count++;
      } else {
	prefix_count++;
      }
    } else {
      if (zero_count > 1) {
	count = prefix_count + postfix_count + 1;
	maxcount = (count > maxcount) ? count : maxcount;
	prefix_count = postfix_count;
	postfix_count = 0;	
      }
      zero_count++;
    }
  }
  
  count = prefix_count + postfix_count + 1;
  maxcount = (count > maxcount) ? count : maxcount;
  return maxcount;
}

int main() {
  std::cout << flipBitToWin(1775) << std::endl;
  std::cout << flipBitToWin(0xD8) << std::endl;
}
