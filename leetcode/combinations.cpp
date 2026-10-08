// LeetCode: 77
// Combinations

#include <vector>

class Solution {
public:
  std::vector<std::vector<int>> results;

  void find_combinations(int n, int k, int start, std::vector<int> result) {
    if(result.size() == k) {
      results.push_back(result);
      return;
    }

    for(int i = start; i <= n; ++i) {
      result.push_back(i);
      find_combinations(n, k, i + 1, result);
      result.pop_back();
    }
  }

  std::vector<std::vector<int>> combine(int n, int k) {
    find_combinations(n, k, 1, {});
    return results;
  }
};