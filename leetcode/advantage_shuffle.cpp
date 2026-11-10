// LeetCode: 870
// Advantage Shuffle

#include <algorithm>
#include <map>
#include <vector>

class Solution {
public:
  std::vector<int> advantageCount(std::vector<int>& nums1, std::vector<int>& nums2) {
    auto nums1_sorted = nums1;

    std::vector<int> result(nums1.size(), 0);

    std::sort(nums1_sorted.begin(), nums1_sorted.end());

    std::map<int, std::vector<int>> nums2_map;

    for(int i = 0; i < nums2.size(); ++i) {
      nums2_map[nums2[i]].push_back(i);
    }

    int idx_min = 0;
    int idx_max = nums1.size() - 1;

    for(auto it = nums2_map.rbegin(); it != nums2_map.rend(); ++it) {
      for(const auto& idx : it->second) {
        if(nums1_sorted[idx_max] > it->first) {
          result[idx] = nums1_sorted[idx_max];
          --idx_max;
        } else {
          result[idx] = nums1_sorted[idx_min];
          ++idx_min;
        }
      }
    }

    return result;
  }
};