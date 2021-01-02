//
// Created by gat786 on 1/1/21.
//

#include <iostream>
#include "BinaryTree.hpp"
#include "../../Queue/QueueSimpleCircularArray/QueueSimpleCircularArray.hpp"

struct BinaryTree::BinaryTreeNode * BinaryTree::CreateBinaryTree(int valueOfRoot) {
    auto rootNode = new BinaryTreeNode(valueOfRoot);
    return rootNode;
}

void BinaryTree::PreOrderTraversalRecursive(struct BinaryTreeNode *root) {
    if (root){
        std::cout << root->data << "\t";
        PreOrderTraversalRecursive(root->left);
        PreOrderTraversalRecursive(root->right);
    }
}

void BinaryTree::PostOrderTraversalRecursive(struct BinaryTreeNode *root) {
    if (root){
        PostOrderTraversalRecursive(root->left);
        PostOrderTraversalRecursive(root->right);
        std::cout << root->data << "\t";
    }
}

void BinaryTree::InOrderTraversalRecursive(struct BinaryTreeNode *root) {
    if (root){
        InOrderTraversalRecursive(root->left);
        std::cout << root->data << "\t";
        InOrderTraversalRecursive(root->right);
    }
}
/*
    Level order traversal is defined as follows:
    Visit the root.
        While traversing level (, keep all the elements at level ( + 1 in queue.
        Go to the next level and visit all the nodes at that level.
        Repeat this until all levels are completed.

 */
void BinaryTree::LevelOrderTraversal(struct BinaryTreeNode *root) {
    struct BinaryTreeNode* temp;
    QueueSimpleCircularArray circularQueue{};
    auto queue = circularQueue.CreateQueue();
    if (!root)
        return;
    circularQueue.enqueueItem(queue,root);
}