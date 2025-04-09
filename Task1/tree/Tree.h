//
// Created by Lenovo on 25-4-9.
//

#ifndef TREE_H
#define TREE_H

typedef struct TreeNode{
  char* data;
  struct TreeNode** ChildNode;
  int ChildCount;
}TreeNode;
int TreeTest();

#endif //TREE_H
