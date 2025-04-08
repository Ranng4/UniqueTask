//
// Created by Lenovo on 25-4-8.
//

#include "HashMap.h"
#include<stdlib.h>
#include<string.h>

unsigned int Hash(char* key){
  unsigned int hash_val = 0;
  while(*key){
    hash_val = (hash_val * 31 + *key ) % TABLESIZE;
    key++;
  }
  return hash_val;
}

HashTable* HashTableInit(){
  HashTable* hashTable = (HashTable*)malloc(sizeof(HashTable));
  hashTable->size = 0;
  hashTable->buckets = (Node**)calloc(TABLESIZE, sizeof(Node*));
  return hashTable;
}

void insert(HashTable* hashTable,char* key ,int val ){

  unsigned int index = Hash(key);
  Node*cur = hashTable->buckets[index];

  while (cur != NULL) {
    if (strcmp(cur->key, key) == 0) {
      cur->val = val;  // 更新值
      return;
    }
    cur = cur->next;
  }
  Node* node = (Node*)malloc(sizeof(Node));
  node->key =strdup(key);
  node->val =val;
  node->next = hashTable->buckets[index]->next;
  hashTable->buckets[index]->next = node;
  hashTable->size++;
  return;
}