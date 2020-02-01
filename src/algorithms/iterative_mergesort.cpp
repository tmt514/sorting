#include "iterative_mergesort.h"

#include <cassert>

void IterativeMergeSort::Sort(vector<int> &A) {
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

  for (int len = 1; len <= n; len *= 2) {
    for (int l = 0; l + len < n; l += 2 * len) {
      // 我想要合併 [l, l + len-1] 與 [l + len, l + 2*len-1]
      combine(l, l + len - 1, std::min(l + 2 * len - 1, n - 1));
    }
  }
}

SorterFactoryRegistrar<Sorter, IterativeMergeSort> IterativeMergeSort::_;