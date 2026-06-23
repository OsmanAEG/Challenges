// Project Euler: 2
// Even Fibonacci Numbers

#include <iostream>

template<typename Int_T>
void fib(const Int_T num1, const Int_T num2, Int_T& sum) {
  if(num1 > 4E6 || num2 > 4E6) return;

  const auto next = num1 + num2;

  if(next%2 == 0) sum += next;

  fib(num2, next, sum);
}

int main() {
  unsigned long long sum = 2;
  fib<unsigned long long>(1, 2, sum);

  std::cout << sum << std::endl;

  return 0;
}