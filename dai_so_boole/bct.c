#include <stdio.h>
#include <math.h>

int number_k = 3; // edit
int function(int *ar, int n)
{
    int a, b, c, d, e, f, g, h, i, j, k;
    int ii = n - 1;
    switch (ii)
    {
    case 10:
        k = ar[10];
    case 9:
        j = ar[9];
    case 8:
        i = ar[8];
    case 7:
        h = ar[7];
    case 6:
        g = ar[6];
    case 5:
        f = ar[5];
    case 4:
        e = ar[4];
    case 3:
        d = ar[3];
    case 2:
        c = ar[2];
    case 1:
        b = ar[1];
    case 0:
        a = ar[0];
    }

    // nhập hàm vào đây
    /*
    example
     int result = A && (B || C);
  printf("Kết quả của A AND (B OR C): %d\n", result); còn x' là !x
  dừng quên chỉnh sửa number_k = số biến nhé !
    */
    // a=x b=y c=z
    int x = a, y = b, z = c;
    return !(!(x && y) && z) && !((!x || z) && (!y || !z)); // edit
}

void init(int *a, int n)
{
    for (int i = 0; i < n; i++)
        a[i] = 0;
}
void show(int *a, int n)
{

    for (int i = 0; i < n; i++)
        printf("| %d ", a[i]);
}
void show_tital(int n)
{
    char *abc = "abcdefghijklmnopqrstuvwxyz";
    for (int i = 0; i < n; i++)
        printf("| %c ", abc[i]);
    printf("| F |\n");
}

void hoan_vi(int *a, int n)
{
    int i = n - 1;
    int j = i;
    int count = 0;
    show_tital(n);
    while (j >= 0)
    {
        show(a, n);
        printf("| %d |", function(a, n));
        printf("\n");
        if (a[i] == 0)
            a[i] = 1;
        else
        {
            for (j = i; j >= 0; j--)
            {
                if (a[j] == 1)
                    a[j] = 0;
                else
                {
                    a[j] = 1;
                    break;
                }
            }
        }
    }
}
int main()
{
    int n = number_k;
    int a[n];
    init(a, n);
    hoan_vi(a, n);
}
/*


00000
00001
00010
00011

11111

*/