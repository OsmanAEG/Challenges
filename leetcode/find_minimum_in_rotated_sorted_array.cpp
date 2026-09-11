// LeetCode: 153
// Find Minimum in Rotated Sorted Array

#include <vector>

class Solution {
public:
  int findMin(std::vector<int>& nums) {
    int low = 0;
    int high = nums.size() - 1;

    while(low < high) {
      int mid = (high + low)/2;

      const int low_num = nums[low];
      const int high_num = nums[high];

      const int mid_num = nums[mid];

      if(mid_num > high_num) low = mid + 1;
      else high = mid;
    }

    return nums[low];
  }
};