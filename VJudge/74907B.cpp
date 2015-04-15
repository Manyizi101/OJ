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

const int MAXN = 2 * 100000 + 10;

char a[MAXN];
int flaga = 0;
int flagb = 0;
int len;

void init()
{
	scanf("%s", a);
	len = strlen(a);
	flaga = 0;
	flagb = 0;
}

int main(int argc, char const *argv[])
{
	init();
	for (int i = 0; i < len; i++)
	{
		if (a[len-1] > a[i] && (a[i] - '0') % 2 == 0)
		{
			swap(a[i], a[len-1]);
			flaga = 1;
			break;
		}
	}
	if (flaga == 0)
	{
		for (int j = len - 1; j >= 0; j--)
			if (a[j] > a[len - 1] && (a[j] - '0') % 2 == 0)
			{
				swap(a[j], a[len - 1]);
				flagb = 1;
				break;
			}
	}
	if (flagb == 1 || flaga == 1)	cout << a;
	else cout << -1;
	return 0;
}