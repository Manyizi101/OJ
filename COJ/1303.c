#include  <stdio.h>

int main()
{
    int h = 0, m = 0, a = 0, b = 0, i= 0;
abc:
    while(scanf("%d:%d",&a,&b)!=EOF)
    {
        if(a == -1)
        {
            printf("%d:%d\n", h, m);
            goto abc;
        }
        m += b;
        i = m/60;
        m = m - 60*i;
        h += a + i;
    }
    return 0;
}
