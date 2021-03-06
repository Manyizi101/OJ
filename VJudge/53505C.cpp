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
#define inf (1<<30)
using namespace std;

typedef int Type;
const int MaxM = 1005;
int pre[MaxM], vis[MaxM];
Type dis[MaxM], g[MaxM][MaxM];

void init(int n, int s)
{
    memset(pre, 0, sizeof(pre));
    memset(vis, 0, sizeof(vis));
    for (int i = 0; i <= n; i++)
        dis[i] = inf;
    dis[s] = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            scanf("%d", &g[i][j]);
}

Type prim(int n)
{
    Type ans = -1;
    for (int i = 1; i <= n; i++)
    {
        int u = 0;
        for (int j = 1; j <= n; j++)
            if (!vis[j] && dis[j] < dis[u])
                u = j;
        vis[u] = 1;
        ans = max(ans, dis[u]);
        for (int j = 1; j <= n; j++)
            if (!vis[j] && g[u][j] < dis[j])
            {
                dis[j] = g[u][j];
                pre[j] = u;
            }
    }
    return ans;
}

bool judge(int n)
{
    int cnt = 0;
    for (int i = 1; i <= n; i++)
        cnt += vis[i];
    return cnt == n;
}

int main(int argc, char const *argv[])
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        scanf("%d", &n);
        init(n, 1);
        printf("%d\n", prim(n));
    }
    return 0;
}
