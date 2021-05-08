//
// Created by gat786 on 1/1/21.
//

#ifndef DATASTRUCTURESCPP_BINARYTREE_HPP
#define DATASTRUCTURESCPP_BINARYTREE_HPP

/*
 *  BinaryTree tree{};
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
    tree.InOrderTraversalNonRecursive(binaryTree);
    std::cout << std::endl;
    tree.DeleteTree(binaryTree);
 */

class BinaryTree{
public:
    struct BinaryTreeNode{
        int data;
        struct BinaryTreeNode *left;
        struct BinaryTreeNode *right;

        explicit BinaryTreeNode(int value){
            data = value;
            left = nullptr;
            right = nullptr;
        }

        void attachLeft(struct BinaryTreeNode *node){
            left = node;
        }

        void attachRight(struct BinaryTreeNode *node){
            right = node;
        }
    };

    struct BinaryTreeNode *CreateBinaryTree(int valueOfRoot);

    void PreOrderTraversalRecursive(struct BinaryTreeNode *root);
    void PreOrderTraversalNonRecursive(struct BinaryTreeNode *root);

    void PostOrderTraversalRecursive(struct BinaryTreeNode *root);
    void PostOrderTraversalNonRecursive(struct BinaryTreeNode *root);

    void InOrderTraversalRecursive(struct BinaryTreeNode *root);
    void InOrderTraversalNonRecursive(struct BinaryTreeNode *root);

    void LevelOrderTraversal(struct BinaryTreeNode *root);

    void DeleteTree(struct BinaryTreeNode *root);
};

#endif //DATASTRUCTURESCPP_BINARYTREE_HPP
