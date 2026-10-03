// LeetCode: 215
// Kth Largest Element in an Array

#include <queue>
#include <vector>

class Solution {
public:
  int findKthLargest(std::vector<int>& nums, int k) {
    std::priority_queue<int, std::vector<int>, std::less<int>> max_heap;

    for(const auto& num : nums) max_heap.push(num);

    while(k > 1) {
      max_heap.pop();
      --k;
    }

    return max_heap.top();
  }
};