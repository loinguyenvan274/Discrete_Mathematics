#include <stdio.h>
#include <stdlib.h>
#define INFINITY __INT_MAX__
#define TRUE 1
#define FALSE 0
#define EMPTY -1
#define PASSED 0
#define COST 1
#define LENGTH 2
#define LAST_VERTEX_NAME 3
int nVertex = 0;
void initGraph(int ***graph, int ***tempGraph)
{
    *tempGraph = (int **)malloc(sizeof(int *) * nVertex);
    *graph = (int **)malloc(sizeof(int *) * nVertex);
    for (int i = 0; i < nVertex; i++)
    {
        (*graph)[i] = (int *)malloc(sizeof(int) * nVertex);
        (*tempGraph)[i] = (int *)malloc(sizeof(int) * 4);
        for (int j = 0; j < nVertex; j++)
        {
            (*graph)[i][j] = INFINITY;
        }
        (*tempGraph)[i][PASSED] = FALSE;           // kiểm tra pass hay chưa
        (*tempGraph)[i][COST] = FALSE;             // kiểm tra thuộc đỉnh xung quanh đỉnh hiện tại
        (*tempGraph)[i][LENGTH] = INFINITY;        // khởi tạo độ dài ngắn nhất từ đỉnh được chọn đến nó
        (*tempGraph)[i][LAST_VERTEX_NAME] = EMPTY; // đỉnh phía trước khi chọn nó là đỉnh xét hiện tại
    }
}
void EnterLength(int **graph, int vertex_1, int vertex_2, int length)
{
    if (vertex_1 >= nVertex || vertex_2 >= nVertex || vertex_1 < 0 || vertex_2 < 0)
        exit(1);
    graph[vertex_1][vertex_2] = length;
    graph[vertex_2][vertex_1] = length;
}
void DJS_algorithm(int **graph, int **tempGraph, int cVertex)
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
        DJS_algorithm(graph, tempGraph, adr);
}
void Dijkstra(int **graph, int **tempGraph, int cVertex)
{
    tempGraph[cVertex][LENGTH] = 0;
    DJS_algorithm(graph, tempGraph, cVertex);
}
void freeGraph(int ***graph, int ***tempGraph, int n)
{
    for (int i = 0; i < n; i++)
    {
        free((*graph)[i]);
        free((*tempGraph)[i]);
    }
    free(*graph);
    free(*tempGraph);
    *graph = NULL;
    *tempGraph = NULL;
}
void recursion(int **resultDKT, int endNode)
{
    if (resultDKT[endNode][LAST_VERTEX_NAME] != EMPTY)
    {
        recursion(resultDKT, resultDKT[endNode][LAST_VERTEX_NAME]);
        printf("[%d] -> ", resultDKT[endNode][LAST_VERTEX_NAME]);
    }
}
void findPath(int **resultDKT, int endNode)
{

    recursion(resultDKT, endNode);

    printf("[%d] => length %d", endNode, resultDKT[endNode][LENGTH]);
}
void main()
{
    int **graph = NULL;
    int **tempGraph = NULL;
    int numberOfedges, edge, sVertex, eVertex;
    printf("So dinh : ");
    scanf("%d", &nVertex);
    printf("So canh : ");
    scanf("%d", &numberOfedges);
    initGraph(&graph, &tempGraph);
    int vertex_1, vertex_2, weight;
    printf("vertex 1    vertex 2      weight\n");
    for (int i = 0; i < numberOfedges; i++)
    {
        scanf("%d", &vertex_1);
        scanf("%d", &vertex_2);
        scanf("%d", &weight);
        EnterLength(graph, vertex_1, vertex_2, weight);
    }
    printf("Enter starting vertex : ");
    scanf("%d", &sVertex);

    Dijkstra(graph, tempGraph, sVertex);
    printf("Enter Ending Vertex : ");
    scanf("%d", &eVertex);
    findPath(tempGraph, eVertex);

    freeGraph(&graph, &tempGraph, nVertex);
    printf("\nEnd");
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