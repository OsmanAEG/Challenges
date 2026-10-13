// Project Euler: 91
// Right Triangles with Integer Coordinates

#include "helper.h"

using Int_T = long long;
using Vector_T = std::vector<Int_T>;

bool is_right_triangle(const Vector_T& pt1, const Vector_T& pt2) {
  const Int_T x1 = pt1[0];
  const Int_T y1 = pt1[1];

  const Int_T x2 = pt2[0];
  const Int_T y2 = pt2[1];

  if(x1 == 0 && y1 == 0) return false;
  if(x2 == 0 && y2 == 0) return false;
  if(pt1 == pt2) return false;

  const Int_T side0 = x1*x1 + y1*y1;
  const Int_T side1 = x2*x2 + y2*y2;
  const Int_T side2 = (x2-x1)*(x2-x1) + (y2-y1)*(y2-y1);

  std::vector<Int_T> triangle_sides = {side0, side1, side2};
  std::sort(triangle_sides.begin(), triangle_sides.end());

  const auto a = triangle_sides[0];
  const auto b = triangle_sides[1];
  const auto c = triangle_sides[2];

  return (a + b == c);
}

int main() {
  const Int_T N = 50;

  Int_T count = 0;

  for(Int_T x1 = 0; x1 <= N; ++x1) {
    for(Int_T y1 = 0; y1 <= N; ++y1) {
      for(Int_T x2 = x1; x2 <= N; ++x2) {
        for(Int_T y2 = 0; y2 <= N; ++y2) {
          if(x1 == x2 && y2 <= y1) continue;
          if(is_right_triangle({x1, y1}, {x2, y2})) ++count;
        }
      }
    }
  }

  std::cout << count << std::endl;

  return 0;
}