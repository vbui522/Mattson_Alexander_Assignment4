# Mattson_Alexander_Assignment4
CSCI 2720: Assignment 2 - Sorted Linked List
[To pair remote key with odin](https://github.com/cs1302uga/cs1302-tutorials/blob/master/github-setup.md#setting-up-ssh-keys)

Rachel Mattson
811951277
ram13275@uga.edu

Sarah Alexander
811190156
sa29588@uga.edu



We partner coded for most of the classes. Rachel spent more time implementing merge, intersect, deleteAlt while Sarah spent time figuring out the time complexities. 


Circular Linked List:
Pseudocode for deleteSubsection:

For our intersection method, we created a new SortedLinkedList and a ListNode was created to access the elements of the SortedLinkedList being passed in. We then had a while loop to loop through the list being passed in. Within the while loop, we have an if statement that uses our searchItem method in order to find values that are the same. After confirming a value was found that was the same, an ItemType object was created to initialize and insert items into a final list. It loops through until the next item is null, which then causes the loop to break. At the end of the method, we return the final list. 


Pseudocode for mode:


Doubly Linked List:
PseudoCode for SwapAlternates


Compiling contructions:

Use `make run` to run the file with input.txt seeding the list.
To enter in a different command line argument, use `make` to compile the code, then `./main <your_filename>` to run the program.

To check that there are no memory leaks, compile everything with `make` then run valgrind --leak-check=yes -s ./bin/main input.txt 

