#include   <stdio.h>


int main()
{
    int T, N[1000][1000], a[1000];
    int i, j, key, x;
    scanf("%d", &T);
    for (i = 0; i < T; i++)
    {
        scanf("%d", &a[i]);
        for (j = 0; j < a[i]; j++)  scanf("%d", &N[i][j]);
    }
    for (i = 0; i < T; i++)
    {
        for (j = 0; j < a[i];j++)
        {
            for (x = a[i]-1; x > j; x--)
            {
                if (N[i][j] < N[i][x])
                {
                    key = N[i][j];
                    N[i][j] = N[i][x];
                    N[i][x] = key;
                }
            }
        }
    }
    for (i = 0; i < T; i++)
    {
        for(j = 0; j < a[i]; j++)
        {
            printf("%d ", N[i][j]);
        }
        printf("\n");
    }
    return 0;
}
