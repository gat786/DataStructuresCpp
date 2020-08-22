//
// Created by gat78 on 8/22/2020.
//

#ifndef DATASTRUCTURESCPP_DOUBLYLINKEDLIST_HPP
#define DATASTRUCTURESCPP_DOUBLYLINKEDLIST_HPP


class DoublyLinkedList {
    struct DLLNode{
        int value;
        struct DLLNode* prev;
        struct DLLNode* next;
        DLLNode() { prev = nullptr; next = nullptr;}
        explicit DLLNode(int value) { value = value; prev = nullptr; next = nullptr; }
    };
    DLLNode* start;

public:
    explicit DoublyLinkedList(int value);

    void addtoStart(int value);

    void addToEnd(int value);

    void addToPosition(int value);
};


#endif //DATASTRUCTURESCPP_DOUBLYLINKEDLIST_HPP
