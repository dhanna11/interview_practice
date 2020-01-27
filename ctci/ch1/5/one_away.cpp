#include <iostream>
#include <string>

bool one_insert(std::string s0, std::string s1) {
  int i = 0, j = 0;
  bool found_diff = false;
  while (i < s0.length() && j < s1.length()) {
    if (s0.at(i) != s1.at(j)) {
      if (found_diff)
	return false;
      found_diff = true;
      j++;
    }
    i++;
    j++;
  }
  return true;
}

bool one_replace(std::string s0, std::string s1) {
  bool found_diff = false;
  for (int i = 0; i < s0.length(); i++) {
    if (s0.at(i) != s1.at(i)) {
      if (found_diff)
	return false;
      found_diff = true;
    }
  }
  return true;
}

bool one_away(std::string s0, std::string s1) {
  
  if (s0.length() - 1 == s1.length()) 
    return one_insert(s0, s1);  
  else if (s0.length() + 1 == s1.length()) 
    return one_insert(s1, s0);
  else if (s0.length() == s1.length()) 
    return one_replace(s0, s1);  
  else return false;
}


int main() {
  std::string s0("pale");
  std::string s1("bae");
  std::cout << one_away(s0, s1) << std::endl;


}
