// Project Euler: 71
// Ordered Fractions

#include "helper.h"

using Int_T = unsigned long long;
using Scalar_T = double;

struct Result{
  Int_T num;
  Int_T den;

  Scalar_T fraction;

  Result(Int_T num_in, Int_T den_in) {
    const auto gcd = greatest_common_factor(num_in, den_in);

    num = num_in/gcd;
    den = den_in/gcd;

    fraction = static_cast<Scalar_T>(num)/static_cast<Scalar_T>(den);
  }

  bool operator<(const Result& other) const {
    return fraction < other.fraction;
  }

  bool operator<=(const Result& other) const {
    return fraction <= other.fraction;
  }

  bool operator>(const Result& other) const {
    return fraction > other.fraction;
  }

  bool operator>=(const Result& other) const {
    return fraction >= other.fraction;
  }

  bool operator==(const Result& other) const {
    return fraction == other.fraction;
  }

  bool operator!=(const Result& other) const {
    return fraction != other.fraction;
  }
};

int main() {
  const Int_T N = 1000000;

  Result result = Result(0, 1);

  for(Int_T d = 1; d <= N; ++d) {
    const Int_T n = (3*d-1)/7;

    const auto check = Result(n, d);

    if(check > result) result = check;

  }

  std::cout << result.num << "/" << result.den << std::endl;

  return 0;
}