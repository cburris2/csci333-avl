#include "AVL.h"
#include "Node.h"
#include <iostream>

int main() {
  AVL<int>* avlTree = new AVL<int>();
   
  avlTree->insert(1);
  avlTree->insert(2);
  avlTree->insert(3);
  avlTree->insert(8);
  avlTree->insert(9);
  avlTree->insert(12);
 
//  avlTree->remove(9);
  avlTree->insert(11);
  avlTree->print();
 // std::cout << avl << std::endl;
  //avl->traversalPrint(avl->root);
// std::cout << avlTree->inOrderTraversal(root) << std::endl;
    


}

