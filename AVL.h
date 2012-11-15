#ifndef __AVL_H__
#define __AVL_H__

#include "Node.h"
#include <string>

template <typename T>
class AVL {
 private:
  Node<T>* root;
  void traversalPrint(Node<T>* root);

 public:
  AVL<T>();
  ~AVL<T>();

  bool find(T v);
  void remove(T v);
  void insert(T v);
  void print();
  void treePrint();
  void rotateRight(Node<T>** critNode);
  void rotateLeft(Node<T>** critNode);
  void inOrderTraversal(Node<T>* root);
  void postOrderTraversal(Node<T>* root);
};


#endif
