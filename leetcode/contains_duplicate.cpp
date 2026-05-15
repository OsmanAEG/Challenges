// LeetCode: 217
// Contains Duplicate

#include <unordered_set>
#include <vector>

class Solution {
public:
  bool containsDuplicate(std::vector<int>& nums) {
    std::unordered_set<int> my_set;

    for(const auto& num : nums) {
      if(my_set.find(num) != my_set.end()) return true;
      my_set.insert(num);
    }

    return false;
  }
};