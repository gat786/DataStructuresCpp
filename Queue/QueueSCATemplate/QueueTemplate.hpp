//
// Created by gat786 on 1/2/21.
//

#ifndef DATASTRUCTURESCPP_QUEUETEMPLATE_HPP
#define DATASTRUCTURESCPP_QUEUETEMPLATE_HPP

#include "iostream"
#include "cstring"

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

    struct QueueT<T>::Queue* createQueue();
    struct QueueT<T>::Queue* createQueue(int size);
    bool isQueueEmpty(struct Queue* queue);
    bool isQueueFull(struct Queue* queue);
    void resizeQueue(struct Queue* queue);
    int sizeOfQueue(struct Queue* queue);
    virtual void enqueueItem(struct Queue* queue,T data);
    int dequeueItem(struct Queue* queue);
    void deleteQueue(struct Queue* queue);
    void printQueue(struct Queue* queue);
};

template <typename T>
struct QueueT<T>::Queue* QueueT<T>::createQueue() {
    auto queue = new QueueT<T>::Queue();
    return queue;
}

template <typename T>
struct QueueT<T>::Queue* QueueT<T>::createQueue(int size) {
    auto queue = new QueueT<T>::Queue(size);
    return queue;
}

template <typename T>
void QueueT<T>::printQueue(struct Queue *queue) {
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

template <typename T>
void QueueT<T>::enqueueItem(struct Queue *queue, T data) {
    if (isQueueFull(queue)){
        std::cout << "Queue is already full. Can't add " << data << std::endl;
    }else{
        queue->rear = (queue->rear + 1) % queue->capacity;
        queue->array[queue->rear] = data;
        if(queue->front == -1)
            queue->front = queue->rear;
    }
}

template <typename T>
void QueueT<T>::deleteQueue(struct Queue *queue) {
    delete[] queue->array;
    delete queue;
}

template <typename T>
int QueueT<T>::dequeueItem(struct Queue *queue) {
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

template <typename T>
int QueueT<T>::sizeOfQueue(struct Queue *queue) {
    return (queue->capacity - queue->front + queue->rear + 1) % queue->capacity;
}

template <typename T>
bool QueueT<T>::isQueueFull(struct Queue *queue) {
    return (queue->rear + 1) % queue->capacity == queue->front;
}

template <typename T>
bool QueueT<T>::isQueueEmpty(struct Queue *queue) {
    return queue->front == -1;
}

template <typename T>
void QueueT<T>::resizeQueue(struct Queue *queue) {
    int oldCapacity = queue->capacity;
    queue->capacity = oldCapacity * 2;
    T* newStack = new T[queue->capacity]{};
    memcpy(newStack,queue->array,oldCapacity * sizeof(T));
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


#endif //DATASTRUCTURESCPP_QUEUETEMPLATE_HPP
