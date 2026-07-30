// LeetCode: 88
// Merge Sorted Array

#include <queue>
#include <vector>

class Solution {
public:
  void merge(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n) {
    std::priority_queue<int, std::vector<int>, std::greater<int>> placeholders;

    int idx = 0;

    int idx_1 = 0;
    int idx_2 = 0;

    while(idx < m + n) {
      if(idx_1 >= m) {
        placeholders.push(nums2[idx_2]);
        ++idx_2;
      } else if(idx_2 >= n) {
        placeholders.push(nums1[idx_1]);
        ++idx_1;
      } else if(nums1[idx_1] <= nums2[idx_2]) {
        placeholders.push(nums1[idx_1]);
        ++idx_1;
      } else {
        placeholders.push(nums2[idx_2]);
        ++idx_2;
      }

      ++idx;
    }

    for(int i = 0; i < m + n; ++i) {
      nums1[i] = placeholders.top();
      placeholders.pop();
    }
  }
};