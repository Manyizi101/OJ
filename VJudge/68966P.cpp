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

const int maxn  = 110;
int a[maxn][maxn], dp[maxn][maxn];
struct node
{
    int x, y;
    int val;
} ans[maxn*maxn];

bool cmp(node a, node b)
{
    return a.val < b.val;
}

int main()
{
    int n, k;
    while (~scanf("%d%d", &n, &k))
    {
        if (n == -1 && k == -1)    break;
        int cnt = 0;
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                scanf("%d", &a[i][j]);
                if (i != 0 || j != 0)
                {
                    ans[cnt].x = i;
                    ans[cnt].y = j;
                    ans[cnt++].val = a[i][j];
                }
            }
        }
        sort(ans, ans + cnt, cmp);
        memset(dp, -1, sizeof(dp));
        dp[0][0] = a[0][0];
        int anss = dp[0][0];
        for (int i = 0; i < cnt; ++i)
        {
            int x = ans[i].x;
            int y = ans[i].y;
            for (int xx = max(0, x - k); xx <= min(n - 1, x + k); ++xx)
            {
                if (a[xx][y] >= a[x][y])   continue;
                if (dp[xx][y] == -1)   continue;
                dp[x][y] = max(dp[x][y], dp[xx][y] + a[x][y]);
            }
            for (int yy = max(0, y - k); yy <= min(n - 1, y + k); ++yy)
            {
                if (a[x][yy] >= a[x][y])   continue;
                if (dp[x][yy] == -1)   continue;
                dp[x][y] = max(dp[x][y], dp[x][yy] + a[x][y]);
            }
            anss = max(anss, dp[x][y]);
        }
        printf("%d\n", anss);
    }
    return 0;
}