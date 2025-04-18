//
// Created by Lenovo on 25-4-8.
//

#ifndef QUEUE_H
#define QUEUE_H




#include <math.h>
#include <stdlib.h>
#include<stdbool.h>
#include <stdio.h>
#include "../LinkList/Link.h"

typedef bidirectionalNode* Queue;

Queue QueueInit();
// Queue QueueInit(bidirectionalNode* preNode);
int front(bidirectionalNode* Node);
int back(bidirectionalNode* Node);
bool empty(bidirectionalNode* Node);
int size(bidirectionalNode* Node);
void push(bidirectionalNode* List,int val);
int pop(bidirectionalNode* List);


//test
int queueTest();

#endif //QUEUE_H
