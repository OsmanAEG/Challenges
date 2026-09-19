// Project Euler: 70
// Totient Permutation

#include "helper.h"

using Int_T = unsigned long long;
using Scalar_T = double;

int main() {
  const Int_T N = 10000000;

  Int_T min_n = INT_MAX;
  Scalar_T min_ratio = std::numeric_limits<Scalar_T>::max();

  for(Int_T n = 2; n < N; ++n) {
    const auto phi = totient(n);

    auto n_str = std::to_string(n);
    auto phi_str = std::to_string(phi);

    std::sort(n_str.begin(), n_str.end());
    std::sort(phi_str.begin(), phi_str.end());

    if(n_str == phi_str) {
      const Scalar_T ratio = static_cast<Scalar_T>(n)/static_cast<Scalar_T>(phi);

      if(ratio < min_ratio) {
        min_ratio = ratio;
        min_n = n;
      }
    }
  }

  std::cout << min_n << std::endl;

  return 0;
}
