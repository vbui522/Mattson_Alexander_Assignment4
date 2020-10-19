#ifndef _CLLIST
#define _CLLIST

#include "NodeType.h"
#include "ItemType.h"
#include <string>
using namespace std;

class CircularLinkedList{
    public:
    CircularLinkedList();
    ~CircularLinkedList();
    void insertItem(ItemType &item);
    void deleteItem(ItemType &item);
    int lengthIs() const;
    void print();
    void findItem(ItemType item, NodeType * &location, NodeType *& predLoc, bool &found);
    private:
    NodeType * listData;
    int length;
};

#endif