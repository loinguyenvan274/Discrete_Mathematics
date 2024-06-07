#include <stdio.h>
#include <limits.h>
#define MAX 100
#define INFINITY INT_MAX
#define TRUE 1
#define FALSE 0
#define EMPTY -1
#define PASSED 0
#define COST 1
#define LENGTH 2
#define LAST_VERTEX_NAME 3

int nVertex = 0;
int graph[MAX][MAX];
int tempGraph[MAX][4];

void initGraph()
{
    for (int i = 0; i < nVertex; i++)
    {
        for (int j = 0; j < nVertex; j++)
        {
            graph[i][j] = INFINITY;
        }

        tempGraph[i][PASSED] = FALSE;
        tempGraph[i][COST] = FALSE;
        tempGraph[i][LENGTH] = INFINITY;
        tempGraph[i][LAST_VERTEX_NAME] = EMPTY;
    }
}

void EnterLength(int vertex_1, int vertex_2, int length)
{
    if (vertex_1 >= nVertex || vertex_2 >= nVertex || vertex_1 < 0 || vertex_2 < 0)
        return;

    graph[vertex_1][vertex_2] = length;
}

void DJS_algorithm(int cVertex)
{
    int findMinLength = INFINITY;
    int adr = cVertex;

    for (int j = 0; j < nVertex; j++)
    {
        if (graph[cVertex][j] != INFINITY && cVertex != j && tempGraph[j][PASSED] == FALSE)
        {
            tempGraph[j][COST] = TRUE;
            if (tempGraph[j][LENGTH] > graph[cVertex][j] + tempGraph[cVertex][LENGTH])
            {
                tempGraph[j][LAST_VERTEX_NAME] = cVertex;
                tempGraph[j][LENGTH] = graph[cVertex][j] + tempGraph[cVertex][LENGTH];
            }
        }
    }
    tempGraph[cVertex][COST] = FALSE;
    tempGraph[cVertex][PASSED] = TRUE;

    for (int i = 0; i < nVertex; i++)
    {
        if (tempGraph[i][COST] == TRUE && findMinLength > tempGraph[i][LENGTH] && i != cVertex)
        {
            findMinLength = tempGraph[i][LENGTH];
            adr = i;
        }
    }

    if (adr != cVertex)
        DJS_algorithm(adr);
}

void Dijkstra(int cVertex)
{
    tempGraph[cVertex][LENGTH] = 0;
    DJS_algorithm(cVertex);
}

void recursion(int endNode)
{
    if (tempGraph[endNode][LAST_VERTEX_NAME] != EMPTY)
    {
        recursion(tempGraph[endNode][LAST_VERTEX_NAME]);
        printf("[%d] -> ", tempGraph[endNode][LAST_VERTEX_NAME]);
    }
}

void findPath(int endNode)
{
    recursion(endNode);
    printf("[%d] => duong di ngan nhat :  %d", endNode, tempGraph[endNode][LENGTH]);
}

int main()
{
    int numberOfedges, sVertex, eVertex;
    printf("So dinh : ");
    scanf("%d", &nVertex);
    printf("So canh : ");
    scanf("%d", &numberOfedges);
    initGraph();
    int vertex_1, vertex_2, weight;
    printf("dinh_1    dinh_2      trong so\n");

    for (int i = 0; i < numberOfedges; i++)
    {
        scanf("%d%d%d", &vertex_1, &vertex_2, &weight);
        EnterLength(vertex_1, vertex_2, weight);
    }

    printf("dinh bat dau : ");

    scanf("%d", &sVertex);

    Dijkstra(sVertex);

    printf("dinh cuoi cung : ");
    scanf("%d", &eVertex);
    findPath(eVertex);
    return 0;
}
