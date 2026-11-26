// LeetCode 3718
// Smallest Missing Multiple of K

#include <unordered_set>
#include <vector>

class Solution {
public:
  int missingMultiple(std::vector<int>& nums, int k) {
    std::unordered_set<int> nums_set;

    for(const auto& num : nums) nums_set.insert(num);

    bool found = false;
    int multiple = 1;
    int k_multiple = k;

    while(!found) {
      if(nums_set.find(k_multiple) == nums_set.end()) {
        found = true;
        break;
      } else {
        ++multiple;
        k_multiple = k*multiple;
      }
    }

    return k_multiple;
  }
};