// Project Euler: 87
// Prime Power Triples

#include "helper.h"

using Int_T = unsigned long long;

int main() {
  std::unordered_set<Int_T> results;

  const Int_T N = 50000000;

  std::vector<Int_T> a_primes;
  std::vector<Int_T> b_primes;
  std::vector<Int_T> c_primes;

  const Int_T a_lim = std::pow(N, 1.0/2.0);
  const Int_T b_lim = std::pow(N, 1.0/3.0);
  const Int_T c_lim = std::pow(N, 1.0/4.0);

  for(Int_T i = 2; i < a_lim; ++i) if(is_prime(i)) a_primes.push_back(i);
  for(Int_T i = 2; i < b_lim; ++i) if(is_prime(i)) b_primes.push_back(i);
  for(Int_T i = 2; i < c_lim; ++i) if(is_prime(i)) c_primes.push_back(i);

  for(const auto& a : a_primes) {
    for(const auto& b : b_primes) {
      for(const auto& c : c_primes) {
        const auto result = std::pow(a, 2) + std::pow(b, 3) + std::pow(c, 4);

        if(result < N) results.insert(result);
      }
    }
  }

  std::cout << results.size() << std::endl;

  return 0;
}