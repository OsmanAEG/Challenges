// LeetCode: 746
// Min Cost Climving Stairs

#include <algorithm>
#include <vector>

class Solution {
public:
  int minCostClimbingStairs(std::vector<int>& cost) {
    int n = cost.size();
    if(n <= 1) return cost[0];

    std::vector<int> min_total_cost(n, 0);

    min_total_cost[0] = cost[0];
    min_total_cost[1] = cost[1];

    for(int i = 2; i < n; ++i) {
      min_total_cost[i] = std::min(min_total_cost[i-1], min_total_cost[i-2]) + cost[i];
    }

    return std::min(min_total_cost[n - 1], min_total_cost[n - 2]);
  }
};