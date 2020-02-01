#ifndef __HEAP_SORT_H__
#define __HEAP_SORT_H__

#include "sorter.h"

class HeapSort : public Sorter {
  public:
  HeapSort() : Sorter("HeapSort") {}
  void Sort(vector<int> &A);
  static SorterFactoryRegistrar<Sorter, HeapSort> _;
};

#endif  // __HEAP_SORT_H__