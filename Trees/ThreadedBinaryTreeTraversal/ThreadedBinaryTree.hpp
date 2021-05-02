//
// Created by gat786 on 02/05/21.
//

#ifndef DATASTRUCTURESCPP_THREADEDBINARYTREE_HPP
#define DATASTRUCTURESCPP_THREADEDBINARYTREE_HPP

class ThreadedBinaryTree{
public:
    struct ThreadedBinaryTreeNode{
        struct ThreadedBinaryTree* left;
        struct ThreadedBinaryTree* right;
        int lTag,rTag,data;
    };

    struct ThreadedBinaryTreeNode* CreateThreadedBinaryTree(int valueOfRoot);


};

#endif //DATASTRUCTURESCPP_THREADEDBINARYTREE_HPP
