// Project Euler: 75

// Singular Integer Right Triangles

#include "helper.h"

#include <iostream>
#include <numeric>
#include <unordered_map>

using Int_T = unsigned long long;

int main() {
  const Int_T N = 1500000;
  Int_T result = 0;

  std::unordered_map<Int_T, unsigned int> my_map;

  for(Int_T m = 2; 2 * m * (m + 1) <= N; ++m) {
    for(Int_T n = 1; n < m; ++n) {
      if(std::gcd(m, n) != 1) continue;
      if((m - n) % 2 == 0) continue;

      const Int_T p = 2 * m * (m + n);

      for(Int_T l = p; l <= N; l += p) {
        ++my_map[l];
      }
    }
  }

  for(auto it = my_map.begin(); it != my_map.end(); ++it) {
    if(it->second == 1) ++result;
  }

  std::cout << result << '\n';

  return 0;
}