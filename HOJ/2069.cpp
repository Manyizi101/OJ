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

const int MAXN = 255;
int n;
int p[5] = {50, 25, 10, 5, 1};
int dp[MAXN][100 + 5], tmp[MAXN][100 + 5];
int ans[MAXN];

int main()
{
    ios::sync_with_stdio(false);
    memset(dp, 0, sizeof(dp));
    memset(tmp, 0, sizeof(tmp));
    memset(ans, 0, sizeof(ans));
    dp[0][0] = 1;
    for (int i = 0; i < 5; i++)
    {
        for (int k = 0; k <= 250; k++)
        {
            for (int j = 0; k + j * p[i] <= 250; j++)
            {
                for (int t = 0; t + j <= 100; t++)
                {
                    tmp[k + j * p[i]][t + j] += dp[k][t];
                }
            }
        }
        for (int j = 0; j <= 250; j++)
        {
            for (int k = 0; k <= 100; k++)
            {
                dp[j][k] = tmp[j][k];
                tmp[j][k] = 0;
            }
        }
    }
    for (int i = 0; i <= 250; i++)
    {
        for (int j = 0; j <= 100; j++)
        {
            ans[i] += dp[i][j];
        }
    }
    while (cin >> n)
    {
        cout << ans[n] << endl;
    }
    return 0;
}