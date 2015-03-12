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
#define ll long long int
using namespace std;

#define MAXN 1500+10

int n, m;
int a[MAXN][MAXN];
ll dp[MAXN][MAXN], min_dp[MAXN][MAXN], max_dp[MAXN][MAXN];
const ll INF = -(1LL << 60);

void init()
{
	memset(dp, 200, sizeof(dp));
	memset(min_dp, 200, sizeof(min_dp));
	memset(max_dp, 200, sizeof(max_dp));
	memset(min_dp[0], 0, sizeof(min_dp[0]));
	memset(max_dp[0], 0, sizeof(max_dp[0]));
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= m; ++j)
		{
			scanf("%d", &a[i][j]);
		}
	}
}

int main(int argc, char const *argv[])
{
	init();
	for (int i = 1; i <= n; ++i)
	{
		ll tmp = 0;
		for (int j = 1; j <= m; ++j)
		{
			tmp += a[i][j];
			if (i & 1)
			{
				dp[i][j] = tmp + min_dp[i - 1][j - 1];
			}
			else
			{
				dp[i][j] = tmp + max_dp[i - 1][j + 1];
			}
		}
		for (int j = m; j >= 1; --j)
		{
			max_dp[i][j] = max(dp[i][j], max_dp[i][j + 1]);
		}
		for (int j = 1; j <= m; ++j)
		{
			min_dp[i][j] = max(dp[i][j], min_dp[i][j - 1]);
		}
	}
	ll ans = INF;
	for (int i = 1; i <= m; ++i)
	{
		ans = max(ans, dp[n][i]);
	}
	cout << ans;
	return 0;
}