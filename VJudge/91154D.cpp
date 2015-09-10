#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include<iostream>
#include<cmath>
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
using namespace std;
typedef long long LL;
const LL INF = 100000000000000;
const LL mod = 10000007;
const int N = 1005;
const int inf = 1000000000;
int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};

struct node
{
    int x,y,t,k;
    node(int xx,int yy,int tt,int kk) : x(xx),y(yy),t(tt),k(kk) {}
    bool operator < (const node a) const
    {
        return t<a.t;
    }
};

int edx,edy,n,m,time;
char mp[N][N];
bool vis[N][N];
bool in(int x,int y)
{
    if(x>=0 && x<n && y>=0 && y<n) return true;
    return false;
}
void bfs(int sx,int sy)
{
    memset(vis,0,sizeof(vis));
    time =  inf;
    vis[sx][sy] = 1;
    priority_queue<node> q;
    q.push(node(sx,sy,0,0));
    while(!q.empty())
    {
        node now = q.top();
        q.pop();
        int tx,ty;
        for(int i = 0; i<4; i++)
        {
            tx = now.x + dx[i];
            ty = now.y + dy[i];
            if(mp[tx][ty]=='#'|| (vis[tx][ty]&&(tx!=edx && ty!=edy) )) continue;
            if(!in(tx,ty)) continue;
            if(mp[tx][ty]=='.')
            {
                if(abs(now.x - edx)+abs(now.y - edy)+ 1 + now.t<time)
                    q.push(node(tx,ty,now.t+1,now.k)),vis[tx][ty] = 1;
            }
            else if(mp[tx][ty]=='S')
            {
                if(abs(now.x - edx)+abs(now.y - edy)+ 2 + now.t<time)
                    q.push(node(tx,ty,now.t+2,now.k)),vis[tx][ty] = 1;
            }
            else if(mp[tx][ty]>='0' && mp[tx][ty]<='9')
            {
                int kk = mp[tx][ty] - '0';
                if(abs(now.x - edx)+abs(now.y - edy)+ 1 + now.t<time)
                {
                    if(kk==now.k+1) q.push(node(tx,ty,now.t+1,now.k+1)),vis[tx][ty] = 1;
                    else q.push(node(tx,ty,now.t+1,now.k)),vis[tx][ty] = 1;
                }

            }
            else if(mp[tx][ty] =='T' && now.k>=m)
                time = min(time,now.t+1);
            else if(mp[tx][ty]=='T'&& now.k<m)
            {
                if(abs(now.x - edx)+abs(now.y - edy)+ 1 + now.t<time)
                    q.push(node(tx,ty,now.t+1,now.k)),vis[tx][ty] = 1;
            }

        }
    }

}

int main()
{
    int n,m,l,r,c,sx,sy;
    while(~scanf("%d%d",&n,&m) && n+m)
    {
        for(int i = 0;i<n;i++)
        {
            scanf("%s",mp[i]);
        }
        for(int i =0;i<n;i++)
        {
            for(int j =0;j<n;j++)
            {
                if(mp[i][j]=='K') sx = i,sy = j;
                else if(mp[i][j]=='T') edx = i,edy = j;
            }
        }
        bfs(sx,sy);
        if(time==inf) puts("impossible");
        else printf("%d\n",time);
    }
    return 0;
}
