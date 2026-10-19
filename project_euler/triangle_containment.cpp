// Project Euler: 102
// Triangle Containement

#include "helper.h"

using Int_T = long long;
using String_T = std::string;

bool has_origin(const std::vector<Int_T>& coords) {
  const Int_T x1 = coords[0];
  const Int_T y1 = coords[1];

  const Int_T x2 = coords[2];
  const Int_T y2 = coords[3];

  const Int_T x3 = coords[4];
  const Int_T y3 = coords[5];

  const Int_T c1 = x1*y2 - y1*x2;
  const Int_T c2 = x2*y3 - y2*x3;
  const Int_T c3 = x3*y1 - y3*x1;

  if((c1 > 0 && c2 > 0 && c3 > 0)) return true;
  if((c1 < 0 && c2 < 0 && c3 < 0)) return true;

  return false;
}

int main() {
  Int_T num_origin = 0;
  const String_T filename = "triangle_containment_input.txt";
  const auto input = get_input(filename);

  for(const auto& line : input) {
    std::vector<Int_T> coords;
    String_T num_str = "";

    for(const auto& c : line) {
      if(c == ',') {
        coords.push_back(std::stoll(num_str));
        num_str = "";
      } else {
        num_str += c;
      }
    }

    coords.push_back(std::stoll(num_str));

    if(has_origin(coords)) ++num_origin;
  }

  std::cout << num_origin << std::endl;

  return 0;
}