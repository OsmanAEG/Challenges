// LeetCode: 133
// Clone Graph

#include <unordered_map>
#include <vector>

// Definition for a Node.
class Node {
public:
  int val;
  std::vector<Node*> neighbors;

  Node() {
    val = 0;
    neighbors = std::vector<Node*>();
  }

  Node(int _val) {
    val = _val;
    neighbors = std::vector<Node*>();
  }

  Node(int _val, std::vector<Node*> _neighbors) {
    val = _val;
    neighbors = _neighbors;
  }
};

class Solution {
public:
  using Map_T = std::unordered_map<Node*, Node*>;

  Map_T cloned;

  void dfs(Node* node) {
    if(cloned.find(node) != cloned.end()) return;

    Node* new_node = new Node(node->val);
    cloned[node] = new_node;

    for(Node* neighbor : node->neighbors) {
      dfs(neighbor);
      new_node->neighbors.push_back(cloned[neighbor]);
    }
  }

  Node* cloneGraph(Node* node) {
    if(node == nullptr) return nullptr;

    dfs(node);

    return cloned[node];
  }
};