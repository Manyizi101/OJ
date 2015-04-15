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

const int MAXN = 50 + 10;
int t, n, flag = 0;
double transfer[3][3] = {{0.5, 0.375, 0.125}, {0.25, 0.125, 0.625}, {0.25, 0.375, 0.375}};
double current[3] = {0.63, 0.17, 0.2};

struct matrix
{
	double m[3][3];
	matrix()
	{
		memset(m, 0, sizeof(m)); //注意要清零
	}
};

matrix operator * (const matrix & a, const matrix & b)
{
	matrix c;
	for (int i = 1; i <= 9; i++)
		for (int j = 1; j <= 9; j++)
		{
			c.m[i][j] = 0;
			for (int k = 1; k <= 9; k++)
				c.m[i][j] = (c.m[i][j] + a.m[i][k] * b.m[k][j]); //一般题目都要求要modulo一个数
		}
	return c;
}

matrix quick(matrix base, int pow)
{
	matrix a;
	for (int i = 1; i <= 9; i++) a.m[i][i] = 1; //单位阵，矩阵乘法时要用到
	while (pow)
	{
		if (pow & 1) a = a * base;
		base = base * base;
		pow >>= 1;
	}
	//if (pow==0) return base;
	return a;
}

void init()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		cin >> leaf[i];
	}
}

int main(int argc, char const *argv[])
{
	/*
	scanf("%d", &t);
	while (t--)
	{
		//cout<<"Case #"<<++flag<<":\n";
		init();
	}
	**/

	return 0;
}