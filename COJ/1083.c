#include  <stdio.h>


int  main()
{
    int j = 0 ,key;
    int a = 1, b = 1, K;
    while ((scanf("%d%d%d", &a, &b, &K))&&(a != 0 || b != 0))
    {
        key = 1;
        for(j = 0; j < K; j++)       key *= 10;
        if (a%key == b%key)     printf("-1\n");
        else        printf("%d\n", (a+b));
    }
    return 0;
}
