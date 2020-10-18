#include "ItemType.h"
#include "CircularLinkedList.h"
#include <exception>
#include <cstddef>
// #include "SortedLinkedList.h"
#include "NodeType.h"
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

    CircularLinkedList bossList;
    ItemType item;
    int input;
    std::fstream file;
    file.open(argv[1], fstream::in);

    if(file.is_open()){
        cout << "opened file" << endl;
        file >> input;
        while (!file.eof()) { // fast error checking
            item.initialize(input);
            bossList.insertItem(item);
            file >> input; // next thing
        }
    } else {
        cout << "Failed to open the input file" << endl;
        return 1;
    }

    bossList.print();

    // read in file

    // present menu

    // 

}