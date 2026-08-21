// LeetCode: 739
// Daily Temperatures

#include <stack>
#include <vector>

class Solution {
public:
  std::vector<int> dailyTemperatures(std::vector<int>& temperatures) {
    std::stack<std::pair<int, int>> temp_idx;
    std::vector<int> days(temperatures.size(), 0);

    for(int i = 0; i < temperatures.size(); ++i) {
      while(!temp_idx.empty() && temp_idx.top().first < temperatures[i]) {
        days[temp_idx.top().second] = i - temp_idx.top().second;
        temp_idx.pop();
      }

      temp_idx.push({temperatures[i], i});
    }

    return days;
  }
};