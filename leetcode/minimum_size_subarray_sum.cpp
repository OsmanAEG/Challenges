// LeetCode: 209
// Minimum Size Subarray Sum

#include <algorithm>
#include <climits>
#include <vector>

class Solution {
public:
  int minSubArrayLen(int target, std::vector<int>& nums) {
    int low = 0;
    int high = 0;

    int sum = 0;
    int min_length = INT_MAX;

    while(high < nums.size()) {
      sum += nums[high];

      while(sum >= target) {
        min_length = std::min(min_length, high - low + 1);

        sum -= nums[low];
        ++low;
      }

      ++high;
    }

    return min_length == INT_MAX ? 0 : min_length;
  }
};