#include <iostream>
#include "SinglyLinkedList/SinglyLinkedList.hpp"

int main() {
    SinglyLinkedList ll(16);
    ll.addToEnd(10);
    ll.addToStart(20);
    ll.addAtPosition(40,1);
    ll.printList();
    return 0;
}
