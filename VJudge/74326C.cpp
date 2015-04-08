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

const int MAXN = 10000 + 10;
const ll MOD = 1000000007;
ll n, ans;

void init()
{
	ans = 0;
	scanf("%I64d", &n);
}

ll exgcd(ll a, ll &x, ll b, ll &y)
{
	if (b == 0) {
		x = 1; y = 0;
		return a;
	}
	ll d = exgcd(b, x, a % b, y);
	ll t = x;
	x = y; y = t - a / b * x;
	return d;
}

ll quickpow(ll a, ll p)
{
	ll ans = 1;
	while (p)
	{
		if (p & 1) ans = (ans * a) % MOD;
		p = p >> 1;
		a = (a * a) % MOD;
	}
	return ans;
}

ll lucas(ll n, ll m)
{
	ll res = 1;
	for (ll i = 1; i <= m; i++)
	{
		res = (res * (n - i + 1) ) % MOD;
		res = (res * quickpow(i, MOD - 2)) % MOD;
	}
	return res;
}


int main(int argc, char const *argv[])
{
	init();
	ans = lucas(2 * n - 1, n);
	ans = (ans * 2 - n) % MOD;
	cout << ans;
	return 0;
}

