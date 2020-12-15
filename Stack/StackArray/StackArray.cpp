//
// Created by gat78 on 13-09-2020.
//

/*
 *  Driver code for stackArray -
 *
    StackArray stackArray;
    auto* stack = stackArray.CreateStack();
    std::cout << stackArray.isStackEmpty(stack) << std::endl;
    stackArray.pushItem(1,stack);
    stackArray.pushItem(2,stack);
    stackArray.printStack(stack);
    std::cout << stackArray.popItem(stack) << std::endl;
    stackArray.printStack(stack);
    stackArray.pushItem(3,stack);
    stackArray.pushItem(4,stack);
    stackArray.pushItem(5,stack);
    stackArray.pushItem(6,stack);
    stackArray.pushItem(3,stack);
    stackArray.pushItem(4,stack);
    stackArray.pushItem(5,stack);
    stackArray.pushItem(6,stack);
    stackArray.printStack(stack);
 */


#include <iostream>
#include "StackArray.hpp"

StackArray::Stack* StackArray::CreateStack() {
	auto* stack = new Stack();
	return stack;
}

bool StackArray::isStackEmpty(Stack* stack)
{
	return (stack->top == -1);
}

bool StackArray::isStackFull(Stack* stack) 
{
    return (stack->top == (stack->capacity - 1));
}

void StackArray::pushItem(int data, Stack* stack)
{
    //check if it is full
    if(StackArray::isStackFull(stack)) {
        //do nothing
        std::cout << "Stack is already full cannot add more items";
        return;
    }
    else {
        // increment the top value and
        // insert data at the position
        ++stack->top;
        stack->array[stack->top] = data;
    }
}

int StackArray::popItem(Stack *stack) {
    return stack->array[stack->top--];
}

void StackArray::deleteStack(Stack *stack) {
    if (stack){
        if(stack->array){
            free(stack->array);
        }
        free(stack);
    }
}

void StackArray::printStack(StackArray::Stack *stack) {
    int top = stack->top;
    while(top!=-1){
        std::cout << stack->array[top--] << " | ";
    }
    std::cout << std::endl;
}
