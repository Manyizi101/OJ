#include<stdio.h>
#define MAX 100

int triangle[MAX][MAX];

int main()
{
    int n, i, j;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
        for (j = 0; j <= i; j++)
            scanf("%d", triangle[i] + j);
    for (i = n - 2; i >= 0; i--)
        for (j = 0; j <= i; j++)
            triangle[i][j] += triangle[i + 1][j] > triangle[i + 1][j + 1] ? triangle[i + 1][j] : triangle[i + 1][j + 1];
    printf("%d\n", triangle[0][0]);
    return 0;
}