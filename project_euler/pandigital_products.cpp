// Project Euler: 32
// Pandigital Products

#include <algorithm>
#include <iostream>
#include <set>
#include <string>

using Int_T = unsigned long long;
using String_T = std::string;

int main() {
  String_T target = "123456789";
  Int_T result = 0;

  std::set<Int_T> product_set;

  Int_T a_min = 1;
  Int_T a_max = 100;

  Int_T b_min = 10;
  Int_T b_max = 10000;

  for(Int_T a = a_min; a < a_max; ++a) {
    for(Int_T b = b_min; b < b_max; ++b) {
      const auto product = a*b;

      const auto a_str = std::to_string(a);
      const auto b_str = std::to_string(b);

      const auto product_str = std::to_string(product);

      String_T combo = "";

      combo += a_str;
      combo += b_str;
      combo += product_str;

      std::sort(combo.begin(), combo.end());


      if(combo == target && product_set.find(product) == product_set.end()) {
        result += product;
        product_set.insert(product);
      }
    }
  }

  std::cout << result << std::endl;
}