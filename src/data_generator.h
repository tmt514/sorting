#ifndef __DATA_GENERATOR_H__
#define __DATA_GENERATOR_H__

#include <vector>

class DataGenerator {
 public:
  DataGenerator(bool _allow_repeat = true, int _min_value = 0,
                int _max_value = __INT32_MAX__)
      : allow_repeat(_allow_repeat),
        min_value(_min_value),
        max_value(_max_value) {}
  std::vector<int> GenerateRandomArray(int seed, int N);
  std::vector<int> GenerateRandomPermutation(int seed, int N);

 private:
  bool allow_repeat;
  int min_value;
  int max_value;
};

#endif  // __DATA_GENERATOR_H__
