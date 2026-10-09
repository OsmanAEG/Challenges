// Project Euler: 88
// Product Sum Numbers

#include "helper.h"

using Int_T = unsigned long long;

const Int_T k_min = 2;
const Int_T k_max = 12000;
const Int_T N_max = 2 * k_max;

std::vector<Int_T> min_product_sum(k_max + 1, std::numeric_limits<Int_T>::max());

void search(Int_T start, Int_T product, Int_T sum, Int_T count) {
  const Int_T k = product - sum + count;

  if(k >= 2 && k <= k_max) {
    min_product_sum[k] = std::min(min_product_sum[k], product);
  }

  for(Int_T i = start; i <= N_max / product; ++i) {
    const Int_T new_product = product * i;
    const Int_T new_sum = sum + i;

    search(i, new_product, new_sum, count + 1);
  }
}

int main() {
  search(2, 1, 0, 0);
  std::set<Int_T> unique_numbers;

  for(Int_T k = k_min; k <= k_max; ++k) unique_numbers.insert(min_product_sum[k]);

  Int_T result = 0;

  for(const auto& num : unique_numbers) result += num;

  std::cout << result << std::endl;

  return 0;
}