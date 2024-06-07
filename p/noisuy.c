#include <stdio.h>

int noi_suy(int n)
{
    if (n == 0)
        return 0;
    else if (n == 1)
        return 1;
    return 5 * noi_suy(n - 1) - 6 * noi_suy(n - 2);
}
int fibonacci(int n)
{
    if (n == 0 || n == 1)
        return 1;
    return fibonacci(n - 1) + fibonacci(n - 2);
}
int lap_fibonacci(int n)
{
    int a_n, a_n_1, a_n_2;
    for (int i = 0; i <= n; i++)
    {
        a_n_2 = a_n_1;
        a_n_1 = a_n;
        if (i == 0 || i == 1)
            a_n = 1;
        else
            a_n = a_n_1 + a_n_2;
    }
    return a_n;
}
long lap_noi_suy(int n)
{
    long a_n, a_n_1, a_n_2;
    for (int i = 0; i <= n; i++)
    {
        a_n_2 = a_n_1;
        a_n_1 = a_n;
        if (i == 0)
            a_n = 0;
        else if (i == 1)
            a_n = 1;
        else
        {
            a_n = 5 * a_n_1 - 6 * a_n_2;
        }
    }
    return a_n;
}
int main()
{
    printf("%d", noi_suy(4));
    printf("\n%d", lap_noi_suy(4));
    printf("\nday_fibonacci : ");
    for (int i = 0; i <= 10; i++)
    {
        printf("%ld ", lap_fibonacci(i));
    }
}
