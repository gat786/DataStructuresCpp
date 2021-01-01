//
// Created by gat786 on 1/1/21.
//

#include <iostream>
#include "BinaryTree.hpp"

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