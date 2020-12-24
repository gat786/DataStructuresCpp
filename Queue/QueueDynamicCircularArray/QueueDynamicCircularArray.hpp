//
// Created by gat78 on 24-12-2020.
//

#ifndef DATASTRUCTURESCPP_QUEUEDYNAMICCIRCULARARRAY_HPP
#define DATASTRUCTURESCPP_QUEUEDYNAMICCIRCULARARRAY_HPP

#include "../QueueSimpleCircularArray/QueueSimpleCircularArray.hpp"

class QueueDynamicCircularArray : public QueueSimpleCircularArray{
public:
    void enqueueItem(struct Queue* queue, int data);
    void resizeQueue(struct Queue* queue);
};

#endif //DATASTRUCTURESCPP_QUEUEDYNAMICCIRCULARARRAY_HPP
