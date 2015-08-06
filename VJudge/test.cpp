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
int t, n, m;
int vis[110000];
int ans [100100];
ll sum = 0;
ll ed ;
int cur , pos;

int dfs(int st)
{
    if (cur == ed)
    {
        printf("%d", pos);
        for (int i = 0; i < pos; i++)
            printf(" %d", ans[i]);
        printf("\n");
        return 1;
    }
    for (int i = st; i >= 1; --i)
    {
        if (!vis[i] && cur + i <= ed)
        {
            vis[i] = 1;
            ans[pos] = i;
            pos++;
            cur += i;
            if (dfs(i - 1))
                return 1;
            cur -= i;
            pos--;
            vis[i] = 0;
        }
    }
    return 0;
}

int main()
{
    freopen("A.in", "r", stdin);
    freopen("A.out", "w", stdout);
    int t;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d%d", &n, &m);
        memset(vis, 0, sizeof(vis));
        sum = (n + 1) * n / 2;
        if (sum % m != 0 || sum / m < n)
        {
            printf("NO\n");
            continue;
        }
        printf("YES\n");
        ed = sum / m;
        for (int i = 0; i < m; i++)
        {
            cur = pos = 0;
            dfs(n);
        }
    }
    return 0;
}
