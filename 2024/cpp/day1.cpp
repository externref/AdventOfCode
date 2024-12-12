#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <string>
#include <unordered_map>

void part_1() {
  FILE *fileptr = fopen("inputs/2024/day1.txt", "r");
  char line[50];
  int *arr1 = (int *)malloc(10000 * sizeof(int));
  int *arr2 = (int *)malloc(10000 * sizeof(int));
  int lenarr = 0;

  while (fgets(line, sizeof(line), fileptr)) {
    sscanf(line, "%i %i", arr1 + lenarr, arr2 + lenarr);
    lenarr++;
  }

  std::sort(arr1, arr1 + lenarr);
  std::sort(arr2, arr2 + lenarr);

  int sum = 0;
  for (int i = 0; i < lenarr; i++) {
    sum += abs(arr1[i] - arr2[i]);
  }

  std::cout << sum << std::endl;

  free(arr1);
  free(arr2);
  fclose(fileptr);
}

void part_2() {
  FILE *fileptr = fopen("inputs/2024/day1.txt", "r");
  char line[50];
  int *arr1 = (int *)malloc(10000 * sizeof(int));
  int *arr2 = (int *)malloc(10000 * sizeof(int));
  int lenarr = 0;

  while (fgets(line, sizeof(line), fileptr)) {
    sscanf(line, "%i %i", arr1 + lenarr, arr2 + lenarr);
    lenarr++;
  }

  std::unordered_map<int, int> right_count;
  for (int i = 0; i < lenarr; i++) {
    right_count[arr2[i]]++;
  }

  int similarity_score = 0;
  for (int i = 0; i < lenarr; i++) {
    similarity_score += arr1[i] * right_count[arr1[i]];
  }

  std::cout << similarity_score << std::endl;

  free(arr1);
  free(arr2);
  fclose(fileptr);
}

int main() {
  part_2();
  return 0;
}

extern "C" {
void wrapper(int part) { std::cout << (part == 1) ? part_1() : part_2(); }
}