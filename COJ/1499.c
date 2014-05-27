/*#include   <stdio.h>

int main()
{
    double n=0.0, m=0.0;
    int t=0, i=0;
    while (scanf("%lf", &n))
    {

        if (n == 0)
        {
            printf("EOF\n");
            return 0;
        }
        t = 0;
        m = n;
        for (i = 0; i <10000000; i++)
        {
            n = n/3.0;
            t++;
            if (n <= 1.0/m)
            {
                break;
            }
        }
        printf("%d\n", t);
    }
    return 0;
}**/

#include  <stdio.h>
#include  <math.h>

int main()
{
    int t,n;
    while(scanf("%d", &n))
    {
        if(n==0)
        {
            printf("EOF\n");
            return 0;
        }
        t=0;
        for(t=1; t<100000000; t++)
        {
            if(pow(3,t)>=n*n)
            {
                printf("%d\n", t);
                break;
            }
            else continue;
        }

    }
    return 0;
}
