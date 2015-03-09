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

#define MAXN 10+10

int t, n, a[MAXN];

void init()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)	scanf("%d", &a[i]);
}

bool cal()
{
	while (1)
	{
		sort(a, a + n);
		if (a[0] == a[n - 1])	return 1;
		int tmp = a[n - 1] - a[0];
		a[0] = a[n - 1] = tmp;
	}
}

int main(int argc, char const *argv[])
{
	scanf("%d", &t);
	while (t--)
	{
		init();
		if (cal())
			cout << a[0] << endl;
	}
	return 0;
}