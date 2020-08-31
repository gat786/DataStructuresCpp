//
// Created by gat78 on 8/26/2020.
//

#include "CircularLinkedList.hpp"
#include "iostream"

CircularLinkedList::CircularLinkedList(int value) {
    _start = new CircularLinkedList::CLLNode(value);
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

    if (_current->next == nullptr) {
        std::cout << _current->value << "*";
        return;
    }

    std::cout << _current->value;
    _current = _current->next;

    while(_current!=_start){
        std::cout  << "->" << _current->value;
        _current = _current->next;
    }
    std::cout  << "*" << std::endl;
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
    endNode->next = node;
}

void CircularLinkedList::addAtPosition(int value, int position) {
    if(position == 0){
        CircularLinkedList::addToStart(value);
        return;
    }
    auto* node = new CircularLinkedList::CLLNode(value);
    auto* _currentNode = _start;
    int curr_position = 0;
    if(_currentNode->next!= nullptr){

    }else{
        std::cout << "Length of list is " << curr_position << std::endl;
    }
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
    int curr_position = 0;

    while(true){
        ++curr_position;
        _currentNode = _currentNode->next;
        if (curr_position == position - 1)
            break;
        else if (_currentNode == _start) {
            std::cout << "Position is out of range of this list" << std::endl;
            std::cout << "Length of CLL is " << curr_position << std::endl;
            return;
        }
    }
    auto* nodeToRemove = _currentNode->next;
    _currentNode->next = nodeToRemove->next;
    delete nodeToRemove;
}

CircularLinkedList::CLLNode *CircularLinkedList::getLastNode() {
    CircularLinkedList::CLLNode* _current = _start;

    // if this is true we have only one element and we haven't formed a
    // circle yet
    if(_current->next != nullptr) {
        _current = _current->next;
        while(_current->next!= _start)
            _current = _current->next;

    }
    return _current;
}
