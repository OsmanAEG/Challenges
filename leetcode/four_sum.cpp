// LeetCode: 18
// Four Sum

#include <algorithm>
#include <set>
#include <vector>

class Solution {
public:
  std::vector<std::vector<int>> fourSum(std::vector<int>& nums, int target) {
    std::set<std::vector<int>> result_set;
    std::vector<std::vector<int>> result;

    if(nums.size() < 4) return result;

    std::sort(nums.begin(), nums.end());

    for(int i = 1; i < nums.size() - 2; ++i) {
      for(int j = i + 1; j < nums.size() - 1; ++j) {
        int low = 0;
        int high = nums.size() - 1;

        while(low < i && j < high) {
          const long long sum =
            static_cast<long long>(nums[low])
            + static_cast<long long>(nums[i])
            + static_cast<long long>(nums[j])
            + static_cast<long long>(nums[high]);

          if(sum > static_cast<long long>(target)) {
            --high;
          } else if (sum < static_cast<long long>(target)) {
            ++low;
          } else {
            result_set.insert({nums[low], nums[i], nums[j], nums[high]});
            ++low;
            --high;
          }
        }
      }
    }

    for(const auto& quad : result_set) result.push_back(quad);

    return result;
  }
};