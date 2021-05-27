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
        struct ThreadedBinaryTree* left;
        struct ThreadedBinaryTree* right;
        int data;
        // lTag - predecessor
        // rTag - sucessor
        bool lTag, rTag;

        ThreadedBinaryTreeNode(int value){
            data = value;
            lTag = 0;
            rTag = 1;
            rTag = this;
        }
    };

    struct ThreadedBinaryTreeNode* CreateThreadedBinaryTree(int valueOfRoot);

};

#endif //DATASTRUCTURESCPP_THREADEDBINARYTREE_HPP
