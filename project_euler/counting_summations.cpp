// Project Euler: 76
// Counting Summations

#include "helper.h"

using Int_T = unsigned long long;

void count_sums(Int_T idx, Int_T sum, Int_T N, Int_T& count) {
  if(sum > N) {
    return;
  } else if(sum == N) {
    ++count;
    return;
  } else {
    for(Int_T i = idx; i < N && sum + i <= N; ++i) {
      count_sums(i, sum + i, N, count);
    }
  }
}

int main() {
  const Int_T N = 100;
  Int_T count = 0;

  count_sums(1, 0, N, count);

  std::cout << count << std::endl;

  return 0;
}