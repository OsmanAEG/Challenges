// LeetCode: 88
// Merge Sorted Array

#include <queue>
#include <vector>

class Solution {
public:
  void merge(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n) {
    std::queue<int> placeholders;

    int idx = 0;

    int idx_1 = 0;
    int idx_2 = 0;

    while(idx < m + n) {
      ++idx;

      if(nums1[idx_1] <= nums2[idx_2]) {
        placeholders.push(nums1[idx_1]);
        ++idx_1;
      } else {
        
      }
    }
  }
};