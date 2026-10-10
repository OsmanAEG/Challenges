// LeetCode: 17
// Letter Combinations of a Phone Number

#include <string>
#include <vector>

class Solution {
public:
  std::vector<std::string> results;

  std::vector<char> letter_options(char num) {
    if(num == '2') return {'a', 'b', 'c'};
    else if(num == '3') return {'d', 'e', 'f'};
    else if(num == '4') return {'g', 'h', 'i'};
    else if(num == '5') return {'j', 'k', 'l'};
    else if(num == '6') return {'m', 'n', 'o'};
    else if(num == '7') return {'p', 'q', 'r', 's'};
    else if(num == '8') return {'t', 'u', 'v'};
    else return {'w', 'x', 'y', 'z'};
  }

  void find_combintations(std::string digits, std::string result, int idx) {
    if(result.size() == digits.size()) {
      results.push_back(result);
      return;
    }

    const auto options = letter_options(digits[idx]);

    for(const auto& option : options) {
      auto result_i = result;
      result_i.push_back(option);

      find_combintations(digits, result_i, idx + 1);
    }
  }

  std::vector<std::string> letterCombinations(std::string digits) {
    find_combintations(digits, {}, 0);
    return results;
  }
};