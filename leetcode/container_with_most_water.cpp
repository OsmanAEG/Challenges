// LeetCode: 11
// Container With Most Water

#include <algorithm>
#include <vector>

class Solution {
public:
  int maxArea(std::vector<int>& height) {
    int max_area = 0;

    int low = 0;
    int high = height.size() - 1;

    while(low < high) {
      const auto area = std::min(height[low], height[high])*(high - low);
      max_area = std::max(area, max_area);

      if(height[high] >= height[low]) ++low;
      else --high;
    }

    return max_area;
  }
};