#ifndef DOUBLYLINKEDLIST
#define DOUBLYLINKEDLIST
#include "ItemType.h"
using namespace std;

class DoublyLinkedList {


  struct NodeType {
    ItemType data;
    NodeType *next;
    NodeType *back;
  };


public:
  DoublyLinkedList();
  ~DoublyLinkedList();
  int lengthIs() const;
  void insertItem(ItemType &item);
  void deleteItem(ItemType &item);
  void print();
  void printReverse();
  void swapAlternate();

 private:
  NodeType *head;
  NodeType *tail;

};
#endif








