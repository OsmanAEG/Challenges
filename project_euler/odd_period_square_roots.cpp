// Project Euler: 64
// Odd Period Square Roots

#include "helper.h"

using Int_T = unsigned long long;

Int_T integer_sqrt(Int_T num) {
  return std::sqrt(num);
}

Int_T period(Int_T num) {
  const auto a0 = integer_sqrt(num);

  if(a0*a0 == num) return 0;

  Int_T m = 0;
  Int_T d = 1;
  Int_T a = a0;

  Int_T p = 0;

  while(a != 2*a0) {
    m = d*a - m;
    d = (num-m*m)/d;
    a = (a0 + m)/d;

    ++p;
  }

  return p;
}

int main() {
  Int_T N = 10000;
  Int_T result = 0;

  for(Int_T n = 2; n <= N; ++n) {
    if(period(n) % 2 != 0) ++result;
  }

  std::cout << result << std::endl;

  return 0;
}