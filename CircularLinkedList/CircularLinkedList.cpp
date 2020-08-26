//
// Created by gat78 on 8/26/2020.
//

#include "CircularLinkedList.hpp"
#include "iostream"

CircularLinkedList::CircularLinkedList(int value) {
    _start = new CircularLinkedList::CLLNode(value);
    printList();
}

int CircularLinkedList::listLength() {
    auto* _current = _start;

    int count = 0;

    do {
        ++count;
        _current = _current->next;
    }while (_current!=_start);

    return count;
}

void CircularLinkedList::printList() {
    auto* _current = _start;

    while(_current && _current !=_start){
        std::cout << _current;
        _current = _current->next;
    }
}

void CircularLinkedList::addToStart(int value) {
    auto* node = new CircularLinkedList::CLLNode(value);
    auto* endNode = CircularLinkedList::getLastNode();
    node->next = _start;
    endNode->next = node;
    _start = node;
}

void CircularLinkedList::addToEnd(int value) {
    auto* node = new CircularLinkedList::CLLNode(value);
    auto* endNode = CircularLinkedList::getLastNode();
    node->next = _start;
    printList();
    endNode->next = node;
}

void CircularLinkedList::addAtPosition(int value, int position) {
    if(position == 0){
        CircularLinkedList::addToStart(value);
        return;
    }
    auto* node = new CircularLinkedList::CLLNode(value);
    auto* _currentNode = _start;
    int curr_position = 1;

    while(true){
        _currentNode = _currentNode->next;

        if (curr_position == position - 1)
            break;
        else if (_currentNode == _start) {
            std::cout << "Position is out of range of this list" << std::endl;
            std::cout << "Last position available is " << position << std::endl;
            return;
        }

        ++curr_position;
    }

    node->next = _currentNode;
    _currentNode->next = node;
}

void CircularLinkedList::removeFromPosition(int position) {
    if (position == 0){
        auto* node = CircularLinkedList::getLastNode();
        node->next = _start->next;
        _start = _start->next;
        delete _start;
        return;
    }
    auto* _currentNode = _start;
    int curr_position = 1;

    while(true){
        _currentNode = _currentNode->next;
        if (curr_position == position - 1)
            break;
        else if (_currentNode == _start) {
            std::cout << "Position is out of range of this list" << std::endl;
            std::cout << "Last position available is " << position << std::endl;
            return;
        }
        ++curr_position;
    }
    auto* nodeToRemove = _currentNode->next;
    _currentNode->next = nodeToRemove->next;
    delete nodeToRemove;
}

CircularLinkedList::CLLNode *CircularLinkedList::getLastNode() {
    CircularLinkedList::CLLNode* _current = _start;

    // if this is true we have only one element and we haven't formed a
    // circle yet
    if(_current->next!= nullptr) {
        do {
            _current = _current->next;
        } while (_current != _start);
    }
    return _current;
}
