// Project Euler: 9
// Special Pythagorean Triplet

#include <iostream>

template<typename Int_T>
bool is_pythagorean_triplet(Int_T a, Int_T b, Int_T c) {
  if(a >= b) return false;
  if(b >= c) return false;

  if(a*a + b*b != c*c) return false;

  return true;
}

int main() {
  using Int_T = unsigned long long;
  Int_T num = 1000;

  bool found_triplet = false;
  Int_T triplet_prod = 0;

  for(int a = 1; a <= num - 2; ++a) {
    for(int b = a + 1; b <= num - 1; ++b) {
      for(int c = b + 1; c <= num; ++c) {
        if(is_pythagorean_triplet(a, b, c) && a + b + c == num) {
          triplet_prod = a*b*c;
          found_triplet = true;
          break;
        }
      }

      if(found_triplet == true) break;
    }

    if(found_triplet == true) break;
  }

  std::cout << triplet_prod << std::endl;

  return 0;
}