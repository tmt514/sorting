#ifndef __SORTER_FACTORY_H__
#define __SORTER_FACTORY_H__

#include <vector>
#include <iostream>

template<class T>
class SorterFactory {
  public:
  SorterFactory() {
    std::cout << "Initialize a sorter factory!" << std::endl;
  }
  std::vector<T*> all_sorters;
  void Register(T* sorter) {
    std::cout << "Registering sorter!" << std::endl;
    all_sorters.push_back(sorter);
  }
};

template<class T>
SorterFactory<T>& GetSorterFactory() {
  static SorterFactory<T> factory;
  return factory;
}

template<class Base, class T>
class SorterFactoryRegistrar {
  public:
  SorterFactoryRegistrar() {
    std::cout << "New Registrar!" << std::endl;
    GetSorterFactory<Base>().Register(new T);
  }
};

#endif // __SORTER_FACTORY_H__