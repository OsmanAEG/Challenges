// LeetCode: 435
// Non-Overlapping Intervals

#include <algorithm>
#include <vector>

class Solution {
public:
  bool is_overlapping(std::vector<int> a, std::vector<int> b) {
    if(a[1] > b[0]) return true;
    return false;
  }

  int eraseOverlapIntervals(std::vector<std::vector<int>>& intervals) {
    std::sort(intervals.begin(), intervals.end());

    int num_removed = 0;

    std::vector<int> last = intervals[0];

    for(int i = 1; i < intervals.size(); ++i) {
      if(is_overlapping(last, intervals[i])) {
        ++num_removed;

        if(intervals[i][1] < last[1]) {
          last =  intervals[i];
        }
      } else {
        last = intervals[i];
      }
    }

    return num_removed;
  }
};