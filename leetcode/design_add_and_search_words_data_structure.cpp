// LeetCode: 211
// Design Add and Search Words Data Structure

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

class WordDictionary {
public:
  std::unordered_map<char, int> node_indices;
  std::vector<TrieNode*> nodes;

  WordDictionary() {}

  void addWord(std::string word) {
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

  bool search_recursive(TrieNode* check, std::string& word, int idx) {
    if(idx == word.size()) return check->is_word;

    char c = word[idx];

    if(c == '.') {
      for(auto node : check->nodes) {
        if(search_recursive(node, word, idx + 1)) return true;
      }

      return false;
    }

    if(check->node_indices.find(c) == check->node_indices.end()) {
      return false;
    }

    check = check->nodes[check->node_indices[c]];

    return search_recursive(check, word, idx + 1);
  }

  bool search(std::string word) {
    TrieNode* check;

    char c = word[0];

    if(c == '.') {
      for(auto node : nodes) {
        if(search_recursive(node, word, 1)) return true;
      }

      return false;
    }

    if(node_indices.find(c) == node_indices.end()) {
      return false;
    }

    check = nodes[node_indices[c]];

    return search_recursive(check, word, 1);
  }
};