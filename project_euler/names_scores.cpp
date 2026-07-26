// Project Euler: 22
// Names Scores

#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using Int_T = unsigned long long;
using String_T = std::string;

std::vector<String_T> get_input() {
  std::ifstream file("names_scores_input.txt");
  std::vector<String_T> names;
  String_T name;

  while(std::getline(file, name, ',')) {
    name.erase(name.begin());
    name.pop_back();

    names.push_back(name);
  }

  return names;
}

Int_T alpha_rank(char letter) {
  Int_T rank = 0;

  if(letter == 'A') rank = 1;
  else if(letter == 'B') rank = 2;
  else if(letter == 'C') rank = 3;
  else if(letter == 'D') rank = 4;
  else if(letter == 'E') rank = 5;
  else if(letter == 'F') rank = 6;
  else if(letter == 'G') rank = 7;
  else if(letter == 'H') rank = 8;
  else if(letter == 'I') rank = 9;
  else if(letter == 'J') rank = 10;
  else if(letter == 'K') rank = 11;
  else if(letter == 'L') rank = 12;
  else if(letter == 'M') rank = 13;
  else if(letter == 'N') rank = 14;
  else if(letter == 'O') rank = 15;
  else if(letter == 'P') rank = 16;
  else if(letter == 'Q') rank = 17;
  else if(letter == 'R') rank = 18;
  else if(letter == 'S') rank = 19;
  else if(letter == 'T') rank = 20;
  else if(letter == 'U') rank = 21;
  else if(letter == 'V') rank = 22;
  else if(letter == 'W') rank = 23;
  else if(letter == 'X') rank = 24;
  else if(letter == 'Y') rank = 25;
  else if(letter == 'Z') rank = 26;

  return rank;
}

int main() {
  auto names = get_input();

  std::sort(names.begin(), names.end());

  Int_T score = 0;
  Int_T idx = 1;

  for(const auto& name : names) {
    Int_T name_rank = 0;

    for(const auto& letter : name) {
      name_rank += alpha_rank(letter);
    }

    score += idx*name_rank;
    ++idx;
  }

  std::cout << score << std::endl;

  return 0;
}