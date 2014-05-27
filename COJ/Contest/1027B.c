#include   <stdio.h>

int main()
{
    int h[10], H, i, M = 0;
    for (i = 0; i < 10; i++)    scanf("%d", &h[i]);
    scanf("%d", &H);
    for (i = 0; i < 10; i++)
    {
        if (h[i] <= H+30)    M++;
    }
    printf("%d", M);
    return 0;
}
