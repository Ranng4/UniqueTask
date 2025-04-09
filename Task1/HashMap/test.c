//
// Created by Lenovo on 25-4-9.
//

#include"HashMap.h"
#include<stdio.h>
int main() {
    HashTable* hashTable = HashTableInit();

    insert(hashTable, "apple", 10);
    insert(hashTable, "banana", 20);
    insert(hashTable, "cherry", 30);

    printf("查找 'apple': %d\n", *find(hashTable, "apple"));
    printf("查找 'banana': %d\n", *find(hashTable, "banana"));
    printf("查找 'cherry': %d\n", *find(hashTable, "cherry"));

    update(hashTable, "apple", 100);
    printf("更新后 'apple': %d\n", *find(hashTable, "apple"));

    removeKey(hashTable, "banana");
    printf("删除 'banana' 后查找: %p\n", (void*)find(hashTable, "banana"));

    hashMapPrint(hashTable);

    destroyHashTable(hashTable);

    return 0;
}