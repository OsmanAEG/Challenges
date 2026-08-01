// LeetCode: 80
// Remove Duplicates from Sorted Array II

#include <climits>
#include <vector>

class Solution {
public:
  int removeDuplicates(std::vector<int>& nums) {
    int last_num = INT_MAX;
    int num_reps = 0;

    int idx = 0;

    while(idx < nums.size()) {
      if(last_num != nums[idx]) {
        last_num = nums[idx];
        num_reps = 1;
        ++idx;
      } else if(last_num == nums[idx] && num_reps >= 2) {
        nums.erase(nums.begin() + idx);
      } else {
        last_num = nums[idx];
        ++num_reps;
        ++idx;
      }
    }

    return nums.size();
  }
};