// Project Euler: 205
// Dice Game

#include "helper.h"

using Int_T = unsigned long long;
using Scalar_T = double;

std::vector<Int_T> get_dice_ways(Int_T num_dice, Int_T num_sides) {
  std::vector<Int_T> ways(num_dice*num_sides + 1, 0);

  ways[0] = 1;

  for(Int_T n = 0; n < num_dice; ++n) {
    std::vector<Int_T> next_ways(ways.size(), 0);

    for(Int_T total = 0; total <= n*num_sides; ++total) {
      for(Int_T face = 1; face <= num_sides; ++face) {
        next_ways[total + face] += ways[total];
      }
    }

    ways = next_ways;
  }

  return ways;
}

int main() {
  const Int_T n_peter = 9;
  const Int_T n_colin = 6;

  const auto peter_ways = get_dice_ways(n_peter, 4);
  const auto colin_ways = get_dice_ways(n_colin, 6);

  Int_T win_peter = 0;

  for(Int_T p = 0; p < peter_ways.size(); ++p) {
    for(Int_T c = 0; c < colin_ways.size(); ++c) {
      if(p > c) win_peter += peter_ways[p]*colin_ways[c];
    }
  }

  const Int_T total_peter = std::accumulate(peter_ways.begin(), peter_ways.end(), Int_T{0});

  const Int_T total_colin = std::accumulate(colin_ways.begin(), colin_ways.end(), Int_T{0});

  const Int_T total_outcomes = total_peter*total_colin;

  const auto result = static_cast<Scalar_T>(win_peter)/static_cast<Scalar_T>(total_outcomes);

  std::cout << std::fixed << std::setprecision(7);
  std::cout << result << std::endl;

  return 0;
}