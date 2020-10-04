//
// Created by gat78 on 13-09-2020.
//

#ifndef DATASTRUCTURESCPP_STACKARRAY_HPP
#define DATASTRUCTURESCPP_STACKARRAY_HPP

#define MAX_SIZE 10;

class StackArray {
    struct Stack {
        Stack(int item){
            top = 1;
            capacity = MAX_SIZE;
            array = new int[capacity];
        };

        Stack() {
            top = -1;
            capacity = MAX_SIZE;
            array = new int[capacity];
        };

        int top;
        int capacity;
        int *array;
    };

public:
    struct Stack *CreateStack();

    bool isStackEmpty(Stack* stack);

    bool isStackFull(Stack* stack);

    void pushItem(int data,Stack* stack);

    int popItem(Stack* stack);

    void deleteStack(Stack* stack);

    void printStack(Stack* stack);
};

#endif //DATASTRUCTURESCPP_STACKARRAY_HPP
