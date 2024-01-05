#ifndef TABLEENTRY_H
#define TABLEENTRY_H

#include <string>
#include <ostream>
#include <iostream>

template <typename V> 
class TableEntry {
    public:
      	std::string key;
	V value;

	TableEntry(std::string key, V value);
	TableEntry(std::string key);
	TableEntry();
	template <typename Z>friend bool operator==(const TableEntry<Z> &te1, const TableEntry<Z> &te2);
	template <typename Y>friend bool operator!=(const TableEntry<Y> &te1, const TableEntry<Y> &te2);
	template <typename X>friend std::ostream& operator<<(std::ostream &out, const TableEntry<X> &te);

}; 

template <typename V>
TableEntry<V>::TableEntry(std::string key, V value){
	
	this -> key = key;
	this -> value = value;
}

template <typename V>
TableEntry<V>::TableEntry(std::string key){

	this -> key = key;
}

template <typename V>
TableEntry<V>::TableEntry(){

	key = "";
}

template <typename Z>
bool operator==(const TableEntry<Z> &te1, const TableEntry<Z> &te2){

	if(te1.key == te2.key)
		return true;
	return false;
	
}

template <typename Y>
bool operator!=(const TableEntry<Y> &te1, const TableEntry<Y> &te2){

	if(te1.key != te2.key)
                return true;
        return false;
}

template <typename X>
std::ostream& operator<<(std::ostream &out, const TableEntry<X> &te){
	
	out << "('" << te.key << "' => " << te.value << ")";
	return out;
	
}

#endif
