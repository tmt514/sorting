#include "sort.h"
#include <algorithm>
#include <cassert>
#include <functional>

// SorterFactoryRegistrar<Sorter, SelectionSort> SelectionSort::_;
SorterFactoryRegistrar<Sorter, CppSTLSort> CppSTLSort::_;
// SorterFactoryRegistrar<Sorter, BubbleSort> BubbleSort::_;
// SorterFactoryRegistrar<Sorter, InsertionSort> InsertionSort::_;
SorterFactoryRegistrar<Sorter, QuickSort> QuickSort::_;
// SorterFactoryRegistrar<Sorter, HeapSort> HeapSort::_;
// SorterFactoryRegistrar<Sorter, MergeSort> MergeSort::_;
// SorterFactoryRegistrar<Sorter, IterativeMergeSort> IterativeMergeSort::_;
// SorterFactoryRegistrar<Sorter, RadixSort> RadixSort::_;

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
    for (int i = 0; i + 1 < n; i++)
      if (A[i] > A[i + 1]) {
        Swap(A[i], A[i + 1]);
        changed = true;
      }
  } while (changed);
}

void InsertionSort::Sort(vector<int> A) {
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

void QuickSort::Sort(vector<int> A) {
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

void HeapSort::Sort(vector<int> A) {
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

void MergeSort::Sort(vector<int> A) {
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

  for (int i = 0; i + 1 < n; i++) {
    assert(A[i] <= A[i + 1]);
  }
}

void IterativeMergeSort::Sort(vector<int> A) {
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

  for (int i = 0; i + 1 < n; i++) {
    assert(A[i] <= A[i + 1]);
  }
}

void RadixSort::Sort(vector<int> A) {
  int n = A.size();
  long long K = 4096;

  for (long long base = 1, shift = 0; shift < 32;
       base *= K, shift += 12) {
    vector<int> buckets[K];
    for (auto x : A) {
      // int digit = x / base % K;
      int digit = (x >> shift) & (K - 1);
      buckets[digit].push_back(x);
    }
    A.clear();
    for (int i = 0; i < K; i++) {
      A.insert(A.end(), buckets[i].begin(), buckets[i].end());
    }
  }

  for (int i = 0; i + 1 < n; i++) {
    assert(A[i] <= A[i + 1]);
  }
}