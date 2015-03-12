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

#define MAXN 1500+10

int n, m;
int dp[MAXN][MAXN], dp[MAXN][MAXN];

struct node
{
	int val;
	int used;
	int rank;
} a[MAXN][MAXN];

struct dpx
{
	int val;
	int num;
}dp[MAXN];

bool cmp(node a, node b)
{
	return a.val > b.val;
}

void init()
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			scanf("%d", &a[i][j].val);
			a[i][j].rank = j;
		}
		for (int j = 0; j < m; j++)
		{
			if (a[i][j].val != 0)
			{
				dp[i].val += a[i][j].val;
				dp[i].num++;
				a[i][j].used = 1;
				break;
			}
		}
		sort(a[i], a[i] + m, cmp);
	}
}

int main(int argc, char const *argv[])
{
	init();
	for(int i=0;i<n;i+=2)
	{
		for(int j=0;j<m;j++)
		{
			if(a[i][j].val>==0)
			{
				dp[i].val+=a[i][j].val;
				dp[i].num++;
			}
		}
	}
	for(int i=1;i<n;i+=2)
	{

	}
	return 0;
}