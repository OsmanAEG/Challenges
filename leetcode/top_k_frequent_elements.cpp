// LeetCode: 347
// Top K Frequent Elements

#include <map>
#include <unordered_map>
#include <vector>

class Solution {
public:
  std::vector<int> topKFrequent(std::vector<int>& nums, int k) {
    std::unordered_map<int, int> freq_map;
    std::map<int, std::vector<int>> num_map;

    std::vector<int> result;

    for(const auto& num : nums) freq_map[num] += 1;

    for(auto it = freq_map.begin(); it != freq_map.end(); ++it) {
      num_map[it->second].push_back(it->first);
    }

    for(auto it = num_map.rbegin(); it != num_map.rend(); ++it) {
      if(k == 0) break;

      for(int i = 0; i < it->second.size(); ++i) {
        if(k == 0) break;
        result.push_back(it->second[i]);
        --k;
      }
    }

    return result;
  }
};