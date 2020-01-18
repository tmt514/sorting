#include "data_generator.h"
#include <algorithm>
#include <random>
#include <vector>

std::vector<int> DataGenerator::GenerateRandomArray(int seed, int N) {
  std::vector<int> A;
  std::mt19937 generator(seed);
  std::uniform_int_distribution<int> distribution(min_value, max_value);
  for (int i = 0; i < N; i++) {
    A.push_back(distribution(generator));
  }
  return A;
}

std::vector<int> DataGenerator::GenerateRandomPermutation(int seed, int N) {
  std::vector<int> A;
  std::mt19937 generator(seed);
  for (int i = 0; i < N; i++) {
    A.push_back(i);
  }
  std::shuffle(A.begin(), A.end(), generator);
  return A;
}
