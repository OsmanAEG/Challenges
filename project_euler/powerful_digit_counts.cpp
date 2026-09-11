// Project Euler: 63
// Powerful Digit Counts

#include "helper.h"

using Int_T = boost::multiprecision::cpp_int;

int main() {
  const Int_T base_max = 9;
  const Int_T power_max = 22;

  Int_T result = 0;

  for(Int_T a = 1; a <= base_max; ++a) {
    for(std::size_t b = 1; b <= power_max; ++b) {
      const Int_T power = boost::multiprecision::pow(a, b);

      const auto power_str = power.str();

      if(power_str.size() == b) ++result;
    }
  }

  std::cout << result << std::endl;

  return 0;
}