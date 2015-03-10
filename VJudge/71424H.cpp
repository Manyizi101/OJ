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
#define inf (1<<10)
#define ll long long int
using namespace std;

#define MAXN 9+10

int t, n;
int e[MAXN][MAXN];
char a[MAXN][MAXN];
int st,ed;

void init()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) 
	{
		for (int j = 1; j <= n; j++) 
		{
			if (i == j)
				e[i][j] = 0;
			else
				e[i][j] = inf;
		}
	}
	for (int i = 0; i < n; i++)
	{
		getchar();
		for (int j = 0;j < n; j++)
		{
			scanf("%c", &a[i][j]);
			if (a[i][j] >= 0 && a[i][j] <= 9)	e[i][j] = a[i][j] - '0';
			else if (a[i][j] == '@')	e[i][j] = 0;
			else if (a[i][j] == 'X')	e[i][j] = inf;
			else if(a[i][j]=='v')
			{
				st=i;
				ed=j;
			}
		}
	}
}

int dij()
{
	int dis[10], book[10], i, j, m, n, u, v, min;
	for (i = 1; i <= n; i++) {
		dis[i] = e[startPoint][i];
	}
	//book数组用来标记那个点是已经走过了的。
	for (i = 1; i <= n; i++) {
		book[i] = 0;
	}
	//从源点开始
	book[startPoint] = 1;
	//以下就是Dijkstra算法的重点，是核心思想
	for (i = 1; i <= n - 1; i++) {
		//找到离远点最近的点
		min = inf;
		for (j = 1; j <= n; j++) {
			if (book[j] == 0 && dis[j] < min) {
				min = dis[j];
				u = j;
			}
		}
		book[u] = 1;
		for (v = 1; v <= n; v++) {
			//如果小于inf，则证明点u到点v是有路走的
			if (e[u][v] < inf) {
				if (dis[v] > dis[u] + e[u][v]) {
					dis[v] = dis[u] + e[u][v];
					e[u][v]=0;
				}
			}
		}
	}
	//输出
	for (i = 0; i <= n; i++) {
		printf("%d ", dis[i]);
	}
	cout<<endl;
}



int main(int argc, char const *argv[])
{
	scanf("%s", &t);
	while (t--)
	{
		init();
		dij();
	}
	return 0;
}