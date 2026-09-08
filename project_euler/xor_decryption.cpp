// Project Euler: 59
// XOR Decryption

#include "helper.h"

using Int_T = unsigned long long;

int english_score(const std::string& text) {
  for(const unsigned char c : text) {
    if(c != '\n' && (c < 32 || c > 126)) return -1;
  }

  int score = 0;

  const std::vector<std::string> common_words = {"the", "and", "of", "to", "in", "is", "that"};

  for(const auto& word : common_words) {
    std::size_t pos = 0;

    while((pos = text.find(word, pos)) != std::string::npos) {
      ++score;
      pos += word.size();
    }
  }

  return score;
}

int main() {
  const std::string filename = "xor_decryption_input.txt";
  const auto input = get_input(filename)[0];

  std::vector<Int_T> nums;
  std::string num_str;

  for(const auto& c : input) {
    if(c == ',') {
      nums.push_back(std::stoull(num_str));
      num_str = "";
    } else {
      num_str += c;
    }
  }

  nums.push_back(std::stoull(num_str));

  int best_score = std::numeric_limits<int>::min();
  std::string best_text;
  std::array<char, 3> best_key{};

  for(char a = 'a'; a <= 'z'; ++a) {
    for(char b = 'a'; b <= 'z'; ++b) {
      for(char c = 'a'; c <= 'z'; ++c) {
        const std::array<char, 3> key = {a, b, c};
        std::string decrypted_text;

        for(std::size_t i = 0; i < nums.size(); ++i) {
          const auto decrypted_character = static_cast<char>(nums[i] ^ key[i % 3]);
          decrypted_text += decrypted_character;
        }

        const int score = english_score(decrypted_text);

        if(score > best_score) {
          best_score = score;
          best_text = decrypted_text;
          best_key = key;
        }
      }
    }
  }

  std::cout << "Key: " << best_key[0] << best_key[1] << best_key[2] << "\n" << std::endl;
  std::cout << best_text << "\n" << std::endl;

  Int_T ascii_sum = 0;

  for(const unsigned char c : best_text) ascii_sum += c;

  std::cout << "ASCII sum: " << ascii_sum << '\n';

  return 0;
}