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

const int MAXN = 100 + 10;
int n, m, k;
int w[MAXN][MAXN], dp[MAXN][MAXN][MAXN];
int ans = 0;

int main()
{
    while (~scanf("%d%d%d", &n, &m, &k))
    {
        ans = 0;
        memset(dp, 0, sizeof(dp));
        memset(w, 0, sizeof(w));
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                scanf("%d", &w[i][j]);
            }
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                for (int v = k; v >= 0; v--)
                {
                    dp[i][j][v] = max(dp[i - 1][j][v], dp[i][j - 1][v]);
                    if (v >= w[i][j])
                    {
                        dp[i][j][v] = max(dp[i][j][v], dp[i - 1][j][v - w[i][j]] + w[i][j]);
                        dp[i][j][v] = max(dp[i][j][v], dp[i][j - 1][v - w[i][j]] + w[i][j]);
                    }
                }
            }
        }
        cout << dp[n][m][k] << endl;
    }
    return 0;
}