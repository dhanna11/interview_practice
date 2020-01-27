#include <algorithm>
#include <string>
#include <iostream>
#include <map>

bool check_permutation(std::string str0, std::string str1) {

  if (str0.length() != str1.length())
    return false;
  std::sort(str0.begin(), str0.end());
  std::sort(str1.begin(), str1.end());

  return !str0.compare(str1);
}

std::map<char,int> string_to_charmap(std::string str) {
  

}

bool check_permutation_map(std::string str0, std::string str1) {
  std::map<char,int> &str0_map, &str1_map;
  str0_map = string_to_charmap(str0);
  str1_map = string_to_charmap(str1);

  return str0_map == str1_map;
}

int main() {

  std::string str0("foobar");
  std::string str1("barfoo");
  std::string str2("barfooo");
  std::string str3("abcd    ");
  std::string str4("    abcd");
  std::cout << check_permutation(str0, str1) << '\n';
  std::cout << check_permutation(str0, str2) << '\n';
  std::cout << check_permutation(str3, str4) << '\n';
  
}
