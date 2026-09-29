// Project Euler: 80
// Square Root Digital Expansion

#include "helper.h"

using Int_T = boost::multiprecision::cpp_int;

Int_T sqrt(Int_T num) {
  return boost::multiprecision::sqrt(num);
}

int main() {
  const Int_T N = 100;
  const Int_T N_scale = 199;

  Int_T result = 0;

  std::vector<Int_T> ns;
  std::set<Int_T> ns_to_skip;

  std::vector<Int_T> scaled_roots;

  for(Int_T n = 1; n*n <= N; ++n) {
    ns_to_skip.insert(n*n);
  }

  for(Int_T n = 1; n <= N; ++n) {
    if(ns_to_skip.find(n) == ns_to_skip.end()) {
      ns.push_back(n);
    }
  }

  for(const auto& n : ns) {
    Int_T scaled_n = n;

    for(Int_T i = 1; i < N_scale; ++i) scaled_n *= 10;

    const auto scaled_root = sqrt(scaled_n);
    scaled_roots.push_back(scaled_root);
  }

  for(const auto& scaled_root : scaled_roots) {
    const auto str = scaled_root.str();

    for(const auto& c : str) {
      result += c - '0';
    }
  }

  std::cout << result << std::endl;

  return 0;
}