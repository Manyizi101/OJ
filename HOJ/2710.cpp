#include <stdio.h>
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

const int MAXN = 20017;
int s[MAXN];

int main(int argc, char const *argv[])
{
	int n, m;
	memset(s, 0, sizeof(s));
	s[1] = 1; //此题1也是素数
	for (int i = 2; i < MAXN; i++) //筛选所有范围内的素数
	{
		if (s[i] == 0) //没有被更新过
			for (int j = i; j < MAXN; j += i)
			{
				s[j] = i;
			}
	}
	while (~scanf("%d", &n))
	{
		int ans;
		int maxx = -1;
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &m);
			if (s[m] > maxx)
			{
				maxx = s[m];
				ans = m;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}