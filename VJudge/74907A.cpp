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
const int inf = 1<<31;
using namespace std;

const int MAXN = 11;

int n;
int a[MAXN][MAXN];

void cal()
{
	for(int i=1;i<=10;i++)
	{
		a[i][1]=a[1][i]=1;
	}
	for(int i=2;i<=10;i++)
	{
		for(int j=2;j<=10;j++)
		{
			a[i][j]=a[i-1][j]+a[i][j-1];
		}
	}
	return;
}

void init()
{
	scanf("%d", &n);
	cal();
}

int main(int argc, char const *argv[])
{
	init();
	cout<<a[n][n];
	return 0;
}