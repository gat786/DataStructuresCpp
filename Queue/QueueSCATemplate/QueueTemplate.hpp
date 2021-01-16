//
// Created by gat786 on 1/2/21.
//

#ifndef DATASTRUCTURESCPP_QUEUETEMPLATE_HPP
#define DATASTRUCTURESCPP_QUEUETEMPLATE_HPP

template<class T>
class QueueT{

public:
    struct Queue{
        int front,rear;
        int capacity;
        T* array;

        Queue(){
            front = rear = -1;
            capacity = 1;
            array = new T[capacity]{};
        }

        explicit Queue(int size){
            front = rear = -1;
            capacity = size;
            array = new T[capacity]{};
        }
    };

    struct QueueT::Queue* CreateQueue();
    struct QueueT::Queue* CreateQueue(int size);
    bool isQueueEmpty(struct Queue* queue);
    bool isQueueFull(struct Queue* queue);
    int sizeOfQueue(struct Queue* queue);
    virtual void enqueueItem(struct Queue* queue,int data);
    int dequeueItem(struct Queue* queue);
    void deleteQueue(struct Queue* queue);
    void printQueue(struct Queue* queue);
};


#endif //DATASTRUCTURESCPP_QUEUETEMPLATE_HPP
