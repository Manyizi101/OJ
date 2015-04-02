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

int t;
int n, m;
ll a[MAXN];
ll b[MAXN];
ll l, r;

void init()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
	{
		scanf("%lld", &a[i]);
	}
}

ll cal(ll x)
{
	if (x == l)		return b[l] = a[l];
	else if (x == l + 1)	return b[l + 1] = a[l + 1];
	else return b[x] = cal(x - 1) + cal(x - 2) * a[x];

}

int main(int argc, char const *argv[])
{
	scanf("%d", &t);
	while (t--)
	{
		init();
		while (m--)
		{
			scanf("%lld%lld", &l, &r);
			memset(b, 0, sizeof(b));
			printf("%lld\n", cal(r)%1000000007);
		}
	}
	return 0;
}