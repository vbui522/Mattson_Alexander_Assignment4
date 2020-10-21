#include "ItemType.h"
// #include "NodeType.h"
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
    if (listData != nullptr)
    {
        cout << "In deconstructor" << endl;
        // NodeType *predLoc = listData;
        NodeType *location = listData->next;

        NodeType *temp;
        // while (lengthIs() > 0) {
        //     cout << lengthIs() < " ";
        //     // temp = &location;
        //     deleteItem(location->data); // gotta make sure next is right w pointer notation
        //     // delete temp;
        // }
        do
        {
            deleteItem(location->data);
        } while (location != listData);
        delete listData;
    }
    return;
    // c++: can we delete head or do we need to delete each element
}

void CircularLinkedList::findItem(ItemType item, NodeType *&location, NodeType *&predLoc, bool &found)
{
    // cout << "Trying to find " << item.getValue() << endl;
    bool moreToSearch = true;
    location = listData->next;
    predLoc = listData;
    found = false;

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
    // cout << "leaving findItem, predLoc is " << predLoc->data.getValue() << endl;
    return;
}

int CircularLinkedList::lengthIs() const
{
    return length;
}

void CircularLinkedList::insertItem(ItemType &item)
{
    // cout << "Trying to insert " << item.getValue() << endl;
    // pretty similar to the way its done in the book.
    // I think I've traced through it wnought o understnad what's happening
    // cout << "1" << endl;
    NodeType *newNode = new NodeType;
    newNode->data = item;
    NodeType *predLoc;
    NodeType *location;
    bool found;
    // cout << "5" << endl;

    if (listData != nullptr)
    {
        // cout << "inserting to list" << endl;
        findItem(item, location, predLoc, found);

        newNode->next = location; // predloc-> next
        predLoc->next = newNode;

        // if taking last spot in list
        if (item.compareTo(listData->data) == ItemType::GREATER)
        { //TODO direction
            // cout << "insert to end" << endl;
            listData = newNode;
        }
    }
    else
    { // list is empty
        // cout << "Inserting to empty list" << endl;
        listData = newNode; // was null
        newNode->next = newNode;
    }
    length++;
    // cout << "Leaving insert" << endl;
    // print();
    // cout << " " << endl;
    return;
}

// Assuming that the assinment wants us to delete just one of the input value
void CircularLinkedList::deleteItem(ItemType &item)
{
    NodeType *predLoc;
    // NodeType * newNode;
    NodeType *location;
    bool found;

    findItem(item, location, predLoc, found);
    if (!found)
    {
        cout << "Item not in list!" << endl;
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
    return;
}

// not neccesary for assignment...
void CircularLinkedList::printReverse()
{

    if (listData != nullptr)
    {
        // NodeType *predLoc = listData;
        NodeType *location = listData->next;

        int max_travel = lengthIs() - 1;
        int travel = max_travel;

        while (travel >= 0)
        {
            // cout << "traveling " << travel << " indices" << endl;
            // find one
            int curr = 0;
            location = listData->next;
            while (travel != curr)
            {
                location = location->next;
                curr++;
            }
            cout << location->data.getValue() << " ";
            travel--;
        }
        // loop around many times?
    }
    cout << endl;
    return;
}

void CircularLinkedList::deleteSubsection(int lower, int upper)
{
    // For comparison
    ItemType lowerBound;
    lowerBound.initialize(lower);
    ItemType upperBound;
    upperBound.initialize(upper);

    if (listData != nullptr)
    {
        // NodeType *predLoc = listData;
        NodeType *location = listData->next;
        do
        {
            if (location->data.compareTo(lowerBound) == ItemType::GREATER && location->data.compareTo(upperBound) == ItemType::LESS)
            {
                deleteItem(location->data);
            }
            else if (location->data.compareTo(lowerBound) == ItemType::EQUAL || location->data.compareTo(upperBound) == ItemType::EQUAL)
            {
                deleteItem(location->data);
            }
            location = location->next;

            // predLoc = location;
        } while (location != listData->next);
        print();
    }
    return;
}

void CircularLinkedList::mode()
{

    NodeType *location = listData->next;
    ItemType mode;
    int count;

    mode = listData->data;
    int max_count = 1;
    count = 1; // ?
    do
    {
        // if the next item is the same as the current
        if (location->next->data.compareTo(location->data) == ItemType::EQUAL)
        {
            count++;
        }
        else // start the count over again
        {
            count = 1;
        }
        // update mode if neccesary
        if (count > max_count)
        {
            max_count = count;
            mode = location->data;
            // cout << " updated mode to " << mode.getValue() << " with count " << count << endl;
        }
        // iterate through list
        location = location->next;
    } while (location != listData->next);
    cout << "Mode: " << mode.getValue() << endl;
    return;
}