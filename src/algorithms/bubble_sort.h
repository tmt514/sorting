#ifndef __BUBBLE_SORT_H__
#define __BUBBLE_SORT_H__

#include "sorter.h"

class BubbleSort : public Sorter {
  public:
  BubbleSort() : Sorter("Bubble Sort") {}
  void Sort(vector<int> &A);
  static SorterFactoryRegistrar<Sorter, BubbleSort> _;
};

#endif  // __BUBBLE_SORT_H__