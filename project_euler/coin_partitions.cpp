// Project Euler: 78
// Coin Partitions

#include "helper.h"

using Int_T = unsigned long long;

std::vector<Int_T> num_combinations(Int_T n, Int_T N) {
  std::vector<Int_T> ways(n + 1, 0);
  ways[0] = 1;

  for(Int_T size = 1; size <= n; ++size) {
    for(Int_T total = size; total <= n; ++total) {
      ways[total] += ways[total - size];

      if(ways[total] >= N) ways[total] -= N;
    }
  }

  return ways;
}

int main() {
  const Int_T N = 1000000;

  Int_T limit = 1000;
  Int_T n = 1;

  bool found = false;

  while(!found) {
    const auto ways = num_combinations(limit, N);

    for(n = 1; n <= limit; ++n) {
      if(ways[n] == 0) {
        found = true;
        break;
      }
    }

    if(!found) limit *= 2;
  }

  std::cout << n << std::endl;

  return 0;
}