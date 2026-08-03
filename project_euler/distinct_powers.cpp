// Project Euler: 29
// Distinct Powers

#include <cmath>
#include <boost/multiprecision/cpp_int.hpp>
#include <iostream>
#include <string>
#include <unordered_set>

using Int_T = boost::multiprecision::cpp_int;

Int_T pow(const Int_T a, const Int_T b) {
  Int_T power = 1;

  for(Int_T i = 0; i < b; ++i) power *= a;

  return power;
}

int main() {
  Int_T a_min = 2;
  Int_T a_max = 100;

  Int_T b_min = 2;
  Int_T b_max = 100;

  std::unordered_set<Int_T> distinct_powers;

  for(Int_T a = a_min; a <= a_max; ++a) {
    for(Int_T b = b_min; b <= b_max; ++b) {
      const Int_T power = pow(a, b);
      distinct_powers.insert(power);
    }
  }

  std::cout << distinct_powers.size() << std::endl;

  return 0;
}