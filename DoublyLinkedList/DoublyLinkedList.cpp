

#include "DoublyLinkedList.h"
#include "ItemType.h"
#include <iostream>
#include <ostream>

using namespace std;

DoublyLinkedList::DoublyLinkedList()
{
    head = nullptr;
    tail = nullptr;
    //  length = 0;
}

DoublyLinkedList::~DoublyLinkedList()
{
    NodeType temp = *head;
    while (temp.next != 0)
    {
        NodeType next = *temp.next;
        temp = next;
    }
    delete head;
}

int DoublyLinkedList::lengthIs() const
{
    if (head == nullptr)
    {
        return 0;
    }
    int count = 0;
    NodeType *temp;
    temp = head;
    do
    {
        count++;
        temp = temp->next;
    } while (temp != nullptr);
    {
        return count;
    }
}

void DoublyLinkedList::insertItem(ItemType &item)
{
    // if list is empty
    if (head == nullptr)
    {
        NodeType *temp = new NodeType;
        head = temp;
        tail = temp;
        temp->data = item;
        temp->back = nullptr;
        temp->next = nullptr;
        print();
        cout << "inserted node: " << temp->data.getValue() << " fwd: " << temp->next << " back: " << temp->back << endl;
        // cout <<  " head: " << head->data << " tail: " << tail->data << endl;
         cout << head << endl;
        cout << tail << endl;
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
        cout << "inserted node: " << temp2->data.getValue() << " fwd: " << temp2->next << " back: " << temp2->back << endl;
        // cout <<  " head: " << head->data << " tail: " << tail->data << endl;
        cout << head << endl;
        cout << tail << endl;
        print();
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
        cout << "inserted node: " << nTail->data.getValue() << " fwd: " << nTail->next << " back: " << nTail->back << endl;
        // cout <<  " head: " << head->data << " tail: " << tail->data << endl;
        
         cout << head << endl;
            cout << tail << endl;
        print();
        return;
    }

    // general case
    NodeType *temp3;
    temp3 = head;
    // cout << temp3;
    int  count = 0;
    while (temp3 != nullptr || count > 20)
    {
        count++;
        // cout << "WILEY" << endl;
        /*
    if (item.compareTo(temp3 -> data) == ItemType::EQUAL) {

      if (item.getValue() == temp3 -> data.getValue()) {
        NodeType *nodeH = new NodeType;
        nodeH -> data = item;
        nodeH -> next = head;
        head = nodeH;
        nodeH -> back = nullptr;
        return;
      } // if head is equal to item
      if (item.getValue() == temp3 -> data.getValue() && temp3->next->next == nullptr ) {
        NodeType *nodeT = new NodeType;
        nodeT -> data = item;
        nodeT -> back = tail;
        tail = nodeT;
        nodeT -> next = nullptr;
        return;
      }//end if of tail is equal to item
    } //end equal if

    */

        // item is greater than list
        if (temp3->next == nullptr) {

        }
        // item.compareTo(temp3->data) == ItemType::GREATER || 
        // if (temp has ,moveed off the list node) || (item is at the lower bound of list)
        if (item.compareTo(temp3->next->data) == ItemType::LESS || item.compareTo(temp3->next->data) == ItemType::EQUAL)
        {
            cout << "in general" << endl;
            NodeType *newNode = new NodeType;
            NodeType * succesor;
            succesor = temp3->next;
            newNode->data = item;
            newNode->next = temp3->next;
            newNode->back = temp3;
            succesor->back = newNode;

            // insert forwards
            temp3->next = newNode;


            // insert backwards

            
            cout << "inserted node: " << newNode->data.getValue() << " fwd: " << newNode->next << " back: " << newNode->back << endl;
            // cout <<  " head: " << head->data << " tail: " << tail->data << endl;
            cout << head << endl;
            cout << newNode << endl;
            cout << tail << endl;
            print();
            return;
        } // general case
        temp3 = temp3->next;

    } // looping through list
    return;
}

void DoublyLinkedList::print()
{
    NodeType *temp = head;
    int count = 0;
    while (temp != nullptr && count < 50)
    {
        count++;
        cout << temp->data.getValue() << " ";
        // cout << "next is " << temp->next;
        temp = temp->next;
    }
    cout << endl;
    return;
}

void DoublyLinkedList::printReverse()
{
    NodeType *temp = tail;
    while (tail != nullptr)
    {
        cout << temp->data.getValue() << " ";
        temp = temp->back;
    }
    cout << endl;
    return;
}

void DoublyLinkedList::deleteItem(ItemType &item)
{
    if (head == 0)
    {
        cout << "You cannot delete from an empty list" << endl;
        return;
    }
    else if (head->data.compareTo(item) == ItemType::EQUAL)
    {
        head = head->next;
        return;
    }
    NodeType *temp1 = head;
    NodeType *temp2 = head->next;

    while (temp2 != 0)
    {
        if (temp2->data.compareTo(item) == ItemType::EQUAL)
        {
            temp1->next = temp2->next;
            return;
        }
        temp1 = temp2->next;
        temp2 = temp2->next;
    }
    cout << "Item not found." << endl;
}
