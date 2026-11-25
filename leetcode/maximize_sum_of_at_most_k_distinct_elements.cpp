// LeetCode: 3684
// Maximize Sum of At Most K Distinct Elements

#include <set>
#include <vector>

class Solution {
public:
  std::vector<int> maxKDistinct(std::vector<int>& nums, int k) {
    std::vector<int> k_distinct_nums;
    std::set<int> distinct_nums;

    for(const auto& num : nums) distinct_nums.insert(num);

    int c = 0;

    for(auto it = distinct_nums.rbegin(); it != distinct_nums.rend(); ++it) {
      k_distinct_nums.push_back(*it);
      ++c;

      if(c >= k) break;
    }

    return k_distinct_nums;
  }
};