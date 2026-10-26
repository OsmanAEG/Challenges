// LeetCode: 239
// Sliding Window Maximum

#include <deque>
#include <vector>

class Solution {
public:
  std::vector<int> maxSlidingWindow(std::vector<int>& nums, int k) {
    const int n = nums.size();

    std::vector<int> max_vals;
    std::deque<int> max_vals_idx;

    for(int i = 0; i < n; ++i) {
      while(!max_vals_idx.empty() && max_vals_idx.front() <= i - k) {
        max_vals_idx.pop_front();
      }

      while(!max_vals_idx.empty() && nums[max_vals_idx.back()] <= nums[i]) {
        max_vals_idx.pop_back();
      }

      max_vals_idx.push_back(i);

      if(i >= k - 1) {
        max_vals.push_back(nums[max_vals_idx.front()]);
      }
    }

    return max_vals;
  }
};