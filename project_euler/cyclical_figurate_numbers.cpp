// Project Euler: 61
// Cyclical Figurate Numbers

#include "helper.h"

using Int_T = unsigned long long;

bool is_cyclic(const Int_T a, const Int_T b) {
  const auto a_str = std::to_string(a);
  const auto b_str = std::to_string(b);

  if(a_str[2] != b_str[0] || a_str[3] != b_str[1]) return false;

  return true;
}

int main() {
  Int_T result = 0;

  const Int_T N_min = 1000;
  const Int_T N_max = 10000;

  std::unordered_set<Int_T> triangle_set;
  std::unordered_set<Int_T> square_set;
  std::unordered_set<Int_T> pentagon_set;
  std::unordered_set<Int_T> hexagon_set;
  std::unordered_set<Int_T> heptagon_set;
  std::unordered_set<Int_T> octagon_set;

  Int_T n = 1;

  // triangle set
  while(true) {
    const auto tn = get_triangle_number(n);

    if(tn >= N_max) break;
    if(tn >= N_min) triangle_set.insert(tn);

    ++n;
  }

  // square set
  n = 1;

  while(true) {
    const auto sn = get_square_number(n);

    if(sn >= N_max) break;
    if(sn >= N_min) square_set.insert(sn);

    ++n;
  }

  // pentagon set
  n = 1;

  while(true) {
    const auto pn = get_pentagon_number(n);

    if(pn >= N_max) break;
    if(pn >= N_min) pentagon_set.insert(pn);

    ++n;
  }

  // hexagon set
  n = 1;

  while(true) {
    const auto hn = get_hexagon_number(n);

    if(hn >= N_max) break;
    if(hn >= N_min) hexagon_set.insert(hn);

    ++n;
  }

  // heptagon set
  n = 1;

  while(true) {
    const auto hn = get_heptagon_number(n);

    if(hn >= N_max) break;
    if(hn >= N_min) heptagon_set.insert(hn);

    ++n;
  }

  // octagon set
  n = 1;

  while(true) {
    const auto on = get_octagon_number(n);

    if(on >= N_max) break;
    if(on >= N_min) octagon_set.insert(on);

    ++n;
  }

  const std::array<const std::unordered_set<Int_T>*, 6> polygonal_sets{
      &triangle_set,
      &square_set,
      &pentagon_set,
      &hexagon_set,
      &heptagon_set,
      &octagon_set
  };

  std::array<std::size_t, 5> order{1, 2, 3, 4, 5};

  bool result_found = false;

  while(!result_found) {
    for(const Int_T a : *polygonal_sets[0]) {
      for(const Int_T b : *polygonal_sets[order[0]]) {
        if(b == a || !is_cyclic(a, b)) continue;

        for(const Int_T c : *polygonal_sets[order[1]]) {
          if(c == a || c == b || !is_cyclic(b, c)) continue;

          for(const Int_T d : *polygonal_sets[order[2]]) {
            if(d == a || d == b || d == c || !is_cyclic(c, d)) continue;

            for(const Int_T e : *polygonal_sets[order[3]]) {
              if(e == a || e == b || e == c || e == d || !is_cyclic(d, e)) continue;

              for(const Int_T f : *polygonal_sets[order[4]]) {
                if(f == a || f == b || f == c || f == d || f == e) continue;

                if(!is_cyclic(e, f)) continue;
                if(!is_cyclic(f, a)) continue;

                result = a + b + c + d + e + f;
                result_found = true;
              }

              if(result_found) break;
            }

            if(result_found) break;
          }

          if(result_found) break;
        }

        if(result_found) break;
      }

      if(result_found) break;
    }

    if(result_found) break;

    std::next_permutation(order.begin(), order.end());
  }

  std::cout << result << std::endl;

  return 0;
}