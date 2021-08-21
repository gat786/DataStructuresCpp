//
// Created by gat786 on 02/05/21.
//

#include "ThreadedBinaryTree.hpp"

void ThreadedBinaryTree::CreateThreadedBinaryTree(){
    root = new ThreadedBinaryTree::ThreadedBinaryTreeNode();
}

void ThreadedBinaryTree::insertValue(int value){
    ThreadedBinaryTreeNode* node = new ThreadedBinaryTreeNode(value);
    if(root->left == root && root->right == root){
        root->left = node;
        
        // set right and left nodes to point to root
        node->right = root;
        node->left = root;

        node->lTag = node->rTag = true;
    }else{
        // set dummy node as current node.
        // we have to use currentnode as the node where the new node will be added
        ThreadedBinaryTreeNode* current = root->left;
        // find the node at which current node is to be added.
        while (true)
        {
            // check if value is greater than value in root node. 
            // if it greater than insert on right subtree
            // else insert in left subtree
            if(current->data > node->data){
                // check if node contains a left child node or not
                // if it contains a left child node then set the 
                // child node as current node
                // else set the directionleft as true and 
                // directionRight as false
                if(current->lTag){
                    directionLeft = true;
                    directionRight = false;
                }
                // find the lowest left element
                else{
                    current = current->left;
                }
            }
            else{
                // check if node has a right subnode.
                // if it has then set current to right subnode
                // else set directionRight as true and directionLeft
                // as false
                if(current->rTag){
                    directionRight = true;
                    directionLeft = false;
                }else{
                    current = current->right;
                }
            }
        }

        if(directionLeft){
            // since current node doesnt have a child the left node points to predecessor
            // change node's predecessor to be current's predecessor
            node->left = current->left;
            // set node to be added as left child of current.
            current->left = node;
            // set nodes lefttag equal to currents left tag since it now points to predecessor
            node->lTag = current->lTag;
            // set current nodes lTag to false since it contains a left child now.
            current->lTag = 1;
            // point the node's left pointer to current since it will be a inorder sucessor to it.
            node->right = current;
        }else if(directionRight){
            // we have to fit our node as the right child of current node
            // since currently right child of current points to inorder sucessor save 
            // it as node's right 
            node->right = current->right;
            // set node as right child of current.
            current->right = node;
            // set node's rTag to be similar to currents rTag
            node->rTag = current->rTag;
            // change current's rTag to be false. Since now it has a child
            current->rTag = 1;
            // point nodes left child to current since it is predecessor now.
            node->left = current;
        }
        
    }
}

ThreadedBinaryTree::ThreadedBinaryTreeNode* ThreadedBinaryTree::getInorderSuccessor(
    ThreadedBinaryTreeNode* current
    ){
        // if current node doesnt have a right child then the right node consists of the 
        // inorder successor
        if(current->rTag){
            return current->right;
        }
        
        // if it contains of a child find set it as current
        current = current->right;
        // find the left most node from here
        while(current->lTag != 0){
            current = current->left;
        }
        return current;
}
