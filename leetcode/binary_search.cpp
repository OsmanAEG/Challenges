// LeetCode: 704
// Binary Search

#include <vector>

class Solution {
public:
  int search(std::vector<int>& nums, int target) {
    int low = 0;
    int high = nums.size() - 1;

    while(low <= high) {
      const auto mid = (low + high)/2;
      const auto num_mid = nums[mid];

      if(target < num_mid) {
        high = mid - 1;
      } else if(target > num_mid) {
        low = mid + 1;
      } else {
        return mid;
      }
    }

    return -1;
  }
};
