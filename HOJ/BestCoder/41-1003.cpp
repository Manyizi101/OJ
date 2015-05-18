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

const ll MOD = 998244353;

int t, n, c, l, r;
ll ans;


int SplitNonRepeat(int nNum)//非递归的
{
	int lnCount(0);
	int *pCounts = new int[nNum + 1];
	for (int i = 1; i <= nNum; i++)pCounts[i] = 0;
	pCounts[0] = 1;
	int i(0);
	int maxexp(0);

	for (i = 1; i <= nNum; i++)
	{
		maxexp += i;
		for (int j = maxexp > nNum ? nNum : maxexp; j >= i; j--) //模拟多项式展开
		{
			pCounts[j] += pCounts[j - i];
		}
	}
	lnCount = pCounts[nNum];
	delete []pCounts;
	return lnCount;
}

void init()
{
	ans = 0;
	scanf("%d%d%d%d", &n, &c, &l, &r);
}

int main(int argc, char const *argv[])
{
	scanf("%d", &t);
	while (t--)
	{
		init();
		for (int i = l - c; i <= r - c; i++)
		{
			ans += SplitNonRepeat(i);
			if (ans >= MOD)	ans -= MOD;
		}
		printf("%d\n", ans);
	}
	return 0;
}