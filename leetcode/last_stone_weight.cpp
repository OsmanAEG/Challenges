// LeetCode: 1046
// Last Stone Weight

#include <queue>
#include <vector>

class Solution {
public:
  int lastStoneWeight(std::vector<int>& stones) {
    std::priority_queue<int, std::vector<int>, std::less<int>> min_heap;

    for(const auto& s : stones) min_heap.push(s);

    while(min_heap.size() > 1) {
      const auto one = min_heap.top();
      min_heap.pop();

      const auto two = min_heap.top();
      min_heap.pop();

      if(one != two) min_heap.push(one - two);
    }

    if(!min_heap.empty()) return min_heap.top();

    return 0;
  }
};