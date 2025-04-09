//
// Created by Lenovo on 25-4-8.
//

#ifndef HASHMAP_H
#define HASHMAP_H

#define TABLESIZE  32

typedef struct Node{
  char* key;
  int val;
  struct Node* next;
}Node;

typedef struct HashTable{
  Node** buckets;     // 指向链表头的指针数组
  int size;
}HashTable;


HashTable* HashTableInit();
void insert(HashTable* hashTable,char* key ,int val );
int* find(HashTable* hashTable,const char *key);
void removeKey(HashTable* hashTable,const char *key);
void hashMapPrint(HashTable* hashTable);
void update(HashTable* hash_table, const char* key, int value);
void destroyHashTable(HashTable* hash_table);
#endif //HASHMAP_H
