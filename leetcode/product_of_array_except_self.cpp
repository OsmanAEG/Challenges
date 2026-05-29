// LeetCode: 238
// Product of Array Except Self

#include <vector>

class Solution {
public:
  std::vector<int> productExceptSelf(std::vector<int>& nums) {
    std::vector<int> products(nums.size(), 1);
    int running_prod = 1;

    for(int i = 0; i < nums.size(); ++i) {
      products[i] *= running_prod;
      running_prod *= nums[i];
    }

    running_prod = 1;

    for(int i = nums.size() - 1; i >= 0; --i) {
      products[i] *= running_prod;
      running_prod *= nums[i];
    }

    return products;
  }
};