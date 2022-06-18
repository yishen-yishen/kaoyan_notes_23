#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define MaxVertexNum 100
// 无穷，代表两个顶点之间不存在边/弧
#define INFINITY
// 顶点
typedef char VertexType;
// 带全图的边/弧
typedef int EdgeType;

// 1.邻接矩阵存储
typedef struct
{
    // 顶点
    VertexType Vex[MaxVertexNum];
    // 边
    EdgeType Edge[MaxVertexNum][MaxVertexNum];
    // 顶点数，边数/弧数
    int vexnum, arcnum;
} MGraph;

// 2.邻接表法
// 边/弧
typedef struct ArcNode
{
    // 边/弧指向哪个结点
    int adjvex;
    // 下一个弧的指针
    struct ArcNode *next;
} ArcNode;

// 顶点
typedef struct VNode
{
    // 顶点信息
    VertexType data;
    // 第一条弧/边
    ArcNode *first;
    // adjacent adj. 邻接的，邻近的
} VNode, AdjList[MaxVertexNum];

// 邻接表 图
typedef struct
{
    AdjList vertices;
    int vexnum, arcnum;
} ALGraph;
