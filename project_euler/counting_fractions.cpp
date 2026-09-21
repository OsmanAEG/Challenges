// Project Euler: 72
// Counting Fractions

#include "helper.h"

using Int_T = unsigned long long;

int main() {
  const Int_T N = 1000000;

  Int_T count = 0;

  for(Int_T d = 2; d <= N; ++d) count += totient(d);

  std::cout << count << std::endl;

  return 0;
}