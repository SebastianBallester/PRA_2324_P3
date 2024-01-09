#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <ostream>
#include <stdexcept>
#include "Dict.h"
#include "TableEntry.h"

#include "ListLinked.h"

template <typename V>
class HashTable: public Dict<V> {

    private:
        int n;
	int max;
	ListLinked<TableEntry<V>> * table;
	int h(std::string key);

    public:
	HashTable(int size);
	~HashTable();
	int capacity();
	template <typename X> friend std::ostream& operator<<(std::ostream &out, const HashTable<X> &th);
	V operator[](std::string key);
	void insert(std::string key, V value) override;
	V search(std::string key) override;
	V remove(std::string key) override;
	int entries() override;
};

template <typename V>
int HashTable<V>::h(std::string key){
	
	char c;
	int suma = 0;
	int sol;
	for(int i = 0; i < key.size(); i++){
		c = key.at(i);
		suma += int(c);
	}

	return sol = suma % max;
}

template <typename V>
HashTable<V>::HashTable(int size){

	table = new ListLinked<TableEntry<V>>[size];
	max = size;
	n = 0;
}

template <typename V>
HashTable<V>::~HashTable(){

	delete[] table;
}

template <typename V>
int HashTable<V>::capacity(){

	return max;
}

template <typename X>
std::ostream& operator<<(std::ostream &out, const HashTable<X> &th){

  for(int i = 0; i < th.max; i++){
    out << "Cubeta " << i << std::endl << "List [ " << th.table[i] << "]" << std::endl;
  }
  std::cout << "Hola";
}


template <typename V>
V HashTable<V>::operator[](std::string key){
  
  return search(key);
}

template <typename V>
void HashTable<V>::insert(std::string key, V value){

  int pos = h(key);
  int bus = table[pos].search(key);
  if(bus == -1)
    table[pos].insert(0,TableEntry<V>(key, value));
  else
    throw std::runtime_error("La clave ya existe");

}

template <typename V>
V HashTable<V>::search(std::string key){
  int pos = h(key);
  int bus = table[pos].search(key);
  if(bus == -1)
    throw std::runtime_error("No se encuentra la clave");
  return table[pos].get(bus).value;
  
}

template <typename V>
V HashTable<V>::remove(std::string key){
  int pos = h(key);
  int bus = table[pos].search(key);
  if(bus == -1)
    throw std::runtime_error("No se encuentra la clave");
  return table[pos].remove(bus).value;

}

template <typename V>
int HashTable<V>::entries(){
  
  return n;
}
#endif
