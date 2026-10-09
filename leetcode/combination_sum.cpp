// LeetCode: 39
// Combination Sum

#include <vector>

class Solution {
public:
  std::vector<std::vector<int>> results;

  void find_combinations(std::vector<int>& candidates, std::vector<int> result, int target, int sum, int start) {
    if(sum == target) {
      results.push_back(result);
      return;
    } else if(sum > target) {
      return;
    } else {
      for(int i = start; i < candidates.size(); ++i) {
        auto result_i = result;
        auto sum_i = sum;

        result_i.push_back(candidates[i]);
        sum_i += candidates[i];

        find_combinations(candidates, result_i, target, sum_i, i);
      }
    }
  }

  std::vector<std::vector<int>> combinationSum(std::vector<int>& candidates, int target) {
    find_combinations(candidates, {}, target, 0, 0);
    return results;
  }
};