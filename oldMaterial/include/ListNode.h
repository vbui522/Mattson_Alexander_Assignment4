
#ifndef _LSNODE
#define _LSNODE


#include <cstddef>
#include "ListNode.h"
#include "ItemType.h"
#include <string>
#include <string.h>
#include <iostream>
using namespace std;

class ListNode {
public:


  // Should be possible to make a constructor here

  // use in-class initializer to construct each node here
  
  ListNode(ItemType i, ListNode *n) {
    item = i;
    next = n;
  }

  ListNode(ItemType i) {
    item = i;
    next = nullptr;
  }


  
void printElement() {

  cout <<  this << " "<<  item.getValue()  << " " << next  << endl;
}
			    
  ItemType item;
  ListNode *next;

};

//does this need its own deconstructor or is `delete node` good enough in he linked list class

#endif
