// LeetCode: 1584
// Min Cost to Connect All Points

#include <algorithm>
#include <cstdlib>
#include <vector>

class Solution {
public:
  template<typename Point_T>
  int connection_cost(const Point_T& a, const Point_T& b) {
    return std::abs(a[0] - b[0]) + std::abs(a[1] - b[1]);
  }

  int minCostConnectPoints(std::vector<std::vector<int>>& points) {
    int cost = 0;

    std::vector<std::vector<int>> unconnected;
    std::vector<std::vector<int>> connected;

    unconnected = points;

    connected.push_back(unconnected[0]);
    unconnected.erase(unconnected.begin());

    std::vector<int> min_cost(unconnected.size());

    for(int i = 0; i < unconnected.size(); ++i) {
      min_cost[i] = connection_cost(connected[0], unconnected[i]);
    }

    while(!unconnected.empty()) {
      int min_idx = 0;

      for(int i = 1; i < unconnected.size(); ++i) {
        if(min_cost[i] < min_cost[min_idx]) min_idx = i;
      }

      cost += min_cost[min_idx];

      auto new_point = unconnected[min_idx];

      connected.push_back(new_point);
      unconnected.erase(unconnected.begin() + min_idx);
      min_cost.erase(min_cost.begin() + min_idx);

      for(int i = 0; i < unconnected.size(); ++i) {
        min_cost[i] = std::min(min_cost[i], connection_cost(new_point, unconnected[i]));
      }
    }

    return cost;
  }
};