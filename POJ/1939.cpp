#include <stdio.h>

double cor[2][30000];

int main()
{
    int n, i;
    while (scanf("%d", &n) != EOF)
    {
        for (i = 0; i < n; i++)
            scanf("%lf%lf", &cor[0][i], &cor[1][i]);
        printf("%d", n);
        for (i = 0; i < n; i++)
            printf(" %lf %lf", (cor[0][i] + cor[0][(i + 1) % n]) / 2, (cor[1][i] + cor[1][(i + 1) % n]) / 2);
        putchar('\n');
    }
    return 0;
}