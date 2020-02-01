#include "radix_sort.h"
#include <cassert>

void RadixSort::Sort(vector<int> &A) {
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

SorterFactoryRegistrar<Sorter, RadixSort> RadixSort::_;