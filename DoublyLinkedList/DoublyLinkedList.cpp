
#include "DoublyLinkedList.h"
#include "ItemType.h"
#include <iostream>
#include <ostream>

using namespace std;

DoublyLinkedList::DoublyLinkedList()
{
    head = nullptr;
    tail = nullptr;
    length = 0;
}

DoublyLinkedList::~DoublyLinkedList()
{
    NodeType *temp = head;
    NodeType *temp2 = tail;
    NodeType *delNode = head;
    while (temp->next != 0)
    {
        delNode = temp;
        temp = temp->next;
        delete delNode;
    }
    delete head;
    delete tail;
}

int DoublyLinkedList::lengthIs() const
{
    return length;
}

void DoublyLinkedList::insertItem(ItemType &item)
{
    // if list is empty
    if (head == nullptr)
    {
        NodeType *temp = new NodeType;
        head = temp; //head and tail are set to new node
        tail = temp;
        temp->data = item;
        temp->back = nullptr;
        temp->next = nullptr;
        length++;

        return;
    }

    // insert to start of list
    if (item.compareTo(head->data) == ItemType::LESS)
    {
        NodeType *temp2 = new NodeType;
        temp2->data = item;

        temp2->next = head;
        //    tail = temp2 -> next;
        head = temp2;
        temp2->back = nullptr;
        length++;

        return;
    }

    // inserting to end of list
    if (item.compareTo(tail->data) == ItemType::GREATER)
    {
        NodeType *nTail = new NodeType;
        nTail->data = item;
        tail->next = nTail;
        nTail->back = tail;
        tail = nTail;
        nTail->next = nullptr;
        length++;

        return;
    }

    // general case
    NodeType *temp3;
    temp3 = head;

    int count = 0;
    while (temp3 != nullptr)
    {
        // item is greater than list
        if (temp3->next == nullptr)
        {
        }
        //general case if equal or less than
        if (item.compareTo(temp3->next->data) == ItemType::LESS || item.compareTo(temp3->next->data) == ItemType::EQUAL)
        {

            NodeType *newNode = new NodeType;
            NodeType *succesor;
            succesor = temp3->next;
            newNode->data = item;
            newNode->next = temp3->next;
            newNode->back = temp3;
            succesor->back = newNode;

            // insert forwards
            temp3->next = newNode;
            length++;
            return;
        } // general case
        temp3 = temp3->next;

    } // looping through list
    return;
}

void DoublyLinkedList::print()
{
    NodeType *temp = head;

    while (temp != nullptr) //loopping through nodes until it equals nullptr
    {
        cout << temp->data.getValue() << " ";
        temp = temp->next;
    }
    cout << endl;
    return;
}

void DoublyLinkedList::printReverse()
{
    //sets new node equal to tail and goes backwards
    NodeType *temp = tail;
    while (temp != nullptr)
    {
        cout << temp->data.getValue() << " ";
        temp = temp->back;
    }
    cout << endl;
    return;
}

void DoublyLinkedList::deleteItem(ItemType &item)
{
    //if deleting an empty case
    if (head == nullptr)
    {
        cout << "You cannot delete from an empty list" << endl;
        return;
    }
    //if item is equal to head
    else if (head->data.compareTo(item) == ItemType::EQUAL)
    {
        NodeType *temp = head;
        head = head->next;
        length--;
        delete temp;
        return;
    }
    NodeType *temp1 = head;
    NodeType *temp2 = head->next;

    //looping through till temp2 is at the end
    while (temp2 != nullptr)
    {
        //if lands on node it is searching for
        if (temp2->data.compareTo(item) == ItemType::EQUAL)
        {
            NodeType *tempDel = temp2;
            temp1->next = temp2->next;
            length--;
            print();
            delete tempDel;
            return;
        }
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    cout << "Item not found." << endl;
}

void DoublyLinkedList::swapAlternate() {


 // If linked list is empty or
    // there is only one node in list
  if (head == nullptr || head->next == nullptr) {
    cout << "The list is not big enough for the operation." << endl;
    return;
  }
    // Initialize previous and current pointers
    NodeType *before = head;
    NodeType *currNode = head->next;
    NodeType *n = currNode->next;
    head = currNode; // Change head before proceeeding

    while (true) { //trace through list
      n = currNode->next; //set n node
      currNode -> next = before; // Change next of
        // current as previous node

      if (n == nullptr || n->next == nullptr) { //to stop tracing through list
        before -> next = n;
        //      return;
        break;
      }
      // Change next of previous to next next
      before -> next = n -> next;
      before = n;
      currNode = before->next;
    }

    NodeType *trace = head;
    NodeType *traceB = head -> next;
    trace -> back = nullptr;

    while (trace -> next != nullptr) {// to link them backwards
      trace -> next -> back = trace;
      trace = trace -> next;
      if (trace -> next == nullptr) { //reset tail in list
        tail = trace;
      }
    }
    return;
}


/*
void DoublyLinkedList::swapAlternate()
{
    NodeType *temp = head;
    NodeType *temp2 = temp->next;

    if (lengthIs() == 0)
    {
        cout << "You cannot swap alternates on an empty list." << endl;
        return;
    }
    //until temp does not equal null pointer and its next does not as well
    while (temp != nullptr && temp->next != nullptr)
    {
        //call swap method to switch consecutive two nodes
        swap(temp->data, temp->next->data);
        temp = temp->next->next;
    }
}
*/
