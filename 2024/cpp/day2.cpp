#include <cmath>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <vector>

bool verify_v1(const std::vector<int> &report) {
  bool increasing = true;
  bool decreasing = true;
  for (size_t i = 0; i < report.size() - 1; i++) {
    if (report[i] < report[i + 1]) {
      decreasing = false;
    }
    if (report[i] > report[i + 1]) {
      increasing = false;
    }
    int diff = abs(report[i] - report[i + 1]);
    if (diff < 1 || diff > 3) {
      return false;
    }
  }
  return increasing || decreasing;
}

bool verify_v2(const std::vector<int> &report) {
  if (verify_v1(report)) {
    return true;
  }
  for (size_t i = 0; i < report.size(); i++) {
    std::vector<int> new_report = report;
    new_report.erase(new_report.begin() + i);
    if (verify_v1(new_report)) {
      return true;
    }
  }
  return false;
}

int main() {
  FILE *fileptr = fopen("inputs/day2.txt", "r");
  std::vector<std::vector<int>> reports;
  char line[1024];

  while (fgets(line, sizeof(line), fileptr)) {
    std::stringstream ss(line);
    std::vector<int> report;
    int level;
    while (ss >> level) {
      report.push_back(level);
    }
    reports.push_back(report);
  }
  fclose(fileptr);

  int safe_count = 0;
  for (const auto &report : reports) {
    if (verify_v2(report)) {
      safe_count++;
    }
  }
  std::cout << safe_count << std::endl;
  return 0;
}

extern "C" {
void wrapper(int part) {
  FILE *fileptr = fopen("inputs/2024/day2.txt", "r");
  std::vector<std::vector<int>> reports;
  char line[1024];

  while (fgets(line, sizeof(line), fileptr)) {
    std::stringstream ss(line);
    std::vector<int> report;
    int level;
    while (ss >> level) {
      report.push_back(level);
    }
    reports.push_back(report);
  }
  fclose(fileptr);

  int safe_count = 0;
  for (const auto &report : reports) {
    auto value = part == 1 ? verify_v1(report) : verify_v2(report);
    if (value) {
      safe_count++;
    }
  }
  std::cout << safe_count << std::endl;
}
}