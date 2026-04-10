#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// 最大顶点数
#define MAX_VEX 100

// 边节点结构
typedef struct EdgeNode {
    int adjvex;
    struct EdgeNode* nextedge;
} EdgeNode;

// 顶点结构
typedef struct VexNode {
    int data;
    EdgeNode* firstedge;
} VexNode;

// 邻接表结构
typedef struct {
    VexNode adjlist[MAX_VEX];
    int numVex, numEdge;
} AdjGraph;

// 访问标记数组
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

// 向有向图中添加边
void AddEdge(AdjGraph* G, int v1, int v2) {
    EdgeNode* newNode = (EdgeNode*)malloc(sizeof(EdgeNode));
    newNode->adjvex = v2;
    newNode->nextedge = G->adjlist[v1].firstedge;
    G->adjlist[v1].firstedge = newNode;
}

// 判断是否存在从vi到vj的路径
bool DFS_Path(AdjGraph* G, int vi, int vj) {
    int v;
    EdgeNode* p;

    if (vi == vj) {
        return true;
    }

    visited[vi] = true;
    p = G->adjlist[vi].firstedge;

    while (p != NULL) {
        v = p->adjvex;
        if (!visited[v]) {
            if (DFS_Path(G, v, vj)) {
                return true;
            }
        }
        p = p->nextedge;
    }
    return false;
}

// 判断有向图中vi到vj是否存在路径
bool HasPath(AdjGraph* G, int vi, int vj) {
    int i;
    for (i = 0; i < G->numVex; i++) {
        visited[i] = false;
    }
    if (vi < 0 || vi >= G->numVex || vj < 0 || vj >= G->numVex || vi == vj) {
        return false;
    }
    return DFS_Path(G, vi, vj);
}

// 测试用例
int main() {
    AdjGraph G;
    InitGraph(&G);
    // 修正：普通变量用.访问成员
    G.numVex = 5;
    AddEdge(&G, 0, 1);
    AddEdge(&G, 0, 2);
    AddEdge(&G, 1, 3);
    AddEdge(&G, 3, 4);
    AddEdge(&G, 2, 4);

    int vi = 0, vj = 4;
    if (HasPath(&G, vi, vj)) {
        printf("顶点%d到顶点%d存在路径\n", vi, vj);
    }
    else {
        printf("顶点%d到顶点%d不存在路径\n", vi, vj);
    }

    vi = 4;
    vj = 0;
    if (HasPath(&G, vi, vj)) {
        printf("顶点%d到顶点%d存在路径\n", vi, vj);
    }
    else {
        printf("顶点%d到顶点%d不存在路径\n", vi, vj);
    }

    return 0;
}