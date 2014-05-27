#include   <stdio.h>


int main()
{
    int i, j, key, a[10];
    for (i = 0; i < 10; i++)        scanf("%d", &a[i]);
    for (i = 0; i < 10; i++)
    {
        for (j = 9; j > i; j--)
        {
            if (a[j] > a[i])
            {
                key = a[i];
                a[i] = a[j];
                a[j] = key;
            }
        }
    }
    printf("%d", a[0]+a[1]+a[2]);
    return 0;
}
