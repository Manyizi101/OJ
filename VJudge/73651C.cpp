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
const int inf = 1 << 20;
using namespace std;

const int MAXN = 6;
int a[MAXN] = {1, 1, 2, 7, 4};
int b[MAXN];
int ans[MAXN] = {0};
int m=inf;

int main(int argc, char const *argv[])
{
	for (int i = 0; i < 5; i++)
	{
		scanf("%d", &b[i]);
		ans[i]=b[i]/a[i];
		m=min(m,ans[i]);
	}
	cout<<m;
	return 0;
}