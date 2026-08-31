// Project Euler: 54
// Poker Hands

#include "helper.h"

using Int_T = unsigned long long;
using String_T = std::string;

class Hand {
public:
  Hand(const std::vector<String_T>& cards_in) : cards(cards_in) {}

  std::strong_ordering operator<=>(const Hand& other) const {

    const auto lhs = evaluate();
    const auto rhs = other.evaluate();

    if(lhs.category != rhs.category) return lhs.category <=> rhs.category;

    return lhs.values <=> rhs.values;
  }

  bool operator==(const Hand& other) const { return evaluate() == other.evaluate(); }

private:
  struct Hand_Value {
    int category;
    std::vector<int> values;

    auto operator<=>(const Hand_Value&) const = default;
  };

  std::vector<String_T> cards;

  int card_value(char card) const {

    if(card >= '2' && card <= '9') return card - '0';

    if(card == 'T') return 10;
    else if(card == 'J') return 11;
    else if(card == 'Q') return 12;
    else if(card == 'K') return 13;
    else return 14;
  }

  Hand_Value evaluate() const {
    std::vector<int> values;

    for(const auto& card : cards) values.push_back(card_value(card[0]));
    std::sort(values.rbegin(), values.rend());

    std::map<int, int> counts;

    for(const auto value : values) ++counts[value];

    // check flush
    bool flush = true;

    for(Int_T i = 1; i < cards.size(); ++i) {
      if(cards[i][1] != cards[0][1]) {
        flush = false;
      }
    }

    // check straight
    bool straight = true;

    for(Int_T i = 1; i < values.size(); ++i) {

      if(values[i - 1] - 1 != values[i]) {
        straight = false;
      }
    }

    // ace special case for straight
    if(values == std::vector<int>{14, 5, 4, 3, 2}) {
      straight = true;
      values = {5, 4, 3, 2, 1};
    }

    // one, two, three, and four of a kind
    std::vector<int> pairs;

    std::vector<int> singles;

    int three = 0;

    int four = 0;

    for(auto it = counts.rbegin(); it != counts.rend(); ++it) {
      const int value = it->first;
      const int count = it->second;

      if(count == 4) four = value;
      else if(count == 3) three = value;
      else if(count == 2) pairs.push_back(value);
      else singles.push_back(value);
    }

    // straight and flush
    if(straight && flush) return {8, {values[0]}};

    // four of a kind
    if(four != 0) return {7, {four, singles[0]}};

    // full house
    if(three != 0 && pairs.size() == 1) return {6, {three, pairs[0]}};

    // flush
    if(flush) return {5, values};

    // straight
    if(straight) return {4, {values[0]}};

    // three of a kind
    if(three != 0) return {3, {three, singles[0], singles[1]}};

    // two two of a kind
    if(pairs.size() == 2) {return {2,{pairs[0], pairs[1], singles[0]}};}

    // one two of a kind
    if(pairs.size() == 1) {return {1,{pairs[0], singles[0], singles[1], singles[2]}};}

    // single card value
    return {0, values};
  }
};

int main() {
  const String_T filename = "poker_hands_input.txt";
  const auto input = get_input(filename);

  Int_T player_1_wins = 0;

  for(const auto& line : input) {
    std::vector<String_T> player_1_hand;
    std::vector<String_T> player_2_hand;

    String_T card = "";

    for(const auto& c : line) {
      if(c == ' ' && player_1_hand.size() < 5) {
        player_1_hand.push_back(card);
        card = "";
      } else if(c == ' ' && player_1_hand.size() >= 5) {
        player_2_hand.push_back(card);
        card = "";
      } else {
        card += c;
      }
    }

    player_2_hand.push_back(card);

    const auto hand_1 = Hand(player_1_hand);
    const auto hand_2 = Hand(player_2_hand);

    if(hand_1 > hand_2) ++player_1_wins;
  }

  std::cout << player_1_wins << std::endl;

  return 0;
}