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

int n, m, k, sum = 0;
int x, ans = 0;;

int fastpow(int a, int b, int k) {
	if (b == 0) return 1 % k;
	int tmp = fastpow(a, b >> 1, k);
	tmp = tmp * tmp % k;
	if (b & 1) tmp = (ll) tmp * a % k;
	return tmp;
}

void init()
{
	scanf("%d%d%d", &n, &m, &k);
}

int main(int argc, char const *argv[])
{
	init();
	while (n--)
	{
		scanf("%d", &x);
		if (!fastpow(x,m,k))	ans++;
	}
	cout << ans;
}