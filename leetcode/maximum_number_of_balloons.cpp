// LeetCode: 1189
// Maximum Number of Balloons

#include <string>
#include <unordered_map>
#include <vector>

class Solution {
public:
  int maxNumberOfBalloons(std::string text) {
    std::unordered_map<char, int> text_map;
    std::vector<char> balloon = {'b', 'a', 'l', 'l', 'o', 'o', 'n'};

    int num = 0;

    for(const auto& c : text) {
      text_map[c] += 1;
    }

    bool remainder = true;

    while(remainder) {
      for(const auto& c : balloon) {
        if(text_map[c] == 0) remainder = false;
        else --text_map[c];
      }

      if(remainder) num += 1;
    }

    return num;
  }
};