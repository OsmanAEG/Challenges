// Project Euler: 124
// Ordered Radicals

#include "helper.h"

using Int_T = unsigned long long;

struct Value {
  Int_T rad = 0;
  Int_T n = 0;

  Value(Int_T rad_in, Int_T n_in) {
    rad = rad_in;
    n = n_in;
  }

  auto operator<=>(const Value&) const = default;
};

int main() {
  const Int_T N = 100000;
  const Int_T target = 10000;

  std::vector<Value> results;

  for(Int_T n = 1; n <= N; ++n) {
    Int_T rad = 1;

    const auto prime_factors = get_prime_factors_inclusive(n);

    for(const auto& factor : prime_factors) rad *= factor;

    const auto result_n = Value(rad, n);

    results.emplace_back(result_n);
  }

  std::sort(results.begin(), results.end());

  std::cout << results[target - 1].n << std::endl;

  return 0;
}