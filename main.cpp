#include <iostream>
#include "Trees/BinaryTree/BinaryTree.hpp"

int main() {
  BinaryTree tree{};
  auto rootNode = tree.CreateBinaryTree(1);
  tree.InsertNode(2,rootNode);
  tree.InsertNode(3,rootNode);
  tree.InsertNode(4,rootNode);
  tree.InsertNode(5,rootNode);
  tree.InOrderTraversalNonRecursive(rootNode);
  tree.DeleteTree(rootNode);
}