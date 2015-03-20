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

const int maxn = 10000;

//flag[i]==1表i是素数
bool flag[maxn + 5];
int prime[maxn + 5];

void init()
{
	for (int i = 2; i <= maxn; i++)
	{
		if (!prime[i])
		{
			prime[++prime[0]] = i;
			flag[i] = true;
		}
		for (int j = 1; j <= prime[0] && prime[j] <= maxn / i; j++)
		{
			prime[prime[j]*i] = 1;
			if (i % prime[j] == 0) break;
		}
	}
}

int main(int argc, char const *argv[])
{
	init();
	int x;
	while (scanf("%d", &x) == 1 && x)
	{
		int ans = 0; //方法数
		for (int i = 1; i <= prime[0] && prime[i] <= x / 2 - 1; i++)
		{
			if (flag[x - prime[i]]) ans++;
		}
		printf("%d\n", ans);
	}
	return 0;
}
