#ifndef BSNODE_H
#define BSNODE_H

#include <ostream>

template <typename T> 
class BSNode {
    public:
        T elem;
	BSNode<T>* izquierda;
	BSNode<T>* derecha;
	
	BSNode(T elem, BSNode<T>* izquierda = nullptr, BSNode<T>* derecha = nullptr);
	template <typename U>friend std::ostream& operator<<(std::ostream &out, const BSNode<U> &bsn);
};

template <typename T>
BSNode<T>::BSNode(T elem, BSNode<T>* izquierda, BSNode<T>* derecha){

	this -> elem = elem;
	this -> izquierda = izquierda;
	this -> derecha = derecha;
}

template <typename U>
std::ostream& operator<<(std::ostream &out, const BSNode<U> &bsn){
	
	out << bsn->elem;
	return out;

}
#endif
