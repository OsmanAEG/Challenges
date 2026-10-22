// LeetCode: 55
// Jump Game

#include <vector>

class Solution {
public:
  bool canJump(std::vector<int>& nums) {
    std::vector<bool> can_reach(nums.size(), false);

    can_reach[0] = true;

    for(int i = 0; i < nums.size(); ++i) {
      if(can_reach[i] == false) continue;

      for(int j = i + 1; j <= i + nums[i] && j < nums.size(); ++j) {
        can_reach[j] = true;
      }
    }

    return can_reach[nums.size() - 1];
  }
};