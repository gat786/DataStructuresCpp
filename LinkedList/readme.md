# Linked Lists

A linked list is a data structure used for storing collections of data. 
A linked list has the following properties.

* Successive elements are connected by pointers
* The last element points to NULL (not in the case of circular linked lists)
* Can grow or shrink in size during execution of a program
* Can be made just as long as required (until systems memory exhausts)
* Does not waste memory space (but takes some extra memory for pointers). It
allocates memory as list grows.

### Main Linked Lists Operations
* Insert: inserts an element into the list
* Delete: removes and returns the specified position element from the list

### Auxiliary Linked Lists Operations
* Delete List: removes all elements of the list (disposes the list)
* Count: returns the number of elements in the list
* Find n th node from the end of the list


Linked Lists have three kinds of implementations and they are implemented 
in the given folders below.

1. [Singly Linked Lists](SinglyLinkedList)  
2. [Doubly Linked Lists](DoublyLinkedList)
3. [Circular Linked Lists](CircularLinkedList)