// LeetCode: 49
// Group Anagrams

#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>

class Solution {
public:
  std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs) {
    std::vector<std::vector<std::string>> result;
    std::unordered_map<std::string, std::vector<std::string>> anagram_map;

    for(const auto& str : strs) {
      auto input = str;
      std::sort(input.begin(), input.end());

      anagram_map[input].push_back(str);
    }

    for(auto it = anagram_map.begin(); it != anagram_map.end(); ++it) {
      result.push_back(it->second);
    }

    return result;
  }
};