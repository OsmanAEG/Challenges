// Project Euler: 56
// Powerful Digit Sum

#include "helper.h"

using Int_T = unsigned long long;

int main() {
  const Int_T a_max = 100;
  const Int_T b_max = 100;

  Int_T max_sum = 0;

  for(Int_T a = 1; a < a_max; ++a) {
    for(Int_T b = 1; b < b_max; ++b) {
      Int_T sum = 0;

      const auto result = power_str(a, b);

      for(const auto& c : result) sum += c - '0';

      max_sum = std::max(max_sum, sum);
    }
  }

  std::cout << max_sum << std::endl;

  return 0;
}