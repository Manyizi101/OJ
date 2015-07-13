#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
#include <iostream>
#include <algorithm>
#define debug puts("-----")

typedef long long int ll;
const double pi = acos(-1.0);
const double eps = 1e-8;
const int inf = 0x3f3f3f3f;
const ll INF = 0x3f3f3f3f3f3f3f3fLL;
using namespace std;

const int MAXN = 500 + 10;

int t;
int n, m, g;
int a[MAXN][MAXN];
int vis[MAXN][MAXN];
int flag = 0;


int main()
{
    scanf("%d", &t);
    while (t--)
    {
        int ans = 0;
        memset(vis, 0, sizeof(vis));
        scanf("%d%d", &n, &m);
        scanf("%d", &g);
        int tx, ty;
        for (int i = 0; i < g; i++)
        {
            scanf("%d%d", &tx, &ty);
            a[tx][ty] = 1;
            for (int x = 1; x <= n; x++)   vis[x][ty]++;
            for (int y = 1; y <= m; y++)   vis[tx][y]++;
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (vis[i][j] >= 2)    ans++;
            }
        }
        printf("Case #%d:\n", ++flag);
        cout << ans  << endl;
    }
    return 0;
}