// LeetCode: 287
// Find the Duplicate Number

#include <vector>

class Solution {
public:
  int findDuplicate(std::vector<int>& nums) {
    int idx_slow = nums[0];
    int idx_fast = nums[nums[0]];

    while(idx_slow != idx_fast) {
      idx_slow = nums[idx_slow];
      idx_fast = nums[nums[idx_fast]];
    }

    idx_slow = 0;

    while(idx_slow != idx_fast) {
      idx_slow = nums[idx_slow];
      idx_fast = nums[idx_fast];
    }

    return idx_slow;
  }
};