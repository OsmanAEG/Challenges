// LeetCode: 76
// Minimum Window Substring

#include <climits>
#include <string>
#include <unordered_map>

class Solution {
public:
  using Map_T = std::unordered_map<char, int>;

  std::string minWindow(std::string s, std::string t) {
    if(s.empty() || t.empty() || t.size() > s.size()) return "";

    Map_T t_map;
    Map_T w_map;

    for(const auto& c : t) ++t_map[c];

    const int required = t_map.size();
    int formed = 0;

    int low = 0;
    int best_low = 0;
    int smallest_valid = INT_MAX;

    for(int high = 0; high < s.size(); ++high) {
      const char c = s[high];

      if(t_map.find(c) != t_map.end()) {
        ++w_map[c];
        if(w_map[c] == t_map[c]) ++formed;
      }

      while(formed == required) {
        if(high - low + 1 < smallest_valid) {
          smallest_valid = high - low + 1;
          best_low = low;
        }

        const char removed = s[low];

        if(t_map.find(removed) != t_map.end()) {
          if(w_map[removed] == t_map[removed]) --formed;
          --w_map[removed];
        }

        ++low;
      }
    }

    if(smallest_valid == INT_MAX) return "";

    return s.substr(best_low, smallest_valid);
  }
};