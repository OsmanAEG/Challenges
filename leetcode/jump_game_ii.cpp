// LeetCode: 45
// Jump Game II

#include <algorithm>
#include <climits>
#include <vector>

class Solution {
public:
  std::vector<int> visited;

  int find_min_jump(const std::vector<int>& nums, int idx) {
    if(idx >= nums.size() - 1) return 0;

    if(visited[idx] != -1) return visited[idx];

    int min_jump = INT_MAX;

    for(int i = nums[idx]; i >= 1; --i) {
      if(i + idx < nums.size()) {
        const int jumps = find_min_jump(nums, i + idx);

        if(jumps != INT_MAX) min_jump = std::min(min_jump, jumps + 1);
      }
    }

    visited[idx] = min_jump;
    return min_jump;
  }

  int jump(std::vector<int>& nums) {
    visited.assign(nums.size(), -1);

    return find_min_jump(nums, 0);
  }
};