// Project Euler: 66
// Diophantine Equation

#include "helper.h"

using Int_T = boost::multiprecision::cpp_int;

int main() {
  const Int_T D_max = 1000;

  Int_T max_x = 0;
  Int_T max_D = 0;

  for(Int_T D = 2; D <= D_max; ++D) {
    const Int_T a0 = static_cast<Int_T>(boost::multiprecision::sqrt(D));

    if(a0*a0 == D) continue;

    Int_T m = 0;
    Int_T d = 1;
    Int_T a = a0;

    Int_T x_prev2 = 0;
    Int_T x_prev1 = 1;
    Int_T y_prev2 = 1;
    Int_T y_prev1 = 0;

    while(true) {
      const Int_T x = a*x_prev1 + x_prev2;
      const Int_T y = a*y_prev1 + y_prev2;

      const Int_T num = x*x - D*y*y;

      if(num == 1) {

        if(x > max_x) {
          max_x = x;
          max_D = D;
        }

        break;
      }

      x_prev2 = x_prev1;
      x_prev1 = x;
      y_prev2 = y_prev1;
      y_prev1 = y;

      m = d*a - m;
      d = (D - m*m)/d;
      a = (a0 + m)/d;
    }
  }

  std::cout << max_D << std::endl;

  return 0;
}