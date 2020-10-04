#include <iostream>
#include "Stack/StackArray/StackArray.hpp"

int main() {
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
    return 0;
}
