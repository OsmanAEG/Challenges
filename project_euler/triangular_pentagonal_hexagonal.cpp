// Project Euler: 45
// Triangular Pentagonal Hexagonal

#include "helper.h"

using Int_T = unsigned long long;

int main() {
  Int_T t = 285;
  Int_T p = 165;
  Int_T h = 143;

  Int_T t_num = 0;
  Int_T p_num = 0;
  Int_T h_num = 0;

  bool found = false;

  while(!found) {
    ++t;
    t_num = get_triangle_number(t);

    while(p_num < t_num) {
      ++p;
      p_num = get_pentagon_number(p);
    }

    while(h_num < t_num) {
      ++h;
      h_num = get_hexagon_number(h);
    }

    if(t_num == p_num && h_num == t_num) {
      found = true;
      break;
    }
  }

  std::cout << t_num << std::endl;
}