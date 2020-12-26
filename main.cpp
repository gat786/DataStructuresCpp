#include <iostream>
#include "Queue/QueueLinkedList/QueueLinkedList.hpp"

int main() {
    auto queueLinkedList = new QueueLinkedList();
    auto queue = queueLinkedList->CreateQueue();
    queueLinkedList->EnqueueItem(queue,1);
    queueLinkedList->EnqueueItem(queue,2);
    queueLinkedList->EnqueueItem(queue,3);
    queueLinkedList->PrintQueue(queue);
    std::cout << "Dequeued item " << queueLinkedList->DequeueItem(queue) << std::endl;
    queueLinkedList->PrintQueue(queue);
    queueLinkedList->DeleteQueue(queue);
    delete queueLinkedList;
}