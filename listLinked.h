#include <ostream>
#include "List.h"
#include "Node.h"

template <typename V>
class ListLinked : public List<V> {

    private:

    	Node<V>* first;
	int n;

    public:	
	ListLinked();
    	~ListLinked();
	V operator[](int pos);
	template <typename U> friend std::ostream& operator<<(std::ostream &out, const ListLinked<U> &node);
	void insert(int pos, V e) override;
	void append(V e) override;
	void prepend(V e) override;
	V remove(int pos) override;
	V get(int pos) override;
	int search(V e) override;
	int size() override;
	void invert_list();
};

template <typename V>
ListLinked<V>::ListLinked(){
	first = nullptr;
	n = 0;

}


template <typename V>
void ListLinked<V>::invert_list(){
	
  	Node<V>* aux2 = first;	
	V x;
	for(int i = 0; i <= (n/2); i++){ 
	       	Node<V>* aux = first;	

		
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

template <typename V>
ListLinked<V>::~ListLinked(){
	Node<V>* aux = first;
	while(aux != nullptr){
		aux = first->next;
		delete first;
		first = aux;
	}
}

template <typename V>
V ListLinked<V>::operator[](int pos){
	
	Node<V>* aux = first;
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


template <typename V>
void ListLinked<V>::insert(int pos, V e){
    
  if(pos == 0){
    first = new Node<V>(e, first);
    n++;
  }
  else{
    
    Node<V>* aux = first;
    Node<V>* anterior = nullptr;
	  
    if(pos > n|| pos < 0)
      throw std::out_of_range("fuera de rango");
    else{
      for(int i = 0; i < pos; i++){
	anterior = aux;
	aux = aux -> next;
      }
      anterior-> next = new Node<V>(e, aux);
      n++;
    }
  }
}


template <typename V>
void ListLinked<V>::append(V e){
	Node<V>* aux = first;

   	while(aux->next != nullptr)
		aux = aux->next;
	aux->next = new Node<V>(e, nullptr);
	n++;
}

template <typename V>
void ListLinked<V>::prepend(V e){

	first = new Node<V>(e, first);
	n++;
}

template <typename V>
V ListLinked<V>::remove(int pos){
	Node<V>* aux = first;
	Node<V>* anterior = nullptr;
	V rem;
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

template <typename V>
V ListLinked<V>::get(int pos){
	Node<V>* aux = first;
	
	if(pos > n -1 || pos < 0)
                throw std::out_of_range("fuera de rango");
	else{
		for(int i = 0; i < pos; i++)
			aux = aux -> next;
		return aux -> data;
	}
}

template <typename V>
int ListLinked<V>::search(V e){
	Node<V>* aux = first;
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

template <typename V>
int ListLinked<V>::size(){
	return n;
}

template <typename V>
bool List<V>::empty(){
	if(size() == 0)
		return true;
	return false;
}


