// Project Euler: 23
// Non-Abundant Sums

#include<iostream>
#include<set>
#include<vector>

using Int_T = unsigned long long;

bool is_abundant(const Int_T& num) {
  std::vector<Int_T> divisors;
  Int_T divisors_sum = 0;

  for(Int_T i = 1; i <= num/2; ++i) {
    if(num%i == 0) divisors.push_back(i);
  }

  for(const auto& divisor : divisors) {
    divisors_sum += divisor;
  }

  if(divisors_sum > num) return true;

  return false;
}

int main() {
  Int_T n = 28123;
  Int_T result = 0;

  std::set<Int_T> sums;

  std::vector<Int_T> abundant_nums;

  for(Int_T i = 1; i <= n; ++i) {
    if(is_abundant(i)) abundant_nums.push_back(i);
  }

  for(Int_T i = 0; i < abundant_nums.size(); ++i) {
    for(Int_T j = i; j < abundant_nums.size(); ++j) {
      sums.insert(abundant_nums[i] + abundant_nums[j]);
    }
  }

  for(Int_T i = 1; i <= n; ++i) {
    if(sums.find(i) == sums.end()) {
      result += i;
    }
  }

  std::cout << result << std::endl;

  return 0;
}