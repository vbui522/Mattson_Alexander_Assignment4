CircularLinkedList​() Post-Condition: List is created.

~CircularLinkedList​()
Pre-Condition: List is created. Post-Condition: all nodes are freed.
void​ ​insertItem​(ItemType &​item​)
Pre-Condition: List exists.
Post-Condition: The item is inserted into the list in sorted order. Duplicate items are allowed.
void​ ​deleteItem​(ItemType &​item​)
Pre-Condition: List exists and item initialized. Post-Condition: the node that contains item is removed from the list. If the item is not present on the list print the message that is shown in the example output.
int​ ​lengthIs​() ​const Pre-Condition: List is initialized.
Post-Condition: return length instance variable.
void​ ​print​()
Pre-Condition: List exists.
Post-Condition: items are printed to standard-out based on the implementation in ItemType.