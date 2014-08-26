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
#define inf (1<<28)
using namespace std;

#define MAXN 3403
#define MAXW 12881

int n, m;
int w[MAXN], d[MAXN];
int dp[MAXN][MAXW];

void init()
{
    memset(w, 0, sizeof(w));
    memset(d, 0, sizeof(d));
    memset(dp, 0, sizeof(dp));
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> w[i] >> d[i];
    }
}

//不作任何优化的搜索，TLE
/*
int rec(int i, int j)
{
    int res;
    if (i == n)
    {
        res = 0;
    }
    else if (j < w[i])
    {
        res = rec(i + 1, j);
    }
    else
    {
        res = max(rec(i + 1, j), rec(i + 1, j - w[i]) + d[i]);
    }
    return res;
}
**/

//采用记忆化搜索，出现WA，TLE，MLE，然后我一怒之下还交了一发CE= =，不知道错在哪里。
/*
int rec(int i, int j)
{
    if (dp[i][j] >= 0)     return dp[i][j];
    int res;
    if (i == n)
    {
        res = 0;
    }
    else if (j < w[i])
    {
        res = rec(i + 1, j);
    }
    else
    {
        res = max(rec(i + 1, j), rec(i + 1, j - w[i]) + d[i]);
    }
    return dp[i][j] = res;
}
**/

void solve()
{
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = 0; j <= m; j++)
        {
            if (j < w[i])
            {
                dp[i][j] = dp[i + 1][j];
            }
            else
            {
                dp[i][j] = max(dp[i + 1][j], dp[i + 1][j - w[i]] + d[i]);
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    init();
    solve();
    printf("%d\n", dp[0][m]);
    return 0;
}