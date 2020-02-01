#include "heap_sort.h"

#include <algorithm>
#include <functional>
#include <cassert>

void HeapSort::Sort(vector<int> &A) {
  int n = A.size();

  auto RollDown = [&](int x, int n) {
    while (true) {
      int left_child = 2 * x + 1;
      int right_child = 2 * x + 2;
      // Case 1.
      if (left_child >= n) return;
      // Case 2.
      if (right_child >= n) {
        if (A[left_child] > A[x]) {
          Swap(A[left_child], A[x]);
          x = left_child;
          continue;
        } else {
          return;
        }
      }
      // Case 3.
      int larger_child =
          A[left_child] > A[right_child] ? left_child : right_child;
      if (A[larger_child] > A[x]) {
        Swap(A[larger_child], A[x]);
        x = larger_child;
      } else {
        return;
      }
    }
  };

  auto MyPopHeap = [&](int n) {
    Swap(A[0], A[n - 1]);
    --n;
    RollDown(0, n);
  };

  auto MyMakeHeap = [&](int n) {
    for (int i = n - 1; i >= 0; i--) {
      RollDown(i, n);
    }
  };

  // std::make_heap(A.begin(), A.end());
  MyMakeHeap(n);
  for (int i = n; i > 0; i--) {
    // std::pop_heap(A.begin(), A.begin() + i);
    MyPopHeap(i);
  }

  for (int i = 0; i + 1 < n; i++) {
    assert(A[i] <= A[i + 1]);
  }
}

SorterFactoryRegistrar<Sorter, HeapSort> HeapSort::_;