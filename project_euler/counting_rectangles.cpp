// Project Euler: 85
// Counting Rectangles

#include "helper.h"

using Int_T = unsigned long long;

Int_T num_rectangles(Int_T m, Int_T n) {
  const Int_T choice = 2;
  const auto m_result = binomial_coefficient(m + 1, choice);
  const auto n_result = binomial_coefficient(n + 1, choice);

  return m_result*n_result;
}

struct result {
  Int_T diff;

  static constexpr Int_T target = 2000000;
  Int_T area = 0;

  result(Int_T m, Int_T n) {
    area = m*n;
    const auto num = num_rectangles(m, n);

    diff = (target > num) ? target - num : num - target;
  }

  auto operator<=>(const result&) const = default;
};

int main() {
  const Int_T limit = 1500;
  result best_result = result(1500,1500);

  for(Int_T m = 1; m < limit; ++m) {
    for(Int_T n = m; n < limit; ++n) {
      const auto result_mn = result(m, n);

      if(result_mn < best_result) best_result = result_mn;
    }
  }

  std::cout << best_result.area << std::endl;

  return 0;
}