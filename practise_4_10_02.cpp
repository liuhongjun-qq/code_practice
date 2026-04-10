#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// 题目：以邻接表作存储结构，判别以邻接表方式存储的无向图中
// 是否存在从顶点v1到顶点v2的长度为k的简单路径

#define MAX_VEX 100

typedef struct EdgeNode {
    int adjvex;
    struct EdgeNode* nextedge;
} EdgeNode;

typedef struct VexNode {
    int data;
    EdgeNode* firstedge;
} VexNode;

typedef struct {
    VexNode adjlist[MAX_VEX];
    int numVex, numEdge;
} AdjGraph;

bool visited[MAX_VEX];

// 初始化邻接表
void InitGraph(AdjGraph* G) {
    int i;
    G->numVex = 0;
    G->numEdge = 0;
    for (i = 0; i < MAX_VEX; i++) {
        G->adjlist[i].data = i;
        G->adjlist[i].firstedge = NULL;
    }
}

// 向无向图添加无向边
void AddUndirectedEdge(AdjGraph* G, int v1, int v2) {
    EdgeNode* newNode = (EdgeNode*)malloc(sizeof(EdgeNode));
    newNode->adjvex = v2;
    newNode->nextedge = G->adjlist[v1].firstedge;
    G->adjlist[v1].firstedge = newNode;

    newNode = (EdgeNode*)malloc(sizeof(EdgeNode));
    newNode->adjvex = v1;
    newNode->nextedge = G->adjlist[v2].firstedge;
    G->adjlist[v2].firstedge = newNode;
}

// DFS查找长度为k的简单路径
bool DFS_LengthK(AdjGraph* G, int cur, int target, int curLen, int k) {
    int v;
    EdgeNode* p;

    if (curLen == k && cur == target) {
        return true;
    }
    if (curLen > k) {
        return false;
    }

    visited[cur] = true;
    p = G->adjlist[cur].firstedge;

    while (p != NULL) {
        v = p->adjvex;
        if (!visited[v]) {
            if (DFS_LengthK(G, v, target, curLen + 1, k)) {
                return true;
            }
        }
        p = p->nextedge;
    }

    visited[cur] = false;
    return false;
}

// 判断是否存在长度为k的简单路径
bool HasLengthKPath(AdjGraph* G, int v1, int v2, int k) {
    int i;
    for (i = 0; i < G->numVex; i++) {
        visited[i] = false;
    }

    if (v1 < 0 || v1 >= G->numVex || v2 < 0 || v2 >= G->numVex || k < 0) {
        return false;
    }

    return DFS_LengthK(G, v1, v2, 0, k);
}

int main() {
    AdjGraph G;
    InitGraph(&G);
    G.numVex = 5;

    AddUndirectedEdge(&G, 0, 1);
    AddUndirectedEdge(&G, 0, 2);
    AddUndirectedEdge(&G, 1, 3);
    AddUndirectedEdge(&G, 3, 4);
    AddUndirectedEdge(&G, 2, 4);

    int v1 = 0, v2 = 4, k = 2;
    if (HasLengthKPath(&G, v1, v2, k)) {
        printf("顶点%d到顶点%d存在长度为%d的简单路径\n", v1, v2, k);
    }
    else {
        printf("顶点%d到顶点%d不存在长度为%d的简单路径\n", v1, v2, k);
    }

    k = 3;
    if (HasLengthKPath(&G, v1, v2, k)) {
        printf("顶点%d到顶点%d存在长度为%d的简单路径\n", v1, v2, k);
    }
    else {
        printf("顶点%d到顶点%d不存在长度为%d的简单路径\n", v1, v2, k);
    }

    return 0;
}