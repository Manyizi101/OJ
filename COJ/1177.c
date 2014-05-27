#include   <stdio.h>

int main()
{
    int n, i, j, a[10][10];
    scanf("%d", &n);
    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= i; j++)
        {
            a[i][j] = 1;
        }
    }
    for(i = 2; i <= n; i++)
    {
        for(j = 2; j < i; j++)
        {
            a[i][j] = a[i-1][j-1] + a[i-1][j];
        }
    }
    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= i; j++)
        {
            printf("%3d", a[i][j]);
        }
        printf("\n");
    }
    return 0;
}
