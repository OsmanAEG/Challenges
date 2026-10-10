// Project Euler: 89
// Roman Numerals

#include "helper.h"

using Int_T = unsigned long long;
using String_T = std::string;

Int_T symbol_to_value(const char symbol) {
  if(symbol == 'I') return 1;
  else if(symbol == 'V') return 5;
  else if(symbol == 'X') return 10;
  else if(symbol == 'L') return 50;
  else if(symbol == 'C') return 100;
  else if(symbol == 'D') return 500;
  else if(symbol == 'M') return 1000;
  else return 0;
}

Int_T romanToInt(const String_T& s) {
  if(s.size() == 1) return symbol_to_value(s[0]);

  Int_T result = 0;

  Int_T one = 0;
  Int_T two = 1;

  while(one < s.size()) {
    if(two < s.size() && s[one] == 'I' && (s[two] == 'V' || s[two] == 'X')) {
      result += symbol_to_value(s[two]) - symbol_to_value(s[one]);
      one += 2;
      two += 2;
    } else if(two < s.size() && s[one] == 'X' && (s[two] == 'L' || s[two] == 'C')) {
      result += symbol_to_value(s[two]) - symbol_to_value(s[one]);
      one += 2;
      two += 2;
    } else if(two < s.size() && s[one] == 'C' && (s[two] == 'D' || s[two] == 'M')) {
      result += symbol_to_value(s[two]) - symbol_to_value(s[one]);
      one += 2;
      two += 2;
    } else {
      result += symbol_to_value(s[one]);
      ++one;
      ++two;
    }
  }

  return result;
}

String_T intToRoman(Int_T num) {
  const std::vector<std::pair<Int_T, String_T>> symbols = {{1000, "M"}, {900, "CM"}, {500, "D"},
                                                           {400, "CD"}, {100, "C"},  {90, "XC"},
                                                           {50, "L"},   {40, "XL"},  {10, "X"},
                                                           {9, "IX"},   {5, "V"},    {4, "IV"},
                                                           {1, "I"}};

  String_T result = "";

  for(const auto& [value, symbol] : symbols) {
    while(num >= value) {
      result += symbol;
      num -= value;
    }
  }

  return result;
}

int main() {
  const String_T filename = "roman_numerals_input.txt";
  const auto input = get_input(filename);

  Int_T result = 0;

  for(const auto& roman_num : input) {
    const auto value = romanToInt(roman_num);
    const auto minimal_roman = intToRoman(value);

    result += roman_num.size() - minimal_roman.size();
  }

  std::cout << result << std::endl;

  return 0;
}