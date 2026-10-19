// LeetCode: 198
// House Robber

#include <algorithm>
#include <vector>

class Solution {
public:
  int rob(std::vector<int>& nums) {
    const int n = nums.size();

    if(n == 1) return nums[0];

    std::vector<int> running_total(nums.size(), 0);

    running_total[0] = nums[0];
    running_total[1] = std::max(nums[0], nums[1]);

    for(int i = 2; i < nums.size(); ++i) {
      running_total[i] = std::max(running_total[i-1], running_total[i-2] + nums[i]);
    }

    return running_total[n-1];
  }
};