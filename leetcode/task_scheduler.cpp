// LeetCode: 621
// Task Scheduler

#include <unordered_map>
#include <queue>
#include <vector>

class Solution {
public:
  int leastInterval(std::vector<char>& tasks, int n) {
    std::unordered_map<char, int> task_freq;
    std::priority_queue<int> remaining;

    for(const auto& task : tasks) ++task_freq[task];
    for(const auto& [task, freq] : task_freq) remaining.push(freq);

    int intervals = 0;

    while(!remaining.empty()) {
      std::vector<int> pending;
      int used = 0;

      while(used < n + 1 && !remaining.empty()) {
        int freq = remaining.top();
        remaining.pop();
        ++used;

        --freq;
        if(freq > 0) pending.push_back(freq);
      }

      for(const auto& freq : pending) remaining.push(freq);

      if(remaining.empty()) intervals += used;
      else intervals += n + 1;
    }

    return intervals;
  }
};