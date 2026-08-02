// LeetCode: 75
// Sort Colors

#include <vector>

class Solution {
public:
  void sortColors(std::vector<int>& nums) {
    std::vector<int> counter = {0, 0, 0};

    for(const auto& num : nums) ++counter[num];

    int idx = 0;

    for(int c = 0; c < 3; ++c) {
      for(int i = 0; i < counter[c]; ++i) {
        nums[idx] = c;
        ++idx;
      }
    }
  }
};