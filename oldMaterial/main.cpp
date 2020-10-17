#include "ItemType.h"
#include <exception>
#include <cstddef>
#include "SortedLinkedList.h"
#include "ListNode.h"
#include <iostream>
#include <ostream>
#include <string>
#include <fstream>
#include <sstream>
// #include <string.h>

using namespace std;

SortedLinkedList *inputList(int length)
{

    SortedLinkedList *newList = new SortedLinkedList();

    try
    {
        ItemType current;
        string readNum;
        int nuum;
        // cout << readNum;
        string input;
        getline(cin, input);
        cout << "List elements separated by spaces in order: ";
        getline(cin, input);
        istringstream stream(input);
        string token;
        // std::string token2;
        // std::string token3;

        // getline is the spawn of the devil. We are doing this old-school.
        
        for (int i = 0; i < length; i++)
        {
            stream >> token;
            istringstream(token) >> nuum;
            current.initialize(nuum);
            newList->insertItem(current);
        }
    
    }
    catch (...)
    {
        cout << "Error: cannot parse input information." << endl;
    }
    // cout << "leaving newList" << endl;
    return newList;
}

int main(int argc, char **argv)
{
    //  cout << "How is world?" << endl;

    if (argc <= 1)
    {
        cout << "Usage: ./bin/main [list_file] " << endl;
        return 1;
    }

    // cout << argv[1] << endl;

    string file_name(argv[1]);

    SortedLinkedList bossList; // use for rest of program
    // fill the list with input
    try
    {
        ifstream sFile(file_name);

        ItemType current;
        string readNum;
        int nuum;
        cout << readNum;
        while (sFile >> readNum)
        {
         //   cout << "in while" << endl;
            istringstream(readNum) >> nuum;
            current.initialize(nuum);
            bossList.insertItem(current);
           // cout << "___result___ " << endl;
           // bossList.printList();
            // cout << nuum << endl;
        }
        sFile.close();
    }
    catch (...)
    {
        cout << "Error: cannot parse input information from file " << argv[1] << endl;
    }

    //   // test that we can build a sorted list

    ItemType i1 = ItemType();
    ItemType i2 = ItemType();
    ItemType i3 = ItemType();

    i1.initialize(7);
    i2.initialize(49);
    i3.initialize(11);

    SortedLinkedList test1;
    //   test1.length();
    //   cout << "Test List" << endl;
    test1.insertItem(i1);
    test1.insertItem(i2);
    test1.insertItem(i3);
    //   test1.length();
    //   test1.printList();

    // TODO - check input on insert stuff - is it an Int?.
    // TODO -  output for s is correct?

    bool run = true;
    string choice;

        cout << "Commands:\n(i) - Insert value\n(d) - Delete value\n(s) - Search value"
             << "\n(n) - Print next iterator value\n(r) - Reset Iterator\n(a) - Delete alternate nodes"
             << "\n(m) - Merge two lists\n(t) - Intersection\n(p) - Print list\n(l) - Print length\n(q) - Quit program\n";

    while (run)
    {

        cout << "Enter a command: ";
        cin >> choice; //check length

        // block all operations on an empty list except for those allowed here
        if (choice.compare("q") != 0 && choice.compare("i") != 0 && choice.compare("d") != 0 && bossList.length() == 0)
        {
            cout << "List is empty" << endl;
            continue;
        }

        if (choice.compare("i") == 0)
        {

            // inserting to empty
            bossList.printList(); // works on empty?
            cout << "Enter number: ";
            string input;
            int integer;
            cin >> input;                    //read in string
            istringstream(input) >> integer; // convert string to integer
            ItemType insertItem;
            insertItem.initialize(integer);
            bossList.insertItem(insertItem);
            bossList.printList();

        } //insert if
        else if (choice.compare("d") == 0)
        {
            bossList.printList(); // works on empty?
            cout << "Enter value to delete: ";
            string input;
            int integer;
            cin >> input;                    //read in string
            istringstream(input) >> integer; // convert string to integer
            ItemType dItem;
            dItem.initialize(integer);

            if (bossList.length() == 0)
            {
                cout << "You cannot cannot delete from an empty list." << endl;
                continue;
            }

            bossList.deleteItem(dItem);
            bossList.printList();

        } //delete if
        else if (choice.compare("s") == 0)
        {
            bossList.printList(); // works on empty?
            cout << "Enter value to search: ";
            string input;
            int integer;
            cin >> input;                    //read in string
            istringstream(input) >> integer; // convert string to integer
            ItemType sItem;
            sItem.initialize(integer);
            int i = bossList.searchItem(sItem);

            if (i != -1)
            {
                cout << "Index " << i << endl;
            }
            else
            {
                cout << "Item not found." << endl;
            }
            // TODO - check case

        } //search if
        else if (choice.compare("n") == 0)
        {
            int value = bossList.GetNextItem().getValue();
            if (value >= 0)
            {

                cout << value << endl;
            }

        } //print next iterator if
        else if (choice.compare("r") == 0)
        {
            bossList.ResetList();
        } //restart iterator if
        else if (choice.compare("a") == 0)
        {
            bossList.delAltNode();
            bossList.printList();
        } //delete alternate node if
        else if (choice.compare("m") == 0)
        {
            // TODO, error check second list input
            SortedLinkedList *secondList;
            cout << "Length of list to merge: ";
            // TODO error check length
            int length;
            cin >> length;
            if (cin.fail())
            {
                cout << "Please enter an integer next time" << endl;
                break;
            }
            secondList = inputList(length);
           // cout << "new list: " << endl;

            cout << "List 1: ";
            bossList.printList();
            cout << "List 2: ";
            secondList->printList();

            bossList.merge(secondList);
            bossList.printList();
        } //merge if
        else if (choice.compare("t") == 0)
        {
            // get list from user input
            SortedLinkedList *secondList;
            cout << "Length of list to find intersection: ";
            // TODO error check length
            int length;
            cin >> length;
            if (cin.fail() || length < 0)
            {
                cout << "Please enter a positive integer next time" << endl;
                break;
            }
            secondList = inputList(length);

            // cout << "new list: " << endl;
            // secondList->printList();

            bossList = *bossList.findIntersection(secondList);
             cout << "List 1: ";
            bossList.printList();
            cout << "List 2: ";
            secondList->printList();
            cout << "Intersection: ";
            bossList.printList();

        } //intersection if
        else if (choice.compare("p") == 0)
        {
            bossList.printList();
        } //print list if
        else if (choice.compare("l") == 0)
        {
            cout << "List length is " << bossList.length() << endl;
        } //print length if
        else if (choice.compare("q") == 0)
        {
            cout << "Quitting program..." << endl;
            run = false;
        } //quit program
        else
            cout << "Invalid command, try again!" << endl;
        continue;
    } //while
    exit(0);
}
