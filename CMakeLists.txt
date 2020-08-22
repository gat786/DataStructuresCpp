cmake_minimum_required(VERSION 3.16)
project(DataStructuresCPP)

set(CMAKE_CXX_STANDARD 20)

add_executable(DataStructuresCPP main.cpp SinglyLinkedList/SinglyLinkedList.cpp SinglyLinkedList/SinglyLinkedList.hpp DoublyLinkedList/DoublyLinkedList.cpp DoublyLinkedList/DoublyLinkedList.hpp)