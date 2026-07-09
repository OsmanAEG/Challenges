// Project Euler: 16
// Power Digit Sum

#include <iostream>
#include <string>

using Int_T    = unsigned long long;
using String_T = std::string;

String_T double_strs(const String_T num) {
  const Int_T n = num.size();
  String_T result = "";
  result.resize(n);

  bool extra = false;

  for(int i = n - 1; i >= 0; --i) {
    int sum = (num[i] - '0') + (num[i] - '0');

    if(extra == true) sum += 1;

    if(sum >= 10) {
      result[i] = (sum - 10) + '0';
      extra = true;
    } else {
      result[i] = sum + '0';
      extra = false;
    }
  }

  if(extra == true) result = "1" + result;

  return result;
}

int main() {
  const int n = 1000;
  String_T num = "2";
  Int_T sum = 0;

  for(int i = 1; i < n; ++i) num = double_strs(num);

  for(int i = 0; i < num.size(); ++i) {
    sum += (num[i] - '0');
  }

  std::cout << num << std::endl;
  std::cout << sum << std::endl;

  return 0;
}