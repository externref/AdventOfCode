#include <fstream>
#include <iostream>
#include <regex>
#include <string>

int mul_lexer(const std::string &data) {
  std::regex pattern(R"(mul\((\d+),(\d+)\))");
  int total_sum = 0;
  auto matches = std::sregex_iterator(data.begin(), data.end(), pattern);
  auto matches_end = std::sregex_iterator();

  for (auto it = matches; it != matches_end; ++it) {
    std::smatch match = *it;
    int x = std::stoi(match.str(1));
    int y = std::stoi(match.str(2));
    total_sum += x * y;
  }

  return total_sum;
}

int mul_do_dont_lexer(const std::string &data) {
  bool mul_enabled = true;
  int total_sum = 0;

  std::regex pattern(R"(mul\((\d+),(\d+)\)|do\(\)|don't\(\))");
  auto words_begin = std::sregex_iterator(data.begin(), data.end(), pattern);
  auto words_end = std::sregex_iterator();

  for (std::sregex_iterator i = words_begin; i != words_end; ++i) {
    std::smatch match = *i;

    if (match.str() == "do()") {
      mul_enabled = true;
    } else if (match.str() == "don't()") {
      mul_enabled = false;
    } else if (match.str().substr(0, 3) == "mul") {
      int num1 = std::stoi(match.str(1));
      int num2 = std::stoi(match.str(2));

      if (mul_enabled) {
        total_sum += num1 * num2;
      }
    }
  }

  return total_sum;
}

int main() {
  std::ifstream input_file("inputs/2024/day3.txt");
  std::string data((std::istreambuf_iterator<char>(input_file)),
                   std::istreambuf_iterator<char>());

  int result = mul_do_dont_lexer(data);
  std::cout << "Total sum of enabled mul results: " << result << std::endl;

  return 0;
}

extern "C" {
void wrapper(int part) {
  std::ifstream input_file("inputs/2024/day3.txt");
  std::string data((std::istreambuf_iterator<char>(input_file)),
                   std::istreambuf_iterator<char>());
  auto val = (part == 1) ? mul_lexer(data) : mul_do_dont_lexer(data);
  std::cout << val << std::endl;
}
}