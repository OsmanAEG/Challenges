// LeetCode: 643
// Maximum Average Subarray I

#include <algorithm>
#include <vector>

class Solution {
public:
  double findMaxAverage(std::vector<int>& nums, int k) {
    int sum = 0;

    for(int i = 0; i < k; ++i) sum += nums[i];

    int max_sum = sum;

    int low = 0;
    int high = k - 1;

    while(high < nums.size() - 1) {
      sum = sum - nums[low];
      ++low;

      ++high;
      sum = sum + nums[high];

      max_sum = std::max(max_sum, sum);
    }

    return static_cast<double>(max_sum)/k;
  }
};