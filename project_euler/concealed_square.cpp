// Project Euler: 206
// Concealed Square

#include "helper.h"

using Int_T = unsigned long long;
using String_T = std::string;

bool is_concealed_square(const Int_T& num) {
  const String_T num_str = std::to_string(num*num);

  if(num_str.size() < 18) return false;

  if(num_str[0]  != '1') return false;
  if(num_str[2]  != '2') return false;
  if(num_str[4]  != '3') return false;
  if(num_str[6]  != '4') return false;
  if(num_str[8]  != '5') return false;
  if(num_str[10] != '6') return false;
  if(num_str[12] != '7') return false;
  if(num_str[14] != '8') return false;
  if(num_str[16] != '9') return false;
  if(num_str[18] != '0') return false;

  return true;
}

int main() {
  const Int_T num_min = std::sqrt(1020304050607080900);
  const Int_T num_max = std::sqrt(1929394959697989990);

  Int_T num = num_min;

  while(num <= num_max) {
    if(is_concealed_square(num)) break;
    ++num;
  }

  std::cout << num << std::endl;

  return 0;
}