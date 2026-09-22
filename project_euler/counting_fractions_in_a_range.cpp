// Project Euler: 73
// Counting Fractions in a Range

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
  const Int_T N = 12000;

  const Result result_min = Result(1, 3);
  const Result result_max = Result(1, 2);

  std::set<Result> result_set;

  for(Int_T d = 2; d <= N; ++d) {
    for(Int_T n = 1; n < d; ++n) {
      const auto check = Result(n, d);
      if(check < result_max && check > result_min) result_set.insert(check);
    }
  }

  std::cout << result_set.size() << std::endl;

  return 0;
}