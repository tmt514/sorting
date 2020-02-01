#ifndef __QUICKSORT_H__
#define __QUICKSORT_H__

#include "sorter.h"

class QuickSort : public Sorter {
  public:
  QuickSort() : Sorter("QuickSort") {}
  void Sort(vector<int> &A);
  static SorterFactoryRegistrar<Sorter, QuickSort> _;
};

#endif  // __QUICKSORT_H__