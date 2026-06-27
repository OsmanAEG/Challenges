// Project Euler: 6
// Sum Square Difference

#include <algorithm>
#include <iostream>
#include <string>

int main() {
  using Int_T = unsigned long long;

  Int_T sum_of_squares = 0;
  Int_T square_of_sum = 0;

  Int_T num = 100;

  for(Int_T i = 1; i <= num; ++i) sum_of_squares += i*i;
  for(Int_T i = 1; i <= num; ++i) square_of_sum += i;

  square_of_sum *= square_of_sum;

  const auto diff = square_of_sum - sum_of_squares;

  std::cout << diff << std::endl;

  return 0;
}