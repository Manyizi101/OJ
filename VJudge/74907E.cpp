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

const int MAXN = 100 + 10;

int n, k;
int ans[MAXN];

struct node
{
	int val, rank;
} a[MAXN];

bool cmp(node a, node b)
{
	return a.val < b.val;
}

void init()
{
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i].val);
		a[i].rank = i + 1;
	}
	sort(a, a + n, cmp);
}

int main(int argc, char const *argv[])
{
	init();
	int i = 0;
	while (k > 0 && i <= n)
	{
		ans[i] = a[i].rank;
		k -= a[i].val;
		i++;
	}
	if(k==0)	i++;
	cout << i-1 << endl;
	for (int j = 0; j < i-1; j++)
	{
		cout << ans[j] << " ";
	}
	return 0;
}