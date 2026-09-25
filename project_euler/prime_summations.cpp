// Project Euler: 77
// Prime Summations

#include "helper.h"

using Int_T = unsigned long long;

void count_sums(Int_T idx, Int_T sum, Int_T N, Int_T& count, std::vector<Int_T>& primes) {
  if(sum > N) {
    return;
  } else if (sum == N) {
    ++count;
    return;
  }

  for (Int_T i = idx; i < primes.size() && sum + primes[i] <= N; ++i) {
    count_sums(i, sum + primes[i], N, count, primes);
  }
}

int main() {
  const Int_T N = 5000;
  Int_T num = 2;
  Int_T count = 0;

  std::vector<Int_T> primes;

  while(count <= N) {
    if(is_prime(num)) primes.push_back(num);

    count = 0;
    count_sums(0, 0, num, count, primes);

    if(count > N) break;
    ++num;
  }

  std::cout << num << std::endl;

  return 0;
}