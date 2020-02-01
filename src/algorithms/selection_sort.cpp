#include "selection_sort.h"

SorterFactoryRegistrar<Sorter, SelectionSort> SelectionSort::_;

void SelectionSort::Sort(vector<int> &A) {
  int n = A.size();
  for (int i = 0; i < n; i++)
    for (int j = i + 1; j < n; j++) {
      if (A[i] > A[j]) {
        Swap(A[i], A[j]);
      }
    }
}