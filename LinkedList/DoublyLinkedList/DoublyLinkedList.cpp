//
// Created by gat78 on 8/22/2020.
//
/*
    Driver code for this file :-
    Dont forget to add the header file before pasting this.

    auto* ll = new DoublyLinkedList(1);
    ll->addToEnd(2);
    ll->addToEnd(3);
    ll->addToEnd(4);
    ll->addtoStart(0);
    ll->addToPosition(786,3);
    ll->printDLL();
    ll->removeFromPosition(6);
    ll->printDLL();
 */

#include "iostream"
#include "DoublyLinkedList.hpp"

DoublyLinkedList::DoublyLinkedList(int value) {
    _start = new DLLNode(value);
}

void DoublyLinkedList::addtoStart(int value) {
    auto* node = new DoublyLinkedList::DLLNode(value);
    node->next = _start;
    _start->prev = node;
    _start = node;
}

void DoublyLinkedList::addToEnd(int value) {
    auto* node = new DoublyLinkedList::DLLNode(value);
    DoublyLinkedList::DLLNode* current = _start;

    while (current && current->next)
        current = current->next;
    current->next = node;
    node->prev = current;
}

void DoublyLinkedList::addToPosition(int value, int position) {
    if (position == 0)
        throw std::runtime_error("Use DoublyLinkedList::addToStart");

    auto* node = new DoublyLinkedList::DLLNode(value);
    DoublyLinkedList::DLLNode* current = _start;

    int i = 0;
    while (i < position) {
        if (current->next == nullptr) {
            std::cout << "Lists length is less than specified position";
            current = nullptr;
            break;
        }else {
            current = current->next;
            ++i;
        }
    }
    if (current!= nullptr) {
        DLLNode *prev = current->prev;
        current->prev = node;
        prev->next = node;
        node->prev = prev;
        node->next = current;
    }

}

void DoublyLinkedList::removeFromPosition(int position) {
    DoublyLinkedList::DLLNode* current = _start;

    int i = 0;
    while (i < position) {
        if (current->next == nullptr) {
            std::cout << "last index of list is " << i
                << " cant remove element at " << position << "\n";
            return;
        }
        current = current->next;
        ++i;
    }

    DoublyLinkedList::DLLNode* previous = current->prev;
    if(current->next!= nullptr) {
        DoublyLinkedList::DLLNode *next = current->next;
        previous->next = next;
        next->prev = previous;
        delete current;
    }else{
        previous->next = nullptr;
        delete current;
    }
}

void DoublyLinkedList::printDLL() {
    DoublyLinkedList::DLLNode* current = _start;

    while(current != nullptr){
        if (current->prev!= nullptr)
            std::cout << "(" << current->prev->value << ") <- ";
        std::cout << current->value << " ->";
        if (current->next!= nullptr) {
            std::cout << " (" << current->next->value << ")";
            std::cout << " -- ";
        }
        current = current->next;
    }
    std::cout << " **";
    std::cout << "\n";
}