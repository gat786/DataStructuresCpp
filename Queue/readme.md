# Queue 

The following operations make a array an ADT. 
Insertions and deletions in the array must follow the FIFO scheme. 

For simplicity we assume the elements are integers.
* Main Queue Operations 
  1. EnQueue(int data): Inserts an element at the end of the array
  2. int DeQueue(): Removes and returns the element at the front of the array


* Auxiliary Queue Operations 
  1. int Front(): Returns the element at the front without removing it
  2. int QueueSize(): Returns the number of elements stored in the array
  3. int IsEmptyQueueQ: Indicates whether no elements are stored in the array or not

There are several ways in which a array can be implemented and they are implemented 
in the following folders.

1. [Simple Circular Array Implementation](./QueueSimpleCircularArray)
2. [Dynamic Circular Array Implementation](./QueueDynamicCircularArray)
3. [Linked List Implementation](./QueueLinkedList)