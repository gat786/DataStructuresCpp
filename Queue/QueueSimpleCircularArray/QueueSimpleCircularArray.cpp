//
// Created by gat78 on 15-12-2020.
//

#include "QueueSimpleCircularArray.hpp"

struct QueueSimpleCircularArray::Queue * QueueSimpleCircularArray::CreateQueue() {
    Queue* queue{};
    return queue;
}

bool QueueSimpleCircularArray::isQueueEmpty(struct Queue *queue) {
    return queue->front == -1;
}

bool QueueSimpleCircularArray::isQueueFull(struct Queue *queue) {
    return (queue->rear + 1) % queue->capacity == queue->front
}