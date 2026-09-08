// LeetCode: 888
// Fair Candy Swap

#include <algorithm>
#include <vector>
#include <unordered_set>

class Solution {
public:
  std::vector<int> fairCandySwap(std::vector<int>& aliceSizes, std::vector<int>& bobSizes) {
    int sum_alice = 0;
    int sum_bob = 0;

    for(const auto& c : aliceSizes) sum_alice += c;
    for(const auto& c : bobSizes)   sum_bob += c;

    const auto diff = (sum_alice - sum_bob)/2;

    std::unordered_set<int> bob_set;

    for(int i = 0; i < bobSizes.size(); ++i) bob_set.insert(bobSizes[i]);

    for(int i = 0; i < aliceSizes.size(); ++i) {
      if(bob_set.find(aliceSizes[i] - diff) != bob_set.end()) {
        return {aliceSizes[i], aliceSizes[i] - diff};
      }
    }

    return {0, 0};
  }
};