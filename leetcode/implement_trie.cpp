// LeetCode: 208
// Implement Trie

#include <string>
#include <unordered_map>
#include <vector>

struct TrieNode {
  char val;
  bool is_word = false;
  std::unordered_map<char, int> node_indices;
  std::vector<TrieNode*> nodes;

  TrieNode(char x) : val(x) {}
};

class Trie {
public:
  std::unordered_map<char, int> node_indices;
  std::vector<TrieNode*> nodes;

  Trie() {}

  void insert(std::string word) {
    TrieNode* check;

    char c = word[0];

    if(node_indices.find(c) == node_indices.end()) {
      nodes.emplace_back(new TrieNode(c));
      node_indices[c] = nodes.size() - 1;
    }

    check = nodes[node_indices[c]];

    for(int i = 1; i < word.size(); ++i) {
      c = word[i];

      if(check->node_indices.find(c) == check->node_indices.end()) {
        check->nodes.emplace_back(new TrieNode(c));
        check->node_indices[c] = check->nodes.size() - 1;
      }

      check = check->nodes[check->node_indices[c]];
    }

    check->is_word = true;
  }

  bool search(std::string word) {
    TrieNode* check;

    char c = word[0];

    if(node_indices.find(c) == node_indices.end()) {
      return false;
    }

    check = nodes[node_indices[c]];

    for(int i = 1; i < word.size(); ++i) {
      c = word[i];

      if(check->node_indices.find(c) == check->node_indices.end()) {
        return false;
      }

      check = check->nodes[check->node_indices[c]];
    }

    return check->is_word;
  }

  bool startsWith(std::string prefix) {
    TrieNode* check;

    char c = prefix[0];

    if(node_indices.find(c) == node_indices.end()) {
      return false;
    }

    check = nodes[node_indices[c]];

    for(int i = 1; i < prefix.size(); ++i) {
      c = prefix[i];

      if(check->node_indices.find(c) == check->node_indices.end()) {
        return false;
      }

      check = check->nodes[check->node_indices[c]];
    }

    return true;
  }
};