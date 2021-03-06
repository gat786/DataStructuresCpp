//
// Created by gat78 on 04-10-2020.
//

#include <iostream>
#include <cstring>
#include "StackDynamicArray.hpp"

/*
 * StackDynamicArray dynamicStack;
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
    return 0;
 */

struct StackDynamicArray::Stack * StackDynamicArray::CreateStack() {
    auto stack = new StackDynamicArray::Stack();
    return stack;
}

bool StackDynamicArray::isStackEmpty(Stack *stack) {
    return stack->top == -1;
}

bool StackDynamicArray::isStackFull(Stack *stack) {
    return stack->top == (stack->capacity - 1);
}

void StackDynamicArray::pushItem(int data, Stack* stack)
{
    //check if it is full
    if(StackDynamicArray::isStackFull(stack)) {
        //do nothing

        doubleStackSize(stack);
        pushItem(data,stack);
        return;
    }
    else {
        // increment the top value and
        // insert data at the position
        ++stack->top;
        stack->array[stack->top] = data;
    }
}

void StackDynamicArray::doubleStackSize(Stack *stack) {
    int oldArrayCapacity = stack->capacity;
    stack->capacity = stack->capacity * 2;
    int* newStack = new int[stack->capacity]{};
    memcpy(newStack, stack->array, oldArrayCapacity * sizeof(int));
    std::cout << "increasing stack size to " << stack->capacity << std::endl;
    delete[] stack->array;
    stack->array = newStack;
}


int StackDynamicArray::popItem(Stack *stack) {
    return stack->array[stack->top--];
}

void StackDynamicArray::deleteStack(Stack *stack) {
    if (stack){
        delete[] stack->array;
        delete stack;
    }
}

void StackDynamicArray::printStack(StackDynamicArray::Stack *stack) {
    int top = stack->top;
    std::cout << "stack elements";
    while(top!=-1){
        std::cout << stack->array[top--] << " | ";
    }
    std::cout << std::endl;
}