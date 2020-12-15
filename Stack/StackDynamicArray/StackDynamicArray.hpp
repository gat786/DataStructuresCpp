//
// Created by gat78 on 04-10-2020.
//

#ifndef DATASTRUCTURESCPP_STACKDYNAMICARRAY_HPP
#define DATASTRUCTURESCPP_STACKDYNAMICARRAY_HPP


class StackDynamicArray {
    struct Stack {
        Stack(int item){
            top = 1;
            capacity = 1;
            array = new int[capacity]{};
        };

        Stack() {
            top = -1;
            capacity = 1;
            array = new int[capacity]{};
        };

        int top;
        int capacity;
        int *array;
    };

public:
    struct StackDynamicArray::Stack *CreateStack();

    bool isStackEmpty(Stack* stack);

    bool isStackFull(Stack* stack);

    void doubleStackSize(Stack* stack);

    void pushItem(int data,Stack* stack);

    int popItem(Stack* stack);

    void deleteStack(Stack* stack);

    void printStack(Stack* stack);
};


#endif //DATASTRUCTURESCPP_STACKDYNAMICARRAY_HPP
