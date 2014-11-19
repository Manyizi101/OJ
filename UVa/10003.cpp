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

#define MAXN 1000+10
#define MAXM 50+10

int a[MAXM],dp[MAXN][MAXN];
int n,m;

void init()
{
    memset(a,0,sizeof(a));
    scanf("%d", &m);
    a[0]=0,a[m+1]=n;
    for(int i=1; i<=m; i++)
    {
        scanf("%d", &a[i]);
    }
    for(int i=0; i<=m; i++)
    {
        dp[a[i]][a[i+1]]=0;
    }
}

int main(int argc, char const *argv[])
{
    while(~scanf("%d",&n)&&n)
    {
        init();
        for(int l=2; l<=m+1; l++)
        {
            for(int i=0; i<=m-l+1; i++)
            {
                int j=i+l,x=a[i],y=a[j];
                dp[x][y]=inf;
                for(int k=i+1; k<j; k++)
                {
                    dp[x][y]=min(dp[x][y],dp[x][a[k]]+dp[a[k]][y]+y-x);
                }
            }
        }
        printf("The minimum cutting is %d.\n",dp[0][n]);
    }
    return 0;
}
