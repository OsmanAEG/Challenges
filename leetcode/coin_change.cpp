// LeetCode: 322
// Coin Change

#include <vector>

class Solution {
public:
  int coinChange(std::vector<int>& coins, int amount) {
    std::vector<int> combos(amount + 1, amount + 1);

    combos[0] = 0;

    for(int i = 1; i <= amount; ++i) {
      for(const auto& coin : coins) {
        if(coin > i) continue;

        combos[i] = std::min(combos[i], combos[i-coin] + 1);
      }
    }

    if(combos[amount] == amount + 1) return -1;

    return combos[amount];
  }
};