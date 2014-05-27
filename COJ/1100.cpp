#include  <stdio.h>

using namespace std;

int main()
{
    int m,n,a[301][301];
    int x[301],y[301],z[301];
    int flag,t=0;
    scanf("%d%d", &m,&n);
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
    scanf("%d", &flag);
    flag--;
    z[t]=a[flag][0];
    x[t]=1;
    y[t]=1;
    for(int i=1;i<=n;i++)
    {
        if(a[flag][i]==z[t])
        {
            y[t]++;
        }
        else
        {
            t++;
            x[t]=y[t-1]+1;
            y[t]=x[t];
            z[t]=a[flag][i];
        }
    }
    for(int i=0;i<t;i++)
    {
        printf("%d %d %d\n", x[i],y[i],z[i]);
    }
    return 0;
}
