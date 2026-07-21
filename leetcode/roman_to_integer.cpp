// LeetCode: 13
// Roman to Integer

#include <string>

class Solution {
public:
  int symbol_to_value(const char symbol) {
    if(symbol == 'I') return 1;
    else if(symbol == 'V') return 5;
    else if(symbol == 'X') return 10;
    else if(symbol == 'L') return 50;
    else if(symbol == 'C') return 100;
    else if(symbol == 'D') return 500;
    else return 1000;
  }

  int romanToInt(std::string s) {
    if(s.size() == 1) return symbol_to_value(s[0]);

    int result = 0;

    int one = 0;
    int two = 1;

    while(two <= s.size()) {
      if(s[one] == 'I' && (s[two] == 'V' || s[two] == 'X')) {
        result += symbol_to_value(s[two]) - symbol_to_value(s[one]);
        one += 2;
        two += 2;
      } else if(s[one] == 'X' && (s[two] == 'L' || s[two] == 'C')) {
        result += symbol_to_value(s[two]) - symbol_to_value(s[one]);
        one += 2;
        two += 2;
      } else if(s[one] == 'C' && (s[two] == 'D' || s[two] == 'M')) {
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
};