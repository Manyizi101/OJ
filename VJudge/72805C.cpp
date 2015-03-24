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

const int MAXN = 100000 + 10;
int ans, n, k, r;

struct node
{
	int val;
	int pos;
} x[MAXN];

bool cmp(node a, node b)
{
	if (a.val == b.val)	return a.pos < b.pos;
	else return a.val < b.val;
}

void init()
{
	ans = -1;
	r = 1;
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &x[i].val);
		x[i].pos = i + 1;
	}
	sort(x, x + n, cmp);
}

int main(int argc, char const *argv[])
{
	while (~scanf("%d %d", &n, &k))
	{
		init();
		int i,j;
		for (i = 0; i < n;)
		{
			int dis = r - i;
			for (j = r; j < n; j++)
			{
				if (x[i].val != x[j].val)
				{
					ans = max(ans, dis);
					i = j;
					r = j + 1;
					break;
				}
				if (x[j].pos - x[i].pos > j - i + k)
				{
					ans = max(ans, dis);
					dis--;
					i++;
					r = j;
					break;
				}
				dis++;
			}
			if(j==n)
			{
				ans=max(ans,dis);
				break;
			}
		}
		cout << ans << endl;
	}
	return 0;
}
