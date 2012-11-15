#include "AVL.h"
#include <iostream>

int main() {
  AVL<int>* avl = new AVL<int>();

  avl->insert(1);
  avl->insert(2);
  avl->insert(3);
/*  avl->insert(5);
  avl->insert(7);
  avl->insert(12);
 */
  avl->print();
 // std::cout << avl << std::endl;
  //avl->traversalPrint(avl->root);
  //std::cout<< avl->inOrderTraversal(root) << std::endl;
    



}
