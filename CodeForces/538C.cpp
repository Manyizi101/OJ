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

const int MAXN = 100000 + 10;

int n, m;
int d[MAXN], h[MAXN];
int Max[MAXN];
int ans = -1;
int flag;

void init()
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++)
	{
		scanf("%d%d", &d[i], &h[i]);
	}
	flag = 0;
}

int main(int argc, char const *argv[])
{
	init();
	for (int i = 0; i < m - 1; i++)
	{
		if (abs(h[i + 1] - h[i]) > (d[i + 1] - d[i]))
		{
			flag = 1;
			break;
		}
		Max[i] = (d[i + 1] - d[i] - abs(h[i + 1] - h[i])) / 2 + max(h[i + 1], h[i]);
		ans = max(ans, Max[i]);
	}
	if (d[0] != 1)	ans = max(ans, h[0] + 1);
	if (d[m - 1] != n)	ans = max(ans, h[m - 1] + 1);
	if (m == 1)	ans = max(ans, h[0] + max(n - d[0], d[0]));
	flag == 1 ? puts("IMPOSSIBLE") : printf("%d", ans);
	return 0;
}