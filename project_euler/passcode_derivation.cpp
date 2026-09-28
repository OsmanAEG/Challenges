// Project Euler: 79
// Passcode Derivation

#include "helper.h"

using Int_T = unsigned long long;
using String_T = std::string;

int main() {
  const String_T filename = "passcode_derivation_input.txt";
  const auto input = get_input(filename);

  std::unordered_map<char, std::unordered_set<char>> befores;
  std::unordered_map<char, std::unordered_set<char>> afters;

  for(const auto& passcode : input) {
    for(Int_T i = 0; i < passcode.size(); ++i) {
      const auto num_i = passcode[i];

      befores.try_emplace(num_i);

      for(Int_T j = 0; j < i; ++j) {
        const auto num_j = passcode[j];
        befores[num_i].insert(num_j);
      }

      for(Int_T j = i + 1; j < passcode.size(); ++j) {
        const auto num_j = passcode[j];
        afters[num_i].insert(num_j);
      }
    }
  }

  String_T result;

  while(!befores.empty()) {
    auto next = befores.end();

    for(auto it = befores.begin(); it != befores.end(); ++it) {
      if(it->second.empty()) {
        next = it;
        break;
      }
    }

    const char digit = next->first;
    result += digit;
    befores.erase(next);

    for(const char after : afters[digit]) befores[after].erase(digit);
  }

  std::cout << result << '\n';

  return 0;
}