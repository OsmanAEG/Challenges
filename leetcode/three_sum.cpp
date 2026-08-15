// LeetCode: 15
// Three Sum

#include <algorithm>
#include <set>
#include <vector>

class Solution {
public:
  std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
    std::set<std::vector<int>> result_set;
    std::vector<std::vector<int>> result;

    std::sort(nums.begin(), nums.end());

    for(int i = 1; i < nums.size() - 1; ++i) {
      int low = 0;
      int high = nums.size() - 1;

      while(low < i && i < high) {
        const auto sum = nums[low] + nums[i] + nums[high];

        if(sum > 0) {
          --high;
        } else if(sum < 0) {
          ++low;
        } else {
          result_set.insert({nums[low], nums[i], nums[high]});
          ++low;
          --high;
        }
      }
    }

    for(const auto& trio : result_set) result.push_back(trio);

    return result;
  }
};