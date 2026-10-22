// LeetCode: 853
// Car Fleet

#include <algorithm>
#include <stack>
#include <vector>

class Solution {
public:
  struct Car {
    int position;
    int speed;

    Car(int position_in, int speed_in) : position(position_in), speed(speed_in) {}

    auto operator<=>(const Car&) const = default;
  };

  int carFleet(int target, std::vector<int>& position, std::vector<int>& speed) {
    std::stack<Car> fleets;
    std::vector<Car> cars;

    for(int i = 0; i < position.size(); ++i) {
      const Car car_i = Car(position[i], speed[i]);
      cars.push_back(car_i);
    }

    std::sort(cars.rbegin(), cars.rend());

    fleets.push(cars[0]);

    for(int i = 1; i < cars.size(); ++i) {
      const auto lead = fleets.top();
      const auto curr = cars[i];

      if(lead.speed > curr.speed) {
        fleets.push(curr);
      } else {
        const double lead_time = static_cast<double>(target - lead.position)/static_cast<double>(lead.speed);
        const double curr_time = static_cast<double>(target - curr.position)/static_cast<double>(curr.speed);

        if(curr_time > lead_time) fleets.push(curr);
      }
    }

    return fleets.size();
  }
};