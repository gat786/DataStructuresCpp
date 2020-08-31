//
// Created by gat78 on 8/26/2020.
//

#ifndef DATASTRUCTURESCPP_CIRCULARLINKEDLIST_HPP
#define DATASTRUCTURESCPP_CIRCULARLINKEDLIST_HPP


class CircularLinkedList {
    struct CLLNode {
        int value{};
        struct CLLNode* next;
        CLLNode() { next = this; }
        explicit CLLNode(int value) : value(value), next(nullptr) {}
    };
    CLLNode* _start;

    CLLNode* getLastNode();

public:
    explicit CircularLinkedList(int value);

    int listLength();

    void addToStart(int value);

    void addToEnd(int value);

    void addAtPosition(int value, int position);

    void printList();

    void removeFromPosition(int position);
};


#endif //DATASTRUCTURESCPP_CIRCULARLINKEDLIST_HPP
