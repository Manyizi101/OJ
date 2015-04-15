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
int len;
int x, y;

void init()
{
	scanf("%s", a);
	len = strlen(a);
	x = y = 0;
}

int main(int argc, char const *argv[])
{
	init();
	for (int i = 0; i < len; i++)
	{
		if (a[i] >= 'A' && a[i] <= 'Z')	x++;
		else y++;
	}
	if (x > y)
	{
		for (int i = 0; i < len; i++)
		{
			if (a[i] >= 'a' && a[i] <= 'z')	a[i] = a[i] + 'A' - 'a';
		}
	}
	else
	{
		for (int i = 0; i < len; i++)
		{
			if (a[i] >= 'A' && a[i] <= 'Z')	a[i] = a[i] - 'A' + 'a';
		}
	}
	cout << a;
	return 0;
}