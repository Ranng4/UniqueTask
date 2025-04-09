//
// Created by Lenovo on 25-4-8.
//

#include "Link.h"


#include <stdio.h>
#include<stdlib.h>

//单向链表
// typedef struct unidirectionalNode
// {
//     int val;
//     struct unidirectionalNode*  next;
// }unidirectionalNode;

unidirectionalNode* unidirectionalInit()
{
    //虚拟节点
    unidirectionalNode* Node = (unidirectionalNode*)malloc(sizeof(unidirectionalNode));
    Node->val = 0;
    Node->next = NULL;
    return Node;
}
unidirectionalNode* unidirectionalHeadInsert(unidirectionalNode* Node, int val)
{
    unidirectionalNode* NewNode = (unidirectionalNode*)malloc(sizeof(unidirectionalNode));
    NewNode->val = val;
    NewNode->next = Node->next;
    Node->next = NewNode;
    Node->val++;
    return Node;
}
unidirectionalNode* unidirectionalTailerInsert(unidirectionalNode* Node, int val)
{
    unidirectionalNode* NewNode = (unidirectionalNode*)malloc(sizeof(unidirectionalNode));
    unidirectionalNode* Index = Node;
    while (Index->next != NULL)
    {
        Index = Index->next;
    }
    Index->next = NewNode;
    NewNode->val = val ;
    NewNode->next = NULL;
    Node->val++;
    return Node;
}

void unidirectionalPrint(unidirectionalNode* Node)
{
    unidirectionalNode* Index = Node->next;
    while (Index !=NULL)
    {
        printf("%d\n",Index->val);
        Index=Index->next;
    }
}

void unidirectionalDeleByVal(unidirectionalNode* Node,int val)
{
    unidirectionalNode* pre = Node;
    unidirectionalNode* Index = Node->next;
    while (Index !=NULL)
    {
        if (Index->val == val)
        {
            pre->next =Index->next;
            Node->val --;
            free(Index);
            printf("%d已被删除\n",val);
            return;
        }
        pre=pre->next;
        Index = pre->next;
    }
     printf("%d不存在\n",val);

}


//
// typedef struct bidirectionalNode
// {
//     int val;
//     struct bidirectionalNode*  next;
//     struct bidirectionalNode*  pre;
// }bidirectionalNode;


bidirectionalNode* bidirectionalNodeInit()
{
    //虚拟节点
    bidirectionalNode*  Node = (bidirectionalNode*)malloc(sizeof(bidirectionalNode));
    Node->val = 0;
    Node->next = NULL;
    return Node;
}

bidirectionalNode* bidirectionalNodeHeadInsert(bidirectionalNode* Node, int val)
{
    bidirectionalNode* NewNode = (bidirectionalNode*)malloc(sizeof(bidirectionalNode));
    NewNode->val = val;
    NewNode->pre = Node;
    NewNode->next = Node->next;
    Node->next = NewNode;
    Node->val++;
    return Node;
}

bidirectionalNode* bidirectionalNodeTailerInsert(bidirectionalNode* Node, int val)
{
    bidirectionalNode* NewNode = (bidirectionalNode*)malloc(sizeof(bidirectionalNode));
    bidirectionalNode* Index = Node;
    while (Index->next != NULL)
    {
        Index = Index->next;
    }
    Index->next = NewNode;
    NewNode->val = val;
    NewNode->pre = Index;
    NewNode->next = NULL;
    Node->val++;
    return Node;
}
void bidirectionalNodePrint(bidirectionalNode* Node)
{
    bidirectionalNode* Index = Node->next;
    printf("一共%d个数据\n",Node->val);
    while (Index !=NULL)
    {
        printf("%d\n",Index->val);
        Index=Index->next;
    }
}

void bidirectionalNodeDeleByVal(bidirectionalNode* Node,int val)
{
    bidirectionalNode* Index = Node->next;
    while (Index !=NULL)
    {
        if (Index->val == val)
        {
            Index->pre->next =Index->next;
            Node->val--;
            free(Index);
            printf("%d已被删除\n",val);
            return;
        }
        Index =  Index->pre->next;
    }
    printf("%d不存在\n",val);

}


// test


int LinkListTest()
{
    unidirectionalNode* List = unidirectionalInit();
    unidirectionalTailerInsert(List,1);
    unidirectionalTailerInsert(List,2);
    unidirectionalTailerInsert(List,3);
    unidirectionalTailerInsert(List,4);
    unidirectionalTailerInsert(List,5);
    unidirectionalTailerInsert(List,6);
    unidirectionalDeleByVal(List,3);
    unidirectionalPrint(List);
    return 0;

}







































