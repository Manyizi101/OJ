/*
#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 1<<29
using namespace std;
int n,l[105][105],d[105],ans;
bool v[105];
char a[10];
void dijkstra()
{
    for(int i=1;i<=n;i++)d[i]=l[1][i];
    memset(v,0,sizeof(v));
    v[1]=1;
    for(int i=1;i<n;i++)
    {
        int index=0;
        int mi=maxn;
        for(int j=1;j<=n;j++)
        {
            if(d[j]<mi&&!v[j])
            {
                mi=d[j];
                index=j;
            }
        }
        if(index)
        {
            v[index]=1;
            if(ans<d[index])ans=d[index];
            for(int k=1;k<=n;k++)
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
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)l[i][j]=maxn;
    }
    for(int i=2;i<=n;i++)
    {
        for(int j=1;j<i;j++)
        {
            scanf("%s",a);
            if(a[0]=='x')continue;
            else
            {
                l[i][j]=0;
                int len=strlen(a);
                for(int k=0;k<len;k++)
                {
                    l[i][j]=l[i][j]*10+(a[k]-'0');
                }
                l[j][i]=l[i][j];
            }
        }
    }
    ans=0;
    dijkstra();
    cout<<ans<<endl;
    return 0;
}
**/


#include <iostream>
#include <cstdio>
#include <cstring>
#define  maxn 1<<29

using namespace std;

int n,l[105][105],d[105],ans;
bool v[105];
char a[10];

void dijkstra()
{
    for(int i=1; i<=n; i++) d[i]=l[1][i];
    memset(v,0,sizeof(v));
    v[1]=1;
    for(int i=1; i<n; i++)
    {
        int index=0;
        int mi=maxn;
        for(int j=1; j<=n; j++)
        {
            if(d[j]<mi&&!v[j])
            {
                mi=d[j];
                index=j;
            }
        }
        if(index)
        {
            v[index]=1;
            if(ans<d[index])    ans=d[index];
            for(int k=1; k<=n; k++)
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
    scanf("%d", &n);
    for(int i=1;i<=n;i++)
    {
        for(int j=1; j<=n;j++)  l[i][j]=maxn;
    }
    for(int i=2;i<=n;i++)
    {
        for(int j=1;j<i;j++)
        {
            scanf("%s", a);
            if(a[0]=='x')   continue;
            else
            {
              l[i][j]=0;
              int len=strlen(a);
              for(int k=0; k<len; k++)
              {
                  l[i][j]=l[i][j]*10+(a[k]-'0');
              }
              l[j][i]=l[i][j];
            }
        }
    }
    ans=0;
    dijkstra();
    printf("%d", ans);
    return 0;
}
