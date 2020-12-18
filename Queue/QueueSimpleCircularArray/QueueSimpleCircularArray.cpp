//
// Created by gat78 on 15-12-2020.
//

#include <iostream>
#include "QueueSimpleCircularArray.hpp"

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
            while (index % queue->capacity != queue->rear){
                std::cout << queue->array[index] << " | ";
                ++index;
            };
        }else{
            std::cout << queue->array[queue->front] << " | ";
        }
        std::cout << std::endl;
    }
}