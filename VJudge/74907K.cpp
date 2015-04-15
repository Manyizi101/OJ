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

const int MAXN = 50 + 10;

int a[MAXN], b[MAXN];
int n, x;
int t = 1, ans = 0;

void init()
{
	scanf("%d%d", &n, &x);
	for (int i = 0; i < n; i++)
	{
		scanf("%d%d", &a[i], &b[i]);
	}
}

int main(int argc, char const *argv[])
{
	init();
	for (int i = 0; i < n; i++)
	{
		while (t + x <= a[i])
		{
			t += x;
		}
		if (t <= b[i])
		{
			ans += b[i] - t + 1;
			t = b[i] + 1;
		}
	}
	printf("%d\n", ans);
	return 0;
}