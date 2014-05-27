/*
#include  <cstdio>
#include  <cstring>
#define maxn 1<<30
using namespace std;

int n,l[105][105],d[105],ans,num;
bool v[105];
char a[10];

void dijkstra()
{
    for(int i=1;i<=n;i++)   d[i]=l[1][i];
    memset(v,0,sizeof(v));
    v[1]=1;
    for(int i=1; i<n; i++)
    {
        int index = 0;
        int mi = maxn;
        for(int j=1; j<=n; j++)
        {
            if(d[j]<mi&&!v[j])
            {
                mi=d[j];
                index=d[j];
            }
        }
        if(index)
        {
            v[index]=1;
            if(ans<d[index])    ans=d[index];
            for(int k=1; k<=n;k++)
            {
                if(!v[k]&&d[k]>d[index]+l[index][k])
                {
                    d[k]=d[index]+l[index][k];
                }
            }
        }
    }
}

int main()
{
    while(scanf("%d", &n)==1)
    {
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)   l[i][j]=maxn;
        for(int i=1;i<=n;i++)
        {
            scanf("%d", &num);
            for(int j=1;j<=num;j++)
            {
                scanf("%d", &l[i][j]);
            }
        }
    dijkstra();
    }
    return 0;
}
**/

/*
#include  <cstdio>
#include  <cstring>
#include  <iostream>
#define INF 1<<30
using namespace std;

int d[105],w[105][105];
bool v[105];
int n;

void dijkstra()
{
    memset(v,0,sizeof(v));
    for(int i=0;i<n;i++)    d[i]= i==0?0:INF;
    for(int i=0;i<n;i++)
    {
        int x,m = INF;
        for(int y=0; y<n;y++)   if(!v[y]&&d[y]<=m)  m=d[x=y];
        v[x]=1;
        for(int y=0;y<n;y++)    d[y]<d[x]+w[x][y]?d[y]=d[x]:d[y]=d[x]+w[x][y];
    }
}

int main()
{
    while(scanf("%d", &n)==1)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(i==j)    continue;
                scanf("%d", &w[i][j]);
            }
        }

    }
}
**/




#include <cstdio>
#include <cstring>
#include <iostream>
#define INF  1<<29

using namespace std;

int dist[102][102];
bool v[102];
int n,num;

void floyd()
{
    int i,j,k;
    for(k=1; k<=n; k++)
        for(i=1; i<=n; i++)
            for(j=1; j<=n; j++)
                if(dist[i][k]+dist[k][j]<dist[i][j])
                    dist[i][j]=dist[i][k]+dist[k][j];
}


int main()
{
    while(scanf("%d", &n)==1)
    {
        for(int i=1; i<=n; i++)
            for(int j=1; j<=n; j++)   dist[i][j]=INF;
        for(int i=1; i<=n; i++)
        {
            scanf("%d", &num);
            for(int j=1; j<=num; j++)
            {
                scanf("%d", &dist[i][j]);
            }
        }
        floyd();
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=n; j++)
            {
                if(dist[i][j]==INF)
                {
                    if(i!=j)    printf("disjoint\n");
                }
                else
                {
                    printf("from %d to %d=>%d:",i,j,dist[i][j]);
                    printf("%d,", i);
                    printf("%d\n", j);
                }
            }
        }
    }
    return 0;
}
