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
    length = 0;
    // currentPos = nullptr;
}

//need not default constructor

//deconstructor
CircularLinkedList::~CircularLinkedList()
{
    // c++: can we delete head or do we need to delete each element

}

void CircularLinkedList::findItem(ItemType item, NodeType * location, NodeType * predLoc, bool found){
    cout << "Trying to find " << item.getValue() << endl;
    bool moreToSearch = true;
    location = this->listData->next;
    predLoc = this->listData;
    found = false;

    while (moreToSearch && !found) {
        if (item.compareTo(location->data) == -1) { // less than the lowest value in list mean DNE
            moreToSearch = false;
        } else if (item.compareTo(location->data) == 0) { // Found it!
            found = true;
        } else {
            // move up one
            predLoc = location;
            location = location->next;
            moreToSearch = (location != listData->next); // back to start
        }
    }
    cout << "leaving findItem, predLoc is "<< predLoc->data.getValue() << endl;
    return;
}

int CircularLinkedList::lengthIs() const
{
    return length;
}

void CircularLinkedList::insertItem(ItemType & item)
{
    cout << "Trying to insert " << item.getValue() <<  endl;
    // pretty similar to the way its done in the book.
    // I think I've traced through it wnought o understnad what's happening
    NodeType * predLoc;
    // cout << "1" << endl;
    NodeType * newNode = new NodeType;
    // cout << "2" << endl;
    newNode->data = item;
    // cout << "3" << endl;
    NodeType * location;
    // cout << "4" << endl;
    bool found;
    // cout << "5" << endl;

    if (listData != nullptr){
        cout << "inserting to list" << endl;
        findItem(item, location, predLoc, found);
        // terminates with predloc where we want to insert
        // if not found in list... ?? pred loc is at end...
        cout << predLoc << endl;
        // general case
        // set newNode in list
            cout << "1" << endl;
        newNode->next = predLoc->next;
            cout << "2" << endl;
        cout << predLoc->data.getValue();
        predLoc->next = newNode;
        cout << predLoc->next->data.getValue();
            cout << "3" << endl;

        // if taking last spot in list
        if (item.getValue() < listData->data.getValue()) //TODO direction
            listData = newNode;
    } else { // list is empty
        cout << "Inserting to empty list" << endl;
        listData = newNode; // was null
        newNode->next = newNode; // TODO - understand
    }
    length++;
    cout << "Leaving insert" << endl;
}

void CircularLinkedList::deleteItem(ItemType& item)
{
    NodeType * predLoc;
    // NodeType * newNode;
    NodeType * location;
    bool found;

    findItem(item, location, predLoc, found);
    if (predLoc = location){
        listData = nullptr;
    } // single node in list
    else { 
        predLoc->next = location->next;
        if (location == listData){
            listData = predLoc;
        }
    }
    delete location; // actually remove object
    length--;

}

void CircularLinkedList::print()
{
    if (listData != NULL){
        NodeType * predLoc = listData;
        NodeType * location = predLoc->next;

        while(location != NULL) {
            cout << location->data.getValue();
            predLoc->next = location;
            location = location->next;
        }
    }
    return;
}
