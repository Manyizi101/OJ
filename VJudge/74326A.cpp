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
char a[MAXN];
int i, len, ans;

void init()
{
	ans = 0;
	scanf("%s", a);
	len = strlen(a);
}

int main(int argc, char const *argv[])
{
	init();
	for (i = 0; i < len; i++)
	{
		if (a[i] == 'h')
		{
			ans++;
			break;
		}
	}
	if (ans != 1)	goto fuck;
	for (; i < len; i++)
	{
		if (a[i] == 'e')
		{
			ans++;
			break;
		}
	}
	if (ans != 2)	goto fuck;
	for (; i < len; i++)
	{
		if (a[i] == 'l')
		{
			i++;
			ans++;
			break;
		}
	}
	if (ans != 3)	goto fuck;
	for (; i < len; i++)
	{
		if (a[i] == 'l')
		{
			ans++;
			break;
		}
	}
	if (ans != 4)	goto fuck;
	for (; i < len; i++)
	{
		if (a[i] == 'o')
		{
			ans++;
			break;
		}
	}

fuck:
	if (ans == 5)	cout << "YES";
	else cout << "NO";
	return 0;
}