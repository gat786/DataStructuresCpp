//
// Created by gat786 on 1/1/21.
//

#include <iostream>
#include <stack>
#include <queue>
#include "BinaryTree.hpp"
#include "../../Queue/QueueSimpleCircularArray/QueueSimpleCircularArray.hpp"

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
    tree.PreOrderTraversalRecursive(binaryTree);
    std::cout << std::endl;
    tree.PostOrderTraversalRecursive(binaryTree);
    std::cout << std::endl;
    tree.InOrderTraversalRecursive(binaryTree);
    std::cout << std::endl;
 */

/**
 * Creates a BinaryTreeNode for the input value
 * @param valueOfRoot - input value for the node
 * @returns BinaryTreeNode - a BinaryTreeNode created from the value
 * */
struct BinaryTree::BinaryTreeNode * BinaryTree::CreateBinaryTree(int valueOfRoot) {
    auto rootNode = new BinaryTreeNode(valueOfRoot);
    return rootNode;
}

/**
 * Prints Preorder Traversal of the tree which starts at root recursively
 * @param *root - pointer to the root BinaryTreeNode
 * @returns void
 */ 
void BinaryTree::PreOrderTraversalRecursive(struct BinaryTreeNode *root) {
    if (root){
        std::cout << root->data << "\t";
        PreOrderTraversalRecursive(root->left);
        PreOrderTraversalRecursive(root->right);
    }
}

/**
 * Prints Preorder Traversal of the tree which starts at root nonrecursively
 * @param *root - pointer to the root BinaryTreeNode
 * @returns void
 */ 
void BinaryTree::PreOrderTraversalNonRecursive(struct BinaryTreeNode *root) {
    // Time Complexity: O(n). Space Complexity: O(n).
    std::stack<BinaryTreeNode*> stack;

    while (true){
        while (root){
            std::cout << root->data << "\t";
            stack.push(root);
            root = root->left;
        }
        if (stack.empty())
            break;

        root = stack.top();
        stack.pop();
        root = root->right;
    }
}

/**
 * Prints PostOrder Traversal of the tree which starts at root recursively
 * @param *root - pointer to the root BinaryTreeNode
 * @returns void
 */ 
void BinaryTree::PostOrderTraversalRecursive(struct BinaryTreeNode *root) {
    if (root){
        PostOrderTraversalRecursive(root->left);
        PostOrderTraversalRecursive(root->right);
        std::cout << root->data << "\t";
    }
}

/**
 * Prints PostOrder Traversal of the tree which starts at root nonrecursively
 * @param *root - pointer to the root BinaryTreeNode
 * @returns void
 */ 
void BinaryTree::PostOrderTraversalNonRecursive(struct BinaryTreeNode *root) {
    /*
     * In preorder and inorder traversals, after popping the stack element we
     *  do not need to visit the same vertex again. But in postorder traversal,
     *  each node is visited twice. That means, after processing the left
     *  subtree we will visit the current node and after processing the right
     *  subtree we will visit the same current node. But we should be
     *  processing the node during the second visit. Here the problem is how
     *  to differentiate whether we are returning from the left subtree or the
     *  right subtree.

        We use a previous variable to keep track of the earlier traversed node.
        Let’s assume current is the current node that is on top of the stack.
        When previous is current’s parent, we are traversing down the tree.
        In this case, we try to traverse to current’s left child if available
        (i.e., push left child to the stack). If it is not available, we look
        at current’s right child. If both left and right child do not exist
        (ie, current is a leaf node), we print current’s value and pop it off
        the stack.

        If prev is current’s left child, we are traversing up the tree from the
        left. We look at current’s right child. If it is available, then
        traverse down the right child (i.e., push right child to the stack);
        otherwise print current’s value and pop it off the stack. If previous
        is current’s right child, we are traversing up the tree from the right.
        In this case, we print current’s value and pop it off the stack.
     */
    std::stack<BinaryTreeNode*> stack{};
    BinaryTreeNode* previous = nullptr;
    do {
        while (root!=nullptr){
            stack.push(root);
            root = root->left;
        }
        while (root == nullptr && !stack.empty()){
            root = stack.top();
            if (root->right == nullptr  || root->right == previous){
                std::cout << root->data << "\t";
                stack.pop();
                previous = root;
                root = nullptr;
            } else {
                root = root->right;
            }
        }
    } while (!stack.empty());

}

/**
 * Prints InOrder Traversal of the tree which starts at root recursively
 * @param *root - pointer to the root BinaryTreeNode
 * @returns void
 */ 
void BinaryTree::InOrderTraversalRecursive(struct BinaryTreeNode *root) {
    if (root){
        InOrderTraversalRecursive(root->left);
        std::cout << root->data << "\t";
        InOrderTraversalRecursive(root->right);
    }
}

void BinaryTree::InOrderTraversalNonRecursive(struct BinaryTreeNode *root) {
    // Time Complexity: O(n). Space Complexity: O(n).
    std::stack<BinaryTreeNode*> stack;
    while (true){
        while(root){
            stack.push(root);
            root = root->left;
        }
        if (stack.empty())
            break;
        root = stack.top();
        stack.pop();
        std::cout << root->data << "\t";
        root = root->right;
    }
}

/*
    Level order traversal is defined as follows:
    Visit the root.
        While traversing level (, keep all the elements at level ( + 1 in queue.
        Go to the next level and visit all the nodes at that level.
        Repeat this until all levels are completed.

 */

/**
 * Prints LevelOrder Traversal of the tree which starts at root
 * @param *root - pointer to the root BinaryTreeNode
 * @returns void
 */ 
void BinaryTree::LevelOrderTraversal(struct BinaryTreeNode *root) {
    struct BinaryTreeNode* temp;
    std::queue<BinaryTreeNode*> queue{};

    if (!root)
        return;

    queue.push(root);

    while (queue.empty()){
        temp = queue.front();
        queue.pop();
        std::cout << temp->data << "\t";
        if (temp->left)
            queue.push(temp->left);
        if (temp->right)
            queue.push(temp->right);
    }
}

/**
 * Deletes the memory that has been allocated for the entire tree starting 
 * from *root
 * @param *root - pointer to the root BinaryTreeNode
 * @returns void
 */ 
void BinaryTree::DeleteTree(struct BinaryTreeNode *root) {
    if(root == nullptr) {
        return;
    }
    DeleteTree(root->left);
    DeleteTree(root->right);
    delete root;
}
