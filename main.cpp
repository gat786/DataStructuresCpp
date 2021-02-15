#include <iostream>
#include "Trees/BinaryTree/BinaryTree.hpp"

int main() {
    BinaryTree tree{};
    auto binaryTree = tree.CreateBinaryTree(1);
    auto nodeLeft = new BinaryTree::BinaryTreeNode(2);
    auto nodeRight = new BinaryTree::BinaryTreeNode(3);
    auto nodeLeftLeft = new BinaryTree::BinaryTreeNode(4);
    auto nodeLeftRight = new BinaryTree::BinaryTreeNode(5);
    auto nodeRightLeft = new BinaryTree::BinaryTreeNode(6);
    auto nodeRightRight = new BinaryTree::BinaryTreeNode(7);
    binaryTree->attachLeft(nodeLeft);
    binaryTree->attachRight(nodeRight);
    binaryTree->left->attachLeft(nodeLeftLeft);
    binaryTree->left->attachRight(nodeLeftRight);
    binaryTree->right->attachLeft(nodeRightLeft);
    binaryTree->right->attachRight(nodeRightRight);
    tree.PreOrderTraversalNonRecursive(binaryTree);
    std::cout << std::endl;
    tree.PostOrderTraversalNonRecursive(binaryTree);
    std::cout << std::endl;
    tree.InOrderTraversalRecursive(binaryTree);
    std::cout << std::endl;
}