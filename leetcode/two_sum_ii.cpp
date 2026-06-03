// LeetCode: 167
// Two Sum II

#include<vector>

class Solution {
public:
  std::vector<int> twoSum(std::vector<int>& numbers, int target) {
    int idx_min = 0;
    int idx_max = numbers.size() - 1;

    while(numbers[idx_min] + numbers[idx_max] != target) {
      if(numbers[idx_min] + numbers[idx_max] < target) ++idx_min;
      else --idx_max;
    }

    return {idx_min + 1, idx_max + 1};
  }
};