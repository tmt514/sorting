#include "insertion_sort.h"

void InsertionSort::Sort(vector<int> &A) {
  int n = A.size();
  for (int i = 0; i < n; i++) {
    // 假設 A[0... i-1] 已經排好了。
    for (int j = i; j > 0; j--) {
      if (A[j] < A[j - 1]) {
        Swap(A[j], A[j - 1]);
      } else {
        break;
      }
    }
  }
}

SorterFactoryRegistrar<Sorter, InsertionSort> InsertionSort::_;