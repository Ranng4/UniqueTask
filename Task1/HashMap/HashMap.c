#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define TABLESIZE 100  // 确保定义了合适的表大小

typedef struct Node {
    char *key;
    int val;
    struct Node *next;
} Node;

typedef struct HashTable {
    int size;
    Node **buckets;
} HashTable;

unsigned int Hash(const char *key) {
    unsigned int hash_val = 0;
    while (*key) {
        hash_val = (hash_val * 31 + *key) % TABLESIZE;
        key++;
    }
    return hash_val;
}

HashTable *HashTableInit() {
    HashTable *hashTable = (HashTable *)malloc(sizeof(HashTable));
    hashTable->size = 0;
    hashTable->buckets = (Node **)calloc(TABLESIZE, sizeof(Node *));
    return hashTable;
}

void insert(HashTable *hashTable, const char *key, int val) {
    unsigned int index = Hash(key);
    Node *cur = hashTable->buckets[index];

    // 检查键是否存在，存在则更新
    while (cur != NULL) {
        if (strcmp(cur->key, key) == 0) {
            cur->val = val;
            return;
        }
        cur = cur->next;
    }

    // 创建新节点并插入到链表头部
    Node *node = (Node *)malloc(sizeof(Node));
    node->key = strdup(key);
    node->val = val;
    node->next = hashTable->buckets[index];  // 新节点指向原头节点
    hashTable->buckets[index] = node;        // 更新头节点为新节点
    hashTable->size++;
}

int *find(HashTable *hashTable, const char *key) {
    unsigned int index = Hash(key);
    Node *cur = hashTable->buckets[index];

    while (cur != NULL) {
        if (strcmp(cur->key, key) == 0) {
            return &(cur->val);
        }
        cur = cur->next;
    }
    return NULL;
}

void removeKey(HashTable *hashTable, const char *key) {
    unsigned int index = Hash(key);
    Node *pre = NULL;
    Node *cur = hashTable->buckets[index];

    while (cur != NULL) {
        if (strcmp(cur->key, key) == 0) {
            if (pre == NULL) {
                // 删除头节点
                hashTable->buckets[index] = cur->next;
            } else {
                pre->next = cur->next;
            }
            free(cur->key);
            free(cur);
            hashTable->size--;
            return;
        }
        pre = cur;
        cur = cur->next;
    }
    printf("Key not found: %s\n", key);
}

void hashMapPrint(HashTable *hashTable) {
    for (int i = 0; i < TABLESIZE; i++) {
        Node *cur = hashTable->buckets[i];
        while (cur != NULL) {
            printf("%s: %d\n", cur->key, cur->val);
            cur = cur->next;
        }
    }
}

void update(HashTable* hash_table, const char* key, int value) {
    insert(hash_table, key, value);
}

void destroyHashTable(HashTable* hashTable) {
    for (int i = 0; i < TABLESIZE; i++) {
        Node* current = hashTable->buckets[i];
        while (current != NULL) {
            Node* temp = current;
            current = current->next;
            free(temp->key);
            free(temp);
        }
    }
    free(hashTable->buckets);
    free(hashTable);
}





int HashMapTest() {
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