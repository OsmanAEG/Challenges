// LeetCode: 136
// Single Number

#include <vector>

class Solution {
public:
  int singleNumber(std::vector<int>& nums) {
    int result = 0;

    for(const auto& num : nums) result ^= num;

    return result;
  }
};