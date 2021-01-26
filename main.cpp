#include <iostream>
#include "Queue/QueueSCATemplate/QueueTemplate.hpp"

int main() {
    auto queueTemplate = new QueueT<std::string>();
    auto queue = queueTemplate->createQueue();
    queueTemplate->enqueueItem(queue,"first");
    queueTemplate->enqueueItem(queue,"second");
    queueTemplate->enqueueItem(queue,"third");
    queueTemplate->printQueue(queue);
}