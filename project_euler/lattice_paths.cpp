// Project Euler: 15
// Lattice Paths

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using Int_T = unsigned long long;

int main() {
  const Int_T len = 20;
  const Int_T n   = len + 1;

  std::vector<std::vector<Int_T>> paths(n+1, std::vector<Int_T>(n+1, 1));

  for(Int_T i = 1; i < n; ++i) {
    for(Int_T j = 1; j < n; ++j) {
      paths[i][j] = paths[i-1][j] + paths[i][j-1];
    }
  }

  std::cout << paths[len][len] << std::endl;

  return 0;
}