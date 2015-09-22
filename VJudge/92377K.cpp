#include<cstdio>
#include<cstring>
#include<algorithm>
#include<set>
#include<map>
#include<vector>
#include<iostream>
#include<queue>
using namespace std;

typedef long long int ll;
const int INF  = 0x3f3f3f3f;
const int MAXN = 33;
struct qnode
{
    int v;
    int c;
    qnode(int v=0,int c=0):v(v),c(c) {}
    bool operator<(const qnode &r) const
    {
        return c>r.c;
    }
};
struct Edge
{
    int v;
    ll cost;
    Edge(int v=0,int cost=0):v(v),cost(cost) {}
};
vector<Edge> E[MAXN];
bool vis[MAXN];
ll dist[MAXN];

int xx,yy;

void Dijkstra(int n,int start)
{
    memset(vis,false,sizeof(vis));
    for(int i=1; i<=n; i++)   dist[i] = INF;
    priority_queue<qnode> que;
    while(!que.empty()) que.pop();
    dist[start] = 0;
    que.push(qnode(start,0));
    qnode tmp;
    while(!que.empty())
    {
        tmp = que.top();
        que.pop();
        int u = tmp.v;
        if(vis[u])  continue;
        vis[u] = true;
        for(int i=0; i<E[u].size(); i++)
        {
            int v = E[u][i].v;
            ll cost = E[u][i].cost;
            if(!vis[v]&&dist[u] + cost < dist[v])
            {
                dist[v] = dist[u] + cost;
                que.push(qnode(v,dist[v]));
            }

        }
    }
}
void addedge(int u,int v,int w)
{
    E[u].push_back(Edge(v,w));
}
int bian[1010];
ll zhi[1010];
int main()
{

    int m,n;
    while(scanf("%d%d",&n,&m)&&n+m)
    {
        for(int i=0; i<m; i++)
        {
            int x,y;
            ll z;
            scanf("%d%d%I64d",&x,&y,&z);
            bian[i] = x*1000+y;
            zhi[i] = z;
        }
        ll Max = -1;
        for(int i=0; i<m; i++)
        {
            for(int j=1; j<=n; j++)
                E[j].clear();

            for(int j=0; j<m; j++)
            {
                if(j!=i)
                {
                    //  cout<<xx<<" "<<yy<<endl;
                    xx = bian[j]/1000;
                    yy = bian[j]%1000;
                    addedge(xx,yy,zhi[j]);
                    addedge(yy,xx,zhi[j]);
                }
            }
            Dijkstra(n,1);
            Max = max(Max,dist[n]);
        }
        if(Max>=INF)
            printf("Inf\n");
        else
            printf("%I64d\n",Max);

    }
    return 0;
}
