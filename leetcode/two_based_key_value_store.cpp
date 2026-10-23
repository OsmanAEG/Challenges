// LeetCode: 981
// Time Based Key Value Store

#include <string>
#include <unordered_map>
#include <vector>

class TimeMap {
public:
  using String_T = std::string;
  using Vector_T = std::vector<std::pair<int, String_T>>;
  using Map_T = std::unordered_map<String_T, Vector_T>;

  Map_T dictionary;

  TimeMap() {}

  void set(std::string key, std::string value, int timestamp) {
    dictionary[key].push_back({timestamp, value});
  }

  std::string get(std::string key, int timestamp) {
    const auto it = dictionary.find(key);

    if(it == dictionary.end()) return "";

    const auto& vec = it->second;

    int low = 0;
    int high = vec.size() - 1;

    while(low <= high) {
      const auto mid = (low + high)/2;

      if(timestamp < vec[mid].first) {
        high = mid - 1;
      } else if(timestamp > vec[mid].first) {
        low = mid + 1;
      } else {
        return vec[mid].second;
      }
    }

    if(high < 0) return "";

    return vec[high].second;
  }
};
