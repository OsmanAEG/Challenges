// LeetCode: 169
// Majority Element

#include <vector>
#include <unordered_map>

class Solution {
public:
  int majorityElement(std::vector<int>& nums) {
    std::unordered_map<int, int> map;

    for(const auto& num : nums) {
      ++map[num];

      if(map[num] > nums.size()/2) return num;
    }

    return 0;
  }
};