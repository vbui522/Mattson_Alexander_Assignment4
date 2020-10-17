#include "ItemType.h"
#include "ListNode.h"
// I forget if its neccesary to put these here w g++
#include <cstddef>
#include "SortedLinkedList.h"
#include <string> // do I need?
#include <iostream>
#include <ostream>

// Lots of questions about memory leaks, deconstructre etc. Rememebr to use valgrind to check

using namespace std;

// default  constructor
SortedLinkedList::SortedLinkedList()
{
    head = nullptr;
    currentPos = nullptr;
}

//need not default constructor

//deconstructor
SortedLinkedList::~SortedLinkedList()
{
    // c++: can we delete head or do we need to delete each element

    ListNode temp = *head;
    while (temp.next != 0)
    {
        ListNode next = *temp.next; // gotta make sure next is right w pointer notation
        //delete temp;
        temp = next;
    }
    delete head;
}

int SortedLinkedList::length() const
{
    if (head == nullptr)
    {
        return 0;
    }
    // cout << "entering length" << endl;
    int c = 0;
    ListNode *temp = head;
    do
    {
        // print addresses
        // cout << "Index: " << c <<" ";
        //temp->printElement();
        c++;
        temp = temp->next;
    } while (temp != nullptr);

    //todo one item
    return c;
}

void SortedLinkedList::insertItem(ItemType item)
{
   // cout << "trying to insert: " << item.getValue() << endl;

    //cout << "Entering insert" << endl;
    bool beyondCurrPos = false;

    if (head == nullptr)
    {
        ListNode *newNode = new ListNode(item, nullptr);
        head = newNode;
      //  cout << " New head at " << head->item.getValue() << endl;
        currentPos = head;
        // cout << "inserted first element" << endl;
      //  cout << "inserted to empty list: " << endl;
        // this->printList();
       // newNode->printElement();
        return;
    }

    // need case for inserting at start of list
    if (item.compareTo(head->item) == ItemType::LESS)
    {
        ListNode *newNode2 = new ListNode(item, head);
        head = newNode2;
        currentPos = getPrevious(currentPos);
       // cout << " New head at " << head->item.getValue() << endl;
        //cout << "inserted to head of list:" << endl;
        //newNode2->printElement();
        return;
    }

    // head->printElement();
    ListNode *temp = head; // TODO< temp as ptr?

    while (temp != nullptr)
    {

        if (item.compareTo(temp->item) == ItemType::EQUAL)
        {
            cout << "Sorry. You cannot insert the duplicate item" << endl;
            return;
        }

        if (temp->next == nullptr || item.compareTo(temp->next->item) == ItemType::LESS)
        {
            ListNode *newNode3 = new ListNode(item, temp->next);
            temp->next = newNode3;
            if (!beyondCurrPos || temp == currentPos)
            {
                currentPos = getPrevious(currentPos);
            }
            //cout << "inserted in general case" << endl;
        
            //cout << "___inner result___" << endl;
            //this->printList();
            //newNode3->printElement();
            return;
        }
        //   item is still less than list element, move on
        if (temp == currentPos)
        {
            beyondCurrPos = true;
        }
        temp = temp->next;
    }
}

void SortedLinkedList::deleteItem(ItemType item)
{
    // TODO - check if deletions are correct
    //empty list
    if (head == 0)
    {
        cout << "You cannot delete from an empty list" << endl;
        return; // correct exit?
    }
    // case where deleting head
    else if (head->item.compareTo(item) == ItemType::EQUAL)
    {
        currentPos = currentPos->next;
        head = head->next;
        return;
    }

    // did this way before I had a getPrevious method
    ListNode *temp_k = head;
    ListNode *temp_k_1 = head->next;
    bool afterCursor = false;
    while (temp_k_1 != 0)
    {
        if (temp_k_1 == currentPos->next)
        {
            afterCursor = true;
        }

        if (temp_k_1->item.compareTo(item) == ItemType::EQUAL)
        { // I don't know this enum works like this

            // cout << "Found a match" << endl;
            if (temp_k_1 == currentPos)
            {
                currentPos = currentPos->next;
            }
            else if (!afterCursor)
            {
             //   cout << "increased cursor" << endl;
                currentPos = currentPos->next;
            }
            temp_k->next = temp_k_1->next;
            return;
        }
        temp_k = temp_k->next;
        temp_k_1 = temp_k_1->next;
    }
    // if none of the oher cases are met
    cout << "Item not found." << endl;
}

int SortedLinkedList::searchItem(ItemType item)
{
    ListNode *temp = head;
    int c = 0;
    while (temp != nullptr)
    {
        if (temp->item.compareTo(item) == ItemType::EQUAL)
        {
            return c;
        }
        else
        {
            c++;
            temp = temp->next;
        }
    }
    // if nothing found
    // cout << "Item not found" << endl;
    return -1;
}

ItemType SortedLinkedList::GetNextItem()
{
   // cout << "Enter GNI" << endl;

    // edge case
    ItemType nothing;
    // empty list
    if (head == 0)
    {
        cout << "List is empty" << endl;
        return nothing;
    }
    if (currentPos == nullptr)
    {
        cout << "The end of the list has been reached" << endl;
        ItemType i;
        i.initialize(-1);
        return i;
    }
    // last item
    // if (currentPos->next == nullptr)
    // {
    //     return currentPos->item;
    // }

    else
    { // general case
        ListNode *temp = currentPos;
        currentPos = currentPos->next;
        return temp->item;
    }
}

void SortedLinkedList::ResetList()
{
    // used simply to reset index tracker
    currentPos = head;
}

void SortedLinkedList::printList()
{
    ListNode *temp = head;

    while (temp != nullptr)
    {
        cout << temp->item.getValue() << " ";
        temp = temp->next;
    }
    cout << endl;
    // cout << "cursor index: " << searchItem(currentPos->item) << endl;

    // cout << searchItem(currentPos->item);

    return;
}

ListNode *SortedLinkedList::getPrevious(ListNode *n)
{
    int kIndex = searchItem(n->item);
    ListNode *temp = head;
    int currentIndex = 0;
    while (currentIndex < kIndex - 1)
    {
        currentIndex++;
        temp = temp->next;
    }
    return temp;
    // tool to adjust current pointer.
}

//TODO - his method doesnt work for different sized list - dups go undetected.
int SortedLinkedList::searchDup(SortedLinkedList list2)
{
    ListNode *node1 = this->head;
    ListNode *node2 = new ListNode(list2.getHead()->item, list2.getHead()->next);

    //ItemType comp = temp;

    // while (temp != nullptr) {
    for (int i = 0; i < list2.length(); i++)
    {
        cout << "in first" << endl;
        for (int j = 0; j < this->length(); j++)
        {
            cout << "in second" << endl;
            if (node1->item.compareTo(node2->item) == ItemType::EQUAL)
            {
                cout << "in if" << endl;
                return -1;
            }
            if (node1->next == nullptr || node2->next == nullptr)
            {
                return 1;
            }

            node1 = node1->next;
        }
        node2 = node2->next;
        // TODO - running twice
    }
    cout << "leaving dup" << endl;
    return 1;
    // }
}

void SortedLinkedList::merge(SortedLinkedList *list2)
{

    bool checker = false;
    //cont = searchDup(list2);
    for (int i = 0; i < list2->length(); i++)
    {
        if (this->searchItem(list2->currentPos->item) > -1)
        {
            checker = true;
            // cout << "found dupe" << endl;
        }
        list2->currentPos = list2->currentPos->next;
    }
    list2->ResetList();

    ListNode *temp2 = new ListNode(list2->getHead()->item, list2->getHead()->next);
    int cont;
    // ItemType item;
    // SortedLinkedList finalList;

    //  cont = searchDup(*list2);
    if (checker)
    {
        cout << "Sorry. You cannot insert the duplicate item." << endl;
        return;
    }
    else
    {
        while (temp2 != nullptr)
        {

            ItemType copy;
            int i = temp2->item.getValue();
            copy.initialize(i);

            this->insertItem(copy);
            if (temp2->next == nullptr)
            {
            //    cout << "leaving merge" << endl;
                return;
            }
            temp2 = temp2->next;
            //cout << "Moving onto ";
            //temp2->printElement();
        }
    }
    // cout << "leaving merge" << endl;
}

void SortedLinkedList::delAltNode()
{
    ListNode *temp = this->head;
    int length = this->length();
    if (length < 2)
    {
        //handle
        cout << "List length is too short to apply this operation" << endl;
        return;
    }
    // even case
    if (length % 2 == 0)
    {
        while (temp->next->next != nullptr)
        {
            deleteItem(temp->next->item);
            temp = temp->next;
        }
        deleteItem(temp->next->item);
    }
    else
    { // odd case
        while (temp->next != nullptr)
        {
            deleteItem(temp->next->item);
            temp = temp->next;
        }
    }
    cout << "List after alternate delete: ";
}

ListNode *SortedLinkedList::getHead()
{
    return head;
};

// I believe he said it was fine to make a new list, on piazza
SortedLinkedList *SortedLinkedList::findIntersection(SortedLinkedList *other)
{
    // cout << "====== Intersect =======" << endl;
    SortedLinkedList *finList = new SortedLinkedList();
    ListNode *temp = new ListNode(other->getHead()->item, other->getHead()->next);

    // iterate rthrough other list
    while (temp != nullptr)
    {
        // cout << " - - - " << endl;
       // cout << "temp: " << temp->item.getValue() << endl;
       //  cout << &temp << " " << temp->item.getValue() << " " << temp->next << endl;
        if (this->searchItem(temp->item) != -1)
        { // found in this
            ItemType copy;
            int i = temp->item.getValue();
            copy.initialize(i);
            finList->insertItem(copy);
            // cout << "found an intersection: " << i << endl;
        }
        if (temp->next == nullptr)
            break;
        temp = temp->next;
    }
    // finList->printList();
    // cout << " +==========+" << endl;
    return finList;
}
