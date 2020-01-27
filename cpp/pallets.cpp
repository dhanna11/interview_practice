#include <iostream>
#include <vector>
#include <float.h>
#include <algorithm>

template <class T>
struct pair {
  pair(T p0, T p1) : p0(p0), p1(p1) {}
  T p0;
  T p1;
};

pair<double> largestPair(std::vector<double> nums, double num) {

  std::vector<double>::size_type l,r, res_l, res_r;
  l = 0;
  r = nums.size() - 1;
  std::sort(nums.begin(), nums.end());
  double diff = FLT_MAX;
  while (l < r) {
    double sum = nums[l] + nums[r];
    
    if ((sum < num) && ((num - sum) < diff)) {
      res_l = l;
      res_r = r;
      diff = num - sum;
    }
    else if (sum > num) {
      r--;
    }
    else {
      l++;
    }
  }
  return pair<double>(nums[res_l], nums[res_r]);
};


int main() {
  pair<double> p = largestPair({1.0,1.1, 1.2,1.5,1.9}, 3.0);
  std::cout << p.p0 << std::endl << p.p1 << std::endl;
  return 0;
}
