// LeetCode: 90
// Subsets II

#include <algorithm>
#include <set>
#include <vector>

class Solution {
public:
  std::set<std::vector<int>> results_set;

  void find_all_subsets(std::vector<std::vector<int>>& results, std::vector<int>& nums, std::vector<int> result, int idx) {
    if(results_set.find(result) == results_set.end()) {
      results.push_back(result);
      results_set.insert(result);
    }

    for(int i = idx; i < nums.size(); ++i) {
      auto result_i = result;
      result_i.push_back(nums[i]);

      find_all_subsets(results, nums, result_i, i + 1);
    }
  }

  std::vector<std::vector<int>> subsetsWithDup(std::vector<int>& nums) {
    std::vector<std::vector<int>> results;
    std::sort(nums.begin(), nums.end());

    find_all_subsets(results, nums, {}, 0);

    return results;
  }
};