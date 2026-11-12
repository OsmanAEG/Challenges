// LeetCode: 40
// Combination Sum II

#include <algorithm>
#include <set>
#include <vector>

class Solution {
public:
  std::vector<std::vector<int>> valid_combos;
  std::set<std::vector<int>> valid_combos_set;

  int total;

  void find_combinations(std::vector<int>& candidates, std::vector<int> combo, int idx, int sum) {
    if(sum == total) {
      std::sort(combo.begin(), combo.end());

      if(valid_combos_set.find(combo) == valid_combos_set.end()) {
        valid_combos.push_back(combo);
        valid_combos_set.insert(combo);
      }

      return;
    }

    if(idx >= candidates.size() || sum > total) return;

    for(int i = idx + 1; i < candidates.size(); ++i) {
      if(i > idx + 1 && candidates[i] == candidates[i - 1]) continue;
      if(sum + candidates[i] > total) break;

      auto combo_i = combo;
      combo_i.push_back(candidates[i]);
      find_combinations(candidates, combo_i, i, sum + candidates[i]);
    }
  }

  std::vector<std::vector<int>> combinationSum2(std::vector<int>& candidates, int target) {
    total = target;

    std::sort(candidates.begin(), candidates.end());

    for(int i = 0; i < candidates.size(); ++i) {
      if(i > 0 && candidates[i] == candidates[i - 1]) continue;
      if(candidates[i] > total) break;

      std::vector<int> combo_i = {candidates[i]};
      find_combinations(candidates, combo_i, i, candidates[i]);
    }

    return valid_combos;
  }
};
