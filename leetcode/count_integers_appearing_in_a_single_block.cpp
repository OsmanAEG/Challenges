// LeetCode: 4038
// Count Integers Appearing in a Single Block

#include <set>
#include <vector>

class Solution {
public:
  int countSpecialIntegers(std::vector<int>& nums) {
    if(nums.size() == 0) return 0;

    std::set<int> appeared;
    std::set<int> multiple_blocks;

    auto prev = nums[0];
    appeared.insert(prev);

    for(int i = 1; i < nums.size(); ++i) {
      if(nums[i] == prev) continue;

      prev = nums[i];

      if(appeared.find(nums[i]) == appeared.end()) {
        appeared.insert(nums[i]);
      } else {
        multiple_blocks.insert(prev);
      }
    }

    return appeared.size() - multiple_blocks.size();
  }
};