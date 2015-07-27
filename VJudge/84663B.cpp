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

typedef long long int ll;
const double pi = acos(-1.0);
const double eps = 1e-8;
const int inf = 0x3f3f3f3f;
const ll INF = 0x3f3f3f3f3f3f3f3fLL;
using namespace std;

const int N = 80 + 10;

int t;
char a[N];

int cal(char a[])
{
	int len = strlen(a);
	int tmp = 0, ans = 0;
	for (int i = 0; i < len; i++)
	{
		if (a[i] == 'O')
		{
			tmp++;
			ans += tmp;
		}
		else
		{
			tmp = 0;
		}
	}
	return ans;
}

int main()
{
	scanf("%d", &t);
	while (t--)
	{
		memset(a, 0, sizeof(a));
		scanf("%s", a);
		printf("%d\n", cal(a));
	}
	return 0;
}