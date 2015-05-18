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
const int inf = 1 << 31;
using namespace std;

const int MAXN = 1000 + 10;

int a[MAXN];
int n;
int pre;

void init()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}
	pre = 1000;
}

bool judge(int i, int j)
{
	char x[2][5];
	int flag = 0;
	memset(x, 0, sizeof(x));
	for (int k = 3; k >= 0; k--)
	{
		x[0][k] = i % 10 + '0';
		i /= 10;
	}
	x[0][4] = '\0';
	for (int k = 3; k >= 0; k--)
	{
		x[1][k] = j % 10 + '0';
		j /= 10;
	}
	x[1][4] = '\0';
	for (int q = 0; q < 4; q++)
	{
		if (x[0][q] == x[1][q])	flag++;
	}
	if (flag >= 3)	return true;
	else return false;
}

void output()
{
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << endl;
	}
}

bool gao()
{
	for (int i = 1; i < n; i++)
	{
		if (a[i] < a[i - 1])	return false;
		if (a[i] > 2011)	return false;
	}
	return true;
}

int main(int argc, char const *argv[])
{
	init();
	for (int i = 0; i < n; i++)
	{
		for (int j = pre; j <= 2011; j++)
		{
			if (judge(a[i], j))
			{
				a[i] = j;
				pre = j;
				break;
			}
		}
	}
	if (gao())
		output();
	else
		puts("No solution");
	return 0;
}