#include <stdio.h>

int main()
{
    int a=0,b=0,c=0,n=0,ans=0;
    while(scanf("%d", &n)&&n!=-1)
    {
        a=b=c=ans=0;
        while(n--)
        {
            c=b;
            scanf("%d%d", &a,&b);
            ans+=a*(b-c);
        }
        printf("%d miles\n", ans);
    }
    return 0;
}
