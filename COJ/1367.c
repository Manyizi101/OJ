#include   <stdio.h>


int main()
{
    int m, n, i, j, master = 0, f[1000], g[1000];
    scanf("%d%d", &m, &n);
    for(i = 0; i < m; i++)      scanf("%d", &f[i]);
    for(i = 0; i < n; i++)      scanf("%d", &g[i]);
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (f[i] > g[j])        master += 1;
        }
    }
    printf("%d", master);
    return 0;
}
