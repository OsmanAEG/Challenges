// Project Euler: 84
// Monopoly Odds

#include "helper.h"

using Int_T = unsigned long long;
using Scalar_T = double;
using String_T = std::string;

int main() {
  const Int_T num_turns = 10000000;
  const Int_T num_pos = 40;

  std::vector<Int_T> map_visits(num_pos, 0);

  std::random_device random_device;
  std::mt19937 generate(random_device());

  std::uniform_int_distribution<> dist(1, 4);

  std::array<int, 16> cc_cards;
  std::array<int, 16> ch_cards;

  for(int i = 0; i < 16; ++i) {
    cc_cards[i] = i;
    ch_cards[i] = i;
  }

  std::shuffle(cc_cards.begin(), cc_cards.end(), generate);
  std::shuffle(ch_cards.begin(), ch_cards.end(), generate);

  Int_T cc_idx = 0;
  Int_T ch_idx = 0;

  Int_T position = 0;
  Int_T num_doubles = 0;

  for(Int_T turn = 0; turn < num_turns; ++turn) {
    const auto dice_1 = dist(generate);
    const auto dice_2 = dist(generate);

    const auto roll = dice_1 + dice_2;

    if(dice_1 == dice_2) ++num_doubles;
    else num_doubles = 0;

    if(num_doubles == 3) {
      position = 10;
      num_doubles = 0;

      ++map_visits[position];

      continue;
    }

    position = (position + roll) % num_pos;

    bool sent_to_jail = false;

    if(position == 30) {
      position = 10;
      sent_to_jail = true;
    } else if(position == 2 || position == 17 || position == 33) {
      const int card = cc_cards[cc_idx];

      cc_idx = (cc_idx + 1) % 16;

      if(card == 0) {
        position = 0;
      } else if(card == 1) {
        position = 10;
        sent_to_jail = true;
      }
    } else if(position == 7 || position == 22 || position == 36) {
      const int card = ch_cards[ch_idx];

      ch_idx = (ch_idx + 1) % 16;

      if(card == 0) {
        position = 0;
      } else if(card == 1) {
        position = 10;
        sent_to_jail = true;
      } else if(card == 2) {
        position = 11;
      } else if(card == 3) {
        position = 24;
      } else if(card == 4) {
        position = 39;
      } else if(card == 5) {
        position = 5;
      } else if(card == 6 || card == 7) {
        if(position == 7) {
          position = 15;
        } else if(position == 22) {
          position = 25;
        } else {
          position = 5;
        }
      } else if(card == 8) {
        if(position == 7) {
          position = 12;
        } else if(position == 22) {
          position = 28;
        } else {
          position = 12;
        }
      } else if(card == 9) {
        position = (position + num_pos - 3) % num_pos;
        if(position == 33) {
          const int cc_card = cc_cards[cc_idx];

          cc_idx = (cc_idx + 1) % 16;

          if(cc_card == 0) {
            position = 0;
          } else if(cc_card == 1) {
            position = 10;
            sent_to_jail = true;
          }
        }
      }
    }

    if(sent_to_jail) num_doubles = 0;
    ++map_visits[position];
  }

  std::vector<Int_T> indices(num_pos);

  for(Int_T i = 0; i < num_pos; ++i) indices[i] = i;

  std::sort(indices.begin(),indices.end(),
    [&map_visits](const Int_T a, const Int_T b) {
      return map_visits[a] > map_visits[b];
    }
  );

  for(Int_T i = 0; i < num_pos; ++i) {
    const Scalar_T probability = static_cast<Scalar_T>(map_visits[i]) / static_cast<Scalar_T>(num_turns);

    std::cout << i << ": " << probability * 100.0 << "%" << std::endl;
  }

  std::cout << "\nTop three squares:\n";

  for(Int_T i = 0; i < 3; ++i) {
    std::cout << indices[i] << " : " << map_visits[indices[i]] << std::endl;
  }

  std::cout << "\nModal string: ";

  for(Int_T i = 0; i < 3; ++i) {
    if(indices[i] < 10) std::cout << '0';

    std::cout << indices[i];
  }

  std::cout << std::endl;

  return 0;
}