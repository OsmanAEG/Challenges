// LeetCode: 3942
// Minimum Operations to Sort a Permutation

#include <algorithm>
#include <climits>
#include <map>
#include <vector>

class Solution {
public:
  int min = INT_MAX;
  std::map<std::vector<int>, int> visited;

  bool is_sorted(std::vector<int> nums) {
    for(int i = 1; i < nums.size(); ++i) {
      if(nums[i] < nums[i-1]) return false;
    }

    return true;
  }

  std::vector<int> reverse(std::vector<int> nums) {
    std::reverse(nums.begin(), nums.end());
    return nums;
  }

  std::vector<int> shift(std::vector<int> nums, int steps) {
    std::rotate(nums.begin(), nums.begin() + steps, nums.end());
    return nums;
  }

  void op_sort(const std::vector<int>& nums, int count, bool reversed) {
    const int n = nums.size();

    const int zero = std::find(nums.begin(), nums.end(), 0) - nums.begin();
    if(is_sorted(shift(nums, zero))) min = std::min(min, count + zero);

    const int largest = std::find(nums.begin(), nums.end(), n - 1) - nums.begin();
    if(is_sorted(reverse(shift(nums, largest)))) min = std::min(min, count + largest + 1);

    if(!reversed) op_sort(reverse(nums), count + 1, true);
  }

  int minOperations(std::vector<int>& nums) {
    min = INT_MAX;
    op_sort(nums, 0, false);
    return min == INT_MAX ? -1 : min;
  }
};