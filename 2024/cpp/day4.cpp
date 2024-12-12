#include <fstream>
#include <iostream>
#include <string>
#include <vector>

const std::string FILENAME = "inputs/2024/day4.txt";

std::vector<std::string> grid;

bool check_direction(int row, int col, int dr, int dc,
                     const std::string &target, int rows, int cols) {
  for (int i = 0; i < target.length(); ++i) {
    int r = row + i * dr;
    int c = col + i * dc;
    if (r < 0 || r >= rows || c < 0 || c >= cols || grid[r][c] != target[i]) {
      return false;
    }
  }
  return true;
}

int part_1() {
  std::ifstream infile(FILENAME);
  std::string line;
  while (std::getline(infile, line)) {
    grid.push_back(line);
  }
  const std::vector<std::pair<int, int>> directions = {
      {0, 1}, {1, 0}, {0, -1}, {-1, 0}, {1, 1}, {-1, -1}, {1, -1}, {-1, 1}};
  const std::string target = "XMAS";
  int rows = grid.size();
  int cols = grid[0].size();
  int count = 0;

  for (int row = 0; row < rows; ++row) {
    for (int col = 0; col < cols; ++col) {
      for (auto &dir : directions) {
        int dr = dir.first;
        int dc = dir.second;
        if (check_direction(row, col, dr, dc, target, rows, cols)) {
          count++;
        }
      }
    }
  }
  return count;
}

bool has_xmas(int r, int c, int rows, int cols) {
  if (r <= 0 || r >= rows - 1 || c <= 0 || c >= cols - 1) {
    return false;
  }
  if (grid[r][c] != 'A') {
    return false;
  }

  std::string diag_1 = {grid[r - 1][c - 1], grid[r + 1][c + 1]};
  std::string diag_2 = {grid[r - 1][c + 1], grid[r + 1][c - 1]};

  return (diag_1 == "MS" || diag_1 == "SM") &&
         (diag_2 == "MS" || diag_2 == "SM");
}

int part_2() {
  std::ifstream infile(FILENAME);
  std::string line;
  while (std::getline(infile, line)) {
    grid.push_back(line);
  }
  int rows = grid.size();
  int cols = grid[0].size();
  int count = 0;

  for (int r = 0; r < rows; ++r) {
    for (int c = 0; c < cols; ++c) {
      if (has_xmas(r, c, rows, cols)) {
        count++;
      }
    }
  }
  return count;
}

int main() {

  std::cout << part_2() << std::endl;

  return 0;
}

extern "C" {
void wrapper(int part) {
  auto value = part == 1 ? part_1() : part_2();
  std::cout << value << std::endl;
}
}