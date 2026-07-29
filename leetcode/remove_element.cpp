// LeetCode: 27
// Remove Element

#include <vector>

class Solution {
public:
  int removeElement(std::vector<int>& nums, int val) {
    int idx = 0;

    while(idx < nums.size()) {
      if(nums[idx] == val) {
        nums.erase(nums.begin() + idx);
      } else {
        ++idx;
      }
    }

    return nums.size();
  }
};