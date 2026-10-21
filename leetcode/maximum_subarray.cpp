// LeetCode: 53
// Maximum Subarray

#include <algorithm>
#include <vector>

class Solution {
public:
  int maxSubArray(std::vector<int>& nums) {
    int max = 0;
    if(nums.size() == 0) return max;

    int curr = nums[0];
    max = curr;

    for(int i = 1; i < nums.size(); ++i) {
      curr = std::max(nums[i], nums[i] + curr);
      max = std::max(max, curr);
    }

    return max;
  }
};