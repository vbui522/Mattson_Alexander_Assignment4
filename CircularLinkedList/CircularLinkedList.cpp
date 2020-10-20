#include "ItemType.h"
#include "NodeType.h"
#include "CircularLinkedList.h"
// I forget if its neccesary to put these here w g++
#include <cstddef>
#include <string> // do I need?
#include <iostream>
#include <ostream>
#include <string.h>

// Lots of questions about memory leaks, deconstructre etc. Rememebr to use valgrind to check

using namespace std;


// default  constructor
CircularLinkedList::CircularLinkedList()
{
    listData = nullptr;
    // listData->next = listData;
    length = 0;
    // currentPos = nullptr;
}

//need not default constructor

//deconstructor
CircularLinkedList::~CircularLinkedList()
{
    // c++: can we delete head or do we need to delete each element
}

void CircularLinkedList::findItem(ItemType item, NodeType *&location, NodeType *&predLoc, bool &found)
{
    // cout << "Trying to find " << item.getValue() << endl;
    bool moreToSearch = true;
    location = listData->next;
    predLoc = listData;
    found = false;
    cout << "predloc is " << predLoc->data.getValue() << endl;

    while (moreToSearch && !found)
    {
        if (item.compareTo(location->data) == ItemType::LESS)
        { // less than the lowest value in list mean DNE
            moreToSearch = false;
        }
        else if (item.compareTo(location->data) == ItemType::EQUAL)
        { // Found it!
            found = true;
        }
        else
        {
            // move up one
            predLoc = location;
            location = location->next;
            moreToSearch = (location != listData->next); // back to start
            // if (!moreToSearch){
            //     return;
            // }
        }
    }
    cout << "leaving findItem, predLoc is " << predLoc->data.getValue() << endl;
    return;
}

int CircularLinkedList::lengthIs() const
{
    return length;
}

void CircularLinkedList::insertItem(ItemType &item)
{
    cout << "Trying to insert " << item.getValue() << endl;
    // pretty similar to the way its done in the book.
    // I think I've traced through it wnought o understnad what's happening
    // cout << "1" << endl;
    NodeType *newNode = new NodeType;
    // cout << "2" << endl;
    newNode->data = item;
    // cout << "3" << endl;
    NodeType *predLoc;
    NodeType *location;
    // cout << "4" << endl;
    bool found;
    // cout << "5" << endl;

    if (listData != nullptr)
    {
        cout << "inserting to list" << endl;
        findItem(item, location, predLoc, found);

        // if (found)
        // {
        //     return;
        // }
        
        newNode->next = location; // predloc-> next
        predLoc->next = newNode;
        
        // if taking last spot in list
        if (item.compareTo(listData->data) == ItemType::GREATER)
        { //TODO direction
            cout << "insert to end" << endl;
            listData = newNode;
        }
    }
    else
    { // list is empty
        cout << "Inserting to empty list" << endl;
        listData = newNode;      // was null
        newNode->next = newNode; 
    }
    length++;
    cout << "Leaving insert" << endl;
    print();
    cout << " " << endl;
    return;
}

void CircularLinkedList::deleteItem(ItemType &item)
{
    NodeType *predLoc;
    // NodeType * newNode;
    NodeType *location;
    bool found;

    findItem(item, location, predLoc, found);
    if (!found) {
        cout << "Item not found in list" << endl;
        return;
    }

    if (predLoc == location)
    {
        listData = nullptr;
    } // single node in list
    else
    {
        predLoc->next = location->next;
        if (location == listData)
        {
            listData = predLoc;
        }
    }
    delete location; // actually remove object
    length--;
    return;
}

void CircularLinkedList::print()
{
    if (listData != nullptr)
    {
        NodeType *predLoc = listData;
        NodeType *location = predLoc->next;

        do
        {
            cout << location->data.getValue() << " ";
            // predLoc = location;
            location = location->next;
        } while (location != listData->next);
        cout << endl;
    }
}
