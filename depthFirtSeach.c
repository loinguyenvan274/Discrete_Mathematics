#include <stdio.h>
#define max_size 6
int sizeMaxtrix;
void enterMaxtrix(int maxtrix[][sizeMaxtrix])
{
    for (int i = 0; i < sizeMaxtrix; i++)
    {
        for (int j = 0; j < sizeMaxtrix; j++)
        {
            printf("%d & %d : ", i + 1, j + 1);
            scanf("%d", &maxtrix[i][j]);
        }
    }
}
void printMt(int maxtrix[][sizeMaxtrix])
{
    for (int i = 0; i < sizeMaxtrix; i++)
    {
        for (int j = 0; j < sizeMaxtrix; j++)
        {
            printf("%d ", maxtrix[i][j]);
        }
        printf("\n");
    }
}
void init(int array[])
{
    for (int i = 0; i < sizeMaxtrix; i++)
    {
        array[i] = 0;
    }
}
int main()
{
    printf("Enter Top Numbers : ");
    scanf("%d", &sizeMaxtrix);
    int A[sizeMaxtrix];
    init(A);
    int maxtrix[sizeMaxtrix][sizeMaxtrix];
    enterMaxtrix(maxtrix);
    printf("\n");
    printMt(maxtrix);
}