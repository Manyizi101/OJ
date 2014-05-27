#include   <stdio.h>


int main()
{
    int a, b, c, d;
    scanf("%d%d%d%d", &a, &b, &c, &d);
    if (a == 1)
    {
        printf("L1");
        return 0;
    }
    if (b == 1)
    {
        printf("L2");
        return 0;
    }
    if (c == 1)
    {
        printf("L3");
        return 0;
    }
    if (d == 1)
    {
        printf("L4");
        return 0;
    }
    else
    {
        printf("-1");
        return 0;
    }
}
