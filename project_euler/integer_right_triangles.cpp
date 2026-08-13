// Project Euler: 39
// Integer Right Triangles

#include "helper.h"

using Int_T = unsigned long long;

int main() {
  Int_T max_sols = 0;
  Int_T max_p = 0;

  Int_T p = 3;

  Int_T p_max = 1000;

  while(p < p_max) {
    Int_T num_sols = 0;

    for(Int_T i = 1; i < p - 1; ++i) {
      for(Int_T j = i; j < p - 1; ++j) {
        for(Int_T k = j; k < p - 1; ++k) {
          if((i + j + k == p) && (i*i + j*j == k*k)) ++num_sols;
        }
      }
    }

    if(num_sols > max_sols) {
      max_sols = num_sols;
      max_p = p;
    }

    max_sols = std::max(max_sols, num_sols);
    ++p;
  }

  std::cout << max_p << std::endl;

  return 0;
}