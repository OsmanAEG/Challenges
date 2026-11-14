// LeetCode: 131
// Palindrome Partitioning

#include <string>
#include <vector>

class Solution {
public:
  std::vector<std::vector<std::string>> palindrome_permutations;

  bool is_palindrome(std::string s) {
    int low = 0;
    int high = s.size() - 1;

    while(low < high) {
      if(s[low] != s[high]) return false;

      ++low;
      --high;
    }

    return true;
  }

  void get_palindrome_permutations(std::string s, std::vector<std::string> combos, int low) {
    const auto n = s.size();

    if(low == n) {
      palindrome_permutations.push_back(combos);
      return;
    }

    std::string combo = "";

    for(int high = low; high < n; ++high) {
      combo += s[high];

      if(!is_palindrome(combo)) continue;

      auto combos_i = combos;
      combos_i.push_back(combo);

      get_palindrome_permutations(s, combos_i, high + 1);
    }
  }

  std::vector<std::vector<std::string>> partition(std::string s) {
    get_palindrome_permutations(s, {}, 0);
    return palindrome_permutations;
  }
};