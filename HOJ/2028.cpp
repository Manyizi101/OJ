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

int n;
vector<ll> v;
ll ans;
ll tmp;

ll gcd(ll a, ll b)
{
	return b == 0 ? a : gcd(b, a % b);
}

int main(int argc, char const *argv[])
{
	while (~scanf("%d", &n))
	{
		v.clear();
		cin >> ans;
		for (int i = 1; i < n; i++)
		{
			cin >> tmp;
			v.push_back(tmp);
		}
		for (ll x : v)
		{
			ll c = gcd(ans, x);
			ans = ans / c * x;
		}
		cout << ans << endl;
	}
	return 0;
}