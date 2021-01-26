//
// Created by gat78 on 24-12-2020.
//
#include <cstring>
#include <iostream>
#include "QueueDynamicCircularArray.hpp"

/*
 *  Implementation main code paste it into the main function to see its
 *  running.
 *
    auto queueDynamicCircularArray = new QueueDynamicCircularArray{};
    auto queue = queueDynamicCircularArray->createQueue();
    queueDynamicCircularArray->enqueueItem(queue,1);
    queueDynamicCircularArray->enqueueItem(queue,2);
    queueDynamicCircularArray->enqueueItem(queue,3);
    queueDynamicCircularArray->printQueue(queue);
    queueDynamicCircularArray->enqueueItem(queue,4);
    queueDynamicCircularArray->enqueueItem(queue,5);
    queueDynamicCircularArray->printQueue(queue);
    std::cout << "dequeued data " << queueDynamicCircularArray->dequeueItem(queue) << std::endl;
    queueDynamicCircularArray->printQueue(queue);
    queueDynamicCircularArray->deleteQueue(queue);
    delete queueDynamicCircularArray;
 */

void QueueDynamicCircularArray::enqueueItem(struct Queue *queue, int data) {
    if(isQueueFull(queue))
        resizeQueue(queue);
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->array[queue->rear] = data;
    if(queue->front == -1)
        queue->front = queue->rear;

}

void QueueDynamicCircularArray::resizeQueue(struct Queue *queue) {
    int oldCapacity = queue->capacity;
    queue->capacity = oldCapacity * 2;
    int* newStack = new int[queue->capacity]{};
    memcpy(newStack,queue->array,oldCapacity * sizeof(int));
    std::cout << "increasing size of the queue to " << queue->capacity << std::endl;
    if(queue->front > queue->rear){
        for(int i = 0; i < queue->front; i++){
            queue->array[i+oldCapacity] = queue->array[i];
        }
        queue->rear = queue->rear + oldCapacity;
    }
    delete[] queue->array;
    queue->array = newStack;
}