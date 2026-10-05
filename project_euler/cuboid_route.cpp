// Project Euler: 86
// Cuboid Route

#include "helper.h"

using Int_T = long long;

int main() {
  const Int_T N = 1000000;

  Int_T M = 0;
  Int_T count = 0;

  for(Int_T c = 1; count <= N; ++c) {
    for(Int_T s = 2; s <= 2*c; ++s) {
      const Int_T square = c*c + s*s;

      const Int_T root = sqrt(square);

      if(root*root == square) {
        const Int_T one = 1;
        const auto a_min = std::max(one, s-c);
        const auto a_max = s/2;

        count += a_max - a_min + one;
      }
    }

    if(count > N) M = c;
  }

  std::cout << M << std::endl;

  return 0;
}