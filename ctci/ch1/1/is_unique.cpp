#include <string>
#include <bitset>
#include <iostream>

bool is_unique(std::string s) {
  std::bitset<128> charBitSet;
  for (char& c : s) {
    if (charBitSet.test(c)) 
      return false;
    else
      charBitSet.set(c);
  }
  return true;
}

bool is_unique_no_space(std::string s) {
  for (std::string::size_type i = 0; i < s.length(); i++) {
    for (std::string::size_type j = i + 1; j < s.length(); j++) {
      if (s.at(i) == s.at(j)) return false;
    }
  }
  return true;
}

int main() {

  std::string s0 ("Foobar");
  std::string s1 ("Barfoo");
  std::string s2 ("unique");
  std::string s3 ("abcdef");

  std::cout << is_unique(s0) << '\n';
  std::cout << is_unique(s1) << '\n';
  std::cout << is_unique(s2) << '\n';
  std::cout << is_unique(s3) << '\n';

  std::cout << is_unique_no_space(s0) << '\n';
  std::cout << is_unique_no_space(s1) << '\n';
  std::cout << is_unique_no_space(s2) << '\n';
  std::cout << is_unique_no_space(s3) << '\n';

}
