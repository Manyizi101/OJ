#include   <stdio.h>

int main()
{
    int n, i , j;
    scanf("%d", &n);
    int a[n];
    for (i = 0; i < n; i++) a[i] = ((i+1)*(i+1)+(i+1))/2;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n - i; j++)
        {
            printf("%d ", a[j+i]-i);
        }
        printf("\n");
    }
    return 0;
}
