//
// Created by gat786 on 1/1/21.
//

#ifndef DATASTRUCTURESCPP_BINARYTREE_HPP
#define DATASTRUCTURESCPP_BINARYTREE_HPP

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
