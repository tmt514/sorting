#include "bubble_sort.h"

void BubbleSort::Sort(vector<int> &A) {
  int n = A.size();
  bool changed = false;
  do {
    changed = false;
    for (int i = 0; i + 1 < n; i++)
      if (A[i] > A[i + 1]) {
        Swap(A[i], A[i + 1]);
        changed = true;
      }
  } while (changed);
}

SorterFactoryRegistrar<Sorter, BubbleSort> BubbleSort::_;