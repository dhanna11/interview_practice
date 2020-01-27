#include <iostream>
#include <vector>
#include <set>
#include <assert.h>

bool allUniqueChars(std::string str) {
  int bitvector = 0;
  for (char&c : str) {
    char idx = c - 'a';
    if ((bitvector & (1 << idx)) > 0)
      return false;
    bitvector |= (1 << idx);
  }
  return true;
}

std::vector<std::string> kuniquesubstring(std::string s, int k) {
  std::vector<std::string> strings;
  std::set<std::string> kUniqueStringSet;

  for (int i = 0; i < s.size() - (k - 1); i++) {
    std::string ss = s.substr(i, k);
    if (allUniqueChars(ss)) {
      kUniqueStringSet.insert(ss);
    }
  }
  for (std::string str : kUniqueStringSet) {
    strings.emplace_back(str); 
  }
  
  return strings;
}

int main() {
  std::string str("abcdeefg");
  for (std::string s : kuniquesubstring(str,2))
    std::cout << s << std::endl;
  return 0;
}
