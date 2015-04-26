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
#define ll long long int
const double pi = acos(-1.0);
const double eps = (1e-8);
const int inf = 1 << 31;
using namespace std;

const int MAXN = 10 + 2;

int k, n, m;
int xx, yy;
char a[MAXN][MAXN][MAXN];
int vis[MAXN][MAXN][MAXN];
int ans = 0;
int dir[6][3] = {{ -1, 0, 0}, {1, 0, 0}, {0, -1, 0}, {0, 1, 0}, {0, 0, -1}, {0, 0, 1}};

void init()
{
	memset(vis, 0, sizeof(vis));
	ans = 0;
	scanf("%d%d%d", &k, &n, &m);
	for (int i = 1; i <= k; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			scanf("%s", a[i][j] + 1);
		}
	}
	scanf("%d%d", &xx, &yy);
}

bool judge(int y, int x, int z)
{
	//cout << z << " " << x  << " " << y  << endl;
	//cout << a[z][x][y] << endl;
	if (vis[z][x][y] != 0)	return false;
	if (x <= 0 || y > m || y <= 0 || x > n || z <= 0 || z > k)	return false;
	if (a[z][x][y] == '#')	return false;
	return true;
}

void dfs(int y, int x, int z)
{
	vis[z][x][y] = 1;
	ans++;
	for (int i = 0; i < 6; i++)
	{
		if (judge(y + dir[i][0], x + dir[i][1], z + dir[i][2]))
		{
			dfs( y + dir[i][0], x + dir[i][1], z + dir[i][2]);
		}
	}
}


int main(int argc, char const *argv[])
{
	init();
	dfs(yy, xx, 0);
	cout << ans - 1 << endl;
	return 0;
}