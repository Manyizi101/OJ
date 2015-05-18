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

const int MAXN = 100 + 10;

int n, k;
int a[MAXN];
int ans = 0;
int vis[MAXN];

void init()
{
	memset(vis, 0, sizeof(vis));
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}
	sort(a, a + n);
}

int main(int argc, char const *argv[])
{
	init();
	if (n == 1)
	{
		cout << k - a[0];
		return 0;
	}
	if(a[0]==a[n-1]&&a[0]==k)
	{
		cout<<0;
		return 0;
	}
	while (a[0] != a[n - 1] || ans == 0)
	{
		ans++;
		memset(vis, 0, sizeof(vis));
		for (int i = 0; i < n; i++)
		{
			if (!vis[a[i]])
			{
				vis[a[i]] = 1;
				a[i] = min(a[i] + 1, k);
			}
		}
		sort(a, a + n);
	}
	cout << ans;
	return 0;
}