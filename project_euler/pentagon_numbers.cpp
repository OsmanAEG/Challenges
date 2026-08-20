// Project Euler: 44
// Pentagon Numbers

#include "helper.h"

using Int_T = unsigned long long;

int main() {
  Int_T n_max = 5000;

  Int_T min_diff = INT_MAX;

  for(Int_T j = 1; j < n_max; ++j) {
    for(Int_T k = j + 1; k < n_max; ++k) {
      const auto P_j = get_pentagon_number(j);
      const auto P_k = get_pentagon_number(k);

      const auto sum  = P_k + P_j;
      const auto diff = P_k - P_j;

      if(is_pentagon_number(sum) && is_pentagon_number(diff)) {
        min_diff = std::min(min_diff, diff);
      }
    }
  }

  std::cout << min_diff << std::endl;

  return 0;
}