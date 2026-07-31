// Project Euler: 26
// Reciprical Cycles

#include <algorithm>
#include <iostream>
#include <set>
#include <unordered_map>
#include <vector>

using Scalar_T = double;
using String_T = std::string;

int main() {
  const int n = 1000;

  std::vector<int> max_repetitions;

  for(int d = 2; d < n; ++d) {
    int remainder = 1%d;
    std::unordered_map<int, int> remainders;

    int idx = 0;

    while(remainder != 0 && remainders.find(remainder) == remainders.end()) {
      remainders[remainder] = idx;

      remainder *= 10;
      remainder = remainder % d;

      ++idx;
    }

    if(remainder == 0) max_repetitions.push_back(0);
    else max_repetitions.push_back(idx - remainders[remainder]);
  }

  const auto max_val = *std::max_element(max_repetitions.begin(), max_repetitions.end());

  int idx = 2;

  for(const auto& repetition : max_repetitions) {
    if(repetition == max_val) {
      std::cout << idx << std::endl;
      break;
    }

    ++idx;
  }

  return 0;
}