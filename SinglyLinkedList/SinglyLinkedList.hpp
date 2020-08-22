//
// Created by gat78 on 8/22/2020.
//

#ifndef DATASTRUCTURESCPP_SINGLYLINKEDLIST_HPP
#define DATASTRUCTURESCPP_SINGLYLINKEDLIST_HPP

#pragma once
class SinglyLinkedList
{
    struct SLLNode {
        int value{};
        struct SLLNode* next;
        SLLNode() { next = nullptr; }
        explicit SLLNode(int value) : value(value), next(nullptr) {}
    };
    SLLNode* _start;

public:
    explicit SinglyLinkedList(int value);

    int listLength();

    void addToStart(int value);

    void addToEnd(int value);

    void addAtPosition(int value, int position);

    void printList();
};

#endif //DATASTRUCTURESCPP_SINGLYLINKEDLIST_HPP
