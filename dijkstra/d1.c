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
    }
}

void EnterLength(int vertex_1, int vertex_2, int length)
{
    if (vertex_1 >= nVertex || vertex_2 >= nVertex || vertex_1 < 0 || vertex_2 < 0)
        return;

    graph[vertex_1][vertex_2] = length;
    graph[vertex_2][vertex_1] = length;
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

    for (int i = 0; i < nVertex; i++)
    {
        if (tempGraph[i][COST] == TRUE && findMinLength > tempGraph[i][LENGTH] && i != cVertex)
        {
            findMinLength = tempGraph[i][LENGTH];
            adr = i;
        }
    }

    tempGraph[cVertex][COST] = FALSE;
    tempGraph[cVertex][PASSED] = TRUE;

    if (adr != cVertex)
        DJS_algorithm(adr);
}

void Dijkstra(int cVertex)
{
    for (int i = 0; i < nVertex; i++)
    {
        tempGraph[i][PASSED] = FALSE;
        tempGraph[i][COST] = FALSE;
        tempGraph[i][LENGTH] = INFINITY;
        tempGraph[i][LAST_VERTEX_NAME] = EMPTY;
    }
    tempGraph[cVertex][LENGTH] = 0;
    DJS_algorithm(cVertex);
}

void findPath(int endNode)
{
    if (tempGraph[endNode][LAST_VERTEX_NAME] != EMPTY)
    {
        findPath(tempGraph[endNode][LAST_VERTEX_NAME]);
    }
    printf("-> [%d] ", endNode);
}

int main()
{
    int numberOfedges, sVertex, eVertex;
    printf("So dinh : ");
    scanf("%d", &nVertex);
    printf("So canh : ");
    scanf("%d", &numberOfedges);
    initGraph();
    int vertex_1, vertex_2, weight, pv1, pv2;
    printf("dinh_1    dinh_2      trong so\n");

    for (int i = 0; i < numberOfedges; i++)
    {
        scanf("%d%d%d", &vertex_1, &vertex_2, &weight);
        EnterLength(vertex_1, vertex_2, weight);
    }

    printf("dinh bat dau : ");
    scanf("%d", &sVertex);
    printf("dinh cuoi cung : ");
    scanf("%d", &eVertex);
    printf("di qua canh cua 2 dinh : ");
    scanf("%d%d", &pv1, &pv2);
    Dijkstra(sVertex);
    if (tempGraph[pv1][LENGTH] < tempGraph[pv2][LENGTH])
    {
        sVertex = pv2;
        findPath(pv1);
    }
    else
    {
        sVertex = pv1;
        findPath(pv2);
    }
    Dijkstra(sVertex);
    findPath(eVertex);
    return 0;
}

/* example {
So dinh : 9
So canh : 13
vertex 1    vertex 2      weight
0 3 21
0 1 25
0 2 20
3 5 25
2 5 15
2 4 6
1 4 10
5 6 19
5 7 20
4 6 23
6 8 17
6 7 18
8 7 20
Enter starting vertex : 0
Enter Ending Vertex : 6
[0] -> [2] -> [4] -> [6] => length 49
}
*/