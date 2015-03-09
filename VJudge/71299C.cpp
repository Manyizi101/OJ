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

ll t = 32, n;
int ans;
int up, down;
int tmp = 0;

void init()
{
	ans = 0;
	up = down = 0;
	scanf("%d", &n);
}

double lnchoose(int n, int m)
{
	if (m > n)
	{
		return 0;
	}
	if (m < n / 2.0)
	{
		m = n - m;
	}
	double s1 = 0;
	for (int i = m + 1; i <= n; i++)
	{
		s1 += log((double)i);
	}
	double s2 = 0;
	int ub = n - m;
	for (int i = 2; i <= ub; i++)
	{
		s2 += log((double)i);
	}
	return s1 - s2;
}

double choose(int n, int m)
{
	if (m > n)
	{
		return 0;
	}
	return exp(lnchoose(n, m));
}

int upcal(int n)
{
	up = 0;
	for (int i = 1; i <= n; i++)
	{
		tmp = i;
		while (tmp % 3 == 0 && tmp != 0)
		{
			up++;
			tmp /= 3;
		}
	}
	return up;
}

int downcal(int k)
{
	down = 0;
	for (int i = 1; i <= k; i++)
	{
		tmp = i;
		while (tmp % 3 == 0 && tmp != 0)
		{
			down++;
			tmp /= 3;
		}
	}
	for (int i = 1; i <= n - k; i++)
	{
		tmp = i;
		while (tmp % 3 == 0 && tmp != 0)
		{
			down++;
			tmp /= 3;
		}
	}
	return down;
}

int cal(int x)
{
	int tmp = 0;
	while (x != 0)
	{
		tmp += x % 10;
		x /= 10;
	}
	if (tmp >= 10)	return tmp = cal(tmp);
	return tmp;
}

int main(int argc, char const *argv[])
{
	freopen("71299C.in", "r", stdin);
	freopen("71299C.out", "w", stdout);
	scanf("%d", &t);
	while (t--)
	{
		init();
		/*
		int upsum = upcal(n);
		for (int i = 1; i <= n; i++)
		{
			if (upsum - downcal(i) >= 2)
			{
				ans++;
			}
		}
		**/
		for (int i = 1; i <= 20; i++)
		{
			for (int j = 1; j <= i; j++)
			{
				if ((int)choose(i, j) % 3 == 0)
					cout << choose(i, j) << " ";
			}
			cout << endl;
		}
		//cout << "n= " << n << " sum=　" << cal(n) << " ans= " << ans << " sum=　" << cal(ans)<< endl;
		cout << ans << endl;
	}
	return 0;
}