// Project Euler: 95
// Amicable Chains

#include "helper.h"

using Int_T = unsigned long long;
using Map_T = std::unordered_map<Int_T, Int_T>;

std::pair<Int_T, Int_T> chain_length(Int_T num, const Map_T& map) {
  Int_T length = 0;
  Int_T smallest = num;

  std::set<Int_T> visited;
  const auto origin = num;

  while(visited.find(num) == visited.end()) {
    const auto it = map.find(num);

    if(it == map.end()) return {0, 0};

    ++length;
    visited.insert(num);

    smallest = std::min(smallest, num);
    num = it->second;

    if(num == origin) return {length, smallest};
  }

  return {0, 0};
}

int main() {
  const Int_T N = 1000000;

  Int_T max_length = 0;
  Int_T smallest_member = 0;

  std::vector<Int_T> divisor_sums(N + 1, 0);

  for(Int_T d = 1; d <= N/2; ++d) {
    for(Int_T n = 2*d; n <= N; n += d) {
      divisor_sums[n] += d;
    }
  }

  Map_T amicable_nums;

  for(Int_T n = 1; n <= N; ++n) {
    const auto sum = divisor_sums[n];

    if(sum >= 1 && sum <= N) amicable_nums[n] = sum;
  }

  for(Int_T n = 1; n <= N; ++n) {
    const auto result = chain_length(n, amicable_nums);

    const auto length = result.first;
    const auto smallest = result.second;

    if(length > max_length) {
      max_length = length;
      smallest_member = smallest;
    } else if(length == max_length && length > 0 && smallest < smallest_member) {
      smallest_member = smallest;
    }
  }

  std::cout << smallest_member << std::endl;

  return 0;
}
