//
// Created by gat78 on 25-12-2020.
//

#include <iostream>
#include "QueueLinkedList.hpp"

struct QueueLinkedList::Queue * QueueLinkedList::CreateQueue() {
    auto queue = new Queue();
    return queue;
}

bool QueueLinkedList::IsQueueEmpty(QueueLinkedList::Queue *queue) {
    return queue->front == nullptr;
}

void QueueLinkedList::EnqueueItem(QueueLinkedList::Queue *queue, int data) {
    // create a new node with value given
    auto newNode = new SinglyLinkedList::SLLNode(data);

    // if we have some value at rear push the current node in next part of it
    if (queue->rear)
        queue->rear->next = newNode;

    // update the current rear
    queue->rear = newNode;

    // if front is null then queue is empty and update it to be same as rear
    if (queue->front == nullptr)
        queue->front = queue->rear;
}

int QueueLinkedList::DequeueItem(QueueLinkedList::Queue *queue) {
    int data = 0;
    SinglyLinkedList::SLLNode* temp;

    if (IsQueueEmpty(queue)){
        std::cout << "Queue is currently empty" << std::endl;
        return 0;
    } else {
        temp = queue->front;
        data = queue->front->value;
        queue->front = queue->front->next;
    }

    return data;
}

void QueueLinkedList::DeleteQueue(QueueLinkedList::Queue *queue) {
    SinglyLinkedList::SLLNode* temp;
    while (queue->front){
        temp = queue->front;
        queue->front = queue->front->next;
        delete temp;
    }
    delete queue;
}

void QueueLinkedList::PrintQueue(QueueLinkedList::Queue *queue) {
    auto temp = queue->front;
    while (temp != nullptr) {
        std::cout << temp->value << " | ";
        temp = temp->next;
    }
    std::cout << std::endl;
}