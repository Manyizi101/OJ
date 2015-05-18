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

const int N = 100000;

int t, n;
int ptable[N];
int ans[N];


void init()
{
	scanf("%d", &n);
}

ll lehman(ll n)
{
	ll a, b, c, t, r, m, B = pow(n, 1.0 / 3.0) + 1;
// trial division
	for (ll i = 2; i <= B; i++)
		if (n % i == 0) return i;
	for (ll k = 1; k <= B; k++)
	{
// set m and r
		if (k % 2 == 0) { m = 2; r = 1; }
		else { m = 4; r = (k + n) % m; }
// initialize t and a
		t = 4 * k * n;
		a = sqrt(t); while (a * a < t)a++;
		a += (m + r - a % m) % m;
// try all possible a, test if c is a perfect square
		while (a * a < t + B * B)
		{
			c = a * a - t; b = sqrt(c);
			if (b * b == c) return gcd(a + b, n);
			a += m; // next a
		}
	}
	return 0; // prime
}

int main(int argc, char const *argv[])
{
	scanf("%d", &t);
	prime(ptable);
	while (t--)
	{
		init();
		int x = factor(ptable, n);
		for (int i = 0; i < x; i++)
		{
			cout << ptable[i] << " ";
		}
	}
	return 0;
}