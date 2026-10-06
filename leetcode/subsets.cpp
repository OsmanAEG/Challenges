// LeetCode: 78
// Subsets

#include <algorithm>
#include <vector>

class Solution {
public:
  void find_all_subsets(std::vector<std::vector<int>>& results, std::vector<int>& nums, std::vector<int> result, int idx) {
    results.push_back(result);

    for(int i = idx; i < nums.size(); ++i) {
      auto result_i = result;
      result_i.push_back(nums[i]);

      find_all_subsets(results, nums, result_i, i + 1);
    }
  }

  std::vector<std::vector<int>> subsets(std::vector<int>& nums) {
    std::vector<std::vector<int>> results;
    std::sort(nums.begin(), nums.end());

    find_all_subsets(results, nums, {}, 0);

    return results;
  }
};