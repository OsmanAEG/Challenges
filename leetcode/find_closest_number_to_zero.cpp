// LeetCode: 2239
// Find Closest Number to Zero

#include<algorithm>
#include<climits>
#include<vector>

class Solution {
public:
  int findClosestNumber(std::vector<int>& nums) {
    auto min_dif = std::abs(nums[0]);
    auto min_num = nums[0];

    for(const auto& num : nums) {
      if(std::abs(num) < min_dif) {
        min_dif = std::abs(num);
        min_num = num;
      } else if(std::abs(num) == min_dif) {
        if(num > min_num) min_num = num;
      }
    }

    return min_num;
  }
};