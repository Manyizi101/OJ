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

#define MAXN 50+10

int n,m;
char a[MAXN][MAXN];
int used[MAXN][MAXN];
int dir[4][2]={{0,1}, {1,0},{0,-1},{-1,0}};

void init()
{
	memset(used, 0 ,sizeof(used));
	scanf("%d%d", &n,&m);
	for(int i=0;i<=n+1;i++)
	{
		used[i][0]=1;
		used[i][m+1]=1;
	}
	for(int i=0;i<=m+1;i++)
	{
		used[0][i]=1;
		used[n+1][i]=1;
	}
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]+1;
	}
}

int dfs(int x, int y)
{
	used[x][y]=1;
	static int st = x, ed = y;
	for(int i=0;i<4;i++)
	{
		if(x==st&&y==ed)
		if(x+)
	}
}

int main(int argc, char const *argv[])
{
	init();
	return 0;
}