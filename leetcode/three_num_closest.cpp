// LeetCode: 16
// Three Sum Closest

#include <algorithm>
#include <climits>
#include <vector>

class Solution {
public:
  int threeSumClosest(std::vector<int>& nums, int target) {
    int diff = INT_MAX;
    int sum = 0;

    std::sort(nums.begin(), nums.end());

    for(int i = 1; i < nums.size(); ++i) {
      int low = 0;
      int high = nums.size() - 1;

      while(low < i && i < high) {
        const auto sum_i = nums[low] + nums[i] + nums[high];
        const auto diff_i = std::abs(target - sum_i);

        if(diff_i < diff) {
          diff = diff_i;
          sum = sum_i;
        }

        if(sum_i > target) --high;
        else ++low;
      }
    }

    return sum;
  }
};