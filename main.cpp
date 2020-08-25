#include <iostream>
#include "DoublyLinkedList/DoublyLinkedList.hpp"

int main() {

    auto* ll = new DoublyLinkedList(1);
    ll->addToEnd(2);
    ll->addToEnd(3);
    ll->addToEnd(4);
    ll->addtoStart(0);
    ll->addToPosition(786,3);
    ll->printDLL();
    ll->removeFromPosition(6);
    ll->printDLL();
    return 0;
}
