// LeetCode: 875
// Koko Eating Bananas

#include <algorithm>
#include <vector>

class Solution {
public:
  long long hours_k(const std::vector<int>& piles, int h, int k) {
    long long hours = 0;

    for(const auto& pile : piles) {
      hours += (static_cast<long long>(pile) + k - 1) / k;
      if (hours > h) return hours;
    }

    return hours;
  }

  int minEatingSpeed(std::vector<int>& piles, int h) {
    std::sort(piles.begin(), piles.end());

    int k_min = 1;
    int k_max = piles[piles.size() - 1];

    while(k_min <= k_max) {
      int k_mid = k_min + (k_max - k_min)/2;

      if(hours_k(piles, h, k_mid) <= h) k_max = k_mid - 1;
      else k_min = k_mid + 1;
    }

    return k_min;
  }
};