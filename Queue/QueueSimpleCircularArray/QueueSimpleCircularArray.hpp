//
// Created by gat78 on 15-12-2020.
//

#ifndef DATASTRUCTURESCPP_QUEUESIMPLECIRCULARARRAY_HPP
#define DATASTRUCTURESCPP_QUEUESIMPLECIRCULARARRAY_HPP

class QueueSimpleCircularArray{

public:
    struct Queue{
        int front,rear;
        int capacity;
        int* array;

        Queue(){
            front = rear = -1;
            capacity = 1;
            array = new int[capacity]{};
        }

        explicit Queue(int size){
            front = rear = -1;
            capacity = size;
            array = new int[capacity];
        }
    };

    struct QueueSimpleCircularArray::Queue* CreateQueue();
    struct QueueSimpleCircularArray::Queue* CreateQueue(int size);
    bool isQueueEmpty(struct Queue* queue);
    bool isQueueFull(struct Queue* queue);
    int sizeOfQueue(struct Queue* queue);
    virtual void enqueueItem(struct Queue* queue,int data);
    int dequeueItem(struct Queue* queue);
    void deleteQueue(struct Queue* queue);
    void printQueue(struct Queue* queue);
};

#endif //DATASTRUCTURESCPP_QUEUESIMPLECIRCULARARRAY_HPP
