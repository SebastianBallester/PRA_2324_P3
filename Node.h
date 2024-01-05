#include <ostream>

template <typename T> 
class Node {
    public:
       T data;
       Node<T>* next;

       Node(T data, Node<T>* next = nullptr);
       template <typename U> friend std::ostream& operator<<(std::ostream &out, const Node<U> &node);
    
};


template <typename T>
Node<T>::Node(T data_, Node<T>* next_){
	data = data_;
	next = next_;
}

template <typename U>
std::ostream& operator<<(std::ostream &out, const Node<U> &node){
	
	while(node != nullptr){
		out << node.data << " ";
		node = node.next;
	}
	return out;
	
}
