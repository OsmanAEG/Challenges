// Project Euler: 28
// Number Spirals Diagonals

#include <iostream>
#include <vector>

using Int_T = unsigned long long;

int main() {
  Int_T n = 1001;
  std::pair<Int_T, Int_T> pos = {n/2, n/2};
  Int_T steps = 1;
  int dir = 1;

  Int_T x_stretch = 1;
  Int_T y_stretch = 1;

  Int_T sum = 1;

  while(steps < n*n) {
    Int_T x_steps = 0;
    Int_T y_steps = 0;

    // horizontal
    while(x_steps < x_stretch && steps < n*n) {
      pos.first += dir;

      ++steps;
      ++x_steps;

      if(pos.first == pos.second || pos.first + pos.second == n - 1) sum += steps;
    }

    x_steps = 0;
    ++x_stretch;

    // vertical
    while(y_steps < y_stretch && steps < n*n) {
      pos.second += dir;

      ++steps;
      ++y_steps;

      if(pos.first == pos.second || pos.first + pos.second == n - 1) sum += steps;
    }

    y_steps = 0;
    ++y_stretch;

    dir *= -1;
  }

  std::cout << sum << std::endl;
}