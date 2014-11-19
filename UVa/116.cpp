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

#define MAXN 10+10
#define MAXM 100+10

int m,n;
int road[MAXN][MAXM],dp[MAXN][MAXM],path[MAXN][MAXM];
int a,b,c,Min;
int ans,id;

void init()
{
    memset(road,0,sizeof(road));
    memset(dp,0,sizeof(dp));
    memset(path,0,sizeof(path));
    for(int i=0; i<n; ++i)
    {
        for(int j=0; j<m; ++j)
        {
            scanf("%d", &road[i][j]);
        }
    }
}

int main(int argc, char const *argv[])
{
    while(~scanf("%d%d", &n,&m))
    {
        init();
        for(int j=m-1; j>=0; --j)
        {
            for(int i=0; i<n; ++i)
            {
                a=dp[(i-1+n)%n][j+1];
                b=dp[i][j+1];
                c=dp[(i+1)%n][j+1];
                Min=min(a,min(b,c));

                dp[i][j]=road[i][j]+Min;
                path[i][j]=inf;
                if(Min==a)
                {
                    path[i][j]=(i-1+n)%n;
                }
                if(Min==b)
                {
                    path[i][j]=min(path[i][j],i);
                }
                if(Min==c)
                {
                    path[i][j]=min(path[i][j],(i+1)%n);
                }
            }
        }

        ans=inf;
        for(int i=0; i<n; ++i)
        {
            if(ans>dp[i][0])
            {
                ans=dp[i][0],id=i;
            }
        }
        printf("%d", id+1);
        id=path[id][0];

        for(int j=1; j<m; ++j)
        {
            printf(" %d", id+1);
            id=path[id][j];
        }

        printf("\n%d\n",ans);
    }
    return 0;
}
