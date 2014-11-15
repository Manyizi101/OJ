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

#define MAXN 250+10
#define MAXM 70+10

int vis[MAXN][MAXM][3];
int dp[MAXN][MAXM];
int t[MAXN];
int d1[MAXM],d2[MAXM];
int n,T,m1,m2;
int ca=1;

void init()
{
    scanf("%d",&T);
    for(int i=1; i<n; i++)
        scanf("%d",&t[i]);
    scanf("%d",&m1);
    for(int i=1; i<=m1; i++)
        scanf("%d",&d1[i]);
    scanf("%d",&m2);
    for(int i=1; i<=m2; i++)
        scanf("%d",&d2[i]);
    memset(vis,0,sizeof vis);
}

int main(int argc, char const *argv[])
{
    while(~scanf("%d",&n),n)
    {
        init();
        for(int i=1; i<=m1; i++)
        {
            vis[d1[i]][1][0]=1;
            int temp=d1[i];
            for(int j=1; j<n; j++)
            {
                temp+=t[j];
                if(temp<=T)
                    vis[temp][j+1][0]=1;
                else
                    break;
            }
        }
        for(int i=1; i<=m2; i++)
        {
            vis[d2[i]][n][1]=1;
            int temp=d2[i];
            for(int j=n-1; j>=1; j--)
            {
                temp+=t[j];
                if(temp<=T)
                    vis[temp][j][1]=1;
                else
                    break;
            }
        }
        for(int i=1; i<n; i++) dp[T][i]=inf;
        dp[T][n]=0;

        for(int i=T-1; i>=0; i--)
        {
            for(int j=1; j<=n; j++)
            {
                dp[i][j]=dp[i+1][j]+1;
                if(j<n&&vis[i][j][0]&&i+t[j]<=T)
                    dp[i][j]=min(dp[i][j],dp[i+t[j]][j+1]);
                if(j>1&&vis[i][j][1]&&i+t[j-1]<=T)
                    dp[i][j]=min(dp[i][j],dp[i+t[j-1]][j-1]);
            }
        }

        printf("Case Number %d: ",ca++);
        if(dp[0][1]>=inf)
            printf("impossible\n");
        else
            printf("%d\n",dp[0][1]);
    }
    return 0;
}
