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

#define MAXN 99+10

int t, n;
char a[MAXN][MAXN];
int ans = 0;
struct point
{
	int x, y;
} p[4];

void init()
{
	ans = 0;
	memset(a, 0, sizeof(a));
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%s", a[i] + 1);
	}
}

int judge(int x, int y)
{
	p[0].x = x, p[0].x = y;
	p[1].x = n - x, p[1].x = y;
	p[2].x = n - x, p[2].x = n - y;
	p[3].x = x, p[3].x = n - y;
	int flag = 0;
	char tmp;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4 && j != i; j++)
		{
			if (a[p[i].x][p[i].y] == a[p[j].x][p[j].y])
			{
				flag++;
			}
		}
	}
	return flag;
}

int main(int argc, char const *argv[])
{
	scanf("%d", &t);
	while (t--)
	{
		init();
		for (int i = 1; i <= (n + 1) / 2; i++)
		{
			for (int j = 1; j <= (n + 1) / 2; j++)
			{
				int tmp = judge(i, j);
				if (tmp == 0)
				{
					ans += 3;
					cout << 0;
				}
				else if (tmp == 2)
				{
					ans += 2;
					cout << 2;
				}
				else if (tmp == 8)
				{
					ans += 0;
					cout << 8;
				}
				else
				{
					ans++;
					cout << 4;
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}