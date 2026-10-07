// Project Euler: 92
// Square Digit Chains

#include "helper.h"

using Int_T = unsigned long long;

Int_T find_chain_link(Int_T num) {
  while(num != 89 && num != 1) {
    num = square_digits(num);
  }

  return num;
}

int main() {
  const Int_T N = 10000000;
  const Int_T S = 89;
  Int_T count = 0;

  for(Int_T i = 1; i < N; ++i) {
    const Int_T start = find_chain_link(i);
    if(start == S) ++count;
  }

  std::cout << count << std::endl;

  return 0;
}