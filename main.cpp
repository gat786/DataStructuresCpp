#include <iostream>
#include "Stack/StackDynamicArray/StackDynamicArray.hpp"

int main() {
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
}
