#include "AVL.h"
#include "Node.h"
#include <iostream>

int main() {
  AVL<int>* avlTree = new AVL<int>();
   
  avlTree->insert(4);
  avlTree->insert(7);
  avlTree->insert(6);
  avlTree->insert(8);
  avlTree->insert(9);
  avlTree->insert(12);
 
  avlTree->print();
/*  avlTree->remove(9);  // remove not working 100%
  avlTree->remove(4);
  avlTree->remove(2);
  avlTree->print();
 // std::cout << avl << std::endl;
  //avl->traversalPrint(avl->root);
// std::cout << avlTree->inOrderTraversal(root) << std::endl;
  */  


}

