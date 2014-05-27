/*
#include   <stdio.h>


int main()
{
    int a, b, M = 1;
    scanf("%d%d", &a, &b);
    while((M*a) <= b)
    {
        M++;
    }
    printf("%d", M);
    return 0;
}

此版本各种WA，原因未知。
**/

#include   <stdio.h>


int main()
{
    int a , b , M =1;
    scanf("%d%d", &a, &b);
    for(M = 1; ; M++)
    {
        if ((a*M) > b)
        {
            printf("%d", M);
            return 0;
        }
    }
}
