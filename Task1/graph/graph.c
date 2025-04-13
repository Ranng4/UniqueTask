//
// Created by Lenovo on 25-4-13.
//

#include "graph.h"
#include<stdlib.h>
#include<stdio.h>

typedef struct GraphNode {
    int dest; // 目标
    struct GraphNode* next;
    int weight; //权重
}Node;


typedef  struct Graph {
    int V; // 顶点数
    Node** adj; //相邻表数组
    int* inDegree; //入度
}Graph;


Graph* GraphInit(int V) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->V = V;
    graph->adj = (Node**)malloc(V*sizeof(Node*));
    graph->inDegree = (int*)malloc(V*sizeof(int));

    for (int i =0;i<V;i++) {
        graph->adj[i]=NULL;
        graph->inDegree[i]=0;
    }
    return graph;
}

//加边
void addEdge(Graph* graph,int src,int dest) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->dest=dest;
    newNode->next=graph->adj[src];
    graph->adj[src]=newNode;
    graph->inDegree[dest]++;
}

int* topologicalSort(Graph*graph) {
    int V = graph->V;
    int* res = (int*)malloc(V*sizeof(int));
    int index =0;

    int* queue = (int*)malloc(V*sizeof(int));
    int front = 0;
    int rear = 0;
    for (int i = 0;i<V;i++) {
        if (graph->inDegree[i]==0) {
            queue[rear++]=i;
        }
    }
    while (front<rear) {
        int u = queue[front++];
        res[index++]=u;
        Node* node = graph->adj[u];
        while (node) {
            int v = node->dest;
            if (--graph->inDegree[v]==0) {
                queue[rear++]=v;
            }
            node=node->next;
        }
    }
    free(queue);
    return res;
}

int GraphTest1() {
    Graph*graph = GraphInit(6);
    addEdge(graph,5,2);
    addEdge(graph,5,0);
    addEdge(graph,4,0);
    addEdge(graph,4,1);
    addEdge(graph,2,3);
    addEdge(graph,3,1);
   int * res = topologicalSort(graph);
    for (int i =0;i<6;i++) {
        printf("%d\n",res[i]);
    }
    return 0;
}
