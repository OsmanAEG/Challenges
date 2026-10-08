// Project Euler: 97
// Large Non-Mersenne Prime

#include "helper.h"

using Int_T = unsigned long long;

int main() {
  const Int_T N = 10;
  const Int_T mod = 10000000000;

  const Int_T mult = 28433;
  const Int_T base = 2;
  const Int_T powr = 7830457;
  const Int_T ones = 1;

  Int_T step_1 = 1;

  for(Int_T i = 0; i < powr; ++i) {
    step_1 = (step_1 * base) % mod;
  }

  const Int_T step_2 = (step_1 * mult) % mod;
  const Int_T step_3 = (step_2 + ones) % mod;

  std::cout << step_3 << std::endl;

  return 0;
}