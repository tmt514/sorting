#include "sort.h"

SorterFactoryRegistrar<Sorter, SelectionSort> SelectionSort::_;
SorterFactoryRegistrar<Sorter, CppSTLSort> CppSTLSort::_;
SorterFactoryRegistrar<Sorter, BubbleSort> BubbleSort::_;

void Swap(int &x, int &y) {
  int tmp = x;
  x = y;
  y = tmp;
}

void SelectionSort::Sort(vector<int> A) {
  int n = A.size();
  for (int i = 0; i < n; i++)
    for (int j = i + 1; j < n; j++) {
      if (A[i] > A[j]) {
        Swap(A[i], A[j]);
      }
    }
}

void BubbleSort::Sort(vector<int> A) {
  int n = A.size();
  bool changed = false;
  do {
    changed = false;
    for (int i = 0; i+1 < n; i++)
      if (A[i] > A[i+1]) {
        Swap(A[i], A[i+1]);
        changed = true;
      }
  } while (changed);
}