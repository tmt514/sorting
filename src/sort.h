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

class InsertionSort : public Sorter {
  public:
  InsertionSort() : Sorter("Insertion Sort") {}
  void Sort(vector<int> A);
  static SorterFactoryRegistrar<Sorter, InsertionSort> _;
  
};

class QuickSort : public Sorter {
  public:
  QuickSort() : Sorter("QuickSort") {}
  void Sort(vector<int> A);
  static SorterFactoryRegistrar<Sorter, QuickSort> _;
};

class HeapSort : public Sorter {
  public:
  HeapSort() : Sorter("HeapSort") {}
  void Sort(vector<int> A);
  static SorterFactoryRegistrar<Sorter, HeapSort> _;
};

class MergeSort : public Sorter {
  public:
  MergeSort() : Sorter("MergeSort") {}
  void Sort(vector<int> A);
  static SorterFactoryRegistrar<Sorter, MergeSort> _;
};

class IterativeMergeSort : public Sorter {
  public:
  IterativeMergeSort() : Sorter("IterativeMergeSort") {}
  void Sort(vector<int> A);
  static SorterFactoryRegistrar<Sorter, IterativeMergeSort> _;
};

class RadixSort : public Sorter {
  public:
  RadixSort() : Sorter("RadixSort") {}
  void Sort(vector<int> A);
  static SorterFactoryRegistrar<Sorter, RadixSort> _;
};

#endif  // __SORT_H__