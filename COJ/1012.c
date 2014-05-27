#include<stdio.h>

int main()
{
    static int a[201][201];
    int n,k;
    int i,j,t=1,key;
    scanf("%d%d",&n,&k);
    for(i=1; i<=n; i++)
    {
        t=1;
        while( t )
        {
            scanf("%d",&t);
            if( t )
            {
                a[i][t]=1;
                a[t][i]=1;
            }
        }
    }
    for(i=1; i<=n; i++)
    {
        key=0;
        for(j=1; j<=n; j++)
            if(a[i][j])
                key++;
        a[i][0]=key;
    }
    key=0;
    for(i=1; i<=n; i++)
        if(a[i][0]>=k)
            key++;
    printf("%d\n",key);
    return 0;
}
