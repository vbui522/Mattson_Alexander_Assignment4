#ifndef _SRTLIST
#define _SRTLIST
#include "ListNode.h"
#include "ItemType.h"
#include <string>
using namespace std;

class SortedLinkedList {

 public:
  SortedLinkedList();
  ~SortedLinkedList();
  int length() const;
  void insertItem(ItemType item);
  void deleteItem(ItemType item);
  int searchItem(ItemType item);
  ItemType GetNextItem();
  void ResetList();
  void printElement(ListNode *node);
  void printList();
  ListNode*  getPrevious(ListNode * n);
  int searchDup(SortedLinkedList list2);
    void merge(SortedLinkedList * list2);
  void delAltNode();
  ListNode* getHead();
  SortedLinkedList* findIntersection(SortedLinkedList * other);
  
private:
  ListNode *head;
  ListNode *currentPos;
}; 



#endif
