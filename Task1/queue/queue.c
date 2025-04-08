//
// Created by Lenovo on 25-4-8.
//

#include "queue.h"


bidirectionalNode* QueueInit()
{
    bidirectionalNode* Node = bidirectionalNodeInit();
    return Node;
}

// bidirectionalNode* QueueInit(bidirectionalNode* preNode)
// {
//     bidirectionalNode* newNode = QueueInit();
//     preNode = preNode->next;
//     free(preNode->pre);
//     while (preNode!= NULL)
//     {
//         bidirectionalNodeTailerInsert(newNode,preNode->val);
//         newNode->val++;
//         preNode = preNode->next;
//         free(preNode->pre);
//     }
//     return newNode;
// }

int front(bidirectionalNode* Node)
{
    return Node->next->val;
}

int back(bidirectionalNode* Node)
{
    while (Node->next!=NULL)
    {
        Node=Node->next;
    }
    return Node->val;
}

bool empty(bidirectionalNode* Node)
{
    return Node->val == 0;
}
int size(bidirectionalNode* Node)
{
    return Node ->val;
}

void push(bidirectionalNode* List,int val)
{
    bidirectionalNodeTailerInsert(List,val);
}
int pop(bidirectionalNode* List)
{
    if (List->val==0)
    {
        printf("队列为空");
        return NAN;
    }
    bidirectionalNode* cur =List->next;
    int val = cur->val;
    List->next = cur->next;
    cur->next->pre = List;
    free(cur);
    List->val--;
    return val;
}
