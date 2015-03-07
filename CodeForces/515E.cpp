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

#define MAXN 100000+10

int n,m;
int d[MAXN],h[MAXN],a[MAXN],b[MAXN];
int ans=0;

void init()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%d", &d[i]);
	}
	for(int i=1;i<=n;i++)
	{
		scanf("%d", &h[i]);
	}
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d", &a[i], &b[i]);
	}
}

int dist(int x, int y)
{
	int tmp=0;
	if(x<=y)
	{
		for(int i=1;i<x;i++)
		{
			tmp+=d[i];
		}
		for(int i=b[i]+1;i<=n;i++)
		{
			tmp+=d[i];
		}
		return tmp;
	}
}

int main(int argc, char const *argv[])
{
	init();
	for(int i=1;i<=m;i++)
	{
		if(a[i]<b[i])
		{
			ans=2*(h[a[i]-1]+h[b[i]+1])+dist(a[i]-1,b[i]+1);
			for(int i=)
		}
	}
	return 0;
}