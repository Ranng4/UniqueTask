//
// Created by Lenovo on 25-4-8.
//

#ifndef LINK_H
#define LINK_H

// 单向链表节点
typedef struct unidirectionalNode {
    int val;
    struct unidirectionalNode* next;
} unidirectionalNode;

// 单向链表初始化
unidirectionalNode* unidirectionalInit();
// 单向链表头部插入
unidirectionalNode* unidirectionalHeadInsert(unidirectionalNode* Node, int val);
// 单向链表尾部插入
unidirectionalNode* unidirectionalTailerInsert(unidirectionalNode* Node, int val);
// 单向链表打印
void unidirectionalPrint(unidirectionalNode* Node);
// 值删除
void unidirectionalDeleByVal(unidirectionalNode* Node,int val);

// 双向链表节点
typedef struct bidirectionalNode {
    int val;
    struct bidirectionalNode* next;
    struct bidirectionalNode* pre;
} bidirectionalNode;


bidirectionalNode* bidirectionalNodeInit();
bidirectionalNode* bidirectionalNodeHeadInsert(bidirectionalNode* Node, int val);
bidirectionalNode* bidirectionalNodeTailerInsert(bidirectionalNode* Node, int val);
void bidirectionalNodePrint(bidirectionalNode* Node);
void bidirectionalNodeDeleByVal(bidirectionalNode* Node,int val);




//test
int LinkListTest();

#endif //LINK_H
