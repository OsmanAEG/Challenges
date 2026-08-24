// Project Euler: 49
// Prime Permutations

#include "helper.h"

using Int_T = unsigned long long;

int main() {
  Int_T min = 1000;
  Int_T max = 10000;

  std::vector<std::vector<Int_T>> results;

  for(Int_T i = 1000; i < max; ++i) {
    for(Int_T j = i + 1; j < max; ++j) {
      const Int_T diff = j - i;
      const Int_T k = j + diff;

      if(k >= max) break;

      const bool are_primes = is_prime(i) && is_prime(j) && is_prime(k);
      const bool are_perms = is_integer_permutation(i, j) && is_integer_permutation(j, k);

      if(are_primes && are_perms) results.push_back({i, j, k});
    }
  }

  for(const auto& result : results) {
    std::cout << "[" << result[0] << ", " << result[1] << ", " << result[2] << "]" << std::endl;
  }

  std::cout << results[1][0] << results[1][1] << results[1][2] << std::endl;

  return 0;
}