// LeetCode: 84
// Largest Rectangle in Histogram

#include <algorithm>
#include <stack>
#include <vector>

class Solution {
public:
  int largestRectangleArea(std::vector<int>& heights) {
    int max_area = 0;
    int n = heights.size();

    std::stack<std::pair<int, int>> running_areas;

    for(int i = 0; i < heights.size(); ++i) {
      int idx_start = i;

      while(!running_areas.empty() && running_areas.top().second > heights[i]) {
        const auto idx    = running_areas.top().first;
        const auto height = running_areas.top().second;

        running_areas.pop();

        const auto area = height*(i-idx);

        max_area = std::max(max_area, area);

        idx_start = idx;
      }

      running_areas.push({idx_start, heights[i]});
    }

    while(!running_areas.empty()) {
      const auto idx    = running_areas.top().first;
      const auto height = running_areas.top().second;

      running_areas.pop();

      const auto area = height*(n-idx);
      max_area = std::max(max_area, area);
    }

    return max_area;
  }
};