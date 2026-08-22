#include <algorithm>
#include <climits>
#include <cmath>
#include <fstream>
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

// is triangle number
template<typename Int_T>
bool is_triangle_number(Int_T num) {
  Int_T n = 1;
  Int_T tn = n*(n+1)/2;

  while(tn < num) {
    tn = n*(n+1)/2;
    ++n;
  }

  if(tn == num) return true;

  return false;
}

// get triangle number
template<typename Int_T>
Int_T get_triangle_number(Int_T n) {
  return n*(n+1)/2;
}

// is pentagon number
template<typename Int_T>
bool is_pentagon_number(Int_T num) {
  Int_T n = 1;
  Int_T pn = n*(3*n-1)/2;

  while(pn < num) {
    pn = n*(3*n-1)/2;
    ++n;
  }

  if(pn == num) return true;

  return false;
}

// get pentagon number
template<typename Int_T>
Int_T get_pentagon_number(Int_T n) {
  return n*(3*n-1)/2;
}

// is triangle number
template<typename Int_T>
bool is_hexagon_number(Int_T num) {
  Int_T n = 1;
  Int_T hn = n*(2*n-1);

  while(hn < num) {
    hn = n*(2*n-1);
    ++n;
  }

  if(hn == num) return true;

  return false;
}

// get hexagon number
template<typename Int_T>
Int_T get_hexagon_number(Int_T n) {
  return n*(2*n-1);
}

// get input
std::vector<std::string> get_input(std::string filename) {
  std::ifstream file(filename);

  std::vector<std::string> lines;
  std::string line;

  while(std::getline(file, line)) {
    if(!line.empty()) lines.push_back(line);
  }

  return lines;
}

// get prime factors
template<typename Int_T>
std::vector<Int_T> get_prime_factors(Int_T num) {
  std::vector<Int_T> prime_factors;
  for(int i = 2; i < num; ++i) {
    if(num%i == 0 && is_prime(i)) prime_factors.push_back(i);
  }

  return prime_factors;
}