//
// Created by gat78 on 15-12-2020.
//

#include <iostream>
#include "QueueSimpleCircularArray.hpp"

/*
 * QueueSimpleCircularArray queueCircularArray{};
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
 */

struct QueueSimpleCircularArray::Queue * QueueSimpleCircularArray::CreateQueue() {
    auto queue = new Queue{};
    return queue;
}

struct QueueSimpleCircularArray::Queue * QueueSimpleCircularArray::CreateQueue(int size) {
    auto queue = new Queue(size);
    return queue;
}

bool QueueSimpleCircularArray::isQueueEmpty(struct Queue *queue) {
    return queue->front == -1;
}

bool QueueSimpleCircularArray::isQueueFull(struct Queue *queue) {
    return (queue->rear + 1) % queue->capacity == queue->front;
}

void QueueSimpleCircularArray::enqueueItem(struct Queue *queue, int data) {
    if (isQueueFull(queue)){
        std::cout << "Queue is already full. Can't add " << data << std::endl;
    }else{
        queue->rear = (queue->rear + 1) % queue->capacity;
        queue->array[queue->rear] = data;
        if(queue->front == -1)
            queue->front = queue->rear;
    }
}

int QueueSimpleCircularArray::dequeueItem(struct Queue *queue) {
    int data = 0;
    if(isQueueEmpty(queue)){
        std::cout << "Queue is empty can't pop elements" << std::endl;
        return 0;
    }else{
        data = queue->array[queue->front];
        if(queue->front == queue->rear)
            queue->front = queue->rear = -1;
        else
            queue->front = (queue->front + 1) % queue->capacity;
    }
    return data;
}

int QueueSimpleCircularArray::sizeOfQueue(struct Queue *queue) {
    return (queue->capacity - queue->front + queue->rear + 1) % queue->capacity;
}

void QueueSimpleCircularArray::deleteQueue(struct Queue *queue) {
    delete[] queue->array;
    delete queue;
}

void QueueSimpleCircularArray::printQueue(struct Queue *queue) {
    if (isQueueEmpty(queue)){
        std::cout << "Queue is empty" << std::endl;
    } else {
        if (queue->front != queue->rear) {
            int index = queue->front;
            do {
                std::cout << queue->array[index] << " | ";
                index = (++index) % queue->capacity;
            } while (index % queue->capacity != queue->rear + 1);
        }else{
            std::cout << queue->array[queue->front] << " | ";
        }
        std::cout << std::endl;
    }
}