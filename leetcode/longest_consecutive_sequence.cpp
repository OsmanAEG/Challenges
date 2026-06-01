// LeetCode: 128
// Longest Consecutive Sequence

#include<algorithm>
#include<set>
#include<vector>

class Solution {
public:
  int longestConsecutive(std::vector<int>& nums) {
    if(nums.size() == 0) return 0;

    std::set<int> nums_set;
    for(const auto& num : nums) nums_set.insert(num);

    int last_num = *nums_set.begin();
    int longest = 1;
    int curr = 1;

    for(const auto& num : nums_set) {
      if(num - last_num == 1) {
        ++curr;
        longest = std::max(longest, curr);
      } else {
        curr = 1;
      }

      last_num = num;
    }

    return longest;
  }
};