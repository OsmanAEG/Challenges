// LeetCode: 56
// Merge Intervals

#include <algorithm>
#include <vector>

using Vector_T  = std::vector<int>;
using Vectors_T = std::vector<std::vector<int>>;

class Solution {
public:
  Vectors_T merge(Vectors_T& intervals) {
    std::sort(intervals.begin(), intervals.end(),
      [](const Vector_T& vec1, const Vector_T& vec2) { return vec1[0] < vec2[0]; });

    int low  = 0;
    int high = low + 1;

    while(high < intervals.size()) {
      if(intervals[low][1] >= intervals[high][0]) {
        intervals[low][1] = std::max(intervals[high][1], intervals[low][1]);

        intervals.erase(intervals.begin() + high);
      } else {
        ++low;
        ++high;
      }
    }

    return intervals;
  }
};