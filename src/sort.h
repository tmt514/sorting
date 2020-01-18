#ifndef __SORT_H__
#define __SORT_H__

#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include "sorter_factory.h"
using std::string;
using std::vector;

class Sorter {
 public:
  string name;
  Sorter(string _name) : name(_name) {}
  virtual void Sort(vector<int> A) = 0;
};

class SelectionSort : public Sorter {
 public:
  SelectionSort() : Sorter("Selection Sort") {}
  void Sort(vector<int> A);
  static SorterFactoryRegistrar<Sorter, SelectionSort> _;
};

class CppSTLSort : public Sorter {
  public:
  CppSTLSort() : Sorter("C++ STL Sort") {}
  void Sort(vector<int> A) { std::sort(A.begin(), A.end()); }
  static SorterFactoryRegistrar<Sorter, CppSTLSort> _;
};

class BubbleSort : public Sorter {
  public:
  BubbleSort() : Sorter("Bubble Sort") {}
  void Sort(vector<int> A);
  static SorterFactoryRegistrar<Sorter, BubbleSort> _;
};

#endif  // __SORT_H__