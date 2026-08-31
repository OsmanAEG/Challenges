// Project Euler Helper Functions
#include <algorithm>
#include <boost/multiprecision/cpp_int.hpp>
#include <climits>
#include <cmath>
#include <compare>
#include <fstream>
#include <functional>
#include <iostream>
#include <map>
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

// multiple strs
template<typename String_T, typename Int_T>
String_T multiply_strs(String_T num, Int_T multiple) {
  String_T result = num;
  const Int_T n = num.size();

  for(Int_T m = 0; m < multiple - 1; ++m) {

    bool extra = false;

    for(int i = n - 1; i >= 0; --i) {
      const int adj = result.size() - n + i;
      int sum = (result[adj] - '0') + (num[i] - '0');

      if(extra == true) sum += 1;

      if(sum >= 10) {
        result[adj] = (sum - 10) + '0';
        extra = true;
      } else {
        result[adj] = sum + '0';
        extra = false;
      }
    }

    if(result.size() > num.size()) {
      int i = result.size() - num.size() - 1;

      while(i >= 0 && extra == true) {
        int sum = (result[i] - '0') + 1;

        if(sum >= 10) {
          result[i] = (sum - 10) + '0';
          extra = true;
        } else {
          result[i] = sum + '0';
          extra = false;
        }

        --i;
      }
    }

    if(extra == true) result = "1" + result;
  }

  return result;
}

// add strs
template<typename String_T>
String_T add_strs(String_T num1, String_T num2) {
  if(num2.size() > num1.size()) {
    const auto tmp = num1;
    num1 = num2;
    num2 = tmp;
  }

  using Int_T = unsigned long long;
  const Int_T n = num2.size();

  bool extra = false;

  for(int i = n - 1; i >= 0; --i) {
    const int adj = num1.size() - n + i;
    int sum = (num1[adj] - '0') + (num2[i] - '0');

    if(extra == true) sum += 1;

    if(sum >= 10) {
      num1[adj] = (sum - 10) + '0';
      extra = true;
    } else {
      num1[adj] = sum + '0';
      extra = false;
    }
  }

  const int m = num1.size() - n;

  for(int i = m - 1; i >= 0; --i) {
    int sum = (num1[i] - '0');

    if(extra == true) sum += 1;

    if(sum >= 10) {
      num1[i] = (sum - 10) + '0';
      extra = true;
    } else {
      num1[i] = sum + '0';
      extra = false;
    }
  }

  if(extra == true) num1 = "1" + num1;
  extra = false;

  return num1;
}

// is integer permutation
template<typename Int_T>
bool is_integer_permutation(Int_T num1, Int_T num2) {
  auto num1_str = std::to_string(num1);
  auto num2_str = std::to_string(num2);

  std::sort(num1_str.begin(), num1_str.end());
  std::sort(num2_str.begin(), num2_str.end());

  return num1_str == num2_str;
}

// factorial
template<typename Int_T>
Int_T factorial(Int_T num) {
  Int_T fac = 1;

  for(Int_T i = 1; i <= num; ++i) fac *= i;

  return fac;
}

// combinatoric
template<typename Int_T>
Int_T combinatoric(Int_T n, Int_T r) {
  Int_T n_m_r = n-r;

  const auto n_fac = factorial(n);
  const auto r_fac = factorial(r);
  const auto n_m_r_fac = factorial(n_m_r);

  return n_fac/(r_fac*n_m_r_fac);
}

// reverse number
template<typename Int_T>
Int_T reverse_number(Int_T num) {

  Int_T reversed = 0;

  while(num > 0) {
    reversed = reversed * 10 + num % 10;
    num /= 10;
  }

  return reversed;
}

// is palindrome number
template<typename Int_T>
bool is_palindrome_number(Int_T num) {
  return num == reverse_number(num);
}

// lychrel step
template<typename Int_T>
Int_T lychrel_step(Int_T num) {
  return num + reverse_number(num);
}