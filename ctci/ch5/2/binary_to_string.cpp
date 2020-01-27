#include <iostream>
#include <string>
#include <math.h>
#include <assert.h>
#include <climits>

class frac {
public:

  int lcm(uint64_t a, uint64_t b) {
    return (a / gcd(a,b)) * b;
  }
  
  int gcd(uint64_t a, uint64_t b) {
    return b == 0 ? a : gcd(b, a % b);
  }
  
  frac(double n)  {
    assert(n < 1.0);
    assert(n > 0.0);
    std::string n_str = std::to_string(n);
    size_t dec_places = n_str.size() - 2;
    num = std::stoi(n_str.substr(2));
    dom = pow(10, dec_places);
    uint64_t g = gcd(num, dom);
    num/=g;
    dom/=g;
  }
  
  frac(uint64_t num, uint64_t dom) : num(num), dom(dom) {}
      
  frac& operator-=(const frac& rhs) {
    uint64_t l = lcm(dom, rhs.dom);
    num = num * (l / dom) - rhs.num * (l / rhs.dom);
    dom = l;
    return *this;
  }
  
  uint64_t num, dom;
};

inline bool operator>=(const frac& lhs, const frac& rhs) {
  return (lhs.num * rhs.dom) >= (rhs.num * lhs.dom);
}

inline bool operator==(const frac& lhs, const frac& rhs) {
  return (lhs.num * rhs.dom) == (rhs.num * lhs.dom);

}

std::ostream& operator<<(std::ostream& os, const frac& f) {
  os << f.num << "/" << f.dom << std::endl;
  return os;
}

std::string binary_to_string(double n) {
  std::string bin_string;
  frac fn(n);
  frac zero(0, 1);
  
  for(uint64_t i = 0; i < 32; i++) {
    if (fn == zero)
      break;
    
    frac power_2_frac(1, 1 << i);
    if (fn >= power_2_frac) {
      std::cout << "power2: " << power_2_frac << "remained frac: " << fn;
      fn-=power_2_frac;
      std::cout << fn << std::endl;
      bin_string.append("1");
    }
    else {
      bin_string.append("0");
    }
  }
  return bin_string;
}

int main() {
  std::cout << binary_to_string(.5) << std::endl;
}
