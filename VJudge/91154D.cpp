#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include<iostream>
#include<cmath>
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
using namespace std;
typedef long long LL;
const LL mod = 10000007;
const int N = 105;
const int inf = 1<<30;

int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};

set<int>s;
struct node
{
    int x,y,t,k;
    set<int> s;
    node(int xx,int yy,int tt,int kk,set<int>ss)
    {
        x = xx,y =yy,t = tt,k =kk,s  =ss;
    }
    bool operator < (const node a) const
    {
        return t>a.t;
    }

};
int edx,edy,n,m,time;
char mp[N][N];
int  vis[N][N][10];
bool in(int x,int y)
{
    if(x>=0 && x<n && y>=0 && y<n) return true;
    return false;
}
void bfs(int sx,int sy)
{
    time =  inf;
    vis[sx][sy][0] = 0;
    priority_queue<node> q;
    q.push(node(sx,sy,0,0,s));
    while(!q.empty())
    {
        node now = q.top();
        q.pop();
        int nkey = now.k;
        int tx,ty;
        for(int i = 0; i<4; i++)
        {
            tx = now.x + dx[i];
            ty = now.y + dy[i];

            if(!in(tx,ty)) continue;
            if(mp[tx][ty]=='#')
                continue;

            if(mp[tx][ty]=='.')
            {
                if(vis[tx][ty][nkey]<now.t+1)   continue;
                if(abs(now.x - edx)+abs(now.y - edy)+ 1 + now.t>=time) continue;
                q.push(node(tx,ty,now.t+1,now.k,now.s)),vis[tx][ty][nkey] = now.t+1;
            }
            else if(mp[tx][ty]=='S')
            {
                if(now.s.find(tx*1000+ty)!=now.s.end() && now.t+1<vis[tx][ty][nkey])
                {
                    if(abs(now.x - edx)+abs(now.y - edy)+ 1 + now.t>=time) continue;
                    q.push(node(tx,ty,now.t+1,now.k,now.s)),vis[tx][ty][nkey] = now.t+1 ;
                }
                else
                {
                    if( vis[tx][ty][nkey]>now.t+2)
                    {
                        if(abs(now.x - edx)+abs(now.y - edy)+ 2 + now.t>=time) continue;
                        set<int> t = now.s;
                        t.insert(tx*1000+ty);
                        q.push(node(tx,ty,now.t+2,now.k,t));
                        vis[tx][ty][nkey] =  now.t+2;
                    }
                }
            }
            else if(mp[tx][ty]>='0' && mp[tx][ty]<='9')
            {
                int kk = mp[tx][ty] - '0';
                if(abs(now.x - edx)+abs(now.y - edy)+ 1 + now.t>=time) continue;
                if(kk==now.k+1 && vis[tx][ty][nkey+1]>now.t+1) q.push(node(tx,ty,now.t+1,now.k+1,now.s)),vis[tx][ty][nkey+1] = now.t+1;
                else if(vis[tx][ty][nkey]>now.t+1)q.push(node(tx,ty,now.t+1,now.k,now.s)),vis[tx][ty][nkey] = now.t+1;

            }
            else if(mp[tx][ty] =='T' && now.k>=m) time = min(time,now.t+1);
            else if(mp[tx][ty]=='T'&& now.k<m)
            {
                if(abs(now.x - edx)+abs(now.y - edy)+ 1 + now.t>=time ) continue;
                if(vis[tx][ty][nkey]>now.t+1)
                    q.push(node(tx,ty,now.t+1,now.k,now.s)),vis[tx][ty][nkey] = now.t+1;
            }

        }
    }

}
int main()
{
    int l,r,c,sx,sy;
    while(~scanf("%d%d",&n,&m) && n+m)
    {
        for(int i = 0; i<n; i++)
        {

            scanf("%s",mp[i]);
            for(int j =0; j<n; j++)
            {
                if(mp[i][j]=='K') sx = i,sy = j;
                else if(mp[i][j]=='T') edx = i,edy = j;
                for(int k = 0; k<=9; k++) vis[i][j][k] = inf;
            }
        }
        bfs(sx,sy);
        if(time==inf) puts("impossible");
        else printf("%d\n",time);
    }
    return 0;
}
