// LeetCode: 1
// Two Sum

#include <unordered_map>
#include <vector>

class Solution {
public:
  std::vector<int> twoSum(std::vector<int>& nums, int target) {
    std::unordered_map<int, int> diff_map;

    for(int i = 0; i < nums.size(); ++i) {
      if(diff_map.find(nums[i]) != diff_map.end()) {
        return {diff_map[nums[i]], i};
      }

      const auto diff = target - nums[i];
      diff_map[diff] = i;
    }

    return {0, 0};
  }
};