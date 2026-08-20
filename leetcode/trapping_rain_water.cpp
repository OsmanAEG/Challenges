// LeetCode: 42
// Trapping Rain Water

#include <algorithm>
#include <vector>

class Solution {
public:
  int trap(std::vector<int>& height) {
    int total = 0;

    int low = 0;
    int high = 1;

    while(high < height.size() && height[low] == 0) {
      ++low;
      ++high;
    }

    while(high < height.size()) {
      int right = high;

      while(high < height.size() && height[high] < height[low]) {
        if(height[high] > height[right]) right = high;

        ++high;
      }

      if(high < height.size()) right = high;

      int trapped = 0;
      const int water_level = std::min(height[low], height[right]);

      for(int i = low + 1; i < right; ++i) {
        trapped += water_level - height[i];
      }

      total += trapped;

      low = right;
      high = low + 1;
    }

    return total;
  }
};