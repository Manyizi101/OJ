#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<ctime>
#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<deque>
#include<list>
#include<set>
#include<map>
#include<stack>
#include<queue>
#include<numeric>
#include<iomanip>
#include<bitset>
#include<sstream>
#include<fstream>
#define debug puts("-----")
#define pi (acos(-1.0))
#define eps (1e-8)
#define inf (1<<30)
using namespace std;


typedef double mytype;
const int NV = 105;
const int NE = 10005 * 2;
mytype dis[NV];
int pre[NV], vis[NV], he[NV], ecnt, pcnt;
struct edge
{
    int v, next;
    mytype l;
} E[NE];
void adde(int u, int v, mytype l)
{
    E[++ecnt].v = v;
    E[ecnt].l = l;
    E[ecnt].next = he[u];
    he[u] = ecnt;
}
void init(int n, int s)
{
    ecnt = 0;
    memset(pre, 0, sizeof(pre));
    memset(vis, 0, sizeof(vis));
    memset(he, -1, sizeof(he));
    for (int i = 0; i <= n; i++)
        dis[i] = inf;
    dis[s] = 0;
}
struct point
{
    int u;
    mytype l;
    point(int a, mytype b): u(a), l(b) {}
    bool operator<(const point p) const
    {
        return l > p.l;
    }
};
mytype prim_heap(int n, int s)
{
    priority_queue<point> q;
    q.push(point(s, 0));
    mytype ans = 0;
    pcnt = 0;
    while (!q.empty())
    {
        point p = q.top();
        q.pop();
        int u = p.u;
        if (vis[u])
            continue;
        vis[u] = 1;
        ans += p.l; //==dis[x]
        pcnt++;
        for (int i = he[u]; i != -1; i = E[i].next)
            if (!vis[E[i].v] && E[i].l < dis[E[i].v])
            {
                dis[E[i].v] = E[i].l;
                pre[E[i].v] = u;
                q.push(point(E[i].v, dis[E[i].v]));
            }
    }
    return ans;
}
bool judge(int n)
{
    return pcnt == n;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int len = n * (n - 1) / 2;
        int q[1005], w[1005];
        for (int i = 1; i <= n; i++)
            scanf("%d%d", &q[i], &w[i]);
        init(n, 1);
        int len2 = 0;
        for (int i = 1; i <= n - 1; i++)
            for (int j = i + 1; j <= n; j++)
            {
                double l = hypot(q[j] - q[i], w[j] - w[i]);
                if (l >= 10 && l <= 1000)
                {
                    adde(i, j, l);
                    adde(j, i, l);
                    len2++;
                }
            }
        double ans = prim_heap(n, 1);
        if (!judge(n))
            cout << "oh!" << endl;
        else
            printf("%.1lf\n", ans * 100);
    }
    return 0;
}
