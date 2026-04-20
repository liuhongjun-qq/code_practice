//设计算法实现图的广度优先搜索遍历
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

#define MAXNUM 100
#define INF 65535

typedef int VertexType;
typedef int EdgeType;

typedef struct {
    VertexType vexs[MAXNUM];
    EdgeType arcs[MAXNUM][MAXNUM];
    int vexNum, arcNum;
}Graph;

//创建无向网（邻接矩阵）
void createMGraph(Graph* G) {
    int i, j, k;
    int w;

    printf("输入顶点数和边数：");
    scanf("%d %d", &G->vexNum, &G->arcNum);

    //输入顶点
    printf("输入这%d个顶点的值：", G->vexNum);
    for (i = 0; i < G->vexNum; i++) {
        scanf("%d", &G->vexs[i]);
    }

    //初始化邻接矩阵
    for (i = 0; i < G->vexNum; i++) {
        for (j = 0; j < G->vexNum; j++) {
            G->arcs[i][j] = INF;
        }
    }

    //输入边
    printf("\n输入各条边的顶点及权值：\n");
    for (k = 0; k < G->arcNum; k++) {
        printf("第%d条边：", k + 1);
        scanf("%d %d %d", &i, &j, &w);
        G->arcs[i][j] = w;
        G->arcs[j][i] = w;
    }
}

//输出邻接矩阵
void printMGraph(Graph* G) {
    int i, j;
    printf("邻接矩阵为：\n");
    for (i = 0; i < G->vexNum; i++) {
        for (j = 0; j < G->vexNum; j++) {
            if (G->arcs[i][j] == INF) {
                printf("%-6s", "INF");
            }
            else {
                printf("%-6d", G->arcs[i][j]);
            }
        }
        printf("\n");
    }
}

//增加一个顶点
void InsertVex(Graph* G, VertexType v) {
    G->vexs[G->vexNum] = v;
    for (int i = 0; i <= G->vexNum; i++) {
        G->arcs[G->vexNum][i] = INF;
        G->arcs[i][G->vexNum] = INF;
    }
    G->vexNum++;
}

//删除一个顶点
void DeleteVex(Graph* G, int pos) {
    int i, j;

    for (i = pos; i < G->vexNum - 1; i++) {
        G->vexs[i] = G->vexs[i + 1];
    }

    //删除行
    for (i = pos; i < G->vexNum - 1; i++) {
        for (j = 0; j < G->vexNum; j++) {
            G->arcs[i][j] = G->arcs[i + 1][j];
        }
    }

    //删除列
    for (j = pos; j < G->vexNum - 1; j++) {
        for (i = 0; i < G->vexNum - 1; i++) {
            G->arcs[i][j] = G->arcs[i][j + 1];
        }
    }
    printf("顶点%d已被删除。\n", G->vexs[pos]);
    G->vexNum--;
}

//增加一条边
void InsertArc(Graph* G, int i, int j, int w) {
    G->arcs[i][j] = w;
    G->arcs[j][i] = w;
    G->arcNum++;
    printf("边(%d,%d)添加成功。\n", i, j);
}

//删除一条边
void DeleteArc(Graph* G, int i, int j) {
    G->arcs[i][j] = INF;
    G->arcs[j][i] = INF;
    G->arcNum--;
    printf("边(%d,%d)删除成功。\n", i, j);
}

//深度优先搜索
int visited[MAXNUM];

void DFS(Graph* G, int v, int target, int* found) {
    visited[v] = 1;
    if (v == target) {
        *found = 1;
        return;
    }

    for (int i = 0; i < G->vexNum; i++) {
        if (G->arcs[v][i] != INF && !visited[i]) {
            DFS(G, i, target, found);
        }
    }
}

//广度优先BFS
int queue[MAXNUM];
int front = 0; 
int rear = 0;

//入队
void EnQueue(int v) {
    queue[rear++] = v;
}

//出队
int DeQueue() {
    return queue[front++];
}

//判断队列是否为空
int IsEmpty() {
    return front == rear;
}

//广度优先搜索遍历
void BFS(Graph* G, int v) {
    for (int i = 0; i < G->vexNum; i++) {
        visited[i] = 0;
    }
    printf("广度优先遍历序列：");
    printf("%d ", G->vexs[v]);
    visited[v] = 1; 
    EnQueue(v);

    // 队列不为空就继续遍历
    while (!IsEmpty()) {
        int current = DeQueue(); 
        for (int i = 0; i < G->vexNum; i++) {
            if (G->arcs[current][i] != INF && !visited[i]) {
                printf("%d ", G->vexs[i]);
                visited[i] = 1;
                EnQueue(i);
            }
        }
    }
    printf("\n");
}


int main() {
    Graph G;
    createMGraph(&G);
    printMGraph(&G);
    int start;
    printf("\n输入BFS的起点：");
    scanf("%d", &start);
    BFS(&G, start);
    return 0;
}