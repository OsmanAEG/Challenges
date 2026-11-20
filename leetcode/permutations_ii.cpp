// LeetCode: 47
// Permutations II

#include <set>
#include <vector>

class Solution {
public:
  std::set<std::vector<int>> permutations_set;

  void find_permutations(std::vector<int> nums, std::vector<int> permute, int idx) {
    permute.push_back(nums[idx]);
    nums.erase(nums.begin() + idx);

    if(nums.size() == 0) {
      permutations_set.insert(permute);
      return;
    }

    for(int i = 0; i < nums.size(); ++i) {
      find_permutations(nums, permute, i);
    }
  }

  std::vector<std::vector<int>> permuteUnique(std::vector<int>& nums) {
    std::vector<std::vector<int>> permutations;

    for(int i = 0; i < nums.size(); ++i) {
      find_permutations(nums, {}, i);
    }

    for(const auto& permute : permutations_set) {
      permutations.push_back(permute);
    }

    return permutations;
  }
};