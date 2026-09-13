// Project Euler: 65
// Convergents of e

#include "helper.h"

using Int_T = boost::multiprecision::cpp_int;

Int_T e_coefficient(const Int_T n) {
    if (n == 1) return 2;
    if (n % 3 == 0) return 2 * (n / 3);
    return 1;
}

std::pair<Int_T, Int_T> e_fraction(Int_T n, Int_T num, Int_T den) {
  if (n == 1) return {num, den};

  const auto result = add_fraction(e_coefficient(n), static_cast<Int_T>(1), num, den);

  num = result.second;
  den = result.first;

  return e_fraction(n - 1, num, den);
}

int main() {
  const Int_T N = 100;

  Int_T sum = 0;

  Int_T num = 0;
  Int_T den = 1;

  const auto fraction = e_fraction(N, num, den);

  const auto result = add_fraction(static_cast<Int_T>(2), static_cast<Int_T>(1), fraction.first, fraction.second);

  num = result.first;

  const auto num_str = num.convert_to<std::string>();

  for(const char digit : num_str) sum += digit - '0';

  std::cout << sum << std::endl;

  return 0;
}