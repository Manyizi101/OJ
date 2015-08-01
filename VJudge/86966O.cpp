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

//区间DP

const int maxn = 2000 + 10;
int n, a[maxn], dp[maxn][maxn] = {0};

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &a[i]);
    }
    for (int i = 1; i <= n; ++i)
    {
        dp[i][i] = a[i] * n;
    }
    for (int len = 1; len < n; ++len)
    {
        for (int i = 1; i <= n; ++i)
        {
            int j = i + len;
            dp[i][j] = max(dp[i + 1][j] + a[i] * (n - len), dp[i][j - 1] + a[j] * (n - len));
        }
    }
    printf("%d\n", dp[1][n]);
    return 0;
}