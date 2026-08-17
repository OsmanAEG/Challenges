// Project Euler: 42
// Coded Triangle Numbers

#include "helper.h"

using Int_T = unsigned long long;
using String_T = std::string;

bool is_triangle_number(Int_T num) {
  for(Int_T n = 1; n <= num; ++n) {
    const auto tn = n*(n+1)/2;

    if(tn == num) return true;
  }

  return false;
}

Int_T word_to_num(String_T word) {
  Int_T value = 0;

  for(const auto& c : word) {
    if(c == 'A') value += 1;
    else if(c == 'B') value += 2;
    else if(c == 'C') value += 3;
    else if(c == 'D') value += 4;
    else if(c == 'E') value += 5;
    else if(c == 'F') value += 6;
    else if(c == 'G') value += 7;
    else if(c == 'H') value += 8;
    else if(c == 'I') value += 9;
    else if(c == 'J') value += 10;
    else if(c == 'K') value += 11;
    else if(c == 'L') value += 12;
    else if(c == 'M') value += 13;
    else if(c == 'N') value += 14;
    else if(c == 'O') value += 15;
    else if(c == 'P') value += 16;
    else if(c == 'Q') value += 17;
    else if(c == 'R') value += 18;
    else if(c == 'S') value += 19;
    else if(c == 'T') value += 20;
    else if(c == 'U') value += 21;
    else if(c == 'V') value += 22;
    else if(c == 'W') value += 23;
    else if(c == 'X') value += 24;
    else if(c == 'Y') value += 25;
    else value += 26;
  }

  return value;
}

int main() {
  Int_T result = 0;

  String_T filename = "coded_triangle_numbers_in.txt";
  String_T input = get_input(filename)[0];

  std::vector<String_T> words;
  String_T word = "";

  Int_T idx = 0;

  while(idx < input.size()) {
    if(input[idx] != '"' && input[idx] != ',') word += input[idx];

    if(input[idx] == ',') {
      words.push_back(word);
      word = "";
    }

    ++idx;
  }

  words.push_back(word);

  for(const auto& w : words) {
    const auto num = word_to_num(w);
    if(is_triangle_number(num)) ++result;
  }

  std::cout << result << std::endl;

  return 0;
}