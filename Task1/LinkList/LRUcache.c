#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<Link.h>

typedef struct cacheNode {
    int val;
    char* key;
    struct cacheNode* pre;
    struct cacheNode* next;
} cacheNode;

cacheNode* init(int cap) {
    cacheNode* head = (cacheNode*)malloc(sizeof(cacheNode));
    head->next = NULL;
    head->key = "capacity";
    head->val = cap;
    head->pre = NULL;
    return head;
}

cacheNode* put(cacheNode* head, char *key, int val) {

    cacheNode* p = head->next;
    while(p) {
        if(strcmp(p->key, key) == 0) {
            p->val = val;

            if(p->pre) p->pre->next = p->next;
            if(p->next) p->next->pre = p->pre;

            p->next = head->next;
            if(head->next) head->next->pre = p;
            head->next = p;
            p->pre = head;
            return head;
        }
        p = p->next;
    }


    cacheNode* newNode = (cacheNode*)malloc(sizeof(cacheNode));
    newNode->key = strdup(key);
    newNode->val = val;


    newNode->next = head->next;
    if(head->next) head->next->pre = newNode;
    head->next = newNode;
    newNode->pre = head;


    if(head->val > 0) {
        head->val--;
    } else {
        cacheNode* last = head;
        while(last->next) last = last->next;
        last->pre->next = NULL;
        free(last->key);
        free(last);
    }
    return head;
}

int get(cacheNode* head, char *key) {
    cacheNode* p = head->next;
    while(p) {
        if(strcmp(p->key, key) == 0) {
            if(p->pre) p->pre->next = p->next;
            if(p->next) p->next->pre = p->pre;

            p->next = head->next;
            if(head->next) head->next->pre = p;
            head->next = p;
            p->pre = head;

            return p->val;
        }
        p = p->next;
    }
    printf("没有%s\n", key);
    return -1;
}


int LRUTest() {
    cacheNode* cache = init(2);

    cache = put(cache, "A", 1);
    cache = put(cache, "B", 2);
    printf("A: %d\n", get(cache, "A"));

    cache = put(cache, "C", 3);
    printf("B: %d\n", get(cache, "B"));

    return 0;
}