// Project Euler: 99
// Largest Exponential

#include "helper.h"

using Int_T = unsigned long long;
using Scalar_T = double;
using String_T = std::string;

int main() {
  Int_T n = 1;
  Int_T largest_line = 0;
  Scalar_T largest_result = 0.0;

  String_T filename = "largest_exponential_input.txt";
  const auto input = get_input(filename);

  for(const auto& line : input) {
    String_T base_str = "";
    String_T expo_str = "";

    Int_T i = 0;

    while(line[i] != ',') {
      base_str.push_back(line[i]);
      ++i;
    }

    ++i;

    while(i < line.size()) {
      expo_str.push_back(line[i]);
      ++i;
    }

    const Int_T base = std::stoull(base_str);
    const Int_T expo = std::stoull(expo_str);

    const Scalar_T result = expo*std::log(base);

    if(result > largest_result) {
      largest_result = result;
      largest_line = n;
    }

    ++n;
  }

  std::cout << largest_line << std::endl;

  return 0;
}