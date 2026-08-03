// LeetCode: 274
// H-Index

#include <algorithm>
#include <vector>

class Solution {
public:
  int hIndex(std::vector<int>& citations) {
    const auto num_papers = citations.size();
    std::sort(citations.rbegin(), citations.rend());

    for(int i = 0; i < num_papers; ++i) {
      if(i + 1 > citations[i]) return i;
    }

    return citations.size();
  }
};