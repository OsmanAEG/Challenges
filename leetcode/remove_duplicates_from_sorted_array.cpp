// LeetCode: 26
// Remove Duplicates from Sorted Array

#include <climits>
#include <vector>

class Solution {
public:
  int removeDuplicates(std::vector<int>& nums) {
    int last_num = INT_MAX;

    int idx = 0;

    while(idx < nums.size()) {
      if(last_num == nums[idx]) {
        nums.erase(nums.begin() + idx);
      } else {
        last_num = nums[idx];
        ++idx;
      }
    }

    return nums.size();
  }
};