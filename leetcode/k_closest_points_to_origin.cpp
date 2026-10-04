// LeetCode: 973
// K Closest Points to Origin

#include <cmath>
#include <queue>
#include <vector>


struct Origin_Point {
  double dist;
  int x;
  int y;

  Origin_Point(const std::vector<int>& point) {
    x = point[0];
    y = point[1];

    dist = std::sqrt(x*x + y*y);
  }

  auto operator<=>(const Origin_Point&) const = default;
};

class Solution {
public:
  std::vector<std::vector<int>> kClosest(std::vector<std::vector<int>>& points, int k) {
    std::vector<std::vector<int>> result;

    std::priority_queue<Origin_Point, std::vector<Origin_Point>, std::greater<Origin_Point>> min_heap;

    for(const auto& point : points) {
      const auto origin_point = Origin_Point(point);
      min_heap.push(origin_point);
    }

    while(k > 0) {
      const auto origin_point = min_heap.top();
      min_heap.pop();
      result.push_back({origin_point.x, origin_point.y});
      --k;
    }

    return result;
  }
};