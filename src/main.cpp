#include <algorithm>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <random>
#include <string>
#include <vector>
#include "data_generator.h"
#include "algorithms/sorter.h"
#include "algorithms/sorter_factory.h"
using std::cout;
using std::endl;
using std::fixed;
using std::setprecision;
using std::shuffle;
using std::string;
using std::vector;

const string kCLR = "\033[0m";
const string kHY = "\033[1;33m";
const string kHW = "\033[1;37m";

int main(int argc, char* argv[]) {
  // 資料長度。
  int N = 100;

  auto factory = GetSorterFactory<Sorter>();
  auto data_generator = DataGenerator();
  cout << "Total " << factory.all_sorters.size() << " sorters." << endl;
  cout << string(80, '=') << endl;

  // 把所有註冊的排序方法通通列舉出來，一個一個測時間。
  for (auto&& sorter : factory.all_sorters) {
    cout << kHY << sorter->name << kCLR << endl;
    double total_time = 0;
    int number_of_tests = 0;
    int testseed = 514;  // 固定一個 Seed，讓所有方法被測試到的測試資料相同。
    while (total_time <= 5.0 && number_of_tests < 500) {
      auto A = data_generator.GenerateRandomArray(testseed, N);
      auto start_time = clock();
      sorter->Sort(A);
      auto end_time = clock();
      total_time += (end_time - start_time) / (double)CLOCKS_PER_SEC;
      ++number_of_tests;
      ++testseed;
    }
    auto average_duration = total_time / number_of_tests;
    cout << "Sorting " << N << " number takes [" << kHW << fixed
         << setprecision(6) << average_duration << kCLR << " sec] in "
         << number_of_tests << " tests." << endl;
  }

  return 0;
}