#ifndef BSTREEDICT_H
#define BSTREEDICT_H

#include <ostream>
#include <stdexcept>
#include "Dict.h"
#include "BSTree.h"
#include "TableEntry.h"

template <typename V>
class BSTreeDict: public Dict<V> {

 private:
  BSTree<TableEntry<V>>* tree;

 public:
  BSTreeDict();
  ~BSTreeDict();
  template <typename T> friend std::ostream& operator<<(std::ostream &out, const BSTreeDict<T> &bs);
  V operator[](std::string key);
  void insert(std::string key, V value) override;
  V search(std::string key) override;
  V remove(std::string key) override;
  int entries() override;
};


template <typename V>
BSTreeDict<V>::BSTreeDict(){

  tree = new BSTree<TableEntry<V>>[1];  
}

template <typename V>
BSTreeDict<V>::~BSTreeDict(){

  delete[] tree;
}

template <typename T>
std::ostream& operator<<(std::ostream &out, const BSTreeDict<T> &bs){

  out <<"(" << *(bs.tree) << ")";
  return out;
}

template <typename V>
V BSTreeDict<V>::operator[](std::string key){

  return search(key);
}

template <typename V>
void BSTreeDict<V>::insert(std::string key, V value){

  tree->insert(TableEntry<V>(key,value));
  
}

template <typename V>
V BSTreeDict<V>::search(std::string key){

  TableEntry<V> aux = tree->search(TableEntry<V>(key));
  return aux.value;
}

template <typename V>
V BSTreeDict<V>::remove(std::string key){

  V aux = search(key);
  tree->remove(TableEntry<V>(key));
  return aux;
}

template <typename V>
int BSTreeDict<V>::entries(){

  return tree->size();
}
#endif
