#include "BST.h"
#include <iostream>

template <typename T>
BST<T>::BST() {
  root = 0;
}

template <typename T>
BST<T>::~BST() {
  
}


template <typename T>
bool BST<T>::find(T v) {
  Node<T>* temp = new Node<T>(v);
  root = temp;  
  return true;
}

template <typename T>
void BST<T>::insert(T v) {
  Node<T>* temp = new Node<T>(v);
  Node<T>** curr = &root;

  while (*curr != 0) {
    if (v < (*curr)->getValue()) {
      curr = &((*curr)->getLeftChild());
    } else if (v > (*curr)->getValue()) {
      curr = &((*curr)->getRightChild());
    }
  }
  *curr = temp;
}

template <typename T>
void BST<T>::remove(T v) {
  Node<T>** curr = &root;
  Node<T>* nodeToRemove;
  Node<T>* iOS;

   if ((*curr) !=0) {
	  while((*curr) != 0 && (*curr)->getValue() != v){
		if(v > (*curr)->getValue()){
		    curr= &(*curr)->getRightChild();
		}
		else{  
		    curr= &(*curr)->getLeftChild();
		    }
			  
	  }
	  nodeToRemove = *curr;
	  if(*curr == 0) { return;}
	  iOS = (*curr)->getRightChild(); 	  
	  while(iOS->getValue() != 0 && iOS->getValue() > v){ 
		if(v < iOS->getValue() && iOS->getValue() != 0){
		    iOS = iOS->getLeftChild();
		}
	  
	  }
	  iOS->setLeftChild(*nodeToRemove->getLeftChild()); 	
	  *curr=iOS;
	  delete nodeToRemove;


    }
}
template <typename T>
void BST<T>::print() {
  traversalPrint(root);
}

template <typename T>
void BST<T>::traversalPrint(Node<T>* root) {
  if(root != 0) {
  
    traversalPrint(root->getLeftChild());
    
    std::cout << root->getValue() << std::endl;
    
    traversalPrint(root->getRightChild()); 


  }

}

template class BST<int>;
template class BST<double>;
//template class BST<std::string>;
