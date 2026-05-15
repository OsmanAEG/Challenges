// LeetCode: 242
// Valid Anagram

#include <map>
#include <string>

class Solution {
public:
  bool isAnagram(std::string s, std::string t) {
    std::map<char, int> s_map;
    std::map<char, int> t_map;

    for(const auto& c : s) s_map[c] += 1;
    for(const auto& c : t) t_map[c] += 1;

    if(s_map.size() != t_map.size()) return false;

    for(auto it = s_map.begin(); it != s_map.end(); ++it) {
      if(s_map[it->first] != t_map[it->first]) return false;
    }

    return true;
  }
};