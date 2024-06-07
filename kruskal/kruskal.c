#include <stdio.h>
#include <limits.h>

#define MAX 100
#define INFINITY INT_MAX

#define DINH_1 0
#define DINH_2 1
#define TRONG_SO 2

int nVertex = 0;
int e;
int graph[MAX][MAX];
int list[MAX][3];
int parent[MAX];
int canh = 0;

int find(int x)
{
    if (parent[x] != x)
        parent[x] = find(parent[x]);
    return parent[x];
}

void unionSets(int x, int y)
{
    int parent_x = find(x);
    int parent_y = find(y);
    parent[parent_x] = parent_y;
}

void Swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void A_Swap(int list[MAX][3], int a, int b)
{
    Swap(&list[a][DINH_1], &list[b][DINH_1]);
    Swap(&list[a][DINH_2], &list[b][DINH_2]);
    Swap(&list[a][TRONG_SO], &list[b][TRONG_SO]);
}

void initGraph()
{
    for (int i = 0; i < nVertex; i++)
    {
        for (int j = 0; j < nVertex; j++)
        {
            if (i == j)
                graph[i][j] = 0;
            else
                graph[i][j] = INFINITY;
        }
    }
}

void showG()
{
    for (int i = 0; i < nVertex; i++)
    {
        for (int j = 0; j < nVertex; j++)
        {
            if (graph[i][j] == INFINITY)
                printf("INF ");
            else
                printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
}

int kruskal()
{
    int min_khung_cay = 0;

    for (int i = 0; i < nVertex; i++)
    {
        parent[i] = i;
    }

    for (int i = 0; i < e; i++)
    {
        int u = list[i][DINH_1];
        int v = list[i][DINH_2];
        int w = list[i][TRONG_SO];

        if (find(u) != find(v))
        {
            unionSets(u, v);
            min_khung_cay += w;
            graph[u][v] = graph[v][u] = w;
            canh++;
        }
        if (canh == nVertex - 1)
            break;
    }

    return min_khung_cay;
}

int main()
{
    int v1, v2, h, min;
    printf("Nhap so dinh: ");
    scanf("%d", &nVertex);
    printf("Nhap so canh: ");
    scanf("%d", &e);
    printf("nhap lan luoc : dinh_1    dinh_2    trong_so ENTER\n");

    initGraph();

    for (int i = 0; i < e; i++)
    {
        scanf("%d%d%d", &v1, &v2, &h);
        list[i][DINH_1] = v1 - 1;
        list[i][DINH_2] = v2 - 1;
        list[i][TRONG_SO] = h;
    }

    for (int i = 0; i < e - 1; i++)
    {
        min = i;
        for (int j = i + 1; j < e; j++)
        {
            if (list[min][TRONG_SO] > list[j][TRONG_SO])
                min = j;
        }
        A_Swap(list, min, i);
    }

    printf("Khung cay nho nhat la: %d\n", kruskal());
    showG();

    return 0;
}
/*
PS D:\toanroirac\kruskal> ./kruskal
Nhap so dinh: 7
Nhap so canh: 12
nhap lan luoc : dinh_1    dinh_2    trong_so ENTER
1 2 3
1 4 1
1 6 3
2 3 4
2 6 6
3 4 3
3 5 7
3 7 5
4 5 6
4 6 2
5 6 5
6 7 1
Khung cay nho nhat la: 15
0 3 INF 1 INF INF INF
3 0 INF INF INF INF INF
INF INF 0 3 INF INF INF
1 INF 3 0 INF 2 INF
INF INF INF INF 0 5 INF
INF INF INF 2 5 0 1
INF INF INF INF INF 1 0
*/