#include "AVL.h"
#include <iostream>
#include <list>
#include <vector>
#include <iomanip>
#include <math.h>
#include <string>



template <typename T>
AVL<T>::AVL() {
  root = 0;
}

template <typename T>
AVL<T>::~AVL() {
  
}


template <typename T>
bool AVL<T>::find(T v) {
  Node<T>* temp = new Node<T>(v);
  root = temp;
  return true;
}

template <typename T>
void AVL<T>::insert(T v) {
    Node<T>* temp = new Node<T>(v);
    Node<T>** curr = &root;
    Node<T>** critNode = &root;
    Node<T>** insertNode = &root;
    bool dblRotate = false;
    std::cout << "created nodes" << std::endl;


  /* insert from BST */
  while (*curr != 0) {
   
   
   
   if (v < (*curr)->getValue()) {
     if((*curr)->getLeftChild() != 0) { 
     (*curr)->setBalance((*curr)->getBalance()-1);
     }

     if((*curr)->getRightChild() != 0) { 
     (*curr)->setBalance((*curr)->getBalance()+1);
     }
    std::cout << "in while" << std::endl;
      if ((*curr)->getBalance() == -1){
		critNode = curr;
		dblRotate = true;
	}
     curr = &((*curr)->getLeftChild());
    } 
    else if (v > (*curr)->getValue()) {
    
     if((*curr)->getLeftChild() != 0) { 
     (*curr)->setBalance((*curr)->getBalance()-1);
     }

     if((*curr)->getRightChild() != 0) { 
     (*curr)->setBalance((*curr)->getBalance()+1);
     }
    std::cout << "in while" << std::endl;
      if ((*curr)->getBalance() == 1) {

		critNode = curr;
	}
    curr = &((*curr)->getRightChild());
    }

  }//end while 
  


  *curr = temp;
  insertNode = curr;
 //Right Right Case
    std::cout << "in if" << std::endl;
    if ((*critNode)->getBalance() == -1 ){
	  rotateRight(critNode);

     (*critNode)->setBalance(0);
     }

    else if ((*critNode)->getBalance() == 1 ){
	  rotateLeft(critNode);

     (*critNode)->setBalance(0);

     }

    else {
    dblRotate=true;
// }
 }
/*  while(critNode != 0){
     
    if (v < (*curr)->getValue()) {
       
	 dblRotate = true;
     curr = &((*curr)->getLeftChild());
    }


  }*/

  //  std::cout << (*critNode)->getValue() << std::endl;


}

template <typename T>
void AVL<T>::remove(T v) {
  Node<T>** curr = &root;
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
	  
	  if(*curr != 0){
	   Node<T>* nTR = (*curr);	  
	     if(nTR->getRightChild() == 0 && nTR->getLeftChild()==0){
	     *curr = 0;
	     }
	     else if (nTR->getRightChild() ==0){

		    *curr = (*curr)->getLeftChild();
	     } 
	     else if(nTR->getLeftChild() == 0){

		    *curr = (*curr)->getRightChild();
	     }
	     else {
		    iOS = nTR->getRightChild();
		    while (iOS->getLeftChild() != 0){

				iOS = iOS->getLeftChild();
				*curr = (*curr)->getRightChild();

		    }
		    iOS->setLeftChild(*(nTR->getLeftChild()));	  	    
		    *curr = (*curr)->getRightChild();

	     }
		delete nTR;
	  std::cout<< "nodeToRemove del "<<std::endl;

    }
    }
}



template <typename T>
void AVL<T>::rotateLeft(Node<T>** critNode) {
    Node<T>* tempRC = *critNode;
    Node<T>* tempLC = (*critNode)->getRightChild()->getLeftChild();
  
    *critNode = tempRC->getRightChild();
    
    (*critNode)->setLeftChild(*tempRC);
    
    tempRC->setRightChild(*tempLC);
    
    std::cout << "critNode is " << (*critNode)->getValue() << std::endl;
    std::cout << "root is " << root->getValue() << std::endl;
    std::cout << "tempRC is " << tempRC->getValue() << std::endl;
   
}

template <typename T>
void AVL<T>::rotateRight(Node<T>** critNode) {
    Node<T>** tempRC = &root;
    Node<T>** tempLC = &root;
    
    (*tempLC) = (*critNode)->getLeftChild();
    (*tempRC) = (*tempLC)->getRightChild();
    
    (*tempLC)->setRightChild(**critNode);
    (*critNode)->setLeftChild(**tempRC);

}


template <typename T>
void AVL<T>::print() {
  traversalPrint(root);
}

template <typename T>
void AVL<T>::traversalPrint(Node<T>* root) {
  if(root != 0) {

    std::cout << root->getValue() << std::endl;

  //  std::cout << "balance =" << root->getBalance() << std::endl;
    traversalPrint(root->getLeftChild());

  //  std::cout << root->getValue() << std::endl;
    traversalPrint(root->getRightChild()); 

  }

}



template <typename T>
void AVL<T>::treePrint(){
    std::list<Node<T>* > x;

    std::vector<std::vector<bool> > isPresent;
    std::vector<std::vector<T> > levels;
    
    std::vector<T> firstRows;
    std::vector<bool> otherRows;
    
    levels.push_back(firstRows);
    isPresent.push_back(otherRows);
    
    levels[0].push_back(root->getValue());
    isPresent[0].push_back(true);


    x.push_front(root);

    int curLevel = 1;
    int nextLevel = 0;
    int depth = 1;

    while(!x.empty()){
		Node<T>* val = x.front();
		x.pop_front();

		curLevel--;

		std::vector<T> row;
		std::vector<bool> nextRow;
		
		levels.push_back(row);
		isPresent.push_back(nextRow);

		if(val->getLeftChild()!=0){
		    x.push_back(val->getLeftChild());
		    levels[depth].push_back(val->getLeftChild()->getValue());
		    isPresent[depth].push_back(true);
		    nextLevel++;

		} 
		else { isPresent[depth].push_back(false);

		}

		if(val->getRightChild()!=0){
		    
		    x.push_back(val->getRightChild());
		    levels[depth].push_back(val->getRightChild()->getValue());
		    isPresent[depth].push_back(true);
		    nextLevel++;
    
		}
		if(curLevel==0){
		    depth++;
		    curLevel = nextLevel;
		    nextLevel = 0;

		}
		else { isPresent[depth].push_back(false);

		}


	 } 

	  int width;
	  for(int i = 0; i < depth; i++){
		width = pow(1.625, depth-i-1);
		if(isPresent[i][0]){
		    std::cout << std::setw(width) << levels[i][0];
		}
		else{
		    std::cout << std::setw(width) << "  ";
		}
		for(int j = 1; j < (int)levels[i].size(); j++){
		    if(isPresent[i][j]){
			  std::cout << std::setw(pow(1.75, depth-i-1)) <<
				std::setfill(' ') << levels[i][j];
	  	    }
		    else {
			  std::cout << std::setw(pow(1.75, depth-i-1)) <<
				    std::setfill(' ') << " ";
		    }

		}  
		std::cout << std::endl;
	  }

	  

}



template <typename T>
void AVL<T>::inOrderTraversal(Node<T>* root) {
    if (root != 0) {
    inOrderTraversal(root->getLeftChild());

   // inOrderTraversal(root->getValue());

    inOrderTraversal(root->getLeftChild());
    }

}



template <typename T>
void AVL<T>::postOrderTraversal(Node<T>* root) {
	  
    if (root != 0) {
	  postOrderTraversal(root->getLeftChild());
	  postOrderTraversal(root->getRightChild());
	 // postOrderTraversal(root->getValue());
    }
}

template class AVL<int>;
template class AVL<double>;
template class AVL<std::string>;
