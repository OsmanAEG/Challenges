// LeetCode: 383
// Ransom Note

#include <string>
#include <unordered_map>

class Solution {
public:
  bool canConstruct(std::string ransomNote, std::string magazine) {
    std::unordered_map<char, int> magazine_map;

    for(const auto& c : magazine) ++magazine_map[c];

    for(const auto& c : ransomNote) {
      if(magazine_map[c] > 0) {
        --magazine_map[c];
      } else {
        return false;
      }
    }

    return true;
  }
};