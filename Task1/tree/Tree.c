//
// Created by Lenovo on 25-4-9.
//

#include "Tree.h"

#include <stdio.h>
#include<stdlib.h>
#include <string.h>

TreeNode* TreeRootInit(const char* data){
   TreeNode* root = (TreeNode*)malloc(sizeof(TreeNode));
   root->data = strdup(data);
   root->ChildCount=0;
   root->ChildNode =NULL;
   return root;
}

void addChild(TreeNode* parentNode, TreeNode* childNode) {
    parentNode->ChildCount++;
    parentNode->ChildNode = (TreeNode**)realloc(
        parentNode->ChildNode,
        parentNode->ChildCount * sizeof(TreeNode*)
    );
    parentNode->ChildNode[parentNode->ChildCount - 1] = childNode;
}


// 前序递归
void preOrderRecursive(TreeNode* root) {
    if (root==NULL){return;}
    printf("%s ",root->data);
    for (int i=0;i < root->ChildCount;i++) {
        preOrderRecursive(root->ChildNode[i]);
    }
}

// 非递归先序遍历
void preOrderIterative(TreeNode* root) {
    if (root==NULL){return;}
    TreeNode** stack = (TreeNode**)malloc(sizeof(TreeNode*));
    int top = -1;
    stack[++top] = root;
    while (top>=0) {
        TreeNode* Node = stack[top--];
        printf("%s ",Node->data);
        for (int i = Node->ChildCount-1;i>=0;i--) {
            stack = (TreeNode**)realloc(stack, (top + Node->ChildCount) * sizeof(TreeNode*));
            stack[++top] =Node->ChildNode[i];
        }
    }
    free(stack);
}
// 递归后序遍历
void postOrderRecursive(TreeNode* root) {
    if (root ==NULL) return;
    for (int i =0;i < root->ChildCount;i++) {
        postOrderRecursive(root->ChildNode[i]);
    }
    printf("%s ",root->data);

}

// 非递归后序遍历
void postOrderIterative(TreeNode* root) {
    if (root ==NULL) return;
    TreeNode** stack1 = (TreeNode**)malloc(sizeof(TreeNode*));
    TreeNode** stack2 = (TreeNode**)malloc(sizeof(TreeNode*));
    int top1 = -1, top2 = -1;
    stack1[++top1] = root;

    while (top1 >= 0) {
        TreeNode* node = stack1[top1--];
        stack2 = (TreeNode**)realloc(stack2, (top2 + node->ChildCount) * sizeof(TreeNode*));
        stack2[++top2] = node;

        for (int i = 0; i < node->ChildCount; i++) {
            stack1 = (TreeNode**)realloc(stack1, (top1 + node->ChildCount) * sizeof(TreeNode*));
            stack1[++top1] = node->ChildNode[i];
        }
    }

    while (top2 >= 0) {
        printf("%s ", stack2[top2--]->data);
    }

    free(stack1);
    free(stack2);
}

// 递归中序遍历(二叉树)
void inOrderRecursive(TreeNode* root) {
    if (root ==NULL) return;
    if (root->ChildCount!=0) {
        inOrderRecursive(root);
    }
    printf("%s ",root->data);
    for (int i=1;i<root->ChildCount;i++) {
        inOrderRecursive(root->ChildNode[i]);
    }
}

// 非递归中序遍历

void inOrderIterative(TreeNode* root) {
    if (root == NULL) return;

    // 初始化栈和队列（带动态扩容）
    int stack1_capacity = 100;
    int stack2_capacity = 100;
    int queue_capacity = 100;

    TreeNode** stack1 = (TreeNode**)malloc(sizeof(TreeNode*) * stack1_capacity);
    TreeNode** stack2 = (TreeNode**)malloc(sizeof(TreeNode*) * stack2_capacity);
    TreeNode** queue = (TreeNode**)malloc(sizeof(TreeNode*) * queue_capacity);

    int top1 = -1;
    int top2 = -1;
    int num = -1;

    stack1[++top1] = root;

    while (top1 >= 0) {
        //动态扩容检查
        if (top1 >= stack1_capacity - 1) {
            stack1_capacity *= 2;
            stack1 = (TreeNode**)realloc(stack1, stack1_capacity * sizeof(TreeNode*));
        }

        TreeNode* Node = stack1[top1--];

        // 处理非空节点
        if (Node != NULL) {
            if (Node->ChildCount > 0 && Node->ChildNode != NULL) {
                // 将当前节点压入stack2（等待后续处理）
                if (++top2 >= stack2_capacity - 1) {
                    stack2_capacity *= 2;
                    stack2 = (TreeNode**)realloc(stack2, stack2_capacity * sizeof(TreeNode*));
                }
                stack2[top2] = Node;

                // 反向遍历子节点（跳过NULL），压入stack1
                for (int i = Node->ChildCount - 1; i >= 0; i--) {
                    if (Node->ChildNode[i] != NULL) { // 跳过NULL子节点
                        if (++top1 >= stack1_capacity - 1) {
                            stack1_capacity *= 2;
                            stack1 = (TreeNode**)realloc(stack1, stack1_capacity * sizeof(TreeNode*));
                        }
                        stack1[top1] = Node->ChildNode[i];
                    }
                }
            } else {
                // 叶子节点或无效子节点结构，直接加入队列
                if (++num >= queue_capacity - 1) {
                    queue_capacity *= 2;
                    queue = (TreeNode**)realloc(queue, queue_capacity * sizeof(TreeNode*));
                }
                queue[num] = Node;

                // 如果stack2有父节点，弹出并加入队列
                if (top2 >= 0) {
                    if (++num >= queue_capacity - 1) {
                        queue_capacity *= 2;
                        queue = (TreeNode**)realloc(queue, queue_capacity * sizeof(TreeNode*));
                    }
                    queue[num] = stack2[top2--];
                }
            }
        }
    }

    // 处理stack2剩余的父节点
    while (top2 >= 0) {
        if (++num >= queue_capacity - 1) {
            queue_capacity *= 2;
            queue = (TreeNode**)realloc(queue, queue_capacity * sizeof(TreeNode*));
        }
        queue[num] = stack2[top2--];
    }

    // 输出结果（跳过可能的NULL）
    for (int i = 0; i <= num; i++) {
        if (queue[i] != NULL) { // 防御性检查
            printf("%s ", queue[i]->data);
        }
    }

    free(stack1);
    free(stack2);
    free(queue);
}



// 层级遍历
void levelOrder(TreeNode* root) {

}


// 释放树的内存
void freeTree(TreeNode* root) {
    if (root == NULL) return;

    for (int i = 0; i < root->ChildCount; i++) {
        freeTree(root->ChildNode[i]);
    }

    free(root->ChildNode);
    free(root->data);
    free(root);
}

int TreeTest() {

    TreeNode* root = TreeRootInit("A");
    TreeNode* child1 = TreeRootInit("B");
    TreeNode* child2 = TreeRootInit("C");
    TreeNode* child3 = TreeRootInit("D");
    TreeNode* child4 = TreeRootInit("E");
    TreeNode* child5 = TreeRootInit("F");
    TreeNode* child6 = TreeRootInit("G");
    TreeNode* child7 = TreeRootInit("M");
    TreeNode* child8 = TreeRootInit("N");



    addChild(root, child1);
    addChild(root, child2);
    addChild(child1, child3);
    addChild(child1, child4);
    addChild(child3, child7);
    // addChild(child3, child8);
    // addChild(child2, child5);
    addChild(child2, child6);


    inOrderIterative(root);
    printf("\n");

    return 0;
}