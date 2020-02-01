#ifndef __MERGESORT_H__
#define __MERGESORT_H__

#include "sorter.h"

class MergeSort : public Sorter {
  public:
  MergeSort() : Sorter("MergeSort") {}
  void Sort(vector<int> &A);
  static SorterFactoryRegistrar<Sorter, MergeSort> _;
};

#endif  // __MERGESORT_H__