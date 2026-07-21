// Project Euler: 17
// Number Letter Counts

#include <iostream>
#include <string>

using Int_T    = unsigned long long;
using String_T = std::string;

Int_T count_letters(const Int_T num) {
  Int_T result = 3;

  if(num < 100) result -= 3;
  if(num >= 100 && num%100 == 0) result -= 3;

  const auto str = std::to_string(num);

  for(Int_T i = 0; i < str.size(); ++i) {
    const char d = str[i];

    const Int_T pos = str.size() - 1 - i;

    if(pos == 3) {
      result += 11;
    } else if(pos == 2) {
      if(d == '1' || d == '2' || d == '6') result += 10;
      if(d == '3' || d == '7' || d == '8') result += 12;
      if(d == '4' || d == '5' || d == '9') result += 11;
    } else if(pos == 1) {
      if(d == '1') result += 3;
      if(d == '2' || d == '3' || d == '8' || d == '9') result += 6;
      if(d == '5' || d == '4' || d == '6') result += 5;
      if(d == '7') result += 7;
    } else {
      if(pos == 0 && str.size() == 1 || pos == 0 && str[i-1] != '1') {
        if(d == '1' || d == '2' || d == '6') result += 3;
        if(d == '3' || d == '7' || d == '8') result += 5;
        if(d == '4' || d == '5' || d == '9') result += 4;
      } else {
        if(d == '1' || d == '2') result += 6 - 3;
        if(d == '3' || d == '4' || d == '8' || d == '9') result += 8 - 3;
        if(d == '5' || d == '6') result += 7 - 3;
        if(d == '7') result += 9 - 3;
      }
    }
  }

  return result;
}

int main() {
  const Int_T n = 1000;
  Int_T total = 0;

  for(Int_T i = 1; i <= n; ++i) {
    total += count_letters(i);
  }

  std::cout << total << std::endl;

  return 0;
}