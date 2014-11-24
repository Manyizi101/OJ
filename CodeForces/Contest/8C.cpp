#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <deque>
#include <list>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <numeric>
#include <iomanip>
#include <bitset>
#include <sstream>
#include <fstream>
#define debug "output for debug\n"
#define pi (acos(-1.0))
#define eps (1e-8)
#define inf 0x3f3f3f3f
#define ll long long int
using namespace std;

#define MAXN 1<<24

int dp[MAXN],pre[MAXN],gra[26][26],x[26],y[26],ans[60];
int n;

int dis(int i, int j)
{
    return (x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]);
}

void init()
{
    int x0,y0;
	scanf("%d%d%d", &x0,&y0,&n);
	for(int i=0;i<n;i++)    scanf("%d%d", &x[i],&y[i]);
	x[n]=x0,y[n]=y0;
	for(int i=0;i<=n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            gra[i][j]=gra[j][i]=dis(i,j);
        }
    }
    memset(dp, -1, sizeof(dp));
    dp[0]=0;
}

int main(int argc, char const *argv[])
{
	init();
	for(int i=0;i<1<<n;i++)
    {
        if(dp[i]!=-1)
        {
            for(int j=0;j<n;j++)
            {
                if(!((1<<j)&i))
                {
                    int t=i|(1<<j),tem=dp[i]+2*gra[j][n];
                    if(dp[t]==-1||dp[t]>tem)
                    {
                        dp[t]=tem;
                        pre[t]=i;
                    }
                    for(int k=0;k<n;k++)
                    {
                        if(!(t&(1<<k)))
                        {
                            int t2=t|(1<<k),tem=dp[i]+gra[n][j]+gra[j][k]+gra[k][n];
                            if(dp[t2]==-1||dp[t2]>tem)
                            {
                                dp[t2]=tem;
                                pre[t2]=i;
                            }
                        }
                    }
                    break;
                }
            }
        }
    }
    int x=(1<<n)-1,pr,tem,a,b,cnt=0;
    printf("%d\n", dp[x]);
    while(x)
    {
        pr=pre[x];
        tem=pr^x;
        a=b=0;
        for(int i=0;i<n;i++)
        {
            if((1<<i)&tem)
            {
                b=a;
                a=i+1;
            }
        }
        ans[cnt++]=0;
        ans[cnt++]=a;
        if(b)
        {
            ans[cnt++]=b;
        }
        x=pr;
    }
    ans[cnt++]=0;
    for(int i=cnt-1;i>=0;i--)
    {
        printf("%d ",ans[i]);
    }
    printf("\n");
	return 0;
}
