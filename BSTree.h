#ifndef BSTREE_H
#define BSTREE_H

#include <ostream>
#include <stdexcept>
#include "BSNode.h"

template <typename T> 
class BSTree {
    private:
        int nelem;
	BSNode<T> *root;

	BSNode<T>* search(BSNode<T>* n, T e) const;
	BSNode<T>* insert(BSNode<T>* n;T e);
	void print_inorder(std::ostream &out, BSNode<T> n) const;
	BSNode<T>* remove(BSNode<T>* n, T e);
	T max(BSNode<T>* n) const;
	BSNode<T>* remove_max(BSNode<T>* n);
	void delete_cascade(BSNode<T>* n);

    public:
        BSTree();
	int size const();
	T search(T e);
	T operator[](T e) const;
	void insert(T e);
	template <typename U> frien std::ostram& operator<<(std::ostream &out, const BSTree<T> &bst);
      	void remove(T e);	
	~BSTree();
    
};


temlate <typename T>
BSTree::BSTree(){

}


template <typename T>
int BSTree::size() const{

	return nelem;
}

template <typename T>
T BSTree::search(T e) const{

	BSNode<T>* aux = search(root, e);
	return aux -> elem;
}

template <typename T>
BSNode<T>* BSTree::search(BSNode<T>* n, T e) const{

	if(n == nullptr)
		throw(std::runtime_error);
	else if
}

#endif
