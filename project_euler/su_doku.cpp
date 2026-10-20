// Project Euler: 96
// Su Doku

#include "helper.h"

using Int_T = unsigned long long;
using Vector_T = std::vector<char>;
using Grid_T = std::vector<std::vector<char>>;
using String_T = std::string;

struct Sudoku_Grid {
  Grid_T puzzle;

  Sudoku_Grid(Grid_T puzzle_in) : puzzle(puzzle_in) {}

  Vector_T row(Int_T i) const {
    Vector_T row_i;

    for(Int_T j = 0; j < puzzle[i].size(); ++j) {
      if(puzzle[i][j] != '0') row_i.push_back(puzzle[i][j]);
    }

    return row_i;
  }

  Vector_T col(Int_T j) const {
    Vector_T col_j;

    for(Int_T i = 0; i < puzzle.size(); ++i) {
      if(puzzle[i][j] != '0') col_j.push_back(puzzle[i][j]);
    }

    return col_j;
  }

  Vector_T block(Int_T i_in, Int_T j_in) const {
    Vector_T block_ij;

    Int_T i_min;
    Int_T i_max;

    Int_T j_min;
    Int_T j_max;

    if(i_in <= 2) {
      i_min = 0;
      i_max = 2;
    } else if(i_in <= 5) {
      i_min = 3;
      i_max = 5;
    } else {
      i_min = 6;
      i_max = 8;
    }

    if(j_in <= 2) {
      j_min = 0;
      j_max = 2;
    } else if(j_in <= 5) {
      j_min = 3;
      j_max = 5;
    } else {
      j_min = 6;
      j_max = 8;
    }

    for(Int_T i = i_min; i <= i_max; ++i) {
      for(Int_T j = j_min; j <= j_max; ++j) {
        if(puzzle[i][j] != '0') block_ij.push_back(puzzle[i][j]);
      }
    }

    return block_ij;
  }
};

struct Sudoku_Position {
  Sudoku_Grid& grid;
  Int_T i;
  Int_T j;

  std::unordered_set<char> taken;

  Vector_T options = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};

  Sudoku_Position(Sudoku_Grid& grid_in, Int_T i_in, Int_T j_in)
    : grid(grid_in), i(i_in), j(j_in) {
      const auto row = grid.row(i);
      const auto col = grid.col(j);
      const auto block = grid.block(i, j);

      for(const auto& num : row) taken.insert(num);
      for(const auto& num : col) taken.insert(num);
      for(const auto& num : block) taken.insert(num);

      for(const auto& num : taken) {
        options.erase(std::remove(options.begin(), options.end(), num), options.end());
      }
    }
};

bool solve(Sudoku_Grid& grid) {
  bool found_empty = false;

  Int_T best_i = 0;
  Int_T best_j = 0;

  Vector_T best_options;

  for(Int_T i = 0; i < grid.puzzle.size(); ++i) {
    for(Int_T j = 0; j < grid.puzzle[i].size(); ++j) {
      if(grid.puzzle[i][j] != '0') continue;

      const Sudoku_Position position(grid, i, j);

      if(position.options.empty()) return false;

      if(!found_empty || position.options.size() < best_options.size()) {
        found_empty = true;

        best_i = i;
        best_j = j;
        best_options = position.options;
      }
    }
  }

  if(!found_empty) return true;

  for(const auto& num : best_options) {
    grid.puzzle[best_i][best_j] = num;

    if(solve(grid)) return true;

    grid.puzzle[best_i][best_j] = '0';
  }

  return false;
}

Grid_T get_puzzle(const std::vector<String_T>& full_grid, Int_T idx) {
  Grid_T grid;

  for(Int_T i = 0; i < 9; ++i) {
    Vector_T row;

    for(const auto& c : full_grid[idx + i]) {
      row.push_back(c);
    }

    grid.push_back(row);
  }

  return grid;
}

int main() {
  const String_T filename = "su_doku_input.txt";
  const auto input = get_input(filename);

  Int_T total = 0;

  for(Int_T i = 1; i < input.size(); i += 10) {
    Sudoku_Grid grid(get_puzzle(input, i));
    solve(grid);

    total += 100 * (grid.puzzle[0][0] - '0') + 10*(grid.puzzle[0][1] - '0') + (grid.puzzle[0][2] - '0');
  }

  std::cout << total << std::endl;

  return 0;
}