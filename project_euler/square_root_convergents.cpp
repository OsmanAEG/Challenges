// Project Euler: 57
// Square Root Convergents

#include "helper.h"

using Int_T = boost::multiprecision::cpp_int;

std::pair<Int_T, Int_T> over_two_plus_over_two(Int_T N, Int_T num, Int_T den) {
  if(N == 1) return {num, den};

  const auto result = add_fraction(static_cast<Int_T>(2),
                                   static_cast<Int_T>(1),
                                   num,
                                   den);

  num = result.second;
  den = result.first;

  return over_two_plus_over_two(N - 1, num, den);
}

int main() {
  const Int_T N = 1000;
  Int_T sum = 0;

  for(Int_T n = 1; n <= N; ++n) {
    Int_T num_n = 1;
    Int_T den_n = 2;

    const auto fraction_n = over_two_plus_over_two(n, num_n, den_n);

    const auto result_n = add_fraction(static_cast<Int_T>(1),
                                       static_cast<Int_T>(1),
                                       fraction_n.first,
                                       fraction_n.second);

    num_n = result_n.first;
    den_n = result_n.second;

    const auto num_n_str = num_n.convert_to<std::string>();
    const auto den_n_str = den_n.convert_to<std::string>();

    if(num_n_str.size() > den_n_str.size()) ++sum;
  }

  std::cout << sum << std::endl;

  return 0;
}