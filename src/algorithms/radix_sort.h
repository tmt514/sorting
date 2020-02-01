#ifndef __RADIX_SORT_H__
#define __RADIX_SORT_H__

#include "sorter.h"

class RadixSort : public Sorter {
  public:
  RadixSort() : Sorter("RadixSort") {}
  void Sort(vector<int> &A);
  static SorterFactoryRegistrar<Sorter, RadixSort> _;
};

#endif  // __RADIX_SORT_H__