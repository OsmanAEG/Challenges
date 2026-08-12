#include <cmath>
#include <iostream>
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