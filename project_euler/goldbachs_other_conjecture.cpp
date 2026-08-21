// Project Euler: 46
// Goldbachs Other Conjecture

#include "helper.h"

using Int_T = unsigned long long;

int main() {
  Int_T num = 2;
  bool found = false;

  while(!found) {
    if(!is_prime(num) && num%2 != 0) {
      bool meets_conjecture = false;

      for(Int_T p = 2; p < num; ++p) {
        if(is_prime(p)) {
          for(Int_T n = 1; n < num; ++n) {
            if(p + 2*n*n == num) meets_conjecture = true;
          }
        }
      }

      if(meets_conjecture != true) {
        found = true;
        break;
      }
    }

    if(found == false) ++num;
  }

  std::cout << num << std::endl;

  return 0;
}