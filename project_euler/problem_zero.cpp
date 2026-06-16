// Project Euler: 0
// Problem Zero

#include<iostream>

int main() {
  long long sum = 0;

  for(long long i = 1; i <= 250000; i+=2) sum += i*i;
  std::cout << sum << std::endl;

  return 0;
}