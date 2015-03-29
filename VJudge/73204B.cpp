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
const int inf = 1 << 20;
using namespace std;

char x;
int a1;
ll ans;
ll a[4];

void init()
{
	memset(a, 0, sizeof(a));
	a1 = 0;
	for (int i = 0; i < 4; i++)
	{
		cin >> a[i];
	}
	for (int i = 0; i < 3; i++)
	{
		cin >> x;
		if (x == '*')	a1++;
	}
	sort(a, a + 4);
}

int main(int argc, char const * argv[])
{
	init();
	if (a1 == 3)
	{
		ans = 1;
		for (int i = 0; i < 4; i++)
		{
			ans *= a[i];
		}
	}
	else if (a1 == 2)
	{
		ans = inf;
		ll tmp;
		for (int i = 0; i < 4; i++)
		{
			tmp = a[(i + 0) % 4] * a[(i + 1) % 4] * a[(i + 2) % 4] + a[(i + 3) % 4];
		}
		ans=min(ans,tmp);
		for (int i = 0; i < 4; i++)
		{
			tmp = a[(i + 0) % 4] * a[(i + 1) % 4] + a[(i + 2) % 4] * a[(i + 3) % 4];
		}
		ans=min(ans,tmp);
		tmp = a[0]*a[2]+a[1]*a[3];
		ans=min(ans,tmp);
		tmp = a[1]*a[3]+a[0]*a[2];
		ans=min(ans,tmp);
	}
	else if(a1==1)
	{
		ans = inf;
		ll tmp;
		for (int i = 0; i < 4; i++)
		{
			tmp = a[(i + 0) % 4] * a[(i + 1) % 4] + a[(i + 2) % 4] + a[(i + 3) % 4];
		}
		ans=min(ans,tmp);
		tmp = a[0]*a[2]+a[1]+a[3];
		ans=min(ans,tmp);
		tmp = a[1]*a[3]+a[0]+a[2];
		ans=min(ans,tmp);
	}
	else
	{
		ans = 0;
		for (int i = 0; i < 4; i++)
		{
			ans += a[i];
		}
	}
	cout << ans;
	return 0;
}