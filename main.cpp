#include <iostream>
#include "DoublyLinkedList/DoublyLinkedList.hpp"

int main() {

    auto* ll = new DoublyLinkedList(1);
    ll->addToEnd(2);
    ll->addToEnd(3);
    ll->addToEnd(4);
    ll->addtoStart(0);
    ll->addToPosition(786,8);
    ll->printDLL();
    ll->removeFromPosition(5);
    ll->printDLL();
    return 0;
}
