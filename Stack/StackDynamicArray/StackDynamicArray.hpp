//
// Created by gat78 on 04-10-2020.
//

#ifndef DATASTRUCTURESCPP_STACKDYNAMICARRAY_HPP
#define DATASTRUCTURESCPP_STACKDYNAMICARRAY_HPP

/*
 *
    StackDynamicArray dynamicStack;
    auto stack = dynamicStack.CreateStack();
    dynamicStack.printStack(stack);
    dynamicStack.pushItem(1,stack);
    dynamicStack.printStack(stack);
    dynamicStack.pushItem(2,stack);
    dynamicStack.pushItem(3,stack);
    dynamicStack.printStack(stack);
    dynamicStack.pushItem(2,stack);
    dynamicStack.pushItem(3,stack);
    dynamicStack.pushItem(2,stack);
    dynamicStack.pushItem(3,stack);
    dynamicStack.pushItem(2,stack);
    dynamicStack.pushItem(3,stack);
    dynamicStack.printStack(stack);
    dynamicStack.popItem(stack);
    dynamicStack.printStack(stack);
    dynamicStack.deleteStack(stack);
    return 0;
 */

class StackDynamicArray {
    struct Stack {
        explicit Stack(int size){
            top = -1;
            if (size > 0)
                capacity = size, array = new int[capacity]{};
            else {
                std::cout << "capacity cannot be less than 1 setting it as default i.e. 1";
                capacity = 1, array = new int[capacity]{};
            }
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
