// Project Euler: 47
// Distinct Primes Factors

#include "helper.h"

using Int_T = unsigned long long;

int main() {
  bool found = false;
  Int_T n = 4;

  Int_T num = 2;

  std::vector<Int_T> consectutive;

  while(!found) {
    const auto prime_factors = get_prime_factors(num);

    if(prime_factors.size() == n) {
      consectutive.push_back(num);
    } else {
      consectutive.clear();
    }

    if(consectutive.size() == n) {
      found = true;
      break;
    }

    ++num;
  }

  std::cout << consectutive[0] << std::endl;

  return 0;
}