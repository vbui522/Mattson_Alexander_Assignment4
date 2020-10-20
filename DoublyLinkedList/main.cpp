#include "ItemType.h"
#include "DoublyLinkedList.h"
#include <exception>
#include <cstddef>
// #include "SortedLinkedList.h"
// #include "NodeType.h"
#include <iostream>
#include <ostream>
#include <string>
#include <fstream>
#include <sstream>
// #include <string.h>

using namespace std;

int main(int argc, char **argv)
{
    cout << "Hello, World" << endl;

    if (argc <= 1)
    {
        cout << "Usage: ./main [list_file] " << endl;
        return 1;
    }

    DoublyLinkedList *bossList = new DoublyLinkedList();
    ItemType item;
    int input;
    std::fstream file;
    file.open(argv[1], fstream::in);

    if (file.is_open())
    {
        cout << "opened file" << endl;
        while (!file.eof())
        {
            file >> input;
            cout << "reading file: ";
            item.initialize(input);
            cout << item.getValue() << endl;
            bossList->insertItem(item);
            cin.get();
            // file >> input; // next thing
        }
    }
    else
    {
        cout << "Failed to open the input file" << endl;
        return 1;
    }

    bossList->print();
    cout << "insert (i), delete (d), length (l), print (p), deleteSub (b), mode (m), quit (q)" << endl;

    string choice;
    bool running = true;
}
/*
    while (running)
    {
        cout << "Enter a command: ";
        cin >> choice;

        if (choice.compare("i") == 0)
        {
            bossList->print(); // works on empty?
            cout << "Enter number: ";
            string input;
            int integer;
            cin >> input;                    //read in string
            istringstream(input) >> integer; // convert string to integer
            ItemType insertItem;
            insertItem.initialize(integer);
            bossList->insertItem(insertItem);
            bossList->print();
        }
        else if (choice.compare("d") == 0)
        {
            bossList->print(); // works on empty?
            cout << "Enter value to delete: ";
            string input;
            int integer;
            cin >> input;                    //read in string
            istringstream(input) >> integer; // convert string to integer
            ItemType dItem;
            dItem.initialize(integer);

            if (bossList->lengthIs() == 0)
            {
                cout << "You cannot cannot delete from an empty list." << endl;
                continue;
            }

        }
        else if (choice.compare("l") == 0)
        {
            bossList->lengthIs();
        }
        else if (choice.compare("p") == 0)
        {
            bossList->print();
        }
        else if (choice.compare("b") == 0)
        {

        }
        else if (choice.compare("m") == 0)
        {

        }
        else if (choice.compare("q") == 0)
        {
            cout << "Exiting..." << endl;
            return 0;
        }
    }
}
*/