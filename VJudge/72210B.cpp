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

#define MAXN 1000*1000

int n;
char tmp;
struct node
{
	int a[4];
	int b[4];
} x[MAXN];
int flag = 0;
int rank[MAXN];

void init()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		getchar();
		for (int j = 0; j < 2; j++)
		{
			scanf("%c", &tmp);
			x[i].a[j] = tmp - '0';
		}
		getchar();
		for (int j = 3; j > 1; j--)
		{
			scanf("%c", &tmp);
			x[i].a[j] = tmp - '0';
		}
		if (i != n - 1)
		{
			getchar();
			getchar();
			getchar();
		}
	}
}

bool judge(int i)
{
	for (int j = 0; j <= flag; j++)
	{
		for (int m = 0; m < 4; m++)
		{
			if (x[i].b[0] == x[rank[j]].b[m]) 	return true;
		}
	}
	return false;
}

int main(int argc, char const *argv[])
{
	init();
	for (int i = 0; i < n; i++)
	{
		for (int m = 0; m < 4; m++)
		{
			for (int j = 0; j < 4; j++)
			{
				x[i].b[m] = x[i].b[m] * 10 + x[i].a[(j+m)%4];
			}
		}
	}
	for(int i=0;i<n;i++)	cout<<x[i].b[0]<<endl;
	rank[flag] = 0;
	for (int i = 0; i < n; i++)
	{
		if (!judge(i))
		{
			rank[++flag] = i;
			cout<<flag<<endl;
			break;
		}
		else
		{
			continue;
		}
	}
	cout << flag+1;
	return 0;
}
