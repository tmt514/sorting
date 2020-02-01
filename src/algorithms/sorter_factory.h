#ifndef __SORTER_FACTORY_H__
#define __SORTER_FACTORY_H__

#include <iostream>
#include <map>
#include <string>
#include <vector>

template <class T>
class SorterFactory {
 public:
  SorterFactory() { std::cout << "Initialize a sorter factory!" << std::endl; }
  std::vector<T *> all_sorters;
  std::map<std::string, T *> sorters_by_name;
  void Register(T *sorter) {
    std::cout << "Registering sorter! [" << sorter->name << "](" << &*sorter
              << ")" << std::endl;
    all_sorters.push_back(sorter);
    sorters_by_name[sorter->name] = sorter;
  }
  T *GetSorter(std::string name) { return sorters_by_name[name]; }
};

template <class T>
SorterFactory<T> &GetSorterFactory() {
  static SorterFactory<T> factory;
  return factory;
}

template <class Base, class T>
class SorterFactoryRegistrar {
 public:
  SorterFactoryRegistrar() {
    std::cout << "New Registrar!" << std::endl;
    GetSorterFactory<Base>().Register(new T);
  }
};

#endif  // __SORTER_FACTORY_H__