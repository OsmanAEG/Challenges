// LeetCode: 121
// Best Time to Buy and Sell Stock

#include<algorithm>
#include<climits>
#include<vector>

class Solution {
public:
  int maxProfit(std::vector<int>& prices) {
    int max = 0;
    int min_buy  = INT_MAX;

    for(int i = 0; i < prices.size(); ++i) {
      min_buy = std::min(prices[i], min_buy);
      max = std::max(prices[i] - min_buy, max);
    }

    return max;
  }
};