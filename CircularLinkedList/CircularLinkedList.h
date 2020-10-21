#ifndef _CLLIST
#define _CLLIST

#include "ItemType.h"
#include <string>
using namespace std;

class CircularLinkedList
{

    struct NodeType
    {
        ItemType data;
        NodeType *next;
        // NodeType *back;
    };

public:
    CircularLinkedList();
    ~CircularLinkedList();
    void insertItem(ItemType &item);
    void deleteItem(ItemType &item);
    int lengthIs() const;
    void print();
    void findItem(ItemType item, NodeType *&location, NodeType *&predLoc, bool &found);
    void printReverse();
    // void swapAlternate();
    void deleteSubsection(int lower, int upper);
    void mode();

private:
    NodeType *listData;
    int length;
};

#endif