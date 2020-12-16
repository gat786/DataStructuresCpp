//
// Created by gat78 on 15-12-2020.
//

#ifndef DATASTRUCTURESCPP_QUEUESIMPLECIRCULARARRAY_HPP
#define DATASTRUCTURESCPP_QUEUESIMPLECIRCULARARRAY_HPP

class QueueSimpleCircularArray{
    struct Queue{
        int front,rear;
        int capacity;
        int* queue;

        Queue(){
            front = rear = -1;
            capacity = 1;
            queue = new int[capacity]{};
        }

        explicit Queue(int size){
            front = rear = -1;
            capacity = size;
            queue = new int[capacity];
        }
    };

public:

    struct QueueSimpleCircularArray::Queue* CreateQueue();
    bool isQueueEmpty(struct Queue* queue);
    bool isQueueFull(struct Queue* queue);
    int sizeOfQueue(struct Queue* queue);
    void enqueueItem(struct Queue* queue,int data);
    void dequeueItem(struct Queue* queue);
    void deleteQueue(struct Queue* queue);
};

#endif //DATASTRUCTURESCPP_QUEUESIMPLECIRCULARARRAY_HPP
