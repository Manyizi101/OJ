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
#define debug puts("-----")
#define pi (acos(-1.0))
#define eps (1e-8)
#define inf (1<<28)
#define ll long long int
using namespace std;
int gcd(int a,int b)
{
    if(b==0 ) return a;
    return gcd(b,a%b);
}
vector<int> g[30];
bool vis[30];
int n,m,cnt;
void dfs(int cur,int x)
{
    if(cur==n)
    {
        for(int i=0; i<g[x].size(); i++)
        {
            if(!vis[g[x][i]]) cnt++,cnt%=m;
        }
        return ;
    }

    else
    {
        for(int i=1; i<=n; i++)
        {
            if(!vis[g[x][i]])
            {
                vis[g[x][i]]=1;
                dfs(cur+1,g[x][i]);
                vis[g[x][i]]=0;
            }
        }
    }
    return;
}
int main()
{
    for(int i=1; i<=28; i++)
    {
        for(int j=1; j<=28; j++)
        {
            if(i!=j && gcd(i,j)==1)
                g[i].push_back(j);
        }
    }
    int t;
    scanf("%d",&t);
    while(t--)
    {
        cnt=0;
        scanf("%d%d",&n,&m);
        memset(vis,0,sizeof(vis));
        dfs(1,1);
        cout<<cnt%m<<endl;
    }

}
