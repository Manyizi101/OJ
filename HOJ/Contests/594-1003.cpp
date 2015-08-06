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

const int maxn = 1e5 + 5;

int t, n, m;
int vis[maxn];

void dfs(ll xx, int m)
{
    while (m--)
    {
        ll ans[maxn];
        int num = 0;
        ll rnt = xx;
        while (rnt > 0)
        {
            for (int i = n; i > n - m; --i)
            {
                if (vis[i] == 0 && rnt >= i)
                {
                    ans[num++] = i;
                    vis[i] = 1;
                    rnt -= i;
                    break;
                }
            }
            for (int i = n - m; i >= 1; --i)
            {
                if (vis[i] == 0 && rnt >= i)
                {
                    ans[num++] = i;
                    vis[i] = 1;
                    rnt -= i;
                }
            }
        }
        printf("%d", num);
        for (int i = 0; i < num; ++i)
        {
            printf(" %I64d", ans[i]);
        }
        printf("\n");
    }
}

int main()
{
    freopen("A.in", "r", stdin);
    freopen("A.out", "w", stdout);
    scanf("%d", &t);
    while (t--)
    {
        memset(vis, 0, sizeof(vis));
        scanf("%d%d", &n, &m);
        ll  sum = n * (n + 1) / 2;
        if (sum % m != 0 || sum / m < n)    printf("NO\n");
        else
        {
            printf("YES\n");
            dfs(sum / m, m);
        }
    }
    return 0;
}