// LeetCode: 228
// Summary Ranges

#include <string>
#include <vector>

class Solution {
public:
  std::vector<std::string> summaryRanges(std::vector<int>& nums) {
    if(nums.size() == 0) return {};
    if(nums.size() == 1) return {std::to_string(nums[0])};

    std::vector<std::string> ranges;

    int low  = 0;
    int high = 0;

    while(high + 1 < nums.size()) {
      if(nums[high+1] == nums[high] + 1) {
        ++high;
      } else if(low == high) {
        ranges.push_back(std::to_string(nums[high]));
        low = high+1;
        high = low;
      } else {
        ranges.push_back(std::to_string(nums[low]) + "->" + std::to_string(nums[high]));
        low = high+1;
        high = low;
      }
    }

    if(low == high) ranges.push_back(std::to_string(nums[high]));
    else ranges.push_back(std::to_string(nums[low]) + "->" + std::to_string(nums[high]));

    return ranges;
  }
};