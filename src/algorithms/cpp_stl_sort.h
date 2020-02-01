#ifndef __CPP_STL_SORT_H__
#define __CPP_STL_SORT_H__

#include "sorter.h"

class CppSTLSort : public Sorter {
  public:
  CppSTLSort() : Sorter("C++ STL Sort") {}
  void Sort(vector<int> &A) { std::sort(A.begin(), A.end()); }
  static SorterFactoryRegistrar<Sorter, CppSTLSort> _;
};

#endif  // __CPP_STL_SORT_H__