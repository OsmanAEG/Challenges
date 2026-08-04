// Project Euler: 31
// Coin Sums

#include <iostream>
#include <map>
#include <set>
#include <vector>

using Int_T = unsigned long long;
using Vec_T = std::vector<Int_T>;
using Map_T = std::map<Int_T, Int_T>;
using Set_T = std::set<Map_T>;

void find_combos(const Vec_T& options, Set_T& combos, Map_T map, Int_T sum, Int_T idx) {
  if(sum > 200) {
    return;
  } else if(sum == 200) {
    combos.insert(map);
    return;
  } else {
    for(int i = idx; i < options.size(); ++i) {
      const auto option_i = options[i];
      auto map_i = map;

      map_i[option_i] += 1;

      find_combos(options, combos, map_i, sum + option_i, i);
    }
  }
}

int main() {
  const Vec_T coins = {1, 2, 5, 10, 20, 50, 100, 200};
  Set_T combos;
  Map_T empty_map;

  find_combos(coins, combos, empty_map, 0, 0);

  std::cout << combos.size() << std::endl;

  return 0;
}