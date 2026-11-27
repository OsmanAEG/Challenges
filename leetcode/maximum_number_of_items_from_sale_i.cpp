// LeetCode: 3946
// Maximum Number of Items from Sale I

#include <algorithm>
#include <vector>

class Solution {
public:
  int maximumSaleItems(std::vector<std::vector<int>>& items, int budget) {
    const int n = items.size();
    std::vector<int> dp(budget + 1, 0);

    for(int i = 0; i < n; ++i) {
      const int factor = items[i][0];
      const int price  = items[i][1];

      int free_copies = 0;

      for(int j = 0; j < n; ++j) {
        if(j != i && items[j][0] % factor == 0) ++free_copies;
      }

      for(int b = budget; b >= price; --b) {
        int copies = dp[b - price] + 1 + free_copies;
        dp[b] = std::max(dp[b], copies);
      }

      for(int b = price; b <= budget; ++b) {
        int copies = dp[b - price] + 1;
        dp[b] = std::max(dp[b], copies);
      }
    }

    return dp[budget];
  }
};