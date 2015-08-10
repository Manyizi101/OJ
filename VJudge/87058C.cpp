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

typedef long long int ll;
const double pi = acos(-1.0);
const double eps = 1e-8;
const int inf = 0x3f3f3f3f;
const ll INF = 0x3f3f3f3f3f3f3f3fLL;
using namespace std;

const int maxn = 105;

int g[maxn][maxn];
int vis[25][25][25];
int n,m,k,ans;
int dir[4][2]= {1,0,-1,0,0,1,0,-1};

struct node
{
    int x,y;
    int step;
    int k;
};

void bfs()
{
    node u;
    u.x=1;
    u.y=1;
    u.step=0;
    u.k=k;
    queue<node> q;
    vis[1][1][k]=1;
    q.push(u);

    while(!q.empty())
    {
        u=q.front();
        q.pop();
        if(u.x==n&&u.y==m)
        {
            ans=u.step;
            return;
        }

        node v;
        if(u.k>=0)
        {
            for(int i=0; i<4; i++)
            {
                v.x=u.x+dir[i][0];
                v.y=u.y+dir[i][1];
                v.step=u.step+1;

                if(g[v.x][v.y]) v.k=u.k-1;
                else v.k=k;
                if(v.x>=1&&v.x<=n&&v.y>=1&&v.y<=m&&!vis[v.x][v.y][v.k])
                {
                    if(v.k>=0)
                    {
                        vis[v.x][v.y][v.k]=1;
                        q.push(v);
                    }
                }
            }
        }
    }
}

int main()
{
    int T;
    scanf("%d",&T);
    for(int t=1; t<=T; t++)
    {
        memset(g,0,sizeof(g));
        memset(vis,0,sizeof(vis));
        cin>>n>>m>>k;

        for(int i=1; i<=n; i++)
            for(int j=1; j<=m; j++)
                cin>>g[i][j];

        ans=-1;
        bfs();
        cout<<ans<<"\n";
    }
    return 0;
}
