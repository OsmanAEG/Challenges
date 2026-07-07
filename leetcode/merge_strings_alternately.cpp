// LeetCode: 1768
// Marge Strings Alternately

#include <string>

class Solution {
public:
  std::string mergeAlternately(std::string word1, std::string word2) {
    int i = 0;

    std::string merged = "";

    while(i < word1.size()) {
      merged += word1[i];
      if(i < word2.size()) merged += word2[i];
      ++i;
    }

    while(i < word2.size()) {
      merged += word2[i];
      ++i;
    }

    return merged;
  }
};