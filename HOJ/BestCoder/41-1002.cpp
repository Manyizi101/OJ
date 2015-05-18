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

const int MAXN = 20000 + 10;

int t, n;
string a[MAXN];
int ans, sum;

int gcd(int a, int b)
{
	return b == 0 ? a : gcd(b, a % b);
}

void init()
{
	ans = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (a[i].compare(a[j]) == 0)
			{
				continue;
			}
			if ((a[i].length() + a[j].length()) % 2 == 0)	ans++;
		}
	}
	sum = n * (n - 1) / 2;
}

int main(int argc, char const *argv[])
{
	scanf("%d", &t);
	while (t--)
	{
		init();
		if (sum != ans)
			cout << (sum - ans) / gcd(sum, ans) << '/' << sum / gcd(sum, ans) << endl;
		else
			cout << "0/1" << endl;
	}
	return 0;
}