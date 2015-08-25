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

const int MAXN = 100005;
const int MAXE = 200005;

struct Node
{
    int v,p,d;
    Node(){}
    Node(int v, int p, int d):v(v),p(p),d(d){}
};

struct Edge
{
    int v,n;
    Edge(){}
    Edge(int v, int n):v(v),n(n){}
};

Node Q[2100005];
Edge E[MAXE];
int H[MAXN], cntE;
int head, tail;
ll ans;
int n,k;

void clear()
{
    ans=0;
    cntE=0;
    memset(H,-1,sizeof(H));
}

void addedge(int u,int v)
{
    E[cntE] = Edge(v, H[u]);
    H[u] = cntE++;
}

void bfs()
{
    int cnt = 0;
    head = tail =0;
    for(int i=1;i<=n;++i)
    {
        Q[tail++] = Node(i,0,0);
    }
    while(head!=tail)
    {
        Node x = Q[head++];
        int u =x.v, p=x.p;
        for(int i=H[u];~i;i=E[i].n)
        {
            int v = E[i].v;
            if(v!=p)
            {
                Q[tail++] = Node(v,u,x.d+1);
                ans+=x.d+1;
                ++cnt;
                if(cnt==k)  return;
            }
        }
    }
}

void solve()
{
    int u,v;
    clear();
    scanf("%d%d", &n,&k);
    k*=2;
    for(int i=1;i<n;++i)
    {
        scanf("%d%d", &u,&v);
        addedge(u,v);
        addedge(v,u);
    }
    bfs();
    printf("%I64d\n", ans/2);
}

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        solve();
    }
    return 0;
}
