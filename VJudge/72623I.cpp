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

#define MAXN

int n, ans = 0;
string a[7] = {"Saturday", "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday"};

int PowerMod(int a, int b, int c)
{
	int ans = 1;
	a = a % c;
	while (b > 0) {
		if (b % 2 == 1)
			ans = (ans * a) % c;
		b = b / 2;
		a = (a * a) % c;
	}
	return ans;
}

int main(int argc, char const *argv[])
{
	//freopen("72623I.out", "w", stdout);
	//while (~scanf("%d", &n))
	{
		for (int n = 1; n < 600; n++)
		{
			ans = 0;
			for (int i = 1; i <= n; i++)
			{
				ans += PowerMod(i, i, 7);
			}
			cout << n << ":" << a[ans % 7] << endl;
		}
	}
	return 0;
}