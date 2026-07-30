// Project Euler: 25
// 1000-digit Fibonacci Number

#include <iostream>
#include <string>

using String_T = std::string;

String_T add(const String_T num_1, const String_T num_2) {
  auto result = num_2;
  bool extra = false;

  for(int i = num_1.size() - 1; i >= 0; --i) {
    const int adj = result.size() - num_1.size() + i;
    int sum = (result[adj] - '0') + (num_1[i] - '0');

    if(extra == true) sum += 1;

    if(sum >= 10) {
      result[adj] = (sum - 10) + '0';
      extra = true;
    } else {
      result[adj] = sum + '0';
      extra = false;
    }
  }

  for(int i = result.size() - num_1.size() - 1; i >= 0; --i) {
    int sum = (result[i] - '0');

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
  String_T last_2 = "1";
  String_T last_1 = "1";

  int idx = 2;

  while(last_1.size() < n) {
    ++idx;
    const auto result = add(last_2, last_1);
    last_2 = last_1;
    last_1 = result;
  }

  std::cout << idx << std::endl;
  return 0;
}