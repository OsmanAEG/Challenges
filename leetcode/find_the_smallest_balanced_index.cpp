// LeetCode: 3862
// Find the Smallest Balanced Index

#include <vector>

class Solution {
public:
  int smallestBalancedIndex(std::vector<int>& nums) {
    const int n = nums.size();

    std::vector<long long> left(n, 0);
    std::vector<long long> right(n, 1);

    long long sum_left = 0;
    long long product_right = 1;

    for(int i = 0; i < n; ++i) {
      left[i] = sum_left;
      sum_left += nums[i];
    }

    for(int i = n - 1; i >= 0; --i) {
      right[i] = product_right;

      if(product_right > sum_left / nums[i]) {
        product_right = sum_left + 1;
      } else {
        product_right *= nums[i];
      }
    }

    for(int i = 0; i < n; ++i) {
      if(left[i] == right[i]) return i;
    }

    return -1;
  }
};
