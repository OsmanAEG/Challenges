// Project Euler: 69
// Totient Maximum

#include "helper.h"

using Int_T = unsigned long long;
using Scalar_T = double;

int main() {
  const Int_T N = 1000000;

  double max = 0.0;
  Int_T max_n = 0;

  for(Int_T n = 2; n <= N; ++n) {
    const Int_T phi_n = totient(n);

    const auto tmp_max = static_cast<Scalar_T>(n)/static_cast<Scalar_T>(phi_n);

    if(tmp_max > max) {
      max_n = n;
      max = tmp_max;
    }
  }

  std::cout << max_n << std::endl;

  return 0;
}