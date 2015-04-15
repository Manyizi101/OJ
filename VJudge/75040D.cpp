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

const int MAXN = 10000 + 10;

int n, sum, len;
string a[MAXN];
string x;
string ans[MAXN];

bool cmp(string a, string b)
{
	if (a.size() == b.size())	return a < b;
	else return a.size() < b.size();
}

void init()
{
	sum = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)	cin >> a[i];
	cin >> x;
	for (int i = 0; i < n; i++)
	{
		a[i] += x;
		sum += a[i].size();
	}
	len = sum / (n / 2);
	sort(a, a + n);
}

int main(int argc, char const *argv[])
{
	init();
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (a[i].size() + a[j].size() == len)
			{
				cout << a[i] << a[j].substr(0, a[j].size() - 1) << endl;
				a[i].clear();
				a[j].clear();
			}
		}
	}
	return 0;
}