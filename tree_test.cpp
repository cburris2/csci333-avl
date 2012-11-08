#include "AVL.h"

int main() {
  AVL<int>* avl = new AVL<int>();

  avl->insert(10);
  avl->insert(5);
  avl->insert(15);
  avl->insert(3);
  avl->insert(7);
  avl->insert(12);
 
  avl->insert(17);
  avl->remove(7);
  
  avl->treePrint();
  avl->print();

}
