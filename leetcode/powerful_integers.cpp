// LeetCode: 970
// Powerful Integers

#include <set>
#include <vector>

class Solution {
public:
  std::vector<int> powerfulIntegers(int x, int y, int bound) {
    std::set<int> result;
    std::vector<int> x_ns;
    std::vector<int> y_ns;

    for(long long x_n = 1; x_n <= bound - 1; x_n *= x) {
      x_ns.push_back(x_n);
      if(x == 1) break;
    }

    for(long long y_n = 1; y_n <= bound - 1; y_n *= y) {
      y_ns.push_back(y_n);
      if(y == 1) break;
    }

    for(const auto& x_i : x_ns) {
      for(const auto& y_i : y_ns) {
        if(x_i + y_i <= bound) result.insert(x_i + y_i);
        else break;
      }
    }

    return std::vector<int>(result.begin(), result.end());
  }
};