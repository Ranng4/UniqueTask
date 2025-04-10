//
// Created by Lenovo on 25-4-10.
//

#ifndef SKIPLIST_H
#define SKIPLIST_H

#define HEIGHT 5

typedef struct SkipNode {
    int key;
    char* val;
    struct SkipNode** next; // 各层的next指针
} SkipNode;

typedef struct SkipList {
    SkipNode* header; // 头节点
    int level;        // 当前层数
} SkipList;



int SkipTest();

#endif //SKIPLIST_H
