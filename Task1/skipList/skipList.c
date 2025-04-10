#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <limits.h>
#include"skipList.h"
// #define HEIGHT 5
//
// typedef struct SkipNode {
//     int key;
//     char* val;
//     struct SkipNode** next; // 各层的next指针
// } SkipNode;
//
// typedef struct SkipList {
//     SkipNode* header; // 头节点
//     int level;        // 当前层数
// } SkipList;


SkipNode* createNode(int key,char* val, int level) {
    SkipNode* node = (SkipNode*)malloc(sizeof(SkipNode));
    node->key = key;
    node->val = strdup(val);
    node->next = (SkipNode**)malloc(level * sizeof(SkipNode*));
    for (int i = 0; i < level; i++) {
        node->next[i] = NULL;
    }
    return node;
}


SkipList* SkipListInit() {
    SkipList* list = (SkipList*)malloc(sizeof(SkipList));
    list->level = 1;
    list->header = createNode(INT_MIN ,NULL,HEIGHT);
    for (int i = 0; i < HEIGHT; i++) {
        list->header->next[i] = NULL;
    }
    return list;
}


int randomLevel() {
    srand(time(0));
    return rand()%(HEIGHT-1)+1; //1~HEIGHT
}


void SkipNodeInsert(SkipList* list, int key, char* val) {
    SkipNode* update[HEIGHT];
    SkipNode* current = list->header;

    for (int i = list->level - 1; i >= 0; i--) {
        while (current->next[i] != NULL && current->next[i]->key < key)
            current = current->next[i];
        update[i] = current;
    }

    current = current->next[0];
    if (current != NULL && current->key == key) {
        free(current->val);
        current->val = strdup(val);
        printf("%d已经被更新成%s",key,val);
        return; // 已存在
    }

    int level = randomLevel();
    if (level > list->level) {
        for (int i = list->level; i < level; i++) {
            update[i] = list->header;
        }
        list->level = level;
    }

    SkipNode* newNode = createNode(key,val, level);
    for (int i = 0; i < level; i++) {
        newNode->next[i] = update[i]->next[i];
        update[i]->next[i] = newNode;
    }
}


char* SkipNodeFind(SkipList* list, int key) {
    SkipNode* current = list->header;
    for (int i = list->level - 1; i >= 0; i--) {
        while (current->next[i] != NULL && current->next[i]->key < key)
            current = current->next[i];
    }
    current = current->next[0];
    if (current != NULL && current->key == key) {
        return current->val;
    }
    return "NOT FOUND";
}


void SkipNodeUpdate(SkipList* list, int key, char* val) {
    SkipNode* current = list->header;
    for (int i = list->level - 1; i >= 0; i--) {
        while (current->next[i] != NULL && current->next[i]->key < key)
            current = current->next[i];
    }
    current = current->next[0];
    if (current != NULL && current->key == key) {
        free(current->val);
        current->val = strdup(val);
        printf("更新成功\n");
        return;
    }
    printf("UPDATE FAIL, NOT FOUND\n");
}


void SkipNodeDele(SkipList* list, int key) {
    SkipNode* update[HEIGHT];
    SkipNode* current = list->header;

    for (int i = list->level - 1; i >= 0; i--) {
        while (current->next[i] != NULL && current->next[i]->key < key)
            current = current->next[i];
        update[i] = current;
    }

    current = current->next[0];
    if (current == NULL || current->key != key) {
        printf("Key not found\n");
        return;
    }

    for (int i = 0; i < list->level; i++) {
        if (update[i]->next[i] != current)
            break;
        update[i]->next[i] = current->next[i];
    }

    free(current->next);
    free(current);

    while (list->level > 1 && list->header->next[list->level - 1] == NULL)
        list->level--;
    
    printf("删除成功\n");
}


int SkipTest() {
    srand(time(NULL));
    SkipList* list = SkipListInit();

    SkipNodeInsert(list, 5, "1`23");
    SkipNodeInsert(list, 3, "12314");
    SkipNodeInsert(list, 7, "4141");

    printf("查找5: %s\n", SkipNodeFind(list, 5));
    printf("查找3: %s\n", SkipNodeFind(list, 3));
    printf("查找7: %s\n", SkipNodeFind(list, 7));
    printf("查找10: %s\n", SkipNodeFind(list, 10));

    SkipNodeUpdate(list, 5, "Updated");
    printf("查找5: %s\n", SkipNodeFind(list, 5));
    SkipNodeDele(list, 5);
    printf("删除5后查找5: %s\n", SkipNodeFind(list, 5));

    return 0;
}