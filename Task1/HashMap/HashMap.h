//
// Created by Lenovo on 25-4-8.
//

#ifndef HASHMAP_H
#define HASHMAP_H

#define TABLESIZE 32

typedef struct Node{
  char* key;
  int val;
  struct Node* next;
}Node;

typedef struct HashTable{
  Node** buckets;     // 指向链表头的指针数组
  int size;
}HashTable;


#endif //HASHMAP_H
