#include  <stdio.h>

int main()
{
    int m,n;
    int i,j;
    scanf("%d%d", &m, &n);
    for(i=1000000;i>=1;i--)
    {
        if(m%i==0&&n%i==0)
        {
            printf("%d\n", i);
            goto abc;
        }
    }
    abc:for(j=1;j<1000000;j++)
    {
        if(j%m==0&&j%n==0)
        {
            printf("%d", j);
            return 0;
        }
    }
}
