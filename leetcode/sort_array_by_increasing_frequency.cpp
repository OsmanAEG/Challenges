// LeetCode: 1636
// Sort Array By Increasing Frequency

#include <algorithm>
#include <map>
#include <unordered_map>
#include <vector>

class Solution {
public:
  std::vector<int> frequencySort(std::vector<int>& nums) {
    std::unordered_map<int, int> num_frequencies;
    std::map<int, std::vector<int>> frequency_nums;

    std::vector<int> result(nums.size(), 0);

    for(const auto& num : nums) {
      ++num_frequencies[num];
    }

    for(auto it = num_frequencies.begin(); it != num_frequencies.end(); ++it) {
      frequency_nums[it->second].push_back(it->first);
    }

    int idx = 0;

    for(auto it = frequency_nums.begin(); it != frequency_nums.end(); ++it) {
      std::sort(it->second.rbegin(), it->second.rend());

      for(const auto& num : it->second) {
        for(int i = 0; i < it->first; ++i) {
          result[idx] = num;
          ++idx;
        }
      }
    }

    return result;
  }
};