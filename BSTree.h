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
	BSNode<T>* insert(BSNode<T>* n,T e);
	void print_inorden(std::ostream &out, BSNode<T>* n) const{
 
	  if(n != nullptr){
	    print_inorden(out, n->izquierda);
	    out << n->elem << " ";
	    print_inorden(out, n-> derecha);
	  }
	}

	BSNode<T>* remove(BSNode<T>* n, T e);
	T max(BSNode<T>* n) const;
	BSNode<T>* remove_max(BSNode<T>* n);
	void delete_cascade(BSNode<T>* n);

    public:
        BSTree();
	int size() const;
	T search(T e);
	T operator[](T e) const;
	void insert(T e);
        friend std::ostream& operator<<(std::ostream &out, const BSTree<T> &bst){

	  
	  bst.print_inorden(out, bst.root);
	  return out;
	}

      	void remove(T e);	
	~BSTree();
    
};


template <typename T>
BSTree<T>::BSTree(){
  root = nullptr;
  nelem = 0;
}


template <typename T>
int BSTree<T>::size() const{

	return nelem;
}

template <typename T>
T BSTree<T>::search(T e){

	BSNode<T>* aux = search(root, e);
	return aux -> elem;
}

template <typename T>
BSNode<T>* BSTree<T>::search(BSNode<T>* n, T e) const{

  if(n == nullptr)
    throw std::runtime_error("No se encuentra el elemento");
  else{
    if(n->elem < e)
      return search(n->derecha, e);
    else{
      if(n->elem > e)
	return search(n->izquierda, e);
      else
	return n;

    }
  }
}


template <typename T>
void BSTree<T>::insert(T e){

  root = insert(root, e);
  nelem++;

}

template <typename T>
T BSTree<T>::operator[](T e) const{

  return search(e);

}

template <typename T>
BSNode<T>* BSTree<T>::insert(BSNode<T>* n, T e){

  if(n == nullptr)
    return new BSNode<T>(e);
  else{
    if(n->elem == e)
      throw std::runtime_error("El elemento ya existe");
    else{
      if(n->elem < e)
	n->derecha = insert(n->derecha, e);
      else
	n->izquierda = insert(n->izquierda, e);
      return n;
    }
  }   
}

/*
template <typename U>
std::ostream& operator<<(std::ostream& out, const BSTree<U> &bst){

  print_inorden(out, bst.root);
  return out;
  
  }

template <typename T>
void BSTree<T>::print_inorden(std::ostream& out, BSNode<T>* n) const{

  if(n != nullptr){
    print_inorden(out, n.first_descendant());
    out << n->elem;
    for(BSNode<T>* d : sorted(n.remaining_descendants())){
      print_inorden(out, d);
    }
  }

  }*/

template <typename T>
void BSTree<T>::remove(T e){

  root = remove(root, e);
  nelem--;

}

template <typename T>
BSNode<T>* BSTree<T>::remove(BSNode<T>* n, T e){

  if(n == nullptr)
    throw std::runtime_error("No se encontró el elemento");
  else{
    if(n->elem < e)
      n->derecha = remove(n->derecha, e);
    else{
      if(n->elem > e)
	n->izquierda = remove(n->izquierda, e);
      else{
	if(n->izquierda != nullptr && n->derecha != nullptr){
	  n->elem = max(n->izquierda);
	  n->izquierda = remove_max(n->izquierda);
	}
	else
	  n = (n->izquierda != nullptr)? n->izquierda : n->derecha;
      }
    }
  }
  return n;	
}

template <typename T>
T BSTree<T>::max(BSNode<T>* n) const{

  if(n == nullptr)
    throw std::runtime_error("No encontrado");
  else{
    if(n->derecha != nullptr)
      return max(n->derecha);
    else
      return n->elem;
  }
}

template <typename T>
BSNode<T>* BSTree<T>::remove_max(BSNode<T>* n){

  if(n->derecha == nullptr)
    return n->izquierda;
  else{
    n->derecha = remove_max(n->derecha);
    return n;
  }
}

template <typename T>
BSTree<T>::~BSTree(){
  delete_cascade(root);

}

template <typename T>
void BSTree<T>::delete_cascade(BSNode<T>* n){
  
   if(n != nullptr){
	    delete_cascade(n->izquierda);
	    delete n;
	    delete_cascade(n-> derecha);
	  }
	

}

#endif
