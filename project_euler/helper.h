#include <algorithm>
#include <cmath>
#include <iostream>
#include <set>
#include <string>
#include <unordered_set>
#include <vector>

// Helper functions

// is prime
template<typename Int_T>
bool is_prime(const Int_T num) {
  if(num < 2) return false;

  for(Int_T i = 2; i <= std::sqrt(num); ++i) {
    if(num%i == 0) return false;
  }

  return true;
}

// is pandigital
template<typename String_T>
bool is_pandigital(String_T num) {
  String_T pandigits = "";

  for(int i = 0; i < num.size(); ++i) {
    pandigits += std::to_string(i + 1);
  }

  std::sort(num.begin(), num.end());

  if(num == pandigits) return true;

  return false;
}