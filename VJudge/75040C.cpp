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

const int MAXN = 100000 + 10;

int x[MAXN];
int tmp, n;

void init()
{
	cin >> n;
	memset(x, 0, sizeof(x));
}

bool cmp(int a, int b)
{
	return a > b;
}

int main(int argc, char const *argv[])
{
	init();
	for (int i = 0; i < n; i++)
	{
		cin >> tmp;
		if (i < (n + 1) / 2)
		{
			if (0 < tmp - i)
			{
				x[tmp - i]++;
			}
		}
		else
		{
			if (0 < tmp + i + 1 - n)
			{
				x[tmp + i + 1 - n]++;
			}
		}
	}
	sort(x, x + MAXN, cmp);
	cout << n - x[0] << endl;
	return 0;
}
