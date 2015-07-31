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

const int MAXN = 100000 + 10;

int n, a[MAXN], b[MAXN];
int ans[MAXN];
int vis[MAXN];

int main()
{
    while (~scanf("%d", &n))
    {
        memset(vis, 0, sizeof(vis));
        for (int i = 1; i <= n; ++i)
        {
            scanf("%d", &a[i]);
            b[i] = i;
        }
        for (int i = 1; i <= n; ++i)
        {
            if (vis[i] == 0)
            {
                int len = 0;
                int cnt = a[b[i]];
                ans[len++] = b[i];
                vis[i] = 1;
                while (cnt != b[i])
                {
                    ans[len++] = cnt;
                    vis[cnt] = 1;
                    cnt = a[cnt];
                }
                printf("(");
                printf("%d", ans[0]);
                for (int x = 1; x < len; ++x)
                {
                    printf(" %d", ans[x]);
                }
                printf(")");
            }
        }
        printf("\n");
    }
    return 0;
}