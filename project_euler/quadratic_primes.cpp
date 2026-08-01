// Project Euler: 27
// Quadratic Primes

#include <algorithm>
#include <cmath>
#include <iostream>

using Int_T = long long;

template<typename Int_T>
bool is_prime(const Int_T num) {
  if(num < 2) return false;

  for(Int_T i = 2; i <= std::sqrt(num); ++i) {
    if(num%i == 0) return false;
  }

  return true;
}

int main() {
  Int_T max_primes = 0;
  std::pair<Int_T, Int_T> ab_pair = {0, 0};

  Int_T a_min = -999;
  Int_T a_max = 999;

  Int_T b_min = -1000;
  Int_T b_max = 1000;

  for(Int_T a = a_min; a <= a_max; ++a) {
    for(Int_T b = b_min; b <= b_max; ++b) {
      bool prime = true;
      Int_T num_primes = 0;
      Int_T n = 0;

      while(prime == true) {
        if(is_prime(n*n + a*n + b)) {
          ++num_primes;
          ++n;
        } else {
          prime = false;
        }
      }

      if(num_primes > max_primes) {
        max_primes = num_primes;
        ab_pair.first = a;
        ab_pair.second = b;
      }
    }
  }

  std::cout << ab_pair.first*ab_pair.second << std::endl;

  return 0;
}