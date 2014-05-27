#include   <stdio.h>

int main()
{
    int n, i, a[100];
    int q = 0, w = 0;
    scanf("%d", &n);
    for (i = 0; i < n; i++)     scanf("%d", &a[i]);
    for (i = 0; i < n; i++)
    {
        if (a[i] == 0)   q++;
        if (a[i] == 1)   w++;
    }
    printf("%d", q-w);
    return 0;
}
