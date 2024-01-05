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
	template <typename X> friend std::ostream&operator<<(std::ostream &out, cost HashTable<V> &th);
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
		c = ky.at(i);
		suma =+ int(c);
	}

	sol = suma % max;
}

template <typename V>
HashTable<V>::HashTable(int size){

	table = new int[size];
	max = size;
	n = 0;
}

template <typename V>
HashTable<V>::~HashTable(){

	delete[] table;
}

template <typename V>
int HashTable<V>::capacity(){

	return n;
}

template <typename V>
V HashTable<V>::operator[](std::string key){


}
#endif
