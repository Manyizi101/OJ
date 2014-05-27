#include   <stdio.h>

int main()
{
    int a[10] = {1,5,13,14,20,26,34,48,52,60};
    int n, m, i;
    scanf("%d", &n);
    for (i = 0; i < 10; i++)
    {
        if(n==a[i])
        {
            printf("%d", i);
            return 0;
        }

    }
    printf("-1");
    return 0;
}
