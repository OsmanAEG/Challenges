// LeetCode: 252
// Meeting Rooms

#include <algorithm>
#include <vector>

// Definition of Interval:
class Interval {
public:
  int start;
  int end;

  Interval(int start, int end) {
    this->start = start;
    this->end = end;
  }

  auto operator<=>(const Interval&) const = default;
};

class Solution {
public:
  bool is_overlapping(Interval a, Interval b) {
    if(a.end > b.start) return true;
    return false;
  }

  bool canAttendMeetings(std::vector<Interval>& intervals) {
    std::sort(intervals.begin(), intervals.end(), [](const Interval& a, const Interval& b) {
      return a.start < b.start;
    });

    for(int i = 1; i < intervals.size(); ++i) {
      if(is_overlapping(intervals[i - 1], intervals[i])) return false;
    }

    return true;
  }
};