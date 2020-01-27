#include <vector>
#include <iostream>

struct IntObj {
  int i;
  int valid;
};
  
int maxSubsetSum(std::vector<int>& arr, int k, std::vector<IntObj>& memo) {
  if (k < 0)
    return 0;
  else if (memo[k].valid) 
    return memo[k].i;
  else {
    int t1 = std::max(arr[k] + maxSubsetSum(arr, k - 2, memo), arr[k]);
    int result = std::max(t1, maxSubsetSum(arr, k - 1, memo)); 
    memo[k].i = result;
    memo[k].valid = true;
    return result;
  }
}


int maxSubsetSum(std::vector<int> arr) {
  std::vector<IntObj> memo(arr.size());
  return  maxSubsetSum(arr, static_cast<int>(arr.size() - 1), memo);
}

int main() {
  std::cout << maxSubsetSum(std::vector<int> ({-2,1,3,-4,5})) << std::endl;
  std::cout << maxSubsetSum(std::vector<int> ({3,7,4,6,5})) << std::endl;
  std::cout << maxSubsetSum(std::vector<int> ({2,1,5,8,4})) << std::endl;
  std::cout << maxSubsetSum(std::vector<int> ({3,5,-7,8,10})) << std::endl;
}
