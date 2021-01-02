cmake_minimum_required(VERSION 3.16)
project(DataStructuresCPP)

set(CMAKE_CXX_STANDARD 20)

add_executable(DataStructuresCPP main.cpp
        LinkedList/SinglyLinkedList/SinglyLinkedList.cpp
        LinkedList/SinglyLinkedList/SinglyLinkedList.hpp
        LinkedList/DoublyLinkedList/DoublyLinkedList.cpp
        LinkedList/DoublyLinkedList/DoublyLinkedList.hpp
        LinkedList/CircularLinkedList/CircularLinkedList.cpp
        LinkedList/CircularLinkedList/CircularLinkedList.hpp
        Stack/StackArray/StackArray.cpp
        Stack/StackArray/StackArray.hpp
        Stack/StackDynamicArray/StackDynamicArray.cpp
        Stack/StackDynamicArray/StackDynamicArray.hpp
        Queue/QueueSimpleCircularArray/QueueSimpleCircularArray.cpp
        Queue/QueueSimpleCircularArray/QueueSimpleCircularArray.hpp
        Queue/QueueDynamicCircularArray/QueueDynamicCircularArray.cpp
        Queue/QueueDynamicCircularArray/QueueDynamicCircularArray.hpp
        Queue/QueueLinkedList/QueueLinkedList.cpp
        Queue/QueueLinkedList/QueueLinkedList.hpp
        Trees/BinaryTree/BinaryTree.cpp
        Trees/BinaryTree/BinaryTree.hpp
        Queue/QueueSCATemplate/QueueTemplate.cpp
        Queue/QueueSCATemplate/QueueTemplate.hpp)