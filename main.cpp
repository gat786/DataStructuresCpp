#include <iostream>
#include "Queue/QueueSimpleCircularArray/QueueSimpleCircularArray.hpp"

int main() {
    QueueSimpleCircularArray queueCircularArray{};
    auto queue = queueCircularArray.CreateQueue();
    queueCircularArray.enqueueItem(queue,1);
    queueCircularArray.enqueueItem(queue,2);
    queueCircularArray.enqueueItem(queue,3);
    queueCircularArray.enqueueItem(queue,4);
    queueCircularArray.printQueue(queue);
    std::cout << "dequeuing item " << queueCircularArray.dequeueItem(queue) << std::endl;
    queueCircularArray.enqueueItem(queue,5);
    queueCircularArray.enqueueItem(queue,6);
    queueCircularArray.enqueueItem(queue,7);
    std::cout << "dequeuing item " << queueCircularArray.dequeueItem(queue) << std::endl;
    std::cout << "dequeuing item " << queueCircularArray.dequeueItem(queue) << std::endl;
    queueCircularArray.enqueueItem(queue,8);
    queueCircularArray.enqueueItem(queue,9);
    queueCircularArray.enqueueItem(queue,10);
    queueCircularArray.enqueueItem(queue,11);
    std::cout << "dequeuing item " << queueCircularArray.dequeueItem(queue) << std::endl;
    queueCircularArray.enqueueItem(queue,12);
    queueCircularArray.printQueue(queue);
    queueCircularArray.deleteQueue(queue);
}
