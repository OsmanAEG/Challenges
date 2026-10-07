// LeetCode: 46
// Permutations

#include <vector>

class Solution {
public:
  std::vector<std::vector<int>> permutations;

  void find_permutations(std::vector<int> nums, std::vector<int> permute, int idx) {
    permute.push_back(nums[idx]);
    nums.erase(nums.begin() + idx);

    if(nums.size() == 0) {
      permutations.push_back(permute);
      return;
    }

    for(int i = 0; i < nums.size(); ++i) {
      find_permutations(nums, permute, i);
    }
  }

  std::vector<std::vector<int>> permute(std::vector<int>& nums) {
    for(int i = 0; i < nums.size(); ++i) {
      find_permutations(nums, {}, i);
    }

    return permutations;
  }
};