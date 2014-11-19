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

#define MAXN 100+10

int dp[MAXN][MAXN],road[MAXN][MAXN];
int dir[4][2]= {{-1,0},{0,1},{1,0},{0,-1}};
int t,r,c;
string name;
int ans=0;

void init()
{
    memset(dp,0,sizeof(dp));
    cin>>name;
    scanf("%d%d", &r, &c);
    for(int i=1; i<=r; i++)
    {
        for(int j=1; j<=c; j++)
        {
            scanf("%d", &road[i][j]);
        }
    }
    ans=0;
}

bool ok(int i, int j)
{
    return !(i<1||i>r||j<1||j>c);
}

int dfs(int row,int column)
{
    if(dp[row][column])
        return dp[row][column];
    int rec=0;
    for(int i=0; i<4; i++)
    {
        int tempi=row+dir[i][0],tempj=column+dir[i][1];
        if(ok(tempi,tempj)&&road[tempi][tempj]<road[row][column])
            rec=max(dfs(tempi,tempj),rec);
    }
    dp[row][column]=rec+1;
    return dp[row][column];
}

int main(int argc, char const *argv[])
{
    scanf("%d", &t);
    while(t--)
    {
        init();
        for(int i=1; i<=r; i++)
        {
            for(int j=1; j<=c; j++)
            {
                if(dp[i][j]==0)
                {
                    ans=max(ans,dfs(i,j));
                }
                else
                    ans=max(ans,dp[i][j]);
            }
        }
        cout<<name;
        printf(": %d\n", ans);
    }
    return 0;
}
