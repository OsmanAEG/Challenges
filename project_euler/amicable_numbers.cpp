// Project Euler: 21
// Amicable Numbers

#include <iostream>
#include <set>

using Int_T = unsigned long long;

Int_T factor_sums(Int_T num) {
  Int_T sum = 0;

  for(int i = 1; i <= num/2; ++i) {
    if(num%i == 0) sum += i;
  }

  return sum;
}

bool is_amicable_pair(Int_T num1, Int_T num2) {
  if(num1 != num2 && factor_sums(num2) == num1) return true;
  return false;
}

int main() {
  const Int_T n = 10000;
  std::set<Int_T> amicable_pairs;

  Int_T result = 0;

  for(Int_T i = 1; i < n; ++i) {
    const auto j = factor_sums(i);

    if(is_amicable_pair(i, j)) {
      amicable_pairs.insert(i);
      amicable_pairs.insert(j);
    }
  }

  for(const auto& num : amicable_pairs) result += num;

  std::cout << result << std::endl;

  return 0;
}