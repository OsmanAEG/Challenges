// LeetCode: 271
// Encode and Decode Strings

#include<string>
#include<vector>

class Solution {
public:
  std::string encode(std::vector<std::string>& strs) {
    std::string encoded_str = "";

    for(const auto& str : strs) {
      encoded_str += str;
      encoded_str += ';';
    }

    return encoded_str;
  }

  std::vector<std::string> decode(std::string s) {
    std::vector<std::string> decoded_strs;
    std::string temp_str = "";

    for(const auto& c : s) {
      if(c == ';') {
        decoded_strs.push_back(temp_str);
        temp_str = "";
      } else {
        temp_str += c;
      }
    }

    return decoded_strs;
  }
};