#ifndef __INSERTION_SORT_H__
#define __INSERTION_SORT_H__

#include "sorter.h"

class InsertionSort : public Sorter {
  public:
  InsertionSort() : Sorter("Insertion Sort") {}
  void Sort(vector<int> &A);
  static SorterFactoryRegistrar<Sorter, InsertionSort> _;
};

#endif  // __INSERTION_SORT_H__