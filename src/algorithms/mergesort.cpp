#include "mergesort.h"

#include <cassert>
#include <functional>

void MergeSort::Sort(vector<int> &A) {
  int n = A.size();

  auto combine = [&](int l, int m, int r) {
    vector<int> tmp;
    int i = l, j = m + 1;
    while (i <= m || j <= r) {
      if (j > r || (i <= m && A[i] < A[j]))
        tmp.push_back(A[i++]);
      else
        tmp.push_back(A[j++]);
    }
    for (auto x : tmp) A[l++] = x;
  };

  std::function<void(int, int)> mergesort = [&](int l, int r) {
    if (l >= r) return;
    int m = (l + r) / 2;
    mergesort(l, m);
    mergesort(m + 1, r);
    combine(l, m, r);
  };

  mergesort(0, n - 1);
}

SorterFactoryRegistrar<Sorter, MergeSort> MergeSort::_;