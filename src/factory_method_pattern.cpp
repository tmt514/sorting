#include <iostream>
#include "algorithms/sorter.h"

using std::cout;
using std::endl;

int main() {
  auto factory = GetSorterFactory<Sorter>();
  cout << "Total " << factory.all_sorters.size() << " sorters." << endl;

  Sorter* sorter = factory.GetSorter("Bubble Sort");
  cout << "Sorter Address: " << &*sorter << endl;
  return 0;
}