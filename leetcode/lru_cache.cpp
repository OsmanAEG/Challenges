// LeetCode: 146
// LRU Cache

#include <list>
#include <unordered_map>
#include <utility>

class LRUCache {
public:
  using Node_T = std::pair<int, int>;
  using List_T = std::list<Node_T>;
  using It_T   = List_T::iterator;
  using Map_T  = std::unordered_map<int, It_T>;

  int capacity;

  List_T cache;
  Map_T lookup;

  LRUCache(int capacity_in) {
    capacity = capacity_in;
  }

  int get(int key) {
    auto it = lookup.find(key);
    if(it == lookup.end()) return -1;
    cache.splice(cache.begin(), cache, it->second);

    return it->second->second;
  }

  void put(int key, int value) {
    auto it = lookup.find(key);

    if(it != lookup.end()) {
      it->second->second = value;
      cache.splice(cache.begin(), cache, it->second);
      return;
    }

    if(cache.size() == capacity) {
      int old_key = cache.back().first;
      lookup.erase(old_key);
      cache.pop_back();
    }

    cache.push_front({key, value});
    lookup[key] = cache.begin();
  }
};