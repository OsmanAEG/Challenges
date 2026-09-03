// LeetCode: 35
// Search Insert Position

#include <vector>

class Solution {
public:
  int searchInsert(std::vector<int>& nums, int target) {
    int low = 0;
    int high = nums.size() - 1;

    while(low <= high) {
      const auto mid = (low + high)/2;

      if(nums[mid] > target) {
        high = mid - 1;
      } else if(nums[mid] < target) {
        low = mid + 1;
      } else {
        return mid;
      }
    }

    return low;
  }
};
