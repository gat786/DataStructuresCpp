#include <iostream>
#include "CircularLinkedList/CircularLinkedList.hpp"

int main() {
    auto* circularLinkedList = new CircularLinkedList(1);
    circularLinkedList->addToStart(0);
    circularLinkedList->addToEnd(2);
    circularLinkedList->addToEnd(3);
    circularLinkedList->addToEnd(4);
    circularLinkedList->printList();

    std::cout << "Length of list is " <<
        circularLinkedList->listLength() << std::endl;

    circularLinkedList->removeFromPosition(2);
    circularLinkedList->printList();
    circularLinkedList->removeFromPosition(786);
    circularLinkedList->addAtPosition(786,2);
    circularLinkedList->printList();
    return 0;
}
