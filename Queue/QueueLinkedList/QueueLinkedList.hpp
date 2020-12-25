//
// Created by gat78 on 25-12-2020.
//

#ifndef DATASTRUCTURESCPP_QUEUELINKEDLIST_HPP
#define DATASTRUCTURESCPP_QUEUELINKEDLIST_HPP

#include "../../LinkedList/SinglyLinkedList/SinglyLinkedList.hpp"

class QueueLinkedList{
public:
    struct Queue{
        struct SinglyLinkedList::SLLNode* front;
        struct SinglyLinkedList::SLLNode* rear;

        Queue(){
            front = nullptr;
            rear = nullptr;
        }
    };

    struct Queue* CreateQueue();
    bool IsQueueEmpty(QueueLinkedList::Queue* queue);
    void EnqueueItem(QueueLinkedList::Queue* queue, int data);
    int DequeueItem(QueueLinkedList::Queue* queue);
    void DeleteQueue(QueueLinkedList::Queue* queue);
    void PrintQueue(QueueLinkedList::Queue* queue);
};

#endif //DATASTRUCTURESCPP_QUEUELINKEDLIST_HPP
