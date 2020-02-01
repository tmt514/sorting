#ifndef __SORT_H__
#define __SORT_H__

#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include "sorter_factory.h"
using std::string;
using std::vector;

class Sorter {
 public:
  string name;
  Sorter(string _name) : name(_name) {}
  virtual void Sort(vector<int> &A) = 0;

 protected:
  void Swap(int &x, int &y) {
    int tmp = x;
    x = y;
    y = tmp;
  }
};

#endif  // __SORT_H__