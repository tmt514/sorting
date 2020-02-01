#ifndef __SELECTION_SORT_H__
#define __SELECTION_SORT_H__

#include "sorter.h"
#include "sorter_factory.h"

class SelectionSort : public Sorter {
 public:
  SelectionSort() : Sorter("Selection Sort") {}
  void Sort(vector<int> &A);
  static SorterFactoryRegistrar<Sorter, SelectionSort> _;
};

#endif  // __SELECTION_SORT_H__