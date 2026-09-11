// LeetCode: 33
// Search in Rotated Sorted Array

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

    return low;
  }

  int search(std::vector<int>& nums, int target) {
    int abs_min = findMin(nums);
    int tmp_max = nums.size() - 1;

    int tmp_min = 0;
    int abs_max = abs_min - 1;

    int low;
    int high;

    if(abs_min == 0) {
      low = 0;
      high = tmp_max;
    } else {
      if(target >= nums[abs_min] && target <= nums[tmp_max]) {
        low = abs_min;
        high = tmp_max;
      } else {
        low = tmp_min;
        high = abs_max;
      }
    }

    while(low <= high) {
      const auto mid = (low + high)/2;

      if(target > nums[mid]) {
        low = mid + 1;
      } else if(target < nums[mid]) {
        high = mid - 1;
      } else {
        return mid;
      }
    }

    return -1;
  }
};