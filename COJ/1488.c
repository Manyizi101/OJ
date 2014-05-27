#include   <stdio.h>


int main()
{
    int n;
    while (scanf("%d", &n) && n != 0)
    {
        printf("%d\n", (n*n+n)/2+1);
    }
    return 0;
}
