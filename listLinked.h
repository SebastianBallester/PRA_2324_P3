#include <ostream>
#include "List.h"
#include "Node.h"

template <typename T>
class ListLinked : public List<T> {

    private:

    	Node<T>* first;
	int n;

    public:	
	ListLinked();
    	~ListLinked();
	T operator[](int pos);
	template <typename U> friend std::ostream& operator<<(std::ostream &out, const ListLinked<U> &node);
	void insert(int pos, T e) override;
	void append(T e) override;
	void prepend(T e) override;
	T remove(int pos) override;
	T get(int pos) override;
	int search(T e) override;
	int size() override;
	void invert_list();
};

template <typename T>
ListLinked<T>::ListLinked(){
	first = nullptr;
	n = 0;

}


template <typename T>
void ListLinked<T>::invert_list(){
	
  	Node<T>* aux2 = first;	
	T x;
	for(int i = 0; i <= (n/2); i++){ 
	       	Node<T>* aux = first;	

		
		int cont = n - i - 1;	
		while(aux->next != nullptr && cont > 0){
			aux = aux->next;
			cont--;
		}
		x = aux->data;
		aux->data = aux2->data;
		aux2->data = x;
		aux2 = aux2->next;
	}
}

template <typename T>
ListLinked<T>::~ListLinked(){
	Node<T>* aux = first;
	while(aux != nullptr){
		aux = first->next;
		delete first;
		first = aux;
	}
}

template <typename T>
T ListLinked<T>::operator[](int pos){
	
	Node<T>* aux = first;
	if(pos > n-1 || pos < 0)
		throw std::out_of_range("Fuera de rango");
	else{
		for(int i = 0; i < pos; i++)
			aux = aux-> next;
		return aux->data;
	}
}

template <typename U>
std::ostream& operator<<(std::ostream &out, const ListLinked<U> &node){
	Node<U>* aux = node.first;
	while(aux != nullptr){
		out << aux->data << " ";
		aux = aux->next;
	}
	return out;
}


template <typename T>
void ListLinked<T>::insert(int pos, T e){
    
  if(pos == 0){
    first = new Node<T>(e, first);
    n++;
  }
  else{
    
    Node<T>* aux = first;
    Node<T>* anterior = nullptr;
	  
    if(pos > n|| pos < 0)
      throw std::out_of_range("fuera de rango");
    else{
      for(int i = 0; i < pos; i++){
	anterior = aux;
	aux = aux -> next;
      }
      anterior-> next = new Node<T>(e, aux);
      n++;
    }
  }
}


template <typename T>
void ListLinked<T>::append(T e){
	Node<T>* aux = first;

   	while(aux->next != nullptr)
		aux = aux->next;
	aux->next = new Node<T>(e, nullptr);
	n++;
}

template <typename T>
void ListLinked<T>::prepend(T e){

	first = new Node<T>(e, first);
	n++;
}

template <typename T>
T ListLinked<T>::remove(int pos){
	Node<T>* aux = first;
	Node<T>* anterior = nullptr;
	T rem;
	if(pos == 0)
	  first = first -> next;
	else{
	  if(pos > n - 1 || pos < 0)
	    throw std::out_of_range("fuera de rango");
	  else{
	    for(int i = 0; i < pos; i++){
	      anterior = aux;
	      aux = aux -> next;
	    }
	    anterior -> next = aux -> next;
	  }
	}
	    rem = aux->data;
	    delete aux;
	    n--;
	    return rem;
	
	
}

template <typename T>
T ListLinked<T>::get(int pos){
	Node<T>* aux = first;
	
	if(pos > n -1 || pos < 0)
                throw std::out_of_range("fuera de rango");
	else{
		for(int i = 0; i < pos; i++)
			aux = aux -> next;
		return aux -> data;
	}
}

template <typename T>
int ListLinked<T>::search(T e){
	Node<T>* aux = first;
	int pos = 0;

	while(aux != nullptr && aux->data != e){
		aux = aux -> next;
		pos++;
	}
	if(aux == nullptr)
		return -1;
	else
		return pos;
}

template <typename T>
int ListLinked<T>::size(){
	return n;
}

template <typename T>
bool List<T>::empty(){
	if(size() == 0)
		return true;
	return false;
}


