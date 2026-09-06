// Project Euler: 58
// Spiral Primes

#include "helper.h"

using Int_T = unsigned long long;
using Index_T = long long;

int main() {

  bool found_10_percent = false;

  Int_T n = 3;

  std::pair<Index_T, Index_T> pos = {0, 0};

  Int_T steps = 1;

  int dir = 1;

  Int_T x_stretch = 1;
  Int_T y_stretch = 1;

  Int_T num_diag = 1;
  Int_T num_diag_primes = 0;

  while(!found_10_percent) {
    Int_T x_steps = 0;
    Int_T y_steps = 0;

    // horizontal
    while(x_steps < x_stretch && !found_10_percent) {
      pos.first += dir;

      ++steps;
      ++x_steps;

      if(std::abs(pos.first) == std::abs(pos.second)) {
        ++num_diag;
        if(is_prime(steps)) ++num_diag_primes;
      }

      if(steps == n*n) {
        if(10*num_diag_primes < num_diag) found_10_percent = true;
        else n += 2;
      }

    }

    ++x_stretch;

    // vertical
    while(y_steps < y_stretch && !found_10_percent) {
      pos.second += dir;

      ++steps;
      ++y_steps;

      if(std::abs(pos.first) == std::abs(pos.second)) {
        ++num_diag;
        if(is_prime(steps)) ++num_diag_primes;
      }

      if(steps == n*n) {
        if(10*num_diag_primes < num_diag) found_10_percent = true;
        else n += 2;
      }
    }

    ++y_stretch;
    dir *= -1;
  }

  std::cout << n << std::endl;

  return 0;
}