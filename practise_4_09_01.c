#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

/*
题目：设计算法实现无向图顶点的增加和删除
*/
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

    printf("输入各条边的顶点及权值：\n");
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
                printf("INF ");
            } else {
                printf("%d ", G->arcs[i][j]);
            }
        }
        printf("\n");
    }
}

//增加一个顶点
void InsertVex(Graph* G, VertexType v) {
    int cur;
    cur = G->vexNum;
    G->vexs[cur] = v;
    for (int i = 0; i <= cur; i++) {
        G->arcs[cur][i] = INF;
        G->arcs[i][cur] = INF;
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

int main() {
    Graph G;
    int newVex, deletepos;

    createMGraph(&G);
    printMGraph(&G);

    printf("输入要增加的顶点值：");
    scanf("%d", &newVex);
    InsertVex(&G, newVex);
    printMGraph(&G);

    printf("输入要删除的顶点序号：");
    scanf("%d", &deletepos);
    DeleteVex(&G, deletepos);
    printMGraph(&G);

    return 0;
}
