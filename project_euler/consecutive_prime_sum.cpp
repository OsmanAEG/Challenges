// Project Euler: 50
// Consecutive Prime Sum

#include "helper.h"

using Int_T = unsigned long long;

int main() {
  Int_T N = 1000000;

  Int_T max_consecutive = 0;
  Int_T max_prime = 0;

  std::vector<Int_T> primes;

  for(Int_T i = 2; i < N; ++i) {
    if(is_prime(i)) primes.push_back(i);
  }

  for(Int_T i = 0; i < primes.size(); ++i) {
    Int_T sum = 0;
    Int_T num_consecutive = 0;

    for(Int_T j = i; j < primes.size(); ++j) {
      sum += primes[j];
      ++num_consecutive;

      if(sum >= N) break;

      if(is_prime(sum) && num_consecutive > max_consecutive) {
        max_consecutive = num_consecutive;
        max_prime = sum;
      }
    }
  }

  std::cout << max_prime << std::endl;

  return 0;
}