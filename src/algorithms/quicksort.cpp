#include "quicksort.h"

#include <functional>

void QuickSort::Sort(vector<int> &A) {
  std::function<void(int, int)> quicksort = [&](int l, int r) {
    if (l >= r) return;
    int pivot = A[r];
    int lb = l;
    int rb = r - 1;
    for (int i = lb; i <= rb; i++) {
      if (A[i] < pivot) {
        lb++;
      } else if (A[i] >= pivot) {
        Swap(A[i], A[rb--]);
        --i;
      }
    }
    Swap(A[lb], A[r]);
    quicksort(l, lb - 1);
    quicksort(lb + 1, r);
  };

  int n = A.size();
  quicksort(0, n - 1);
}

SorterFactoryRegistrar<Sorter, QuickSort> QuickSort::_;