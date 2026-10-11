// Project Euler: 112
// Bouncy Numbers

#include "helper.h"

using Int_T = unsigned long long;
using String_T = std::string;

String_T bouncy_analysis(Int_T num) {
  bool is_increasing = false;
  bool is_decreasing = false;

  const auto num_str = std::to_string(num);

  for(int i = 1; i < num_str.size(); ++i) {
    if(num_str[i] > num_str[i-1]) is_increasing = true;
    if(num_str[i] < num_str[i-1]) is_decreasing = true;
  }

  if(is_increasing && is_decreasing) return "bouncy";
  else if(is_increasing) return "increasing";
  else return "decreasing";
}

int main() {
  Int_T num_bouncy = 0;
  Int_T num_numbers = 0;

  bool is_99 = false;

  Int_T num = 1;

  while(!is_99) {
    if(bouncy_analysis(num) == "bouncy") ++num_bouncy;
    ++num_numbers;

    if(num_bouncy*100/num_numbers == 99 && num_bouncy*100%num_numbers == 0) {
      is_99 == true;
      break;
    }

    ++num;
  }

  std::cout << num << std::endl;

  return 0;
}