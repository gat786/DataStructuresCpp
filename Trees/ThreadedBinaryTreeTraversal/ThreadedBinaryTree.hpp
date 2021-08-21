//
// Created by gat786 on 02/05/21.
//

#ifndef DATASTRUCTURESCPP_THREADEDBINARYTREE_HPP
#define DATASTRUCTURESCPP_THREADEDBINARYTREE_HPP

/*
    For more information read this -
    https://shunsvineyard.info/2021/04/02/build-the-forest-in-python-series-single-threaded-binary-search-trees/#1-what-is-threaded-binary-trees
*/

class ThreadedBinaryTree{
public:
    struct ThreadedBinaryTreeNode{
        struct ThreadedBinaryTreeNode* left;
        struct ThreadedBinaryTreeNode* right;
        int data;
        // lTag - predecessor
        // rTag - sucessor
        bool lTag, rTag;

        ThreadedBinaryTreeNode(){
            // data = value;
            lTag = 0;
            rTag = 1;

            left = this;
            right = this;
        }

        ThreadedBinaryTreeNode(int value){
            data = value;
            lTag = 0;
            rTag = 1;
            
            left = this;
            right = this;
        }
    };

    ThreadedBinaryTreeNode* root;

    static bool directionLeft, directionRight;
	

    void CreateThreadedBinaryTree();
    void insertValue(int value);
    ThreadedBinaryTreeNode* getInorderSuccessor(ThreadedBinaryTreeNode* currentNode);
    void emptyTree();
    void printTree();

};

#endif //DATASTRUCTURESCPP_THREADEDBINARYTREE_HPP
