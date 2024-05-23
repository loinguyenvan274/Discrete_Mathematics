#include <stdio.h>
#include <stdlib.h>
#define INFINITY __INT_MAX__
#define EMPTY -1
#define TRUE 1
#define FALSE 0
typedef struct undirectedGraph
{
    char *name;
    int **graph;
    int **passedNode;
    int *cost;
} Graph;

void initGraph(Graph *graph, int nVertex)
{
    graph->name = (char *)malloc(sizeof(char) * nVertex);
    graph->graph = (int **)malloc(sizeof(int *) * nVertex);
    graph->passedNode = (int **)malloc(sizeof(int *) * nVertex);
    graph->cost = (int *)malloc(sizeof(int) * nVertex);
    printf("Enter vertexs of Name, only character\n");
    for (int i = 0; i < nVertex; i++)
    {
        printf("Name vertex %d : ", i + 1);
        scanf("%c", &graph->name[i]);
        graph->graph[i] = (int *)malloc(sizeof(int) * nVertex);
        graph->passedNode[i] = (int *)malloc(sizeof(int) * 2);
        graph->passedNode[i][0] = FALSE;
        graph->passedNode[i][0] = INFINITY;
        graph->cost[i] = FALSE;
    }
}

int main()
{
}