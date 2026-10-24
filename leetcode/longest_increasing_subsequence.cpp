// LeetCode: 300
// Longest Increasing Subsequence

#include <algorithm>
#include <vector>

class Solution {
public:
  int lengthOfLIS(std::vector<int>& nums) {
    if(nums.empty()) return 0;

    int max_len = 1;

    std::vector<int> max_lens(nums.size(), 1);

    for(int i = 1; i < nums.size(); ++i) {
      for(int j = 0; j < i; ++j) {
        if(nums[i] > nums[j]) {
          max_lens[i] = std::max(max_lens[i], max_lens[j] + 1);
        }
      }

      max_len = std::max(max_len, max_lens[i]);
    }

    return max_len;
  }
};