#ifndef __ITERATIVE_MERGESORT_H__
#define __ITERATIVE_MERGESORT_H__

#include "sorter.h"

class IterativeMergeSort : public Sorter {
  public:
  IterativeMergeSort() : Sorter("IterativeMergeSort") {}
  void Sort(vector<int> &A);
  static SorterFactoryRegistrar<Sorter, IterativeMergeSort> _;
};

#endif  // __ITERATIVE_MERGESORT_H__