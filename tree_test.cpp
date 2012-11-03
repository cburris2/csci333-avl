#include "BST.h"

int main() {
  BST<int>* bst = new BST<int>();

  bst->insert(10);
  bst->insert(5);
  bst->insert(15);
  bst->insert(3);
  bst->insert(7);
  bst->insert(12);
 
  bst->insert(17);
  bst->remove(7);
  
  bst->treePrint();
  bst->print();

}
