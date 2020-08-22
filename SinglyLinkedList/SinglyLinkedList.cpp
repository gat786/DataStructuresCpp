//
// Created by gat78 on 8/22/2020.
//
/*
 *  Driver code: -
 *  Paste this in Main.cpp for making this example run
 *
 *  SinglyLinkedList ll(16);
 *  ll.addToEnd(10);
 *  ll.addToStart(20);
 *  ll.addAtPosition(40,1);
 *  ll.printList();
 *
 *  Also include the header file ;) 👍🏼
 */

#include <iostream>
#include "SinglyLinkedList.hpp"

SinglyLinkedList::SinglyLinkedList(int value) {
    _start = new SLLNode(value);
}


int SinglyLinkedList::listLength() {
    SinglyLinkedList::SLLNode* current = _start;
    int count = 0;

    while (current)
        ++count, current = current->next;

    return count;
}

void SinglyLinkedList::addToStart(int value) {
    SinglyLinkedList::SLLNode* node =
            new SinglyLinkedList::SLLNode(value);
    node->next = _start;
    _start = node;
}

void SinglyLinkedList::addToEnd(int value) {
    SLLNode* node = new SLLNode(value);
    SLLNode* current = _start;

    while (current && current->next) {
        current = current->next;
    }

    current->next = node;
}

void SinglyLinkedList::addAtPosition(int value, int position) {
    if (position == 0)
        throw std::runtime_error("Use SinglyLinkedList::addToStart");

    SLLNode *node = new SLLNode(value);

    SLLNode* current = _start;

    for (int i = 0; i < position - 1; i++)
        current = current->next;
    if (current->next)
        node->next = current->next;
    current->next = node;
}

void SinglyLinkedList::printList()
{
    SinglyLinkedList::SLLNode* current = _start;
    while (current != nullptr) {
        std::cout << current->value << "->";
        current = current->next;
    }
}