// LeetCode: 1004
// Max Consecutive Ones III

#include <algorithm>
#include <vector>

class Solution {
public:
  int longestOnes(std::vector<int>& nums, int k) {
    int max = 0;
    int max_i = 0;

    int tmp_k = 0;

    int low = 0;
    int high = 0;

    while(high < nums.size()) {
      if(nums[high] == 1) {
        ++high;
        ++max_i;
      } else if (nums[high] == 0 && tmp_k < k) {
        ++high;
        ++max_i;
        ++tmp_k;
      } else {
        if(nums[low] == 0) --tmp_k;
        --max_i;
        ++low;
      }

      max = std::max(max_i, max);
    }

    return max;
  }
};